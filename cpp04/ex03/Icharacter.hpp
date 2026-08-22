 #ifndef ICHARACTER_HPP
 #define ICHARACTER_HPP

 #include <string>

 class AMateria;

 class ICharacter {
	 public:
		 virtual ~ICharacter() {}
		 virtual std::string const & getName() const = 0; // Pure virtual
		 virtual void equip(AMateria* m) = 0; // Pure virtual function to equip
		 virtual void unequip(int idx) = 0; // Pure virtual function to unequip a materia at index
		 virtual void use(int idx, ICharacter& target) = 0; // Pure virtual function to use a materia at index on a target
 };

 #endif // ICHARACTER_HPP