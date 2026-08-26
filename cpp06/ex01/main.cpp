#include "Serializer.hpp"

int main()
{
    Data *agent = new Data;
    agent->name = "bob";
    agent->job_title = "team leader";
    agent->age = 42;

    uintptr_t bit_ptr = Serializer::serialize(agent);
    Data  *serialized = Serializer::deserialize(bit_ptr);

    std::cout << serialized->name << std::endl;
    std::cout << serialized->job_title << std::endl;
    std::cout << serialized->age << std::endl;
    
    delete agent;
}