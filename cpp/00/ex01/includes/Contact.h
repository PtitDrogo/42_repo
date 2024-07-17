/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:08:30 by tfreydie          #+#    #+#             */
/*   Updated: 2024/07/16 22:01:36 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_H
# define CONTACT_H

#include "PhoneBook.h"
class Contact
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
    std::string _age;

public:
    void getNewContactInfo();
    void printPreviewInfo();
    void printContactInfo();
    Contact();
    ~Contact();
};
#endif
