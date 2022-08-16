#include <iostream>
#include <vector>
#include <algorithm>

const int N = 3;

int main() {
	std::vector<std::vector<int>> vec(N);
	int n;
	for (int i=0; i < N; ++i) {
		std::cin >> n;
		vec[i].resize(n);
		for(int j=0; j < n; ++j)
			std::cin >> vec[i][j];
	}

	std::vector<int> v;
  
    set_intersection(vec[0].begin(), vec[0].end(), vec[1].begin(), vec[1].end(),
                          std::back_inserter(v));

    vec[0].clear();
    set_intersection(vec[2].begin(), vec[2].end(), v.begin(), v.end(),
                          std::back_inserter(vec[0]));

    std::cout << vec[0].size() << "\n";

}