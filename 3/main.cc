#include <iostream>
#include <map>
#include "allocator.h"
#include "invoker.h"

int main()
{
   std::cout << "Hello world\n";

   using MapStd     = std::map<int, int>;
   using MapCustom  = std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>>;

   MapInvoker<MapStd> mapStd(10);
   MapInvoker<MapCustom> mapCustom(10); 
    
    return 0;
}