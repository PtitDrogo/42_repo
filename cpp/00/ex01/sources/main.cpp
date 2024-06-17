/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:55:24 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/06/17 16:53:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int main(void)
{
    PhoneBook   phonebook;
    bool        is_running = true;
    std::string input;
    
    
    while (is_running)
    {
        PRINTN("Phonebook, type your command : ");
        std::getline(std::cin, input);
        if (input == "EXIT") {
            phonebook.exitPhonebook(is_running);
        }
        if (input == "ADD") {
            phonebook.add();
        }
        if (input == "SEARCH") {
            phonebook.search();
        }
        if (!std::cin) {
            std::cout << std::endl;
            phonebook.exitPhonebook(is_running);
        }
    }
    return 0;
}

