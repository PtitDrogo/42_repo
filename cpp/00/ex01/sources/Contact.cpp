/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:06:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/17 16:48:30 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void Contact::getNewContactInfo()
{
    PRINT("Enter the first name");
    std::getline(std::cin, _first_name);
    PRINT("Enter the last name");
    std::getline(std::cin, _last_name);
    PRINT("Enter the nickname");
    std::getline(std::cin, _nickname);
    PRINT("Enter the phone number");
    std::getline(std::cin, _phone_number);
    PRINT("Enter the darkest secret, pretty please");
    std::getline(std::cin, _darkest_secret);
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

Contact::Contact() {}

Contact::~Contact() {}