#include <iostream>
#include <thread>
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
} // namespace my_thread

