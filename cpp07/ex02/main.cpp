#include <iostream>
#include "Array.hpp"

int main() {
    // 1) Default constructor
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    // 2) Sized constructor + operator[]
    Array<int> a(3);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i * 10);

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // 3) Copy constructor (deep copy)
    Array<int> b(a);
    b[0] = 99;
    std::cout << "after copy change -> a[0]=" << a[0] << ", b[0]=" << b[0] << std::endl;

    // 4) Assignment operator (deep copy)
    Array<int> c;
    c = a;
    c[1] = 77;
    std::cout << "after assign change -> a[1]=" << a[1] << ", c[1]=" << c[1] << std::endl;

    // 5) Const access
    const Array<int> ca(a);
    std::cout << "const access ca[2] = " << ca[2] << std::endl;

    // 6) Out-of-bounds exception
    try {
        std::cout << a[42] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}