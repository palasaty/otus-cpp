#include <iostream>
int main() {
	int n,m;
	std::cin >> n >> m;

	std::cout << (m >=1 ? m - 1 : 0) << " " << (n >= 1 ? n -1 : 0);
	return 0;
}