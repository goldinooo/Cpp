#pragma once
#include <algorithm>

class NoOccurrenceFound : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "no occurrence found";
    }
};

template<typename T>
typename T::iterator easyfind(T& cont, int num)
{
    typename T::iterator iter = std::find(cont.begin(), cont.end(), num);
    if (iter == cont.end())
        throw NoOccurrenceFound();
    return iter;
}