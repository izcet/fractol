/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelcube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 00:58:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				reset_mandelcube(t_window *win)
{
	float	view[3];

	view[0] = 2.8;
	view[1] = -0.0;
	view[2] = 0.0;
	set_window_view(win, view);
	win->max_iterations = 24;
	win->p_offset = 5;
	win->p_index = 9;
}

static unsigned char	man_compute_point(t_window *win, double re, double im)
{
	unsigned char	i;
	double			x;
	double			y;
	double			temp;

	i = 0;
	x = 0.0;
	y = 0.0;
	re = ((re / WINDOW_SIZE) * win->size) + win->center_x - (win->size * 0.5);
	im = ((im / WINDOW_SIZE) * win->size) + win->center_y - (win->size * 0.5);
	while ((i < win->max_iterations) && ((x * x) + (y * y) < 4))
	{
		temp = (x * x * x) - (y * x * y) - (2 * x * y * y) + re;
		y = (3 * x * x * y) - (y * y * y) + im;
		x = temp;
		i++;
	}
	return (i);
}

static void				man_compute_rows(void *thread)
{
	t_thread		*t;
	t_window		*win;
	int				x;
	int				y;
	unsigned int	i;

	t = (t_thread*)thread;
	win = t->win;
	y = ((WINDOW_SIZE / NUM_THREADS) * t->num) - 1;
	while (++y < ((WINDOW_SIZE / NUM_THREADS) * (t->num + 1)))
	{
		x = -1;
		while (++x < WINDOW_SIZE)
		{
			i = man_compute_point(win, x, y);
			if (i < win->max_iterations)
			{
				i = select_color(win, i);
				put_pixel(win, x, y, i);
			}
		}
	}
	del_thread(t);
}

static void				redraw_mandelcube(t_window *win)
{
	int			i;
	pthread_t	threads[NUM_THREADS];

	i = 0;
	while (i < NUM_THREADS)
	{
		threads[i] = make_thread(win, i, (void*)man_compute_rows);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(threads[i++], NULL);
	use_image(win);
}

void					mandelcube(void)
{
	t_window	*win;

	win = init_window("mandelcube");
	reset_mandelcube(win);
	win->reset_func = reset_mandelcube;
	win->draw_func = redraw_mandelcube;
	init_hooks(win, 0);
	mlx_loop(win->mlx);
}
