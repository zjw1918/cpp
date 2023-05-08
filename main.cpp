#include <GLFW/glfw3.h>
#include <iostream>
// #include <utility>
// #include <functional>

#include "Static.h"

using namespace std;

// 如果不引入glfw头文件时，如下申明函数也是可以运行的
// extern "C" int glfwInit();

int main()
{
    std::cout << "hello world" << std::endl;

    int i = glfwInit();

    std::cout << i << std::endl;

    int sum = addTwo(8, 100);

    std::cout << sum << std::endl;

    std::array<std::string, 5> arr = GetStringArray();
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    auto tupleRes = GetTwoTypesResult();
    std::cout << std::get<0>(tupleRes) << std::endl;
    std::cout << std::get<1>(tupleRes) << std::endl;
    
    // no idea how to include, just list here
    // std::cout << tupleRes.first << std::endl;
    // std::cout << tupleRes.second << std::endl;

    return 0;
}