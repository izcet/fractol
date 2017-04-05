/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:30:26 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:59:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	char *temp;

	if (a && b)
	{
		temp = (char*)malloc(sizeof(char) * size);
		ft_memcpy(temp, b, size);
		ft_memcpy(b, a, size);
		ft_memcpy(a, temp, size);
		free(temp);
	}
}
