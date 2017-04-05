/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:40:26 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:01:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while ((*s1 == *s2) && (*s1 != '\0'))
		{
			s1++;
			s2++;
		}
		return ((unsigned int)((unsigned char)(*s1) - (unsigned char)(*s2)));
	}
	return (0);
}
