#include <iostream>
#include "ClapTrap.hpp"

int main() {

	std::cout << "------ case 1 ------" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	return 0;
}