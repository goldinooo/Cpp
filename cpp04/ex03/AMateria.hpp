#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		AMateria(const std::string& type);
		virtual ~AMateria();
		std::string const & getType() const; // Returns materia type

		virtual AMateria* clone() const = 0; // Pure will override a new inst
		virtual void use(ICharacter& target); // NOT PURE.
};

#endif // AMATERIA_HPP