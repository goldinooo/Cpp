#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called !" << std::endl;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called for " << other.name << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called for " << other.name << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " cannot attack due to insufficient energy or hit points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) 
{
	if (this->hitPoints > 0) {
		this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) 
{
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! Current hit points: " << hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot repair due to insufficient energy or hit points." << std::endl;
	}
}