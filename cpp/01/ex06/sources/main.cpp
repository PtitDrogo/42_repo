/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:46:12 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/28 04:52:51 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please enter warning Level properly" << std::endl;
        return (0);
    }
    Harl Harl;
    Harl.complain(argv[1]);
    
    return 0;
}



