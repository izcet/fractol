/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:49:01 by irhett            #+#    #+#             */
/*   Updated: 2017/02/11 14:54:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] != '\0') && (s2[i] != '\0'))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	else
	{
		if (s1 == s2)
			return (1);
		return (0);
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
