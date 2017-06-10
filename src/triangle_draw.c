/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 06:30:02 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 22:47:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define HALFWIN	(WINDOW_SIZE / 2)
#define WINOFF	(WINDOW_SIZE / t->win->size)

void	draw_horiz(t_riangle *t, int y, double x1, double x2)
{
	unsigned int	color;
	int				start;
	int				end;

	color = select_color(t->win, t->i);
	start = HALFWIN + ((t->win->center_x + x1) / WINOFF);
	end = HALFWIN + ((t->win->center_x + x2) / WINOFF);
	while (start >= end)
	{
		put_pixel(t->win, start, y, color);
		start--;
	}
}

void	draw_normal(t_riangle *t)	
{
	float	slope1;
	float	slope2;
	float	x1;
	float	x2;
	int		y;
	int		max;
	
	slope1 = (t->p3->x - t->p1->x) / (t->p3->y - t->p1->y);
	slope2 = (t->p2->x - t->p1->y) / (t->p2->y - t->p1->y);
	x1 = t->p1->x;
	x2 = t->p1->x;
	y = HALFWIN + ((t->win->center_y + t->p1->y) * WINOFF);
	max = HALFWIN + ((t->win->center_y + t->p2->y) * WINOFF);
	while (y <= max)
	{
		draw_horiz(t, y, x1, x2);
		y++;
		x1 += slope1;
		x2 += slope2;
	}
}

void	draw_center(t_riangle *t)
{
	float	slope1;
	float	slope2;
	float	x1;
	float	x2;
	int		y;
	int		min;
	t_xy	*p4;
	t_xy	*p5;
	t_xy	*p6;

	p4 = get_midpoint(t->p1, t->p2);
	p5 = get_midpoint(t->p2, t->p3);
	p6 = get_midpoint(t->p3, t->p1);
	slope1 = (p6->x - p5->x) / (p6->y - p5->y);
	slope2 = (p6->x - p4->x) / (p6->y - p5->y);
	x1 = p6->x;
	x2 = p6->x;
	y = HALFWIN + ((t->win->center_y + p6->y) * WINOFF);
	min = HALFWIN + ((t->win->center_y + p4->y) * WINOFF);	
	while (y >= min)
	{
		draw_horiz(t, y, x1, x2);
		y--;
		x1 -= slope1;
		x2 -= slope2;
	}
	del_xy(p4);
	del_xy(p5);
	del_xy(p6);
}
