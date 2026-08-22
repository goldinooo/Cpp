#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; // should not create a leak
	delete i;

	std::cout << "-----------------------------" << std::endl;

	Animal* animals[8];
	for(int idx = 0; idx < 8; idx++) {
		if (idx < 4)
			animals[idx] = new Dog();
		else
			animals[idx] = new Cat();
	}
	std::cout << "-----------------------------" << std::endl;
	for(int idx = 0; idx < 8; idx++) {
		animals[idx]->makeSound();
	}
	std::cout << "-----------------------------" << std::endl;

	for(int idx = 0; idx < 8; idx++) {
		delete animals[idx];
	}
	std::cout << "----------- End of main --------" << std::endl;
	return 0;
}
