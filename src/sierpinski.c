/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 01:23:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				reset_sierpinski(t_window *win)
{
	float	view[3];

	view[0] = 500.0;
	view[1] = 0.0;
	view[2] = 0.0;
	set_window_view(win, view);
	win->max_iterations = 2;
	if (win->tri)
		del_tri(win->tri);
	win->tri = start_triangles(win->max_iterations, 500.0, win);
	win->p_offset = 8;
	win->p_index = 0;
}

static void				thread_tri(void *thread)
{
	t_thread	*th;
	t_riangle	*t;

	th = (t_thread*)thread;
	t = (t_riangle*)(th->win);
	if (t)
	{
		if (t->i == t->win->max_iterations)
			draw_normal(t);
		else
		{
			if (t->win->keys->q)
				draw_center(t);
			draw_triangles(t->t1);
			draw_triangles(t->t2);
			draw_triangles(t->t3);
		}
	}
	del_thread(th);
}

void					draw_triangles(t_riangle *t)
{
	pthread_t	threads[3];

	if (t)
	{
		if (t->i == t->win->max_iterations)
			draw_normal(t);
		else
		{
			if (t->win->keys->q)
				draw_center(t);
			if (t->i % 3 == 0 && t->win->max_iterations > 3)
			{
				threads[0] = make_thread((t_window*)(t->t1), 0, thread_tri);
				threads[1] = make_thread((t_window*)(t->t2), 0, thread_tri);
				threads[2] = make_thread((t_window*)(t->t3), 0, thread_tri);
				pthread_join(threads[0], NULL);
				pthread_join(threads[1], NULL);
				pthread_join(threads[2], NULL);
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
	win->triangles = 1;
	init_hooks(win, 0);
	mlx_loop(win->mlx);
}
