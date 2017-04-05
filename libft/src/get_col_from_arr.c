/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_col_from_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:11:08 by irhett            #+#    #+#             */
/*   Updated: 2017/03/10 23:47:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** warning, these check only that the inital pointer is not null.
** if LEN is invalid, or if a null pointer exists in the array
** problems (shrug)
*/

int		*int_col(int **arr, unsigned int col, unsigned int len)
{
	unsigned int	i;
	int				*ans;

	if (!arr)
	{
		ft_error("NULL passed to int_col()");
		return (NULL);
	}
	ans = (int*)malloc(sizeof(int) * len);
	if (!ans)
	{
		ft_error("Unable to allocate space for int[] in int_col()");
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ans[i] = arr[i][col];
		i++;
	}
	return (ans);
}

double	*dub_col(double **arr, unsigned int col, unsigned int len)
{
	unsigned int	i;
	double			*ans;

	if (!arr)
	{
		ft_error("NULL passed to dub_col()");
		return (NULL);
	}
	ans = (double*)malloc(sizeof(double) * len);
	if (!ans)
	{
		ft_error("Unable to allocate space for double[] in dub_col()");
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ans[i] = arr[i][col];
		i++;
	}
	return (ans);
}
