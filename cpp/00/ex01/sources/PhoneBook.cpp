/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 03:28:20 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/17 16:57:51 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

std::string formatString(const std::string &str);
static std::string intToString(int num);
static int stringToInt(const std::string &str);
static bool is_given_index_valid(std::string index, int max_contacts);
static void printInfoHeaders();
static void update_cur_index(int &index);

void PhoneBook::exitPhonebook(bool &keep_running)
{
    PRINT("Exiting phonebook. Goodbye.");
    keep_running = false;
}

void PhoneBook::add()
{
    Contact new_contact;

    if (_cur_num_of_contacts < 8)
        _cur_num_of_contacts += 1;
    new_contact.getNewContactInfo();
    _list_of_contacts[_cur_index] = new_contact;
    update_cur_index(_cur_index);
}

void PhoneBook::search()
{
    std::string contact_index;

    printInfoHeaders();
    for (int i = 0; i < _cur_num_of_contacts; i++)
    {
        PRINTN("|");
        FORMATPRINT(intToString(i));
        _list_of_contacts[i].printPreviewInfo();
    }

    PRINT("Type of the index of the contact");
    std::getline(std::cin, contact_index);
    if (!std::cin)
        return;
    if (is_given_index_valid(contact_index, _cur_num_of_contacts) == false)
        PRINT("Error, please try again later with a valid index");
    else
    {
        _list_of_contacts[stringToInt(contact_index)].printContactInfo();
    }
    return;
}
static bool is_given_index_valid(std::string index, int max_contacts)
{

    int index_int;

    index_int = stringToInt(index);
    return (index.length() == 1 && index_int != -1 && index_int < max_contacts && index_int >= 0);
}

static void printInfoHeaders()
{
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

std::string formatString(const std::string &str)
{
    if (str.length() > 10)
    {
        return str.substr(0, 10 - 1) + '.';
    }
    else
    {
        return str;
    }
}

static std::string intToString(int num)
{
    std::stringstream ss;
    ss << num;
    return (ss.str());
}

static int stringToInt(const std::string &str)
{
    std::istringstream iss(str);
    int number;

    if (!(iss >> number))
    {
        return (-1);
    }
    return (number);
}

static void update_cur_index(int &index)
{
    if (index == 7)
        index = 0;
    else
        index++;
}

PhoneBook::PhoneBook() : _cur_num_of_contacts(0),
                         _cur_index(0) {}

PhoneBook::~PhoneBook() {}
