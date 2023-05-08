#include "Static.h"
#include <array>
#include <iostream>

int s_var = 10;

int addTwo(int a, int b) {
    return a + b;
}

std::array<std::string, 5> GetStringArray() {
    std::array<std::string, 5> res;
    res[0] = "hello";
    res[1] = "world";
    return res;
}

std::tuple<std::string, int> GetTwoTypesResult() {
    return std::make_pair("hello world", 109);
}