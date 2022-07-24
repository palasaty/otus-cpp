#ifndef __allocator_h__
#define __allocator_h__

#include <cstddef>
#include <vector>

//todo: use blocks
template<typename T, std::size_t N = 10>
class Allocator {
public:
	using value_type = T;
	Allocator() = default;

	template <typename U>
	Allocator(const Allocator<U>&) {}

	value_type* allocate (std::size_t n) { 
		return static_cast<value_type*>(::operator new (n*sizeof(value_type)));
	}
	
	void deallocate (value_type* p, std::size_t) noexcept{
		::operator delete(p);
	}
private:
	std::vector<std::vector<char>> _blocks;
};


// todo: implement
template <class T, class U>
constexpr bool operator== (const Allocator<T>&, const Allocator<U>&) noexcept {
	return false;
}

template <class T, class U>
constexpr bool operator!= (const Allocator<T>&, const Allocator<U>&) noexcept {
	return false;
}
#endif