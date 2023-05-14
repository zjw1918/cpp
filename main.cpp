#include <iostream>
#include "FunctionPtr.h"
#include "Static.h"



int main()
{
    std::cout << "hello world" <<  std::endl;
    function_ptr::run();

    int sum = addTwo(1,2);
    std::cout << "sum: " << sum <<  std::endl;
    

    return 0;
}