#include <GLFW/glfw3.h>
#include <iostream>
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

    // GLFWwindow * window = glfwCreateWindow( 800, 600, "OneFLOW GLFW OpenGL Test", NULL, NULL );
    // if ( window == NULL )
    // {
    //     std::cout << "Failed to create GLFW window" << std::endl;
    //     glfwTerminate();
    //     return -1;
    // }
    // // render loop
    // while ( !glfwWindowShouldClose( window ) )
    // {
    //     // check and call events and swap the buffers
    //     glfwPollEvents();
    //     glfwSwapBuffers( window );
    // }
    // glfwMakeContextCurrent( window );
    return 0;
}