/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:46:00 by irhett            #+#    #+#             */
/*   Updated: 2017/05/25 23:03:41 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_mandelbrot(t_window *win)
{
	float	view[4];

	view = {2.0, 2.0, 0.0, 0.0};
	set_window_view(win, view);
	win->max_iterations = 5;
	win->max_iterations = 5;
	// reset colors;
}

void	mandelbrot(void)
{
	t_window	*win;
	float		view[4];

	// can the title string be modified in action?
	win = init_window(500, 500, "Mandelbrot");
	view = {2.0, 2.0, 0.0, 0.0};
	set_window_view(win, view);
	// set hooks
	// set colors
	// set functions for redraw
	mlx_loop();
}
	
