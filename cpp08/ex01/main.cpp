#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "=== Basic valid case ===\n";
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== FullContainer exception ===\n";
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // should throw
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== NoSpan exception (empty) ===\n";
    try {
        Span sp(5);
        std::cout << sp.shortestSpan() << std::endl; // should throw
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== NoSpan exception (one element) ===\n";
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.longestSpan() << std::endl; // should throw
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Copy constructor ===\n";
    try {
        Span original(3);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);

        Span copy(original);
        std::cout << "Copy shortest: " << copy.shortestSpan() << std::endl;
        std::cout << "Copy longest : " << copy.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Assignment operator ===\n";
    try {
        Span a(3);
        a.addNumber(100);
        a.addNumber(200);
        a.addNumber(300);

        Span b;
        b = a;

        std::cout << "Assigned shortest: " << b.shortestSpan() << std::endl;
        std::cout << "Assigned longest : " << b.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== 10000 numbers test ===\n";
    try {
        Span big(10000);
        std::vector<int> nums;
        nums.reserve(10000);

        for (int i = 0; i < 10000; ++i)
            nums.push_back(i); // deterministic values: 0..9999

        big.addMultiNums(nums.begin(), nums.end());

        std::cout << "Big shortest: " << big.shortestSpan() << std::endl; // 1
        std::cout << "Big longest : " << big.longestSpan() << std::endl;  // 9999
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}