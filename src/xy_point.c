/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:46:28 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 13:03:30 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	del_xy(t_xy *p)
{
	if (p)
	{
		ft_bzero(p, sizeof(t_xy));
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyp()");
}

t_xy	*init_xy(double x, double y)
{
	t_xy	*p;

	p = (t_xy*)malloc(sizeof(t_xy));
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xy");
		return (NULL);
	}
	p->x = x;
	p->y = y;
	return (p);
}

t_xy		*get_x_intercept(t_xy *top, t_xy *bottom, float y)
{
	float	x;

	x = top->x + ((y - top->y) / (bottom->y - top->y)) * (bottom->x - top->x);
	return (init_xy(x, y));
}

t_xy		*get_midpoint(t_xy *a, t_xy *b)
{
	return (init_xy(b->x - a->x, b->y - a->y));
}

t_xy		*xy_copy_of(t_xy *point)
{
	t_xy	*p;

	p = init_xy(point->x, point->y);
	return (p);
}
