/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:48:46 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:29:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*temp;

	temp = dst;
	if (dst && src)
	{
		while (*dst != '\0')
			dst++;
		while ((n > 0) && (*src != '\0'))
		{
			*dst = *src;
			dst++;
			src++;
			n--;
		}
		*dst = '\0';
	}
	return (temp);
}
