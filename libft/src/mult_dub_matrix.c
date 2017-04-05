/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_dub_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 22:31:37 by irhett            #+#    #+#             */
/*   Updated: 2017/03/10 23:09:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define T (*t)
#define A (*a)
#define B (*b)

void				mult_dub_matrix_scalar(t_dub_matrix *t, double factor)
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
		ft_error("NULL passsed to mult_dub_matrix_scalar");
}

static t_dub_matrix	*check_errors(t_dub_matrix *a, t_dub_matrix *b)
{
	t_dub_matrix	*t;

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
	t = make_dub_matrix(A.rows, B.cols);
	if (!t)
		return (NULL);
	return (t);
}

t_dub_matrix		*mult_dub_matrix(t_dub_matrix *a, t_dub_matrix *b)
{
	t_dub_matrix	*t;
	unsigned int	row;
	unsigned int	col;
	double			*temp;

	t = check_errors(a, b);
	if (!t)
		return (NULL);
	row = 0;
	while (row < T.rows)
	{
		col = 0;
		while (col < T.cols)
		{
			temp = dub_col(B.data, col, B.rows);
			if (temp)
			{
				T.data[row][col] = dub_dot_product(A.data[row], temp, B.rows);
				free(temp);
			}
			col++;
		}
		row++;
	}
	return (t);
}
