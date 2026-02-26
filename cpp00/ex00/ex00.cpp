#include <iostream>
#include <cctype>
#include <string>


void  print_args(std::string args)
{
	for(size_t i = 0; i < args.length(); i++)
	{
		if(std::isalpha(args.at(i)))
			args.at(i) = (char)std::toupper(args.at(i));
	}
	std::cout << args << std::endl;
}

int main(int ac, char **av)
{
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string args;
		for(int i = 1; i < ac; i++)
			args += av[i];
		print_args(args);
	}
	return 0;
}