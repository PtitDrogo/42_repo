/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:08:25 by tfreydie          #+#    #+#             */
/*   Updated: 2024/07/11 01:44:02 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Zombie* zombieHorde( int N, std::string name )
{
    // Zombie *zombieHorde;
    
    // zombieHorde = (new Zombie[N]);
    Zombie* zombieHorde = new Zombie[N] ;
    zombieHorde[0].announce();
    zombieHorde[1].announce();
    for (int i = 0; i < N; ++i) 
    {
        zombieHorde[i].set_name(name);
        zombieHorde[i].announce();
    }
    return (zombieHorde);
}