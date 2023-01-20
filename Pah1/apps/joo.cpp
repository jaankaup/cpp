#include<iostream>
#include<memory>
#include "BlahConfig.h"
//#include "../include/pah/lib.hpp"
#include "../include/pah/lib.hpp"

int main() {
    std::unique_ptr<uint> u = std::make_unique<uint>(123);
    std::cout << "Hekotus" << *u << std::endl;
    std::cout << Blah_VERSION_MAJOR; // << std::endl;
    std::cout << Blah_VERSION_MINOR; // << std::endl;
    std::cout << sum(13, 15); // << std::endl;
    return 0;
}
