#include "PmergeMe.hpp"

static void printInput(char **av, int ac)
{
    int i = 1;

    while (i < ac)
    {
        std::cout << av[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

static void printVector(const std::vector<int>& v)
{
    size_t i = 0;

    while (i < v.size())
    {
        std::cout << v[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

static void printDeque(const std::deque<int>& d)
{
    size_t i = 0;

    while (i < d.size())
    {
        std::cout << d[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmerge;

        pmerge.parseInput(av);

        std::cout << "Before: ";
        if (ac <= 10)
            printInput(av, ac);
        else
            std::cout << "[too many numbers]" << std::endl;

        long startVector = pmerge.getTime();
        std::vector<int> sortedVector = pmerge.sortVector();
        long endVector = pmerge.getTime();

        long startDeque = pmerge.getTime();
        std::deque<int> sortedDeque = pmerge.sortDeque();
        long endDeque = pmerge.getTime();

        std::cout << "After vector: ";
        if (sortedVector.size() <= 10)
            printVector(sortedVector);
        else
            std::cout << "[too many numbers]" << std::endl;

        std::cout << "After deque: ";
        if (sortedDeque.size() <= 10)
            printDeque(sortedDeque);
        else
            std::cout << "[too many numbers]" << std::endl;

        std::cout << "Time to process a range of "
                  << sortedVector.size()
                  << " elements with std::vector : "
                  << endVector - startVector << " us"
                  << std::endl;

        std::cout << "Time to process a range of "
                  << sortedDeque.size()
                  << " elements with std::deque : "
                  << endDeque - startDeque << " us"
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}


//./PmergeMe $(seq 3000 -1 1)
