#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog() {
	this->type = "wrong dog";
	std::cout << "WrongDog 🐶 default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
	std::cout << "WrongDog 🐶 copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongDog 🐶 copy assignment operator called" << std::endl;
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog 🐶 destructor called" << std::endl;
}