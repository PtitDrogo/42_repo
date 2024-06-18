/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:54:24 by tfreydie          #+#    #+#             */
/*   Updated: 2024/06/18 18:19:47 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include "main.h"

class Zombie
{
private:
    std::string name;

public:
    void announce(void);
    Zombie();
    Zombie(std::string name);
    ~Zombie();
};

#endif
