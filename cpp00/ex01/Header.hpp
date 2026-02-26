#ifndef HEADER_HPP
#define HEADER_HPP

#include <cstddef>
#include <string>


typedef struct {
	std::string first__name;
	std::string last__name;
	std::string nick__name;
	std::string phone__number;
	std::string darkest_secret;

} ContactData;

class Contact {
	private:
		ContactData contactinfo;

	public:
		Contact();
		~Contact();
	
};

#endif // HEADER_HPP