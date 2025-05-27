#include "ram.h"
#include <iostream>

void compute()
{
    int buffer[8];
    read(buffer);
    
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += buffer[i];
    }
    
    std::cout << "Sum: " << sum << std::endl;
}