/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xyzcp_from_zcp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:00:45 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:54:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)
#define M (D.map3d)
#define N (D.map)
#define P (*p)

t_xyzcp	*make_xyz_from_z(t_data *data, unsigned int row, unsigned int col)
{
	t_xyzcp *p;

	p = init_xyzcp();
	if (!p)
		return (NULL);
	P.z = (*(N[row][col])).z;
	P.c = make_col_from_int(get_int_from_col((*(N[row][col])).c));
	P.x = (((float)D.wid - 1.0) / -2.0) + (float)col;
	P.y = (((float)D.len - 1.0) / -2.0) + (float)row;
	return (p);
}

int		make_3d_map_from_zcp(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	D.map3d = init_xyzcp_2d_arr(D.len, D.wid);
	if (D.map3d)
	{
		row = 0;
		while (row < D.len)
		{
			col = 0;
			while (col < D.wid)
			{
				if ((M[row][col] = make_xyz_from_z(data, row, col)) == NULL)
				{
					del_xyzcp_2d_arr(M, row + 1, D.wid);
					return (0);
				}
				col++;
			}
			row++;
		}
		return (1);
	}
	return (0);
}
