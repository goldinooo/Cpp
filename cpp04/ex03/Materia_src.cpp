
#include "Materia_src.hpp"

Materia_src::Materia_src() {
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Materia_src::Materia_src(const Materia_src& other) {
	for (int i = 0; i < 4; ++i) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Materia_src& Materia_src::operator=(const Materia_src& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (inventory[i])
				delete inventory[i];
			inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

Materia_src::~Materia_src() {
	for (int i = 0; i < 4; ++i)
		delete inventory[i];
}

void Materia_src::learnMateria(AMateria* m) {
	if (!m) 
		return;
	for (int i = 0; i < 4; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
	// inventory full
}

AMateria* Materia_src::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL;
}