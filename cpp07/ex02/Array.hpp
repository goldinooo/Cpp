#pragma once

#include <cstddef>
#include <exception>

#define ui unsigned int

template<typename T>
class Array {
    private:
        T*  data;
        ui    _size;
    public:
        Array();
        Array(ui n);
        Array(const Array& oth);
        Array& operator=(const Array& oth);
        ~Array();
        
        T& operator[](ui index);
        const T& operator[](ui index) const;
        ui size() const;

        class OutOfBounds : public std::exception
        {
            public:
               virtual const char* what() const throw();
        };
};

#include "Array.tpp"