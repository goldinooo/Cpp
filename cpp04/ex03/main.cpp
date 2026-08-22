#include <iostream>
#include "Character.hpp"
#include "Ice_cure.hpp"
#include "Materia_src.hpp"


int main() {

	std::cout << "----- Normal Tests -----" << std::endl;
	Character* me = new Character("me");
	Character* bob = new Character("bob");

	Materia_src* src = new Materia_src();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	delete src;
	delete me;
	delete bob;

	std::cout << "\n----- Deep Copy Tests -----" << std::endl;
	Character* alice = new Character("Alice");
	src = new Materia_src();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());	

	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	alice->equip(ice);
	alice->equip(cure);	

	Character* aliceCopy = new Character(*alice); // Deep copy test

	aliceCopy->use(0, *alice); // Should work like original
	aliceCopy->use(1, *alice);

	std::cout << "\n----- Additional Tests -----" << std::endl;
	// Test equip overflow
	Character* tom = new Character("Tom");
	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");
	AMateria* m3 = src->createMateria("ice");
	AMateria* m4 = src->createMateria("cure");
	AMateria* m5 = src->createMateria("ice");
	tom->equip(m1);
	tom->equip(m2);
	tom->equip(m3);
	tom->equip(m4);
	tom->equip(m5); // inventory full

	// Use all 
	for (int i = 0; i < 4; ++i)
		tom->use(i, *alice);

	tom->unequip(1);
	tom->equip(m5);

	std::cout << "After unequip/re-equip:" << std::endl;
	tom->use(1, *alice);

	AMateria* unknown = src->createMateria("fire");
	if (unknown == NULL)
		std::cout << "NULL for unknown type fire" << std::endl;

	// Test Materia_src copy
	Materia_src* srcCopy = new Materia_src(*src);
	AMateria* copyTest = srcCopy->createMateria("ice");
	if (copyTest)
		copyTest->use(*alice);


	delete srcCopy;
	delete tom;
	delete aliceCopy;
	delete alice;
	delete src;

	return 0;
}