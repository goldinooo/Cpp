#pragma once

#include <iostream>
#include <string>
#include <cstdint>
# include <stdint.h>


struct Data {
    std::string name, job_title;
    int age;
};

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer& oth);
        Serializer& operator=(const Serializer& oth);
        ~Serializer();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t bit_ptr);

        //static because they operate at the class level (they don't need or use any instance data or this)
};