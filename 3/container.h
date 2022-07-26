#ifndef __container_h__
#define __container_h__

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
private:
	void preallocate() {

	}

private:
	T* _data = nullptr;
  	Allocator _allocator;
  	size_t _size = 0;
  	size_t _allocatedSize = 0;
	
};

#endif