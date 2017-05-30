/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/05/29 22:30:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define W win->

void			reset_mandelbrot(t_window *win)
{
	float	view[4];

	view = {2.0, 2.0, 0.0, 0.0};
	set_window_view(win, view);
	win->max_iterations = 16;
	win->p_offset = 0;
	win->p_index = 0;
}

unsigned char	man_compute_point(t_window *win, double real, double imag)
{
	unsigned char	i;
	double			x;
	double			y;
	double			temp;

	i = 0;
	x = 0.0;
	y = 0.0;
	real = ((real / WINDOW_SIZE) * Wview_size) + Wcenter_x - (Wview_size * 0.5);
	imag = ((imag / WINDOW_SIZE) * Wview_size) + Wcenter_y - (Wview_size * 0.5);
	while ((i < win->max_iterations) && ((x * x) + (y * y) < 4))
	{
		temp = (x * x) - (y * y) + real;
		y = (2 * x * y) + imag;
		x = temp;
		i++;
	}
	return (i);
}

void			man_compute_rows(void *thread)
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
				i = select_color(t_win, i); //
				put_pixel_to_image(); //
			}
		}
	}
}

void			mandelbrot(t_palette *colors)
{
	t_window	*win;
	float		view[4];

	win = init_window("Mandelbrot", colors);
	reset_mandelbrot(win);
	// set hooks
	// set functions for redraw
	mlx_loop();
}
