/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapwords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:52:43 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 16:56:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		correct_letters(int is_first, char *c, int i)
{
	if (c)
	{
		if (is_first)
			c[i] = ft_toupper(c[i]);
		else
			c[i] = ft_tolower(c[i]);
	}
}

char			*ft_strcapwords(char *str)
{
	int index;
	int is_first;

	index = 0;
	is_first = 1;
	if (str)
	{
		while (str[index] != '\0')
		{
			if (!ft_isalpha(str[index]))
				is_first = 1;
			else
			{
				correct_letters(is_first, str, index);
				is_first = 0;
			}
			index++;
		}
	}
	return (str);
}
