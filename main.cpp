#include <iostream>

template<typename T>
void Print(T arg) {
    std::cout << arg << std::endl;
}

struct Student
{
    std::string name;
    int age;
};

template<typename T, int N>
class MyArray
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};


int main()
{
    std::cout << "hello world" << std::endl;

    // Print(123);
    // Print("hello");

    // Student t = {"Tom", 12};
    // Print(t);

    MyArray<Student, 1> arr;
    std::cout << arr.GetSize() << std::endl;
    std::cout << sizeof(arr) << std::endl;
    
    return 0;
}