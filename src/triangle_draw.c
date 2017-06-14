/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 06:30:02 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 01:39:26 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define HALFWIN	(WINDOW_SIZE / 2)
#define WINOFF	((t->win->size) / WINDOW_SIZE)

void			draw_horiz(t_riangle *t, int y, double x1, double x2)
{
	unsigned int	color;
	int				start;
	int				end;

	color = select_color(t->win, t->i);
	start = ((t->win->center_x + x1));
	end = ((t->win->center_x + x2));
	while (start <= end)
	{
		if (start + HALFWIN >= 0 && start + HALFWIN < WINDOW_SIZE)
			put_pixel(t->win, start + HALFWIN, y, color);
		start++;
	}
}

void			draw_normal(t_riangle *t)
{
	float	slopes[2];
	float	x1;
	float	x2;
	int		y;
	int		max;

	slopes[0] = ((t->p3->x - t->p1->x) / (t->p3->y - t->p1->y));
	slopes[1] = (t->p2->x - t->p1->x) / (t->p2->y - t->p1->y);
	x1 = t->p1->x * WINOFF;
	x2 = t->p1->x * WINOFF;
	y = ((t->win->center_y + t->p1->y) * WINOFF) + HALFWIN;
	max = ((t->win->center_y + t->p2->y) * WINOFF) + HALFWIN;
	while (y <= max)
	{
		if (y >= 0 && y < WINDOW_SIZE)
			draw_horiz(t, y, x1, x2);
		y++;
		x1 += slopes[0];
		x2 += slopes[1];
	}
}

static t_xy		**start_points(t_riangle *t)
{
	t_xy	**p;

	p = (t_xy**)malloc(sizeof(t_xy *) * 3);
	if (!p)
	{
		ft_error("Unable to allocate memory in start_points()");
		return (NULL);
	}
	p[0] = get_midpoint(t->p1, t->p2);
	p[1] = get_midpoint(t->p2, t->p3);
	p[2] = get_midpoint(t->p3, t->p1);
	return (p);
}

static void		end_points(t_xy **p)
{
	del_xy(p[0]);
	del_xy(p[1]);
	del_xy(p[2]);
	free(p);
}

void			draw_center(t_riangle *t)
{
	float	slopes[2];
	float	xs[2];
	int		y;
	int		min;
	t_xy	**p;

	p = start_points(t);
	slopes[0] = (p[1]->x - p[2]->x) / (p[1]->y - p[2]->y);
	slopes[1] = (p[1]->x - p[0]->x) / (p[1]->y - p[0]->y);
	xs[0] = p[1]->x * WINOFF;
	xs[1] = p[1]->x * WINOFF;
	y = HALFWIN + ((t->win->center_y + p[1]->y) * WINOFF);
	min = HALFWIN + ((t->win->center_y + p[2]->y) * WINOFF);
	while (y >= min)
	{
		if (y >= 0 && y < WINDOW_SIZE)
			draw_horiz(t, y, xs[0], xs[1]);
		y--;
		xs[0] -= slopes[0];
		xs[1] -= slopes[1];
	}
	end_points(p);
}
