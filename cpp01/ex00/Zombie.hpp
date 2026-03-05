#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;	

	public:
		Zombie(std::string name)
		{
			this->name = name;
		}	
	void announce()
	{
		std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
	}
};

#endif