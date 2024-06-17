/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:43:05 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/17 16:26:42 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "main.h"
#include "Contact.h"

//----------------------CLASSES----------------------//

class PhoneBook
{
private:
    int             _cur_num_of_contacts;
    int             _cur_index;
    Contact         _list_of_contacts[8];

public:
    void exitPhonebook(bool& keep_running);
    void add();
    void search();
    PhoneBook();
    ~PhoneBook();
};

#endif