/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:33:31 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 15:26:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		is_a_number_block(int *is_neg, int *num, char *str, int i)
{
	if (*is_neg > 0)
	{
		*num *= 10;
		if ((*is_neg == 1) && (str[i] != '0'))
		{
			*num += (str[i] - '0');
			*is_neg = 2;
			*num *= -1;
		}
		else
			*num -= (str[i] - '0');
	}
	else
	{
		*num *= 10;
		*num += (str[i] - '0');
	}
}

static int		my_atoi(char *str, int index, int number, int is_negative)
{
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			is_negative++;
		index++;
	}
	while (str[index] != '\0')
	{
		if (ft_isdigit(str[index]))
			is_a_number_block(&is_negative, &number, str, index);
		else
			return (number);
		index++;
	}
	return (number);
}

int				ft_atoi(char *str)
{
	if (str)
		return (my_atoi(str, 0, 0, 0));
	return (0);
}
