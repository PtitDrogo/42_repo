/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:43:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/10 13:23:10 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define PRINT(x) std::cout << x << std::endl


#include <iostream>
#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number; 
    std::string darkest_secret;
    // int age;
    

public:

};

class PhoneBook
{
private:
    Contact list_of_contacts[8];
    
    
public:
    void exit_phonebook(bool& keep_running);
    void add();
    void search();
};



#endif