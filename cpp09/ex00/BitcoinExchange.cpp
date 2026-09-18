#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
    parseDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    if(this != &other)
        *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
        this->_data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char* BitcoinExchange::invalidDateException::what() const throw()
{
    return "Error: bad input";
}

const char* BitcoinExchange::invalidPriceException::what() const throw()
{
    return "Error: not a positive number.";
}

const char* BitcoinExchange::tooLargeNumberException::what() const throw()
{
    return "Error: too large a number.";
}

const char* BitcoinExchange::invalidFileException::what() const throw()
{
    return "Error: could not open file.";
}

const char* BitcoinExchange::invalidDataBaseException::what() const throw()
{
    return "Error: could not open database.";
}

void BitcoinExchange::parseDataBase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw invalidDataBaseException();

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, price;

        if (std::getline(iss, date, ',') && std::getline(iss, price, ','))
        {
            std::istringstream priceStream(price);
            double value;
            if (isValidDate(date) && priceStream >> value && priceStream.eof())
                _data[date] = value;
        }
    }
    file.close();
}

void BitcoinExchange::processInputFile(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw invalidFileException();

    std::string line;
    std::getline(file, line); // Skip the header line
    if(line != "date | value")
        throw invalidFileException();
    while (std::getline(file, line))
    {
        try
        {
            std::istringstream iss(line);
            std::string date, valueText;
            if (!std::getline(iss, date, '|') || !std::getline(iss, valueText))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            if (!date.empty() && date[date.size() - 1] == ' ')
                date.erase(date.size() - 1);
            if (!isValidDate(date))
                throw invalidDateException();

            while (!valueText.empty() && valueText[0] == ' ')
                valueText.erase(0, 1);
            double value = isValidPrice(valueText);
            multiplyPrice(date, value);
        }
        catch (const invalidDateException&)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    // Check if the date is in the format YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    int month = (date[5] - '0') * 10 + date[6] - '0';
    int day = (date[8] - '0') * 10 + date[9] - '0';
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

double BitcoinExchange::isValidPrice(const std::string& price)
{
    try
    {
        std::istringstream priceStream(price);
        double value;
        char extra;
        if (!(priceStream >> value) || (priceStream >> extra))
            throw invalidPriceException();
        if (value < 0)
            throw invalidPriceException();
        if (value > 1000)
            throw tooLargeNumberException();
        return value;
    }
    catch (const std::invalid_argument& e)
    {
        throw invalidPriceException();
    }
}

void BitcoinExchange::multiplyPrice(const std::string& date, double price)
{
    std::map<std::string, double>::iterator it = _data.find(date);
    if(it != _data.end())
    {
        std::cout << date << " => " << price << " = " << price * it->second << std::endl;
    }
    else
    {
        std::map<std::string, double>::iterator lower = _data.lower_bound(date);
        if (lower == _data.begin())
        {
            std::cout << date << " => " << price << " = " << price * lower->second << std::endl;
        }
        else
        {
            --lower;
            std::cout << date << " => " << price << " = " << price * lower->second << std::endl;
        }
    }
}