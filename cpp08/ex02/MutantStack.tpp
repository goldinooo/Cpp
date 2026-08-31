#pragma once
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& oth) : std::stack<T>(oth) {};

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& oth)
{
    if (this != &oth)
        std::stack<T>::operator=(oth);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}