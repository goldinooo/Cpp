#pragma once
#include <cstddef>

template<typename I, typename F_call>
void    iter(I *arr, const size_t length, F_call function)
{
    for(size_t i = 0; i < length; i++)
        function(arr[i]);
}