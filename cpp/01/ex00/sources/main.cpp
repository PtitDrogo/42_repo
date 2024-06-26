/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:36:11 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/18 18:01:42 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
    //Testing heap zombies;
    Zombie *zombie_gandin = newZombie("heap zombie");
    zombie_gandin->announce();
    delete zombie_gandin;
    zombie_gandin = newZombie("heap zombie 2");
    zombie_gandin->announce();
    delete zombie_gandin;

    //testing random Chump
    randomChump("Olivier");
    randomChump("Charle");
    randomChump("Superman");
    randomChump("Batman");
    
    return 0;
}
