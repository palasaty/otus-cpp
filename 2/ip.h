#ifndef __ip_h__
#define __ip_h__

#include <string>
#include <vector>
#include <algorithm>
#include <array>

using IpBytes = std::array<uint8_t, 4>;

class Ip {
public:
    Ip(const std::string&);
    void print() const;
    bool operator<(const Ip &r) const;

    bool equal(const IpBytes& ) const;
    bool equal_any(uint8_t) const;

private:
    std::string _ip_str;   
    IpBytes _ip_bytes;
};

using IpVector = std::vector<Ip>;

class IpContainer {
public:
    void add(const std::string&);
    void sort();
    
    void print();
    void print_equal(const IpBytes&& );
    void print_equal_any(uint8_t);

private:
    IpVector _data;    
};

#endif