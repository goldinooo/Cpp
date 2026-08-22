#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class fragTrap : public ClapTrap {
public:
    fragTrap();
    fragTrap(const std::string& name);
    fragTrap(const fragTrap& other);
    fragTrap& operator=(const fragTrap& other);
    ~fragTrap();

    void highFivesGuys(void);
};

#endif // SCAVTRAP_HPP
