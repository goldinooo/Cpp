#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _odd(0), _hasOdd(false) {}
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq), _odd(other._odd), _hasOdd(other._hasOdd) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        _odd = other._odd;
        _hasOdd = other._hasOdd;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

long PmergeMe::getTime() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000000L + time.tv_usec;
}

void PmergeMe::parseInput(char **av) {
    int i = 1;
    while (av[i]) {
        char *endptr;
        long num = std::strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || num <= 0 || num > std::numeric_limits<int>::max()) {
            throw std::runtime_error("Invalid input");
        }
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
        i++;
    }
}

void PmergeMe::makePairVector(std::vector<std::pair<int, int> >& pairs)
{
    size_t i = 0;
    _hasOdd = false;

    while (i + 1 < _vec.size())
    {
        if (_vec[i] < _vec[i + 1])
            pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
        else
            pairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));

        i += 2;
    }

    if (i < _vec.size())
    {
        _odd = _vec[i];
        _hasOdd = true;
    }
}

void PmergeMe::makePairDeque(std::deque<std::pair<int, int> >& pairs)
{
    size_t i = 0;
    _hasOdd = false;
    while (i + 1 < _deq.size())
    {
        if (_deq[i] < _deq[i + 1])
            pairs.push_back(std::make_pair(_deq[i], _deq[i + 1]));
        else
            pairs.push_back(std::make_pair(_deq[i + 1], _deq[i]));

        i += 2;
    }
    if (i < _deq.size())
    {
        _odd = _deq[i];
        _hasOdd = true;
    }
}


bool PmergeMe::comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.second < b.second;
}

void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs) {
    std::sort(pairs.begin(), pairs.end(), PmergeMe::comparePairs);
}

void PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> > &pairs) {
    std::sort(pairs.begin(), pairs.end(), PmergeMe::comparePairs);
}

void PmergeMe::insertVector(std::vector<int>& mainChain, int value, size_t limit) {
    size_t left = 0;
    size_t right = limit;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    mainChain.insert(mainChain.begin() + left, value);
}

void PmergeMe::insertDeque(std::deque<int>& mainChain, int value, size_t limit) {
    size_t left = 0;
    size_t right = limit;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    mainChain.insert(mainChain.begin() + left, value);
}

void PmergeMe::insertPendVector(std::vector<int>& mainChain, std::vector<std::pair<int, int> > &pairs) {
    std::vector<size_t> insertionOrder = getInsertionOrder(pairs.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        size_t index = insertionOrder[i] - 1; // Convert to 0-based index
        int smallValue = pairs[index].first;
        int largeValue = pairs[index].second;
        size_t pos = findPositionVector(mainChain, largeValue);
        insertVector(mainChain, smallValue, pos + 1);
    }
}
void PmergeMe::insertPendDeque(std::deque<int>& mainChain, std::deque<std::pair<int, int> > &pairs) {
    std::vector<size_t> insertionOrder = getInsertionOrder(pairs.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        size_t index = insertionOrder[i] - 1; // Convert to 0-based index
        int smallValue = pairs[index].first;
        int largeValue = pairs[index].second;
        size_t pos = findPositionDeque(mainChain, largeValue);
        insertDeque(mainChain, smallValue, pos + 1);
    }
}

size_t PmergeMe::findPositionVector(const std::vector<int>& mainChain, int value) {
    for (size_t i = 0; i < mainChain.size(); ++i) {
        if (mainChain[i] == value) {
            return i;
        }
    }
    return mainChain.size();
}

size_t PmergeMe::findPositionDeque(const std::deque<int>& mainChain, int value) {
    for (size_t i = 0; i < mainChain.size(); ++i) {
        if (mainChain[i] == value) {
            return i;
        }
    }
    return mainChain.size();
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    
    jacobsthal.push_back(0); // J(0)
    jacobsthal.push_back(1); // J(1)
    while(jacobsthal.back() < n) {
        size_t  i = jacobsthal.size();
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<size_t> PmergeMe::getInsertionOrder(size_t n) {
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(n); //Jacobsthal gives us boundary numbers, and we fill the spaces between those boundaries backwards to create the insertion order.
    std::vector<size_t> insertionOrder;
    
    if(n  == 0)
        return insertionOrder;
    insertionOrder.push_back(1); // J(1)
    size_t prev = 1;
    size_t i = 3;
    while (i < jacobsthal.size())
    {
        size_t current = jacobsthal[i];
        if(current > n)
            current = n;
        size_t j = current;
        while (j > prev)
        {
            insertionOrder.push_back(j);
            j--;
        }
        prev = current;
        i++;
    }
    return insertionOrder;
}


std::vector<int> PmergeMe::sortVector()
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> mainChain;

    makePairVector(pairs);
    sortPairsVector(pairs);

    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);

    insertPendVector(mainChain, pairs);
    if(_hasOdd)
        insertVector(mainChain, _odd, mainChain.size());
    return mainChain;
}

std::deque<int> PmergeMe::sortDeque()
{
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> mainChain;

    makePairDeque(pairs);
    sortPairsDeque(pairs);

    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);

    insertPendDeque(mainChain, pairs);
    if(_hasOdd)
        insertDeque(mainChain, _odd, mainChain.size());
    return mainChain;
}