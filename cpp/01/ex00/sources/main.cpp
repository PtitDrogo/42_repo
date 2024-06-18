/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:36:11 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/18 15:48:57 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
    Zombie *zombie_gangin = newZombie("heap zombie");
    randomChump("Olivier");
    randomChump("Charle");
    randomChump("Superman");
    randomChump("Batman");
    delete zombie_gangin;
    
    
    return 0;
}
