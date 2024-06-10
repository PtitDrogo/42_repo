/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:55:24 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/06/10 13:23:37 by tfreydie         ###   ########.fr       */
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
        PRINT("Hello, Phonebook here, type your command");
        getline(std::cin, input);
        if (input == "EXIT") {
            phonebook.exit_phonebook(is_running);
        }
    }
    
    return 0;
}

