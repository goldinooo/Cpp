#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& oth) {
    (void)oth;
}
Serializer& Serializer::operator=(const Serializer& oth)
{
    (void)oth;
    return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t bit_ptr)
{
    return reinterpret_cast<Data *>(bit_ptr);
}
