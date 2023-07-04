#include "Leaen1.h"
#include <iostream>

class MySingleton
{
public:
    // must delete the copy constructor!!
    MySingleton(const MySingleton &) = delete;
    static MySingleton &GET()
    {
        return s_Instance;
    }
    void Print()
    {
        std::cout << "print from single\n";
    }

private:
    // make the constructor private!!
    MySingleton(){};
    static MySingleton s_Instance;
};

// must define
MySingleton MySingleton::s_Instance;

void learn1::runSingleton()
{
    std::cout << "run singleton001\n";
    MySingleton::GET().Print();

    MySingleton &singleton = MySingleton::GET();

    singleton.Print();
}