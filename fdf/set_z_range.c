/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_z_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:06:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:29:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)
#define P (*D.map[row][col])

void		set_z_range(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			if (row + col == 0)
			{
				D.z_min = P.z;
				D.z_max = P.z;
			}
			else
			{
				if (D.z_min > P.z)
					D.z_min = P.z;
				if (D.z_max < P.z)
					D.z_max = P.z;
			}
			col++;
		}
		row++;
	}
}
