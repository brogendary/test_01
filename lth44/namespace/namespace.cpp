#include <iostream>
#include "lmao.h"

void fungsi2()
{
    std::cout<< "ini adalah fungsi biasa" << std::endl;
}


int main()
{

    fungsi2();

    std::cout << lmao::b << std::endl;
    lmao::fungsi();
    lmao::cout(100);

    
    return 0;
}