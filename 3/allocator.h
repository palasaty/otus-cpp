#ifndef __allocator_h__
#define __allocator_h__

#include <cstddef>
#include <vector>
#include <deque>

#include <iostream>


template<typename T, std::size_t N>
class Block {
public:
	Block() {
		//_pool.resize(N);
		_pool = static_cast<T*>(::operator new( N*sizeof(T) ));
	}

	bool full() {
		return _available_pos > N;
	}

	bool has(T* p) {
		return p > _pool && p < _pool + N;
	}

	T* getChunk(size_t n) {
		if (n > N) throw std::bad_alloc();

		std::fill_n(_pool_state.begin() + _available_pos, n, 1);
		return &_pool[_available_pos];
	}

	void resetChunk(T* p, size_t n) {
		size_t i = 0;
		while(&_pool[i++] != p);

		std::fill_n(_pool_state.begin() + i, n, 0);
	}

private:
	void findAvailable() {
		_available_pos = std::distance( std::begin(_pool_state), 
			find_if(_pool_state.begin() + _available_pos, _pool_state.end(), [](bool x) { return !x; }));
	}


private:
	//std::vector<T> _pool;
	T* _pool;
	std::vector<bool> _pool_state = {0};
	std::size_t _available_pos {0}; 
};

//todo: use blocks
template<typename T, std::size_t N = 10>
class Allocator {
public:
	using value_type = T;
	  
	template<typename U>
    struct rebind {
    	using other = Allocator<U>;
  	};

	Allocator() = default;

	template <typename U>
	Allocator(const Allocator<U>&) {}

	value_type* allocate (std::size_t n) { 
		for(auto& b: _blocks) 
			if (!b.full()) 	return b.getChunk(n);

		_blocks.emplace_back();
		return _blocks.back().getChunk(n);
	}
	
	void deallocate (value_type* p, std::size_t n) noexcept{
		for (auto& b : _blocks) {
			if (b.has(p)) {
				b.resetChunk(p, n);
				return;
			}
		}
	}

private:
	std::vector<Block<T,N>> _blocks;
};

#endif