#include <iostream>
#include <vector>
#include <unordered_map>

struct Device{};

class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
    {
        return m_Devices;
    }
};

int main()
{
    std::vector<std::string> arr;
    arr.emplace_back("hello");
    arr.emplace_back("world");

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    for (std::vector<std::string>::iterator it = arr.begin();
         it != arr.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    DeviceManager manager;

    // can't be: audo devices = manager.GetDevices();
    const auto& devices = manager.GetDevices();

    return 0;
}