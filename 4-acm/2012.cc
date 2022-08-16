#include <iostream>

int main() {
	int f;
	std::cin >> f;

	std::cout << ((240 - (12-f)*45) > 0 ? "YES" : "NO") << "\n"; 

	return 0;
}