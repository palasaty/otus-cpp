#include <iostream>
#include "ip.h"

int main()
{
    IpContainer ips;
    
    for (std::string line; std::getline(std::cin, line), !line.empty();) {
       ips.add(line);
    }
    
    ips.sort();
    ips.print_all();
    
    std::cout << "end\n";
    
    return 0;
}