/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:49:19 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define W win->

static void				reset_mandelbrot(t_window *win)
{
	float	view[4];

	view = {2.0, 2.0, 0.0, 0.0};
	set_window_view(win, view);
	win->max_iterations = 16;
	win->p_offset = 0;
	win->p_index = 0;
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
	re = ((re / WINDOW_SIZE) * Wview_size) + Wcenter_x - (Wview_size * 0.5);
	im = ((im / WINDOW_SIZE) * Wview_size) + Wcenter_y - (Wview_size * 0.5);
	while ((i < win->max_iterations) && ((x * x) + (y * y) < 4))
	{
		temp = (x * x) - (y * y) + re;
		y = (2 * x * y) + im;
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
				put_pixel_to_image(); //
			}
		}
	}
	del_thread(t);
}

static void				redraw_mandelbrot(t_window *win)
{
	int		i;
	pthread_t	threads[NUM_THREADS];

	i = 0;
	while (i < NUM_THREADS)
	{
		threads[i] = make_thread(win, i, (void*)man_compute_rows);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
		pthread_join(threads[i++], NULL);
	put_image_to_window(/*?*/);
}

void					mandelbrot(t_palette *colors)
{
	t_window	*win;
	float		view[4];

	win = init_window("Mandelbrot", colors);
	reset_mandelbrot(win);
	win->reset_func = reset_mandelbrot;
	win->draw_func = redraw_mandelbrot;
	// set hooks
	mlx_loop();
}
