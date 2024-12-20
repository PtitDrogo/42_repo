#include "BitcoinExchange.h"

static bool isValidDate(const std::string &date);

BitcoinExchange::BitcoinExchange()
{
    fillMap();
}
BitcoinExchange::BitcoinExchange(BitcoinExchange &other) : _database(other._database)
{
}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _database = other._database;
    }
    return (*this);
}

void BitcoinExchange::fillMap()
{
    std::ifstream ifs;
    ifs.open("data.csv");
    if (ifs.is_open() == false)
        throw std::runtime_error("Error: could not open database.");

    std::string line;

    std::getline(ifs, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Error: WrongFormat in csv header");

    while (std::getline(ifs, line))
    {
        sanitizeLine(line);
    }
}

void BitcoinExchange::sanitizeLine(const std::string &line)
{
    std::string::size_type pos;
    std::string pair[2];

    pos = line.find(',');
    if (pos == std::string::npos)
        return;

    pair[0] = line.substr(0, pos);
    pair[1] = line.substr(pos + 1);
    if (pair[1].empty())
        return;
    char *bad_value_check;
    double bitcoin_value = strtod(pair[1].c_str(), &bad_value_check);

    if (errno == ERANGE)
    {
        errno = 0;
        return;
    }
    if (bitcoin_value < 0)
        return;
    if (isValidDate(pair[0]) == false)
        return;
    if (*bad_value_check != '\0')
        return;
    _database.insert(std::make_pair(pair[0], bitcoin_value));
}

// Methods
void BitcoinExchange::exchangeBitcoin(const char *filename) const
{
    std::ifstream ifs;

    ifs.open(filename);
    if (ifs.is_open() == false)
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(ifs, line);
    if (line != "date | value")
        throw std::runtime_error("Error: Wrong data format.");
    while (std::getline(ifs, line))
    {
        parseLine(line);
    }
    ifs.close();
}

void BitcoinExchange::parseLine(const std::string &line) const
{
    size_t format_line_len = strlen("XXXX-XX-XX | X");
    if (line.length() < format_line_len)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    bool is_valid_date = isValidDate(line.substr(0, strlen("XXXX-XX-XX")));
    bool is_valid_post_date_format = (line[10] == ' ' && line[11] == '|' && line[12] == ' ' && (!isdigit(line[13]) || line[13] != '-' || line[13] != '+'));
    if (is_valid_date == false || is_valid_post_date_format == false)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    double number_bitcoins;
    if (isValidNumberBitcoinsValue(line, number_bitcoins) == false)
        return;
    getDateAndCompare(line, number_bitcoins);
}

bool BitcoinExchange::isValidNumberBitcoinsValue(const std::string &line, double &number_bitcoins) const
{
    std::string last_int_str;
    char *bad_int_check;

    last_int_str = line.substr(strlen("XXXX-XX-XX | "));
    number_bitcoins = strtod(last_int_str.c_str(), &bad_int_check);
    if (*bad_int_check != '\0')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return (false);
    }
    if (errno == ERANGE || number_bitcoins > 1000)
    {
        errno = 0;
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }
    if (number_bitcoins < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    return (true);
}

void BitcoinExchange::getDateAndCompare(const std::string &line, double number_bitcoins) const
{
    std::string date = line.substr(0, strlen("XXXX-XX-XX"));
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

    if (it->first == date)
    {
        std::cout << date << " => " << number_bitcoins << " = " << number_bitcoins * it->second << std::endl;
    }
    else
    {
        if (it == _database.begin())
            std::cerr << "Error: date too early" << std::endl;
        else
        {
            it--;
            std::cout << date << " => " << number_bitcoins << " = " << number_bitcoins * it->second << std::endl;
        }
    }
    return;
}

static bool isValidDate(const std::string &date)
{

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}
