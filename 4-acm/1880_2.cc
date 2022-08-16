#include <iostream>
#include <set>
#include <algorithm>

const int N = 3;

int main() {
	std::set<int> s,s1;
	int n, a, c=0;
	
	for (int i=0; i < N; ++i) {
		std::cin >> n;
		for(int j=0; j < n; ++j) {
			std::cin >> a;
			auto i1 = s.insert(a);
			if (!i1.second) {
				auto i2 = s1.insert(a);
				if (!i2.second) c++;
			}

		}
    }

    std::cout << c << "\n";
}