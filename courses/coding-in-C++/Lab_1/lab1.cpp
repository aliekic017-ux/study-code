#include <iostream>
#include "helloworld.hpp"


void printFromHeader() 
{
    std::cout << "Hello from the header" << std::endl;
}

int main () 
{
    
    std::cout << "Hello World!" << std::endl;
    printFromHeader();
    return 0;

}
