#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "----------- Animals ----------" << std::endl;
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << "-----------Wrong Animals ----------" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongDog();
	const WrongAnimal* i2 = new WrongCat();
	
	std::cout << j2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	
	i2->makeSound(); //will output the cat sound!
	j2->makeSound();
	meta2->makeSound();
	std::cout << "-----------------------------" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete j2;
	delete i2;
	return 0;
}
