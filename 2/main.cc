#include <iostream>
#include "ip.h"

int main()
{
   try {
      IpContainer ips;

      for (std::string line; std::getline(std::cin, line), !line.empty();) {
         ips.add(line);
      }

      ips.sort();
      ips.print();

      ips.print_equal(IpBytes{1});
      ips.print_equal(IpBytes{46,70});
      ips.print_equal_any(46);

   } catch (std::exception& e) {
      std::cout << "Error: " << e.what() << "\n";
   }
    
    return 0;
}