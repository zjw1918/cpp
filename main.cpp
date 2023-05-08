#include <iostream>
#include <cstring>

// 自定义一个String类，实现 
// 1. String s = "Hello"; s[1] = 'z';
// 2. std:cout << s << std::endl;
// 3. 深拷贝，并验证
//    String s2 = s;
//    s2[1] = 'z';

class String{
public:
    String(char* str): _str(str){
       
    }
    String(const String& ses){
        _str = new char[strlen(ses._str)+1];
        strcpy(_str,ses._str);
        //_str[strlen(ses._str)]='\0';
    }
    String& operator=(const String& ses){
        // 自我赋值
        if(ses._str == _str){
            return ses;
        }
        _str = new char[strlen(ses._str)+1];
        strcpy(_str,ses._str);
        return *this;
    }
    ~String(){
        delete[] _str;
    }
private:
    char* _str;
};

int main(int, char**) {
    std::cout << "hello world" << std::endl;
    String s = "Hello"; 
    s[1] = 'z';
    std::cout << s << std::endl;
    return 0;
}
