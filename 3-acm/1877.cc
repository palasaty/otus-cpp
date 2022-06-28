bool check(char c) {
	int n = c - '0';
	return !(n%2); 
}

#include <iostream>
int main() {
	std::string key1, key2; 
	std::getline(std::cin, key1);
	std::getline(std::cin, key2);

	bool result = check(key1.back()) ||  !check(key2.back());

	std::cout << (result ? "yes" : "no") << "\n";
	return 0;
}