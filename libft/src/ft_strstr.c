/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:00:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:45:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*tmp;

	if (big && little)
	{
		if (*little == '\0')
			return ((char*)big);
		while (*big != '\0')
		{
			i = 0;
			if (little[i] == big[i])
			{
				tmp = (char*)big;
				while (little[i] == big[i])
				{
					i++;
					if (little[i] == '\0')
						return (tmp);
				}
			}
			big++;
		}
	}
	return (NULL);
}
