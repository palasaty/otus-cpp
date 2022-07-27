#include <iostream>
#include <deque>
#include <iomanip>
#include <math.h>

int main() {
	double a;
	std::deque<double> arr;
	while(std::cin >> a) {
		arr.push_front(sqrt(a));
	};

	for(auto i: arr)
		std::cout << std::fixed << std::setprecision(4) << i << "\n";

	return 0;
}