/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:54:38 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/18 15:46:26 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H


//----------INCLUDES----------//
#include <string>
#include <iostream>
#include <iomanip>
#include "Zombie.h"

//----------DEFINE----------//
# define PRINT(x) std::cout << x << std::endl
# define PRINTN(x) std::cout << x

//----------FUNCTIONS----------//
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif