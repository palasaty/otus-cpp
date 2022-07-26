#include <iostream>
#include <map>
#include "allocator.h"
#include "container.h"
#include "invoker.h"

int main()
{
   std::cout << "Hello world\n";

   using MapStd     = std::map<int, int>;
   using MapCustom  = std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>, 10>>;
   using ContStd    = Container<int>;
   using ContCustom = Container<int, Allocator<int>>;

   MapInvoker<MapStd> mapStd(10);
   MapInvoker<MapCustom> mapCustom(10); 
   Invoker<ContStd> contStd(10);
   Invoker<ContCustom> contCustom(10);
    
    return 0;
}