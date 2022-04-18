#ifndef __ip_h__
#define __ip_h__

#include <string>
#include <vector>
#include <algorithm>

class Ip {
public:
    Ip(const std::string&);
    void print() const;

private:
    std::string _ip_str;    
};

class IpContainer {
public:
    void add(const std::string&);
    void sort() {}
    
    void print_all() {
        print([](const Ip& ip)->bool { return true; });
    }

private:
    template<typename P>
    void print(P&& p){
        for_each(_data.begin(), _data.end(), [p](const Ip& ip) {
            if (p(ip)) ip.print();
        });    
    }
    
private:
    std::vector<Ip> _data;    
};

#endif