#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>



class ClapTrap {
	private:
	
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
		int alo;

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

#endif // CLAPTRAP_HPP