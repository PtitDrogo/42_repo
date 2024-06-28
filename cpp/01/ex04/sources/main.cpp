/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:46:12 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/28 02:08:21 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        PRINT("Invalid arguments");
        return (1);
    }
    Replace MySed;
    
    MySed.find_and_replace(argv[1], argv[2], argv[3]);
    // std::string s1 = argv[2];
    // std::string s2 = argv[3];
    // std::string filename;
    // std::string outfile_name;
    
    // filename = argv[1];
    // outfile_name = filename + ".replace";
    // PRINT(outfile_name);

    // std::ifstream infile(argv[1]);
    // std::ofstream outFile(outfile_name.c_str(), std::ios::trunc);
    // std::string cur_line;

    // while (std::getline(infile, cur_line))
    // {
    //     size_t pos = cur_line.find(s1);
    //     std::size_t start = 0;
        
    //     if (pos != std::string::npos) 
    //     {
    //         while (pos != std::string::npos)
    //         {
    //             std::cout << "start is " << start << " pos is " << pos << std::endl;
    //             std::string substring = cur_line.substr(start, pos - start);
    //             std::cout << substring << s2;
    //             outFile << substring << s2;
    //             start = pos + s1.size();
    //             pos = cur_line.find(s1, start);
    //         }
            
    //         std::cout << cur_line.substr(start, pos) << std::endl;
    //         outFile << cur_line.substr(start, pos) << std::endl;
    //     }
    //     else
    //     {
    //         outFile << cur_line << std::endl;
    //         PRINT(cur_line);
    //     }
    // }
    return 0;
}


