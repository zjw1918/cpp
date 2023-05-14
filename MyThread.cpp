#include <iostream>
#include <thread>
#include <chrono>
#include "MyThread.h"

namespace my_thread
{
    bool isFinished = false;

    void DoWork() {
        using namespace std::literals::chrono_literals;
        std::cout << "work thread name:" << std::this_thread::get_id() << std::endl;
        while (!isFinished)
        {
            std::cout << "working..." << std::endl;
            std::this_thread::sleep_for(1s);
        }
    }

    void run() {
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

    void Function() {
        Timer timer;

        for (int i = 0; i < 1000; i++)
        {
            std::cout << "hello world\n";
        }
    }
    
    void runTime() {
        // using namespace std::chrono_literals;
        // auto start = std::chrono::high_resolution_clock::now();
        // std::this_thread::sleep_for(1s);
        // auto end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<float> duration = end - start;
        // std::cout << "duration: " << duration.count() << "s" << std::endl;

        Function();

    }
} // namespace my_thread

