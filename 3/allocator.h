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
		bool val = findAvailable() > N;
		return val;
	}

	T* getChunk(size_t n) {
		if (n > N) throw std::bad_alloc();

		std::fill_n(_pool_state.begin() + _available_pos, n, 1);
		return &_pool[_available_pos];
	}

private:
	size_t findAvailable() {
		// TODO: set _available_pos and implement chunking
		return _pool_state[0] ? N + 1 : 0;
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
	
	void deallocate (value_type*, std::size_t) noexcept{
	}

private:
	std::vector<Block<T,N>> _blocks;
};

#endif