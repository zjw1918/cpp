#include <iostream>
#include "FunctionPtr.h"
#include <iostream>
#include "Static.h"
#include "MyThread.h"
#include "FunctionPtr.h"



int main()
{
    std::cout << "hello world" <<  std::endl;
    // function_ptr::run();
    // my_thread::run();
    // my_thread::runTime();
    // my_thread::runUnions();
    // my_thread::runStructBindings();
    // my_thread::runOptionalData();
    my_thread::runVariant();

    int sum = addTwo(1,2);
    std::cout << "sum: " << sum <<  std::endl;
    
    
    std::cin.get();
    return 0;
}