/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:03:55 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/19 14:42:43 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    Zombie::announce(void)
{
    PRINTN(name);
    PRINT(": BraiiiiiiinnnzzzZ...");
}
void    Zombie::set_name(std::string name)
{
    this->name = name;
}
Zombie::Zombie()
{
    // PRINT("I am constructor without name");
    name = "NoName";
}

Zombie::Zombie(std::string name)
{
    // PRINT("I am constructor with name");
    this->name = name;
}

Zombie::~Zombie()
{
    // PRINTN("I am deleting the zombie named : ");
    // PRINT(name);
}