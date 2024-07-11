/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:06:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/07/11 15:29:15 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void Contact::getNewContactInfo()
{
    if (std::cin)
        PRINT("Enter the first name");
    std::getline(std::cin, _first_name);
    if (std::cin)
     PRINT("Enter the last name");
    std::getline(std::cin, _last_name);
    if (std::cin)
        PRINT("Enter the nickname");
    std::getline(std::cin, _nickname);
    if (std::cin)
        PRINT("Enter the phone number");
    std::getline(std::cin, _phone_number);
    if (std::cin)
        PRINT("Enter the darkest secret, pretty please");
    std::getline(std::cin, _darkest_secret);
    if (std::cin)
        PRINT("Enter the age");
    std::getline(std::cin, _age);
}

void Contact::printPreviewInfo()
{
    PRINTN("|");
    FORMATPRINT(formatString(_first_name));
    PRINTN("|");
    FORMATPRINT(formatString(_last_name));
    PRINTN("|");
    FORMATPRINT(formatString(_nickname));
    PRINTN("|");
    std::cout << std::endl;
}
void Contact::printContactInfo()
{
    PRINTN("First name : ");
    PRINT(_first_name);
    PRINTN("Last name : ");
    PRINT(_last_name);
    PRINTN("Nickname : ");
    PRINT(_nickname);
    PRINTN("Darkest secret (do not share) : ");
    PRINT(_darkest_secret);
    PRINTN("Age : ");
    PRINT(_age);
}

Contact::Contact() 
{
    PRINT("creating contact");
}

Contact::~Contact() 
{
    PRINT("destroying contact");
}