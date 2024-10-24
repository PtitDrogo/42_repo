#include "BitcoinExchange.h"


BitcoinExchange::BitcoinExchange() 
{
    fillMap();
}
BitcoinExchange::BitcoinExchange(BitcoinExchange& other) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {

    }
    return (*this);
}

//Methods
bool BitcoinExchange::isInputFileValid(const char *filename)
{
    std::ifstream ifs;

    ifs.open(filename);

    if (ifs.is_open() == false)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    std::string pair[2];
    std::string::size_type pos;

    while (std::getline(ifs, line))
    {
        pos = line.find(',');
        pair[0] = line.substr(0, pos);
        pair[1] = line.substr(pos + 1);
        //add this shit to my map;
        database.insert(std::make_pair(pair[0], strtod(pair[1].c_str(), NULL)));
    }


    ifs.close();
    return true;
}

void BitcoinExchange::fillMap()
{
    std::ifstream ifs;

    ifs.open("data.csv");

    if (ifs.is_open() == false)
    {
        std::cerr << "Error: could not open database." << std::endl;
        return ;
    }

    std::string line;
    std::string pair[2];
    std::string::size_type pos;

    while (std::getline(ifs, line))
    {
        pos = line.find(',');
        pair[0] = line.substr(0, pos);
        pair[1] = line.substr(pos + 1);
        database.insert(std::make_pair(pair[0], strtod(pair[1].c_str(), NULL)));
    }

    //PRINTING MY MAP TO SEE IF IT WORKS
    for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); ++it) 
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    return true;

}





std::ostream    &operator<<(std::ostream &out, BitcoinExchange const &fixed)
{
    out << "btc class whoah !";
    return (out);
}


/*
    First I need to do Parsing on the txt file to validate its format.
    after that I need to look up in my csv file the corresponding date.
    if it exist, do the math and print the result.
    if it doesnt exist, I take the lower date (ence why we need a map and not an unordered one)
    I print this shit and I am good

    A valid date will always be in the following format: Year-Month-Day.

    > head input.txt
    date | value
    2011-01-03 | 3
    2011-01-03 | 2
    2011-01-03 | 1
    2011-01-03 | 1.2
    2011-01-09 | 1
    2012-01-11 | -1
    2001-42-42
    2012-01-11 | 1
    2012-01-11 | 2147483648

*/