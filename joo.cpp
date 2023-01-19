#include<iostream>
#include<memory>

int main() {
    std::unique_ptr<uint> u = std::make_unique<uint>(123);
    std::cout << "Hekotus" << *u << std::endl;
    return 0;
}
