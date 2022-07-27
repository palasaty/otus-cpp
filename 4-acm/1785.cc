#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::string s;

	if (n < 5) s.assign("few");
	else if (n < 10) s.assign("several");
	else if (n < 20) s.assign("pack");
	else if (n < 50) s.assign("lots");
	else if (n < 100) s.assign("horde");
	else if (n < 250) s.assign("throng");
	else if (n < 500) s.assign("swarm");
	else if (n < 1000) s.assign("zounds");
	else s.assign("legion");

	std::cout << s << "\n"; 
	return 0;
}