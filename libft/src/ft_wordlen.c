/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:11:47 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:40:04 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wordlen(char *s, char del)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (s)
	{
		while (s[i] == del)
			i++;
		while (s[i] != del)
		{
			if (s[i] == '\0')
				return (len);
			i++;
			len++;
		}
	}
	return (len);
}
