#include "Base.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>


Base *generate(void)
{
    int r = rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    //If the cast succeeds, the result is non-null, so it knows the real type.

    if (dynamic_cast<A *>(p))
        std::cout << "pointer A is alive" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "pointer B is alive" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "pointer C is alive" << std::endl;
}

void identify(Base &p)
{
    // if the cast fails ,it throws std::bad_cast that why we use try catch 
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "reference A is alive" << std::endl;
        return;
    } catch(...) {}; // const std::bad_cast &
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "reference B is alive" << std::endl;
        return;
    } catch(...) {};
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "reference C is alive" << std::endl;
        return;
    } catch(...) {};
}

int main() {
    srand(time(NULL));
    Base *ptr = generate();
    Base &ref = *ptr;
    identify(ptr);
    identify(ref);
    delete ptr;
}