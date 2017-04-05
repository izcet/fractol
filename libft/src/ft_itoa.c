/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:47:16 by irhett            #+#    #+#             */
/*   Updated: 2017/02/11 14:28:29 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_len(int input)
{
	int		num;

	num = 0;
	if (input == 0)
		return (1);
	if (input == -2147483648)
		return (11);
	if (input < 0)
	{
		num++;
		input *= -1;
	}
	while (input > 0)
	{
		num++;
		input = input / 10;
	}
	return (num);
}

static char		*get_number(int n, char *str, int len)
{
	if (n == 0)
		ft_memcpy(str, "0", len + 1);
	else if (n == -2147483648)
		ft_memcpy(str, "-2147483648", len + 1);
	else
	{
		if (n < 0)
		{
			*str = '-';
			n *= -1;
		}
		str[len] = '\0';
		while (n > 0)
		{
			str[--len] = ((n % 10) + '0');
			n = n / 10;
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = number_len(n);
	str = (char*)(malloc(sizeof(char) * (len + 1)));
	if (str)
		return (get_number(n, str, len));
	return (NULL);
}
