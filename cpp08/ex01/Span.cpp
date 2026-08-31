#include "Span.hpp"
#include <algorithm>

Span::Span() : cap(0) {};
Span::Span(unsigned int N) : cap(N) {};
Span::Span(const Span& oth) {
    *this = oth;
}

Span& Span::operator=(const Span& oth)
{
    if (this != &oth)
    {
        cap = oth.cap;
        cont = oth.cont;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if(cont.size() >= cap)
        throw FullContainer();
    cont.push_back(num);
}

int Span::shortestSpan()
{
    if(cont.size() <= 1)
        throw NoSpan();
    std::vector<int> stack = cont;
    std::sort(stack.begin(), stack.end());
    int short_dist = stack[1] - stack[0];
    for (size_t i = 1; i < stack.size(); i++)
    {
        int dist = stack[i] - stack[i - 1];
        if(dist < short_dist)   
            short_dist = dist;
    }
    return short_dist;
}

int Span::longestSpan()
{
    if(cont.size() <= 1)
        throw NoSpan();
    int min = *std::min_element(cont.begin(), cont.end());
    int max = *std::max_element(cont.begin(), cont.end());
    return max - min;
}

void Span::addMultiNums(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(cont.size() + std::distance(begin, end) > cap)
        throw FullContainer();
    cont.insert(cont.end(), begin, end);
}

const char* Span::FullContainer::what() const throw()
{
    return "Span is full";
}

const char* Span::NoSpan::what() const throw()
{
    return "Not enough elements to find a span";
}