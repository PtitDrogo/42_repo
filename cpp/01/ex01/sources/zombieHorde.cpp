/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:08:25 by tfreydie          #+#    #+#             */
/*   Updated: 2024/07/09 12:52:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieHorde;
    
    zombieHorde = (new Zombie[N]);
    for (int i = 0; i < N; ++i) 
    {
        zombieHorde[i].set_name(name);
        zombieHorde[i].announce();
    }
    return (zombieHorde);
}