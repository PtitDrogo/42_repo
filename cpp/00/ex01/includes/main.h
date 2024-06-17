/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:50:40 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/17 15:18:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

//----------------------INCLUDES----------------------//
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>
#include "PhoneBook.h"

//----------------------DEFINES----------------------//
# define PRINT(x) std::cout << x << std::endl
# define PRINTN(x) std::cout << x
# define FORMATPRINT(x) std::cout << std::right << std::setw(10) << std::setfill(' ') <<  x.substr(0, 10)

//----------------------FUNCTIONS----------------------//
std::string formatString(const std::string& str);

#endif