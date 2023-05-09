#include <iostream>
#include <vector>
#include <unordered_map>

void HelloWorld(int a)
{
    std::cout << "Hello world " << a << std::endl;
}


void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value: values) {
        func(value);
    }
}

int main()
{
    // simplify or make it easy to read
    typedef void(*HelloFunction)(int);

    // void(*fn)();

    HelloFunction fn = HelloWorld;
    // auto fn = HelloWorld;

    fn(12);


    std::vector<int> arr = {0,1,2,3,4,10};
    ForEach(arr, fn);
    // lambda
    ForEach(arr, [](int value) { std::cout << "Lambda: " << value << std::endl; });

    return 0;
}