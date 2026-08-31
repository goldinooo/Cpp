#pragma once

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span {
    private:
        unsigned int cap;
        std::vector<int> cont;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& oth);
        ~Span();

        Span& operator=(const Span& oth);

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        class FullContainer : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NoSpan : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        void addMultiNums(std::vector<int>::iterator begin, std::vector<int>::iterator end);   
};