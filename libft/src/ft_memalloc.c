/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:58:25 by irhett            #+#    #+#             */
/*   Updated: 2016/11/14 11:27:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	index;

	mem = malloc(size);
	index = 0;
	if (mem)
	{
		while (index <= size)
			mem[index++] = 0;
	}
	return (mem);
}
