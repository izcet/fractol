/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point_around_point.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:39:02 by irhett            #+#    #+#             */
/*   Updated: 2017/03/12 18:46:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define P (*p)
#define O (*offset)

static void		reduce(t_xyzcp *p, t_xyzcp *offset)
{
	P.x = O.x - P.x;
	P.y = O.y - P.y;
	P.z = O.z - P.z;
}

static void		increase(t_xyzcp *p, t_xyzcp *offset)
{
	P.x = O.x + P.x;
	P.y = O.y + P.y;
	P.z = O.z + P.z;
}

void			rot_ppx(t_xyzcp *p, t_xyzcp *offset, double angle)
{
	if (p && offset)
	{
		reduce(p, offset);
		rot_pox(p, angle);
		increase(p, offset);
	}
	else
		ft_error("NULL passed to rot_ppx()");
}

void			rot_ppy(t_xyzcp *p, t_xyzcp *offset, double angle)
{
	if (p && offset)
	{
		reduce(p, offset);
		rot_poy(p, angle);
		increase(p, offset);
	}
	else
		ft_error("NULL passed to rot_ppy()");
}

void			rot_ppz(t_xyzcp *p, t_xyzcp *offset, double angle)
{
	if (p && offset)
	{
		reduce(p, offset);
		rot_poz(p, angle);
		increase(p, offset);
	}
	else
		ft_error("NULL passed to rot_ppz)");
}
