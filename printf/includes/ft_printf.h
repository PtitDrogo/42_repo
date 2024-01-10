/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:41:47 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/20 14:33:12 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

void	ft_putncount_str(char *str, int *size);
void	ft_putncount_char(char c, int *size);
void	ft_putnbr(int nbr, int *size);
void	ft_putunsign(unsigned int nbr, char *base, int *size);
void	ft_print_ptr(unsigned long long ptr, int *size);
int		ft_printf(const char *text, ...);

#endif