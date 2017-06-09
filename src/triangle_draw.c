/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 06:30:02 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 12:59:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define PLOT(x) (((x + (win->size / 2.0)) / win->size) * WINDOW_SIZE)

static void	flat_b(t_xy *p1, t_xy *p2, t_xy *p3, t_window *win, unsigned int i)
{
	t_xy	slope;
	t_xy	xs;
	int		y;
	float	x;

	slope.x = (p1->x - p3->x) / (p1->y - p3->y);
	slope.y = (p2->x - p3->x) / (p2->y - p3->y);
	y = PLOT(p3->y);
	xs.x = p1->x;
	xs.y = p2->y;
	while (y >= PLOT(p1->y))
	{
		x = xs.x;
		while (x <= xs.y)
		{
			i = select_color(win, i);
			put_pixel(win, PLOT(x), y, i);
			x += (xs.y - xs.x) / (((xs.y - xs.x) / win->size) * WINDOW_SIZE);
		}
		xs.x -= slope.x;
		xs.y -= slope.y;
		y--;
	}
}

static void	flat_t(t_xy *p1, t_xy *p2, t_xy *p3, t_window *win, unsigned int i)
{
	t_xy	slope;
	t_xy	xs;
	int		y;
	float	x;

	slope.x = (p1->x - p3->x) / (p1->y - p3->y);
	slope.y = (p2->x - p3->x) / (p2->y - p3->y);
	y = PLOT(p3->y);
	xs.x = p1->x;
	xs.y = p2->y;
	while (y <= PLOT(p1->y))
	{
		x = xs.x;
		while (x <= xs.y)
		{
			i = select_color(win, i);
			put_pixel(win, PLOT(x), y, i);
			x += (xs.y - xs.x) / (((xs.y - xs.x) / win->size) * WINDOW_SIZE);
		}
		xs.x -= slope.x;
		xs.y -= slope.y;
		y++;
	}
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

	tri_arr[0] = p1;
	tri_arr[1] = p2;
	tri_arr[2] = p3;
	sort_by_y(tri_arr);
	if (tri_arr[1]->y == tri_arr[2]->y)
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
	}
}

void		fill_midpoints(t_riangle *t)
{
	t_xy	*m1;
	t_xy	*m2;
	t_xy	*m3;

	m1 = get_midpoint(t->p1, t->p2);
	m2 = get_midpoint(t->p1, t->p3);
	m3 = get_midpoint(t->p2, t->p3);
	fill_triangle(m1, m2, m3, t->win, t->i);
	del_xy(m1);
	del_xy(m2);
	del_xy(m3);
}
