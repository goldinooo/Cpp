#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat 🐱 default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat 🐱 copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Cat 🐱 copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat 🐱 destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meeeoooowwww! 🐱" << std::endl;
}