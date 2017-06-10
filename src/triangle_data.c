/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 23:22:08 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 22:25:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define DTR(x) (x * M_PI / 180.0)

void		tri_spawn_children(t_riangle *t)
{
	t_xy	*points[3];

	if (t)
	{
		del_children(t);
		points[0] = xy_copy_of(t->p1);
		points[1] = get_midpoint(t->p1, t->p2);
		points[2] = get_midpoint(t->p3, t->p1);
		t->t1 = init_tri(t->i + 1, points, t->win);
		points[0] = get_midpoint(t->p1, t->p2);
		points[1] = xy_copy_of(t->p2);
		points[2] = get_midpoint(t->p3, t->p2);
		t->t2 = init_tri(t->i + 1, points, t->win);
		points[0] = get_midpoint(t->p3, t->p1);
		points[1] = get_midpoint(t->p3, t->p2);
		points[2] = xy_copy_of(t->p3);
		t->t3 = init_tri(t->i + 1, points, t->win);
	}
}

t_riangle	*tri_more_iterations(t_riangle *t)
{
	if (t && t->i > t->win->max_iterations)
	{
		del_tri(t);
		return (NULL);
	}
	if (!t)
		return (NULL);
	if (t->i < t->win->max_iterations)
	{
		if (!(t->t1) || !(t->t2) || !(t->t3))
			tri_spawn_children(t);
		t->t1 = tri_more_iterations(t->t1);
		t->t2 = tri_more_iterations(t->t2);
		t->t3 = tri_more_iterations(t->t3);
	}
	return (t);
}

t_riangle	*start_triangles(unsigned char i, float side_len, t_window *win)
{
	t_riangle	*t;
	t_xy		*p[3];

	if (i == 0)
		return (NULL);
	p[0] = init_xy(side_len * cos(DTR(0)), side_len * sin(DTR(0)));
	p[1] = init_xy(side_len * cos(DTR(120)), side_len * sin(DTR(120)));
	p[2] = init_xy(side_len * cos(DTR(240)), side_len * sin(DTR(240)));
	t = init_tri(1, p, win);
	t = tri_more_iterations(t);
	return (t);
}

t_riangle	*tri_less_iterations(t_riangle *t)
{
	if (t)
	{
		if (t->i > t->win->max_iterations)
		{
			del_tri(t);
			return (NULL);
		}
		if (t->i == t->win->max_iterations)
			del_children(t);
		else
		{
			t->t1 = tri_less_iterations(t->t1);
			t->t2 = tri_less_iterations(t->t2);
			t->t3 = tri_less_iterations(t->t3);
		}
		return (t);
	}
	return (NULL);
}
