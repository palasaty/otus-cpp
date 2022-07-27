#ifndef __container_h__
#define __container_h__

#include <math.h>

template<typename T, typename Allocator = std::allocator<T>>
class Container {
public:
	Container() = default;
    void add(T item){
		if(_size == _allocatedSize) preallocate();
		
		_data[_size++] = item;
    }
    T* begin(){ return _data; };
  	T* end(){ return _data + _size; };
  	T& operator[](size_t idx) {
  		return _data[idx];
	}
private:
	void preallocate() {
		size_t prevAllocatedSize = _allocatedSize;
		T* prevData = _data;
		_allocatedSize = pow(2, _allocatedSize);
		_data = _allocator.allocate(_allocatedSize);

    	for(size_t i = 0; i < _size; ++i) {
			std::allocator_traits<Allocator>::construct(_allocator, _data + i, *(prevData + i));
			std::allocator_traits<Allocator>::destroy(_allocator, prevData + 1);
		}

		if (prevData) _allocator.deallocate(prevData, prevAllocatedSize);
	}

private:
	T* _data = nullptr;
  	Allocator _allocator;
  	size_t _size = 0;
  	size_t _allocatedSize = 0;
	
};

#endif