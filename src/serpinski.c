/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serpinski.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/07 00:05:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define W 		WINDOW_SIZE
#define D		double
#define HALFWIN	(win->size * 0.5)
#define BJULIAX (((D)win->mous->x / (D)W) * win->size) + win->center_x - HALFWIN
#define BJULIAY (((D)win->mous->y / (D)W) * win->size) + win->center_y - HALFWIN

static void				reset_serpinski(t_window *win)
{
	float	view[3];

	view[0] = 100.0;
	view[1] = 0.0;
	view[2] = 0.0;
	set_window_view(win, view);
	win->max_iterations = 16;
	win->p_offset = 8;
	win->p_index = 0;
}

static void				redraw_serpinski(t_window *win)
{
	use_image(win);
}

void					serpinski(void)
{
	t_window	*win;

	win = init_window("bad julia");
	reset_serpinski(win);
	win->reset_func = reset_serpinski;
	win->draw_func = redraw_serpinski;
	init_hooks(win, 0);
	mlx_loop(win->mlx);
}
