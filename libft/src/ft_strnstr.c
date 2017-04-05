/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:21:07 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 18:01:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			l_len;
	unsigned int	i;
	size_t			lc;

	lc = 0;
	if (little == big)
		return ((char*)big);
	if (!*little)
		return ((char*)big);
	l_len = ft_strlen((char*)little);
	if (!big)
		return (NULL);
	while (lc <= len)
	{
		i = 0;
		while ((big[i] == little[i]) && (big[i]) && ((lc + (l_len - i)) <= len))
			i++;
		if (little[i] == '\0')
			return ((char*)(big));
		if (big[i] == '\0')
			return (NULL);
		big++;
		lc++;
	}
	return (NULL);
}
