/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/05/27 23:09:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define W win->

void			reset_mandelbrot(t_window *win)
{
	float	view[4];

	view = {2.0, 2.0, 0.0, 0.0};
	set_window_view(win, view);
	win->max_iterations = 25;
	// reset colors;
}

unsigned char	compute_mandelbrot(t_window *win, double real, double imag)
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

void			compute_rows(void *thread)
{
	t_thread		*t;
	t_window		*win;
	int				x;
	int				y;
	unsigned char	i;

	t = (t_thread*)thread;
	win = t->win;
	y = ((WINDOW_SIZE / NUM_THREADS) * t->num) - 1;
	while (++y < ((WINDOW_SIZE / NUM_THREADS) * (t->num + 1)))
	{
		x = -1;
		while (++x < WINDOW_SIZE)
		{
			i = compute_mandelbrot(win, x, y);
			if (i < win->max_iterations)
			{
				select_color();
				put_pixel_to_image();
			}
		}
	}
}

void			mandelbrot(void)
{
	t_window	*win;
	float		view[4];

	// can the title string be modified in action?
	win = init_window(500, 500, "Mandelbrot");
	reset_mandelbrot(win);
	// set hooks
	// set colors
	// set functions for redraw
	mlx_loop();
}
