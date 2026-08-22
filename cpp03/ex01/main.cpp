#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "--- Creating ScavTraps ---" << std::endl;
	ScavTrap s1("Serena");
	ScavTrap s2(s1); // copy ctor
	ScavTrap s3;
	s3 = s1; // copy assignment

	std::cout << "--- Actions ---" << std::endl;
	s1.attack("target_1");
	s2.takeDamage(30);
	s2.beRepaired(10);
	s3.guardGate();

	std::cout << "--- Base ClapTrap ---" << std::endl;
	ClapTrap c("Clappy");
	c.attack("a rock");
	c.takeDamage(5);
	c.beRepaired(2);

	std::cout << "--- End of main ---" << std::endl;
	return 0;
}