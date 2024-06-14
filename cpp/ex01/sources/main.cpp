/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:55:24 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/06/14 16:59:45 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
static  void update_cur_index(int &index);

int main(void)
{
    PhoneBook   phonebook;
    bool        is_running = true;
    std::string input;
    int         index = 0;
    
    
    while (is_running)
    {
        PRINT("Hello, Phonebook here, type your command");
        getline(std::cin, input);
        if (input == "EXIT") {
            phonebook.exitPhonebook(is_running);
        }
        if (input == "ADD") {
            phonebook.add(phonebook.list_of_contacts, index);
            update_cur_index(index);
        }
        if (input == "SEARCH") {
            phonebook.search(phonebook.list_of_contacts);
        }
        if (!std::cin) {
            phonebook.exitPhonebook(is_running);
        }
    }
    return 0;
}

static  void update_cur_index(int &index) {
    if (index == 7)
        index = 0;
    else
        index++;
}

