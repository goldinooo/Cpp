#ifndef MATERIA_SRC_HPP
#define MATERIA_SRC_HPP

#include "Imateria_src.hpp"

class Materia_src  : public Imateria_src {
		
	private:
		AMateria* inventory[4];
	public:
		Materia_src();
		Materia_src(const Materia_src& other);
		Materia_src& operator=(const Materia_src& other);
		~Materia_src();
		
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif // MATERIA_SRC_HPP