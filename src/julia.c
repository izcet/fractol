/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 22:55:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define W 		WINDOW_SIZE
#define D		double
#define HALFWIN	(win->size * 0.5)
#define JULIA_X (((D)win->mous->x - (D)(WINDOW_SIZE / 2)) / (D)W)
#define JULIA_Y (((D)win->mous->y - (D)(WINDOW_SIZE / 2))/ (D)W)

static void				reset_julia(t_window *win)
{
	float	view[3];

	view[0] = 3.0;
	view[1] = 0.0;
	view[2] = 0.0;
	set_window_view(win, view);
	win->max_iterations = 32;
	win->p_offset = 0;
	win->p_index = 0;
}

static unsigned char	jul_cp(t_window *win, double re, double im,
		double x, double y)
{
	unsigned char	i;
	double			temp;

	i = 0;
	x = ((x / W) * win->size) + win->center_x - (win->size * 0.5);
	y = ((y / W) * win->size) + win->center_y - (win->size * 0.5);
	while ((i < win->max_iterations) && ((x * x) + (y * y) < 4))
	{
		temp = (x * x) - (y * y) + re;
		y = (2 * x * y) + im;
		x = temp;
		i++;
	}
	return (i);
}

static void				jul_compute_rows(void *thread)
{
	t_thread		*t;
	t_window		*win;
	int				x;
	int				y;
	unsigned int	i;

	t = (t_thread*)thread;
	win = t->win;
	y = ((W / NUM_THREADS) * t->num) - 1;
	while (++y < ((W / NUM_THREADS) * (t->num + 1)))
	{
		x = -1;
		while (++x < W)
		{
			i = jul_cp(win, JULIA_X, JULIA_Y, x, y);
			if (i < win->max_iterations)
			{
				i = select_color(win, i);
				put_pixel(win, x, y, i);
			}
		}
	}
	del_thread(t);
}

static void				redraw_julia(t_window *win)
{
	int		i;
	pthread_t	threads[NUM_THREADS];

	i = 0;
	while (i < NUM_THREADS)
	{
		threads[i] = make_thread(win, i, (void*)jul_compute_rows);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(threads[i++], NULL);
	use_image(win);
}

void					julia(void)
{
	t_window	*win;

	win = init_window("julia");
	reset_julia(win);
	win->reset_func = reset_julia;
	win->draw_func = redraw_julia;
	init_hooks(win, 1);
	mlx_loop(win->mlx);
}
