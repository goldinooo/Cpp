#include "RPN.hpp"


int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    try {
        int result = rpn.calculate(av[1]);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}