/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 13:04:21 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				reset_sierpinski(t_window *win)
{
	float	view[3];

	view[0] = 120.0;
	view[1] = 0.0;
	view[2] = 0.0;
	set_window_view(win, view);
	win->max_iterations = 2;
	if (win->tri)
		del_tri(win->tri);
	win->tri = start_triangles(win->max_iterations, 60.0, win);
	win->p_offset = 8;
	win->p_index = 0;
}

static void				thread_triangles(void *thread)
{
	t_thread	*th;
	t_riangle	*t;


	th = (t_thread*)thread;
	t = (t_riangle*)(th->win);
	if (t)
	{
		if (t->i == t->win->max_iterations)
			fill_triangle(t->p1, t->p2, t->p3, t->win, t->i);
		else
		{
			if (t->win->keys->q)
				fill_midpoints(t);
			draw_triangles(t->t1);
			draw_triangles(t->t2);
			draw_triangles(t->t3);
		}
	}
	del_thread(th);
}

void					draw_triangles(t_riangle *t)
{
	pthread_t	thread_a;
	pthread_t	thread_b;
	pthread_t	thread_c;

	if (t)
	{
		if (t->i == t->win->max_iterations)
			fill_triangle(t->p1, t->p2, t->p3, t->win, t->i);
		else
		{
			if (t->win->keys->q)
				fill_midpoints(t);
			if (t->i == 3 && t->win->max_iterations > 3)
			{
				thread_a = make_thread((t_window*)(t->t1), 0, thread_triangles);
				thread_b = make_thread((t_window*)(t->t2), 0, thread_triangles);
				thread_c = make_thread((t_window*)(t->t3), 0, thread_triangles);
				pthread_join(thread_a, NULL);
				pthread_join(thread_b, NULL);
				pthread_join(thread_c, NULL);
			}
			else
			{
				draw_triangles(t->t1);
				draw_triangles(t->t2);
				draw_triangles(t->t3);
			}
		}
	}		
}

static void				redraw_sierpinski(t_window *win)
{
	draw_triangles(win->tri);
	use_image(win);
}

void					sierpinski(void)
{
	t_window	*win;

	win = init_window("sierpinski");
	win->tri = NULL;
	reset_sierpinski(win);
	win->reset_func = reset_sierpinski;
	win->draw_func = redraw_sierpinski;
	init_hooks(win, 0);
	mlx_loop(win->mlx);
}
