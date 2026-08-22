#ifndef ICE_CURE_HPP
#define ICE_CURE_HPP

#include "AMateria.hpp"


class Ice : public AMateria {
	
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		AMateria* clone() const; // Override 
		void use(ICharacter& target); // Override 
		
};

class Cure : public AMateria {
	
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target); 
		
};


#endif // Cure_HPP