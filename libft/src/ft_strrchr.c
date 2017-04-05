/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:57:13 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:36:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	if (s)
	{
		while (*s != '\0')
		{
			if (*s == c)
				tmp = (char*)s;
			s++;
		}
		if (*s == c)
			tmp = (char*)s;
	}
	return (tmp);
}
