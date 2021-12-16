/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:48:06 by amahi             #+#    #+#             */
/*   Updated: 2021/12/08 07:05:50 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *arr, ...);
int ft_putchar(const char sym);
int ft_putstr(char *str);
int ft_putnbr(int n, int counter);
int ft_putnbr_uns(unsigned int n, int counter);
int ft_destosix(int n, int counter);

#endif