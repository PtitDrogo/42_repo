/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:03:55 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/18 18:34:27 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    Zombie::announce(void)
{
    PRINTN(name);
    PRINT(": BraiiiiiiinnnzzzZ...");
}
Zombie::Zombie()
{
    name = "DEFAULT NAME";
}


Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    PRINTN("I am deleting the zombie named : ");
    PRINT(name);
}