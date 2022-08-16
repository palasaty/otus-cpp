#include <iostream>

int count(int a, int b) {
	int c = 0;	
	if (a <= 7 && b <= 6) c++;
    if (a <= 7 && b >= 3) c++;
    if (a >= 2 && b <= 6) c++;
    if (a >= 2 && b >= 3) c++;

    return c;
}

int main()
{
	int n;
	std::cin >> n;
	int c[n];

	char a;
	int b;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		a = a - 'a' + 1;

		c[i] = count(a, b) + count(b, a);
	}

	for(int i=0; i < n; ++i)
		std::cout << c[i] << "\n";


	return 0;
}