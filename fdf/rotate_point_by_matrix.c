/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point_by_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:23:21 by irhett            #+#    #+#             */
/*   Updated: 2017/03/12 18:51:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define P (*p)
#define T (*t)
#define D T.data
#define X P.x
#define Y P.y
#define Z P.z

void	rotate_point_by_matrix(t_xyzcp *p, t_dub_matrix *t)
{
	float	x;
	float	y;
	float	z;

	if (p && t)
	{
		if (T.rows == 3 && T.cols == 3)
		{
			x = (X * D[0][0]) + (Y * D[1][0]) + (Z * D[2][0]);
			y = (X * D[0][1]) + (Y * D[1][1]) + (Z * D[2][1]);
			z = (X * D[0][2]) + (Y * D[1][2]) + (Z * D[2][2]);
			set_xyzcp(p, x, y, z);
		}
		else
			ft_error("Invalid matrix dimensions in rotate_point_by_matrix()");
	}
	else
		ft_error("NULL passed to rotate_point_by_matrix()");
}
