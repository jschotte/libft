/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:08:03 by exam              #+#    #+#             */
/*   Updated: 2015/12/02 11:48:03 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	ft_letter(int n)
{
	if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	else
		return (n + 48);
}

char	*ft_convert(int nb, char *str, int b)
{
	int i;
	int j;

	j = 0;
	if (nb < 0 && b == 10)
	{
		str[j] = '-';
		j++;
		nb = -nb;
	}
	i = 1;
	while (nb / i > b - 1)
		i *= b;
	while (i != 0)
	{
		str[j] = ft_letter(nb / i);
		nb %= i;
		i /= b;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		j;
	char	*str;

	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		i = 0;
		j = value;
		while (j > 0)
		{
			i++;
			j = j / base;
		}
		str = (char*)malloc(sizeof(str) * i + 1);
		str = ft_convert(value, str, base);
		return (str);
	}
}
