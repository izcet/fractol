/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 06:30:02 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 13:56:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_riangle	*init_tri(unsigned char i, t_xy *p[3], t_window *win)
{
	t_riangle	*t;

	t = (t_riangle*)malloc(sizeof(t_riangle));
	if (!t)
	{
		ft_error("Unable to allocate space in init_triangle()");
		return (NULL);
	}
	ft_bzero(t, sizeof(t_riangle));
	t->p1 = p[0];
	t->p2 = p[1];
	t->p3 = p[2];
	t->win = win;
	t->i = i;
	return (t);
}

void		del_children(t_riangle *t)
{
	if (t)
	{
		if (t->t1)
			del_tri(t->t1);
		if (t->t2)
			del_tri(t->t2);
		if (t->t3)
			del_tri(t->t3);
		t->t1 = NULL;
		t->t2 = NULL;
		t->t3 = NULL;
	}
	else
		ft_error("NULL passed to del_children()");
}

void		del_tri(t_riangle *t)
{
	if (t)
	{
		if (t->p1)
			del_xy(t->p1);
		if (t->p2)
			del_xy(t->p2);
		if (t->p3)
			del_xy(t->p3);
		del_children(t);
		free(t);
	}
	else
		ft_error("NULL passed to del_tri()");
}

void		draw_next(t_riangle *t)
{
	draw_triangles(t->t1);
	draw_triangles(t->t2);
	draw_triangles(t->t3);
}
