/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 06:30:02 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 19:07:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h> //

#define PLOT(x) (int)(((x + (win->size / 2.0)) / win->size) * WINDOW_SIZE)

static void	flat_b(t_xy *p1, t_xy *p2, t_xy *p3, t_window *win, unsigned int i)
{
	t_xy	*slope;
	t_xy	*xs;
	int		y;
	float	x;

	slope = init_xy((p1->x - p3->x) / (p1->y - p3->y), (p2->x - p3->x) / (p2->y - p3->y));
	y = PLOT(p3->y);
	xs = init_xy(p1->x, p2->x);
	printf("BASE: Y %i -> %i\n", y, PLOT(p1->y));
	while (y <= PLOT(p1->y))
	{
		printf("Here\n");
		x = xs->y;
		printf("BASE: X %f -> %f, %f\n", xs->y, xs->x, (xs->y - xs->x) / (((xs->y - xs->x) / win->size) * WINDOW_SIZE));
		while (x >= xs->x)
		{
			i = select_color(win, i);
			printf("BASE: X %i Y %i\n", PLOT(x), y);
			put_pixel(win, PLOT(x), y, i);
			x -= (xs->y - xs->x) / (((xs->y - xs->x) / win->size) * WINDOW_SIZE);
		}
		xs->x -= slope->x;
		xs->y -= slope->y;
		y++;
	}
	del_xy(slope);
	del_xy(xs);
}

static void	flat_t(t_xy *p1, t_xy *p2, t_xy *p3, t_window *win, unsigned int i)
{
	t_xy	*slope;
	t_xy	*xs;
	int		y;
	float	x;

	slope = init_xy((p1->x - p3->x) / (p1->y - p3->y), (p2->x - p3->x) / (p2->y - p3->y));
	y = PLOT(p3->y);
	xs = init_xy(p1->x, p2->x);
	printf("UPSIDE_DOWN: Y %i -> %i\n", y, PLOT(p1->y));
	while (y <= PLOT(p1->y))
	{
		x = xs->x;
		while (x <= xs->y)
		{
			i = select_color(win, i);
			put_pixel(win, PLOT(x), y, i);
			x += (xs->y - xs->x) / (((xs->y - xs->x) / win->size) * WINDOW_SIZE);
		}
		xs->x -= slope->x;
		xs->y -= slope->y;
		y++;
	}
	del_xy(slope);
	del_xy(xs);
}

static void	sort_by_y(t_xy *arr[3])
{
	t_xy	*temp;

	if (arr[0]->y > arr[1]->y)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	if (arr[1]->y > arr[2]->y)
	{
		temp = arr[1];
		arr[1] = arr[2];
		arr[2] = temp;
	}
	if (arr[0]->y > arr[1]->y)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}

void		fill_triangle(t_xy *p1, t_xy *p2, t_xy *p3, t_window *win, 
		unsigned int i)
{
	t_xy	*tri_arr[3];
	t_xy	*fourth;

	tri_arr[0] = xy_copy_of(p1);
	tri_arr[1] = xy_copy_of(p2);
	tri_arr[2] = xy_copy_of(p3);
	sort_by_y(tri_arr);
	if (tri_arr[1]->y == tri_arr[2]->y) // do int conversion to pixel
	{
		if (tri_arr[1]->x < tri_arr[2]->x)
			flat_b(tri_arr[1], tri_arr[2], tri_arr[0], win, i);
		else
			flat_b(tri_arr[2], tri_arr[1], tri_arr[0], win, i);
	}
	else
	{
		fourth = get_x_intercept(tri_arr[0], tri_arr[2], tri_arr[1]->y);
		if (tri_arr[1]->x < fourth->x)
		{
			flat_b(tri_arr[1], fourth, tri_arr[0], win, i);
			flat_t(tri_arr[1], fourth, tri_arr[2], win, i);
		}
		else
		{
			flat_b(fourth, tri_arr[1], tri_arr[0], win, i);
			flat_t(fourth, tri_arr[1], tri_arr[2], win, i);
		}
		del_xy(fourth);
	}
	del_xy(tri_arr[0]);
	del_xy(tri_arr[1]);
	del_xy(tri_arr[2]);
}

void		fill_midpoints(t_riangle *t)
{
	t_xy	*p[3];

	p[0] = get_midpoint(t->p1, t->p2);
	p[1] = get_midpoint(t->p1, t->p3);
	p[2] = get_midpoint(t->p2, t->p3);
	sort_by_y(p);
	flat_t(p[0], p[1], p[2], t->win, t->i);
	del_xy(p[0]);
	del_xy(p[1]);
	del_xy(p[2]);
}
