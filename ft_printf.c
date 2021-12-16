/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:49:49 by amahi             #+#    #+#             */
/*   Updated: 2021/12/16 13:05:39 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_destosix_up(int n, int counter)
{
	char *numbers;

	numbers = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar((const char)numbers[n]);
		counter++;
	}
	else
	{
		counter++;
		counter = ft_destosix_up(n / 16, counter);
		ft_putchar((const char)numbers[n % 16]);
	}
	return (counter);
}

int printaddress(uintptr_t ptr)
{
	write(1, "0x10", 4);
	return (ft_destosix((uintptr_t)((void  *)ptr), 0) + 4);
}

int check_flag(const char *arr, va_list vlist, int i)
{
	if (arr[i] == 'c')
		return (ft_putchar(va_arg(vlist, int)));
	if (arr[i] == 's')
		return (ft_putstr(va_arg(vlist, char *)));
	if (arr[i] == 'd')
		return (ft_putnbr(va_arg(vlist, int), 0));
	if (arr[i] == 'i')
		return (ft_putnbr(va_arg(vlist, int), 0));
	if (arr[i] == 'u')
		return (ft_putnbr_uns(va_arg(vlist, unsigned int), 0));
	if (arr[i] == 'x')
		return (ft_destosix(va_arg(vlist, int), 0));
	if (arr[i] == 'X')
		return (ft_destosix_up(va_arg(vlist, int), 0));
	if (arr[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (arr[i] == 'p')
		return (printaddress(va_arg(vlist, uintptr_t)));
	return (-1);
}

int ft_printf(const char *arr, ...)
{
	va_list			vlist;
	int				i;
	unsigned int	sum;
	
	i = 0;
	sum = 0;
	va_start (vlist, arr);
	if (!arr)
		return (-1);
	while (arr[i])
	{
		if (arr[i] == '%')
		{
			i++;
			sum += check_flag(arr, vlist, i);
		}
		else 
		{
			ft_putchar(arr[i]);
			sum++;
		}
		i++;
	}
	va_end(vlist);
	return (sum);
}

// int main(void)
// {
// 	char *str = "14";
// 	char *str2 = "5678";
// 	char c = 'a';
// 	int my_printf;
// 	int just_printf;
// 	my_printf = ft_printf("%p\n", str);
// 	just_printf = printf("%p\n", str);
// 	printf("Кол-во напечатанного:	%d\nCколько надо:		%d\n", my_printf, just_printf);
// }