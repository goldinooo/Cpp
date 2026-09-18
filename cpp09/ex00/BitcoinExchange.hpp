#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <exception>
#include <algorithm>


class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
        void parseDataBase();
        bool isValidDate(const std::string& date);
        double isValidPrice(const std::string& price);
        void multiplyPrice(const std::string& date, double price);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        std::map<std::string, double>& getData() const;
        void processInputFile(const char* filename);

        class invalidDateException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class invalidPriceException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class tooLargeNumberException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class invalidFileException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class invalidDataBaseException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};