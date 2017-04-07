/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_grid_z.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:50:25 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 15:58:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

void	rotate_grid_z_pos(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			rot_poz(D.map3d[row][col], ROT_ANGLE);
			col++;
		}
		row++;
	}
}

void	rotate_grid_z_neg(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			rot_poz(D.map3d[row][col], (ROT_ANGLE * -1));
			col++;
		}
		row++;
	}
}
