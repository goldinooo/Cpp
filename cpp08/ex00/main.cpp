#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);

    try
    {
        std::cout << "Found: " << *easyfind(v, 3) << std::endl; // should find
        std::cout << "Found: " << *easyfind(v, 8) << std::endl; // should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}