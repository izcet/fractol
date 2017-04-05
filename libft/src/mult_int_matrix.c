/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_int_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:46:24 by irhett            #+#    #+#             */
/*   Updated: 2017/03/11 00:08:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define T (*t)
#define A (*a)
#define B (*b)

void				mult_int_matrix_scalar(t_int_matrix *t, double factor)
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
				T.data[row][col] = T.data[row][col] * factor;
				col++;
			}
			row++;
		}
	}
	else
		ft_error("NULL passsed to mult_int_matrix_scalar");
}

static t_int_matrix	*mult_int_error(t_int_matrix *a, t_int_matrix *b)
{
	t_int_matrix	*t;

	if (!a || !b)
	{
		ft_error("NULL passed to mult_int_matrix()");
		return (NULL);
	}
	if (A.cols != B.rows)
	{
		ft_error("Matrix ineligible for multiplication (wid/len mismatch)");
		return (NULL);
	}
	t = make_int_matrix(A.rows, B.cols);
	if (!t)
		return (NULL);
	return (t);
}

t_int_matrix		*mult_int_matrix(t_int_matrix *a, t_int_matrix *b)
{
	t_int_matrix	*t;
	unsigned int	row;
	unsigned int	col;
	int				*temp;

	t = mult_int_error(a, b);
	if (!t)
		return (NULL);
	row = 0;
	while (row < T.rows)
	{
		col = 0;
		while (col < T.cols)
		{
			temp = int_col(B.data, col, B.rows);
			if (temp)
			{
				T.data[row][col] = int_dot_product(A.data[row], temp, B.rows);
				free(temp);
			}
			col++;
		}
		row++;
	}
	return (t);
}
