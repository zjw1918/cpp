#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

void HelloWorld(int a)
{
    std::cout << "Hello world " << a << std::endl;
}


// void ForEach(const std::vector<int>& values, void(*func)(int))
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
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

    // an example to use lambda in fine_if
    auto it = std::find_if(arr.begin(), arr.end(), [](int value) { return value > 3; });
    std::cout << *it << std::endl;
    std::cout << sizeof(it) / sizeof(int) << std::endl;

    ForEach(arr, fn);
    // lambda
    int a = 1;
    // =, &, a, &a
    // all var by value, all var by refs, ..., ...
    ForEach(arr, [&a](int value) mutable { a++; std::cout << "Lambda: " << a << std::endl; });
    std::cout << "at last a: " << a << std::endl;

    return 0;
}