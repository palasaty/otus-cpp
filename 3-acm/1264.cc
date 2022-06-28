#include <iostream>
int main() {
	int a[6];
	for (int i=0; i < 6; ++i)
		std::cin >> a[i];

	for (int i=0; i < 6; ++i)
		std::cout << a[i] << " ";
	std::cout << "\n";

	std::cout << a[0] - a[4] << " " << a[1] - a[3] << "\n";
	return 0;
}