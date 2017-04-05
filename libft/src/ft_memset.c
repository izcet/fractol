/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:40:34 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 16:55:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int num, size_t len)
{
	char			*pointer;
	unsigned char	c;

	if (p)
	{
		pointer = p;
		c = (unsigned char)num;
		while (len > 0)
		{
			*pointer = c;
			len--;
			pointer++;
		}
	}
	return (p);
}
