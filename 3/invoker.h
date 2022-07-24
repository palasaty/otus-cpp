#ifndef __invoker_h__
#define __invoker_h__

uint32_t factorial(uint32_t n)
{
    if (n == 0)  return 1;
    return n * factorial(n - 1);
}

template<typename T>
class MapInvoker {
public:
	MapInvoker(uint8_t n) {
		fill(n);
		print();
	}
private:
	void fill(uint8_t n) {
	  for (uint8_t i = 0; i < n; ++i) {
	    _map.emplace(i, factorial(i));
	  }
	}

	void print() {
	  for (auto item: _map) 
	    std::cout << item.first << " " << item.second << std::endl;
	}

private:
	T _map;
};

#endif