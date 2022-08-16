#include <iostream>

int main() {
   int a,b,c;
   std::cin >> a >> b >> c;
   if (b*c !=0 && b != 1 && c != 1 )
      std::cout << a - b *c << "\n";
   else
      std::cout << a - b - c << "\n";

   return 0;
}