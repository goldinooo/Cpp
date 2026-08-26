#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    ::swap(a, b);

    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << ::min(10, 20) << std::endl;
    std::cout << ::max(10, 20) << std::endl;

    std::string s1 = "ABC";
    std::string s2 = "XYZ";

    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;

    ::swap(s1, s2);

    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;

    std::cout << ::min(s1, s2) << std::endl;
    std::cout << ::max(s1, s2) << std::endl;

    return 0;
}