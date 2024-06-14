/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:28:20 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/14 16:47:10 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

static  std::string formatString(const std::string& str);
static  std::string intToString(int num);
static  int         stringToInt(const std::string& str);
static  void        printContactInfo(Contact contact);
static  bool        is_given_index_valid(std::string index, int max_contacts);
static  void        printPreviewInfo(Contact contact);
static  void        printInfoHeaders();

void  PhoneBook::exitPhonebook(bool& keep_running) {
    PRINT("Exiting phonebook. Goodbye.");
    keep_running = false;   
}

void    PhoneBook::add(Contact contact_list[8], int index) {
    if (cur_num_of_contacts < 8)
        cur_num_of_contacts += 1;
        
    PRINT("Adding");
    contact_list[index].index = intToString(index);
    PRINT("Enter the first name");
    getline(std::cin, contact_list[index].first_name);
    PRINT("Enter the last name");
    getline(std::cin, contact_list[index].last_name);
    PRINT("Enter the nickname");
    getline(std::cin, contact_list[index].nickname);
    PRINT("Enter the phone number");
    getline(std::cin, contact_list[index].phone_number);
    PRINT("Enter the darkest secret, pretty please");
    getline(std::cin, contact_list[index].darkest_secret);
    PRINT("Enter the age");
    getline(std::cin, contact_list[index].age);
}

void    PhoneBook::search(Contact contact_list[8]) {
    std::string contact_index;
    
    printInfoHeaders();
    for(int i = 0; i < cur_num_of_contacts; i++) 
    {
        printPreviewInfo(contact_list[i]);
    }
    
    PRINT("Type of the index of the contact");
    std::cin >> contact_index;  
    if (!std::cin)
        return ;
    if (is_given_index_valid(contact_index, cur_num_of_contacts) == false)
        PRINT("Error, please try again with a valid index");
    else {
        printContactInfo(contact_list[stringToInt(contact_index)]);
    }
    return ;
}
static  bool    is_given_index_valid(std::string index, int max_contacts) {
    
    int index_int;
    
    index_int = stringToInt(index);
    return (index.length() == 1 && index_int != -1 && index_int < max_contacts && index_int >= 0);

}

static  void    printInfoHeaders() {
    PRINTN("|");
    FORMATPRINT(formatString("INDEX"));
    PRINTN("|");
    FORMATPRINT(formatString("FIRST NAME"));
    PRINTN("|");
    FORMATPRINT(formatString("LAST NAME"));
    PRINTN("|");
    FORMATPRINT(formatString("NICKNAME"));
    PRINTN("|");
    std::cout << std::endl;
}

static  void    printPreviewInfo(Contact contact) {
    PRINTN("|");
    FORMATPRINT(formatString(contact.index));
    PRINTN("|");
    FORMATPRINT(formatString(contact.first_name));
    PRINTN("|");
    FORMATPRINT(formatString(contact.last_name));
    PRINTN("|");
    FORMATPRINT(formatString(contact.nickname));
    PRINTN("|");
    std::cout << std::endl;
}

static  void    printContactInfo(Contact contact) {
    PRINTN("First name : ");
    PRINT(contact.first_name);
    PRINTN("Last name : ");
    PRINT(contact.last_name);
    PRINTN("Nickname : ");
    PRINT(contact.nickname);
    PRINTN("Darkest secret (do not share) : ");
    PRINT(contact.darkest_secret);
    PRINTN("Age : ");
    PRINT(contact.age);
}


static std::string formatString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 10 - 1) + '.';
    } 
    else {return str;}
}

static std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return (ss.str());
}

static int stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int number;
    
    if (!(iss >> number)) {
        return (-1);
    }
    return (number);
}



