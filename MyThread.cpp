#include <iostream>
#include <thread>
#include <chrono>
#include "MyThread.h"
#include <fstream>
#include <optional>
#include <variant>
#include <any>

namespace my_thread
{
    bool isFinished = false;

    void DoWork()
    {
        using namespace std::literals::chrono_literals;
        std::cout << "work thread name:" << std::this_thread::get_id() << std::endl;
        while (!isFinished)
        {
            std::cout << "working..." << std::endl;
            std::this_thread::sleep_for(1s);
        }
    }

    void run()
    {
        std::thread worker(DoWork);
        std::cin.get();
        isFinished = true;
        worker.join();

        std::cout << "main thread name:" << std::this_thread::get_id() << std::endl;
    }

    struct Timer
    {
        std::chrono::_V2::system_clock::time_point start, end;
        std::chrono::duration<float> duration;

        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            float ms = duration.count() * 1000.0f;
            std::cout << "Time took: " << ms << "ms" << std::endl;
        }
    };

    void Function()
    {
        Timer timer;

        for (int i = 0; i < 1000; i++)
        {
            std::cout << "hello world\n";
        }
    }

    void runTime()
    {
        // using namespace std::chrono_literals;
        // auto start = std::chrono::high_resolution_clock::now();
        // std::this_thread::sleep_for(1s);
        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<float> duration = end - start;
        // std::cout << "duration: " << duration.count() << "s" << std::endl;

        Function();
    }

    void example01_union()
    {
        struct MyUnion
        {
            union
            {
                int a;
                float b;
            };
        };

        MyUnion u;
        u.a = 9;
        std::cout << u.a << ", " << u.b << std::endl;
    }

    struct Vector2
    {
        float x, y;
    };

    struct Vector4
    {
        union
        {
            struct
            {
                float x, y, z, w;
            };

            struct
            {
                Vector2 a, b;
            };
        };
    };

    void PrintVector2(const Vector2& vector)
    {
        std::cout << vector.x << ", " << vector.y << std::endl;
    }

    void example01_union_full()
    {
        Vector4 v = {1.0, 2.0, 3.0, 4.0};
        PrintVector2(v.a);
        PrintVector2(v.b);
        v.z = 500.0;
        PrintVector2(v.a);
        PrintVector2(v.b);
    }

    void runUnions()
    {
        // example01_union();
        example01_union_full();
    }

    // struct bindings c++17
    std::tuple<std::string, int> creatPerson() {
        return {"Tom", 19};
    }

    void runStructBindings()
    {
        auto[name, age] = creatPerson();
        std::cout << name << ", " << age << std::endl;  
    }

    // How to Deal with OPTIONAL Data in C++
    std::optional<std::string> ReadFileAsString(const char* filepath) {
        std::ifstream stream(filepath);
        if (stream)
        {
            std::string result;
            // read file
            stream.close();
            return result;
        }
        return {};
    }
    

    void runOptionalData() {
        std::optional<std::string> data = ReadFileAsString("data.txt");
        std::string value = data.value_or("defaule");
        std::cout << value << std::endl;
        
        if (data.has_value())
        {
            std::cout << "read file ok\n";
        } else 
        {
            std::cout << "read file error\n";
        }
    }

    // Multiple TYPES of Data in a SINGLE VARIABLE in C++

    void runVariant() {
        std::variant<std::string, int> data;
        data = "hello";
        std::cout << std::get<std::string>(data) << "\n";
        if (auto valuePtr = std::get_if<std::string>(&data)) {
            std::string& value = *valuePtr;
            std::cout << value << "\n";
        }
    }

    // How to store ANY data in C++
    // std::any may allocate memoty according to the type/size
    void runAny() {
        std::any data;
        data = 1;
        data = std::string("hello any.");
        std::string& str = std::any_cast<std::string&>(data);
        std::cout << str << "\n";
    }

} // namespace my_thread
