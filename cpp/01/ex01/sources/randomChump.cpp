/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:42:34 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/18 16:00:10 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

void randomChump( std::string name )
{
    Zombie new_chump = Zombie(name);
    new_chump.announce();
    return ;
}