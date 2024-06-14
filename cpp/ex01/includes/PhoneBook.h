/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:43:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/14 16:01:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H

//----------------------INCLUDES----------------------//
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>

//----------------------DEFINES----------------------//
# define PRINT(x) std::cout << x << std::endl
# define PRINTN(x) std::cout << x
# define FORMATPRINT(x) std::cout << std::right << std::setw(10) << std::setfill(' ') <<  x.substr(0, 10)



//----------------------CLASSES----------------------//
class Contact
{
private:
    

public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number; 
    std::string darkest_secret;
    std::string age;
    std::string index; //contact knows where it is
    

Contact()
        : 
        first_name(""),
        last_name(""),
        nickname(""),
        phone_number(""),
        darkest_secret(""), 
        index("") {}
};

class PhoneBook
{
private:
    
public:
    int     cur_num_of_contacts;
    Contact list_of_contacts[8];
    PhoneBook() : cur_num_of_contacts(0) {}
    void exitPhonebook(bool& keep_running);
    void add(Contact *contact_list, int index);
    void search(Contact contact_list[8]);
};

#endif