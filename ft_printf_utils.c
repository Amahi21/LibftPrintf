/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:49:52 by amahi             #+#    #+#             */
/*   Updated: 2021/12/08 08:42:29 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char sym)
{
	write(1, &sym, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	return (i);
}
int ft_putnbr(int n, int counter)
{
	char			a;
	if (n == -2147483648)
	{
		counter = write(1, "-2147483648", 11);
		return (counter);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
		counter++;
	}
	a = n % 10 + '0';
	if (n < 10)
	{
		counter++;
		write(1, &a, 1);
	}
	else
	{
		counter++;
		counter = ft_putnbr(n / 10, counter);
		write(1, &a, 1);
	}
	return (counter);
}

int ft_putnbr_uns(unsigned int n, int counter)
{
	char			a;

	a = n % 10 + '0';
	if (n < 10)
	{
		counter++;
		write(1, &a, 1);
	}
	else
	{
		counter++;
		counter = ft_putnbr(n / 10, counter);
		write(1, &a, 1);
	}
	return (counter);
}

int ft_destosix(int n, int counter)
{
	char *numbers;

	numbers = "0123456789abcdef";		
	if (n < 16)
	{
		ft_putchar((const char)numbers[n]);
		counter++;
	}
	else
	{
		counter++;
		counter = ft_destosix(n / 16, counter);
		ft_putchar((const char)numbers[n % 16]);
	}
	return (counter);
}