/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:01:48 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:46:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	if (dst && src)
	{
		while (len > 0)
		{
			if (*src != '\0')
				*(dst++) = *(src++);
			else
			{
				*dst = '\0';
				dst++;
			}
			len--;
		}
	}
	return (tmp);
}
