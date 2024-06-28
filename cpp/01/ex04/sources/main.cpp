/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:46:12 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/28 03:14:28 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        PRINT("Invalid arguments");
        return (1);
    }
    Replace MySed;
    
    MySed.find_and_replace(argv[1], argv[2], argv[3]);
    return 0;
}


