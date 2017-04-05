/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_matrix_scalar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 22:44:23 by irhett            #+#    #+#             */
/*   Updated: 2017/03/10 22:47:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define T (*t)

void	plus_int_matrix_scalar(t_int_matrix *t, int factor)
{
	unsigned int	row;
	unsigned int	col;

	if (t)
	{
		row = 0;
		while (row < T.rows)
		{
			col = 0;
			while (col < T.cols)
			{
				T.data[row][col] += factor;
				col++;
			}
			row++;
		}
	}
	else
		ft_error("NULL passed to plus_int_matrix_scalar()");
}

void	plus_dub_matrix_scalar(t_dub_matrix *t, double factor)
{
	unsigned int	row;
	unsigned int	col;

	if (t)
	{
		row = 0;
		while (row < T.rows)
		{
			col = 0;
			while (col < T.cols)
			{
				T.data[row][col] += factor;
				col++;
			}
			row++;
		}
	}
	else
		ft_error("NULL passed to plus_dub_matrix_scalar()");
}
