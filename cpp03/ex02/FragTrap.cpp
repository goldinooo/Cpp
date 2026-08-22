#include "FragTrap.hpp"
#include <iostream>

fragTrap::fragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called!" << std::endl;
	this->name = "FragTrap";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

fragTrap::fragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called for " << name << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

fragTrap::fragTrap(const fragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << other.name << std::endl;
}

fragTrap& fragTrap::operator=(const fragTrap& other) {
	std::cout << "FragTrap copy assignment operator called for " << other.name << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other); // copy base-class members
	}
	return *this;
}

fragTrap::~fragTrap() {
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

void fragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}