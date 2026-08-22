#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	fragTrap frag("Fraggy");

	std::cout << "\n--- ClapTrap Actions ---\n";
	clap.attack("a target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- ScavTrap Actions ---\n";
	scav.attack("a target");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();

	std::cout << "\n--- FragTrap Actions ---\n";
	frag.attack("a target");
	frag.takeDamage(15);
	frag.beRepaired(10);
	frag.highFivesGuys();
	return 0;
}