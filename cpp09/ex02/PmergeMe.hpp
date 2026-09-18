#pragma once

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq; 
        int _odd;
        bool _hasOdd;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        long getTime();

        std::vector<size_t> generateJacobsthalSequence(size_t n);
        std::vector<size_t> getInsertionOrder(size_t n);

        void parseInput(char **av);

        std::vector<int> sortVector();
        std::deque<int> sortDeque();

        void makePairVector(std::vector<std::pair<int, int> > &pairs);
        void makePairDeque(std::deque<std::pair<int, int> > &pairs);

        static bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b); // static because it doesnt depend on *this* 

        void sortPairsVector(std::vector<std::pair<int, int> > &pairs);
        void sortPairsDeque(std::deque<std::pair<int, int> > &pairs);
        void insertVector(std::vector<int>& mainChain, int value, size_t limit);
        void insertDeque(std::deque<int>& mainChain, int value, size_t limit);
        void insertPendVector(std::vector<int>& mainChain, std::vector<std::pair<int, int> > &pairs);
        void insertPendDeque(std::deque<int>& mainChain, std::deque<std::pair<int, int> > &pairs);
        size_t findPositionVector(const std::vector<int>& mainChain, int value);
        size_t findPositionDeque(const std::deque<int>& mainChain, int value);

};