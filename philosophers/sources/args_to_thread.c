/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:35:38 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/15 15:57:16 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg)
{
    sleep(1);
    int index = *(int *)arg;
    printf("%d ", index);
}


int main(int argc, char const *argv[])
{
    pthread_t   th[10];
    int i;
    
    i = 0;
    while (i < 10)
    {
        if (pthread_create(&th[i], NULL, (void *)routine, &i) != 0)
            perror("failed to create thread");
        i++;
    }
    i = 0;
    while (i < 10)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("failed to join thread");
        i++;
    }
    return 0;
    
}
