/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_cols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:15:36 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:29:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)
#define P (*D.map[row][col])
#define C (*c)

static int	fill_point_colors(t_data *data)
{
	unsigned int	row;
	unsigned int	col;
	t_col			*c;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			if (!P.c)
			{
				c = get_col_from_range(data, row, col);
				if (c)
					P.c = c;
				else
					return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int			set_point_cols(t_data *data, int argc, char **argv)
{
	set_z_range(data);
	D.col = make_col_1d_arr(data, argc, argv);
	if (!D.col)
		return (1);
	return (fill_point_colors(data));
}
