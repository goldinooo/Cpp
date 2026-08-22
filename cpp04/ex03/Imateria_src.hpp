#ifndef IMATERIA_SRC_HPP
#define IMATERIA_SRC_HPP

#include "AMateria.hpp"

class Imateria_src {
	

	public:
	virtual ~Imateria_src() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
		
};

#endif // IMATERIA_SRC_HPP