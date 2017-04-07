/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point_around_origin.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:07:40 by irhett            #+#    #+#             */
/*   Updated: 2017/03/12 18:25:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define P (*p)
#define T (*t)

#define THETA DTR(angle)

void	rot_pox(t_xyzcp *p, double angle)
{
	t_dub_matrix	*t;

	t = make_dub_matrix(3, 3);
	if (t)
	{
		T.data[0][0] = 1.0;
		T.data[0][1] = 0.0;
		T.data[0][2] = 0.0;
		T.data[1][0] = 0.0;
		T.data[1][1] = cos(THETA);
		T.data[1][2] = sin(THETA) * -1.0;
		T.data[2][0] = 0.0;
		T.data[2][1] = sin(THETA);
		T.data[2][2] = cos(THETA);
		rotate_point_by_matrix(p, t);
		del_dub_matrix(t);
	}
}

void	rot_poy(t_xyzcp *p, double angle)
{
	t_dub_matrix	*t;

	t = make_dub_matrix(3, 3);
	if (t)
	{
		T.data[0][0] = cos(THETA);
		T.data[0][1] = 0.0;
		T.data[0][2] = sin(THETA);
		T.data[1][0] = 0.0;
		T.data[1][1] = 1.0;
		T.data[1][2] = 0.0;
		T.data[2][0] = sin(THETA) * -1.0;
		T.data[2][1] = 0.0;
		T.data[2][2] = cos(THETA);
		rotate_point_by_matrix(p, t);
		del_dub_matrix(t);
	}
}

void	rot_poz(t_xyzcp *p, double angle)
{
	t_dub_matrix	*t;

	t = make_dub_matrix(3, 3);
	if (t)
	{
		T.data[0][0] = cos(THETA);
		T.data[0][1] = sin(THETA) * -1.0;
		T.data[0][2] = 0.0;
		T.data[1][0] = sin(THETA);
		T.data[1][1] = cos(THETA);
		T.data[1][2] = 0.0;
		T.data[2][0] = 0.0;
		T.data[2][1] = 0.0;
		T.data[2][2] = 1.0;
		rotate_point_by_matrix(p, t);
		del_dub_matrix(t);
	}
}
