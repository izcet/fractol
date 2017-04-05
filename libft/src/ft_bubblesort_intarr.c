/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort_intarr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:07:19 by irhett            #+#    #+#             */
/*   Updated: 2017/02/11 18:07:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bubblesort_intarr(int *arr, unsigned int arr_len)
{
	unsigned int	i;

	i = 0;
	if (arr && arr_len)
	{
		while (i < arr_len)
		{
			if ((i == 0) || (arr[i] >= arr[i - 1]))
				i++;
			else
			{
				ft_swap(&arr[i], &arr[i - 1], sizeof(int));
				i--;
			}
		}
	}
}
