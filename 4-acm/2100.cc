#include <iostream>

int main() {
	int n, c = 2;
	std::cin >> n;
	std::string s;
	for (int i=0; i < n; ++i) {
		std::cin >> s;
		c++;
		if (s.find('+') != std::string::npos) c++;
	}
	if (c == 13) c++;
	std::cout << c * 100 << "\n";
	return 0;
}