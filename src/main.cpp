#include "lib.h"

#include <iostream>

int main ()
{
    std::cout << "Hello, World!\n";
    std::cout << "Version: " << lib::version() << std::endl;
    
    return 0;
}