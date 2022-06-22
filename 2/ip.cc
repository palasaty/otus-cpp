#include "ip.h"
#include <iostream>
#include <tuple>

Ip::Ip(const std::string& s)
    : _ip_str{s.substr(0, s.find_first_of('\t'))}
{
    size_t idx = 0, pos0 = 0, pos1 = s.find_first_of('.');
    while(pos1 != std::string::npos) {
        _ip_bytes[idx++] = std::stoul(s.substr(pos0, pos1 - pos0));
        
        pos0 = pos1 + 1;
        pos1 = s.find_first_of('.', pos0);
    }
    
    _ip_bytes[idx] = std::stoul(s.substr(pos0));
}

bool Ip::operator<(const Ip &r) const {
    return std::tie(_ip_bytes[0], _ip_bytes[1], _ip_bytes[2], _ip_bytes[3]) <
            std::tie(r._ip_bytes[0], r._ip_bytes[1], r._ip_bytes[2], r._ip_bytes[3]);
}

bool Ip::equal(const IpBytes& b) const {
    for(size_t i=0; i < b.size(); ++i) {
        if (!b[i]) continue;
        if (b[i] != _ip_bytes[i])
            return false;
    }

    return true;   
}

bool Ip::equal_any(uint8_t b) const {
    for(size_t i=0; i < _ip_bytes.size(); ++i) {
        if (b == _ip_bytes[i])
            return true;
    }

    return false; 
}

void Ip::print() const {
    std::cout << _ip_str << "\n";
}

void IpContainer::add(const std::string& s) {
    _data.emplace_back(s);
}

void IpContainer::sort() {
    std::sort(_data.rbegin(), _data.rend());
}

void IpContainer::print(){
    for_each(_data.begin(), _data.end(), [](const Ip& ip) {
        ip.print();
    });    
}

void IpContainer::print_equal(const IpBytes&& b) {
    for_each(_data.begin(), _data.end(), [&b](const Ip& ip) {
        if(ip.equal(b)) ip.print();
    }); 
}
    
void IpContainer::print_equal_any(uint8_t b) {
    for_each(_data.begin(), _data.end(), [&b](const Ip& ip) {
        if(ip.equal_any(b)) ip.print();
    }); 
}
