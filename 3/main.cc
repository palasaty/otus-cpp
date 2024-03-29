#include <iostream>
#include <map>
#include "allocator.h"
#include "container.h"
#include "invoker.h"

int main()
{
   std::cout << "Hello world\n";

   using MapStd     = std::map<int, int>;
   using MapCustom  = std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>>;
   using ContStd    = Container<int>;
   using ContCustom = Container<int, Allocator<int, 20>>;

   try {
      MapInvoker<MapStd> mapStd(10);
      MapInvoker<MapCustom> mapCustom(10); 
      Invoker<ContStd> contStd(10);
      Invoker<ContCustom> contCustom(10);
   } catch(std::exception& e) {
      std::cerr << e.what() << "\n";
   }
    
    return 0;
}