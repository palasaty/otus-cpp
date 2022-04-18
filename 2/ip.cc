#include "ip.h"
#include <iostream>

Ip::Ip(const std::string& s)
    : _ip_str{s.substr(0, s.find_first_of('\t'))}
{}

void Ip::print() const {
    std::cout << _ip_str << "\n";
}

void IpContainer::add(const std::string& s) {
    _data.emplace_back(s);
}
