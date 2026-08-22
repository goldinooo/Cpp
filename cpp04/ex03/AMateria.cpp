#include "AMateria.hpp"
#include <iostream>
#include "Icharacter.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(const std::string& t) : type(t) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
	if (type == "ice") {
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	} 
	else if (type == "cure") {
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	}
}
