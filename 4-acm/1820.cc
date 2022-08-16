#include <iostream>

int main() {
	int k, n;
	std::cin >> n >> k ;

	if (n <= k) 
		std::cout << 2 << "\n";
	else if (2*n%k)
		std::cout << 2*n/k + 1 << "\n";
	else
		std::cout << 2*n/k << "\n";
	return 0;
}