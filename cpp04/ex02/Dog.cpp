#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog 🐶 default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog 🐶 copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog 🐶 copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog 🐶 destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Wooooof Wooooof! 🐶" << std::endl;
}