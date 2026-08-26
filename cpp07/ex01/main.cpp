#include "iter.hpp"
#include <iostream>

void incr(int &num)
{
    num++;
}

void rot13(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = 'a' + (str[i] - 'a' + 13) % 26;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'A' + (str[i] - 'A' + 13) % 26;
    }
}

int main()
{
    int arr_of_int[] = {0, 0, 0};

    ::iter(arr_of_int, 3, incr);

    for (int i = 0; i < 3; i++)
        std::cout << arr_of_int[i] << std::endl;


    std::string arr_of_str[] = {"abc", "xyz"};

    ::iter(arr_of_str, 2, rot13);

    for (int i = 0; i < 2; i++)
        std::cout << arr_of_str[i] << std::endl;
}