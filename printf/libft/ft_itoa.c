/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:45:12 by mclown            #+#    #+#             */
/*   Updated: 2020/11/13 13:15:05 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		count_symbols(unsigned int n)
{
	int count_syms;

	count_syms = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count_syms++;
		n /= 10;
	}
	return (count_syms);
}

static char		*fill_the_array(int count_syms, unsigned int n, char *res)
{
	res[count_syms] = '\0';
	if (!n)
		res[0] = '0';
	while (n != 0)
	{
		res[--count_syms] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char			*res;
	int				count_syms;
	unsigned int	num;
	int				minus_sign;

	minus_sign = 0;
	if (n < 0)
	{
		minus_sign = 1;
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	count_syms = count_symbols(num);
	count_syms += minus_sign;
	res = (char *)malloc((count_syms * sizeof(char)) + 1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res = fill_the_array(count_syms, num, res);
	return (res);
}
