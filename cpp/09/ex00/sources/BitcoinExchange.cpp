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
void BitcoinExchange::exchangeBitcoin(const char *filename) const
{
    std::ifstream ifs;

    ifs.open(filename);
    if (ifs.is_open() == false)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;

    while (std::getline(ifs, line))
    {
        //Evaluate if theres a syntax error;
        isInputTextLineValid(line);
        //if not, do math, and print said math;
    }
}

bool BitcoinExchange::isInputTextLineValid(const std::string& line) const 
{
    int i;

    if (line.length() < strlen("XXXX-XX-XX | X"))
    {
            std::cerr << "5Error: bad input => " << line << std::endl;
            return false;
    }
    //Poor man Regex
    if (!isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) 
        || line[4] != '-' || !isdigit(line[5]) || !isdigit(line[6]) || line[7] != '-'
        || !isdigit(line[8]) || !isdigit(line[9]) || line[10] != ' ' || line[11] != '|'
        || line[12] != ' ' || (!isdigit(line[13]) && line[13] != '-'))
    {
        std::cerr << "4Error: bad input => " << line << std::endl;
        return false;
    }

    std::string last_int_str;
    char * bad_int_check = NULL;

    last_int_str = line.substr(strlen("XXXX-XX-XX | "));
    double int_value = strtod(last_int_str.c_str(), &bad_int_check);
    if (*bad_int_check != '\0')
    {
        std::cerr << "1Error: bad input => " << line << std::endl;
        return false;
    }
    // std::cerr << last_int_str << " VS " << int_value << std::endl;
    if (errno == ERANGE || int_value > 1000)
    {
        std::cerr << "2Error: too large a number." << std::endl;
        return false;
    }
    if (int_value < 0)
    {
        std::cerr << "3Error: not a positive number." << std::endl;
        return false;
    }
    std::cout << line << database[line.substr(0, strlen("XXXX-XX-XX"))] << std::endl;
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
    // for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); ++it) 
    // {
    //     std::cout << it->first << " => " << it->second << std::endl;
    // }
    //END DEBUG
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