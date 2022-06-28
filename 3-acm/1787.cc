#include <iostream>
int main() {
	int k, n;
	std::cin >> k >> n;
	int a[n];
	int s = 0;
	for (int i=0; i < n; ++i) {
		std::cin >> a[i];
		s+=a[i] - k;
		//std::cout << s << "\n";
		if (s < 0) s =0;
	}

	std::cout << s << "\n";
	return 0;
}