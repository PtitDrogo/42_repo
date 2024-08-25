#include "main.h"

void Replace::find_and_replace(char const *file_name, char const *s1, char const *s2)
{
    this->_to_find = s1;
    this->_to_replace = s2;
    this->_filename = file_name;
    this->_outfile_name = this->_filename + ".replace";
    
    std::ifstream infile(this->_filename.c_str());
    std::string cur_line;
    std::string substring;

    if (_to_find.empty())
    {
        std::cerr << "please type a not empty char to replace" << std::endl;
        return ;
    }
    if (infile.is_open())
    {
        std::ofstream outFile(this->_outfile_name.c_str(), std::ios::trunc);
        while (std::getline(infile, cur_line))
        {
            size_t pos = cur_line.find(this->_to_find);
            std::size_t start = 0;
            
            if (pos != std::string::npos) 
            {
                while (pos != std::string::npos)
                {
                    substring = cur_line.substr(start, pos - start);
                    outFile << substring << this->_to_replace;
                    start = pos + this->_to_find.size();
                    pos = cur_line.find(this->_to_find, start);
                }
                outFile << cur_line.substr(start, pos) << std::endl;
            }
            else
            {
                outFile << cur_line << std::endl;
            }
        }
    }

}

Replace::Replace()
{
}

Replace::~Replace()
{
}