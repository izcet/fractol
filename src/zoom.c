/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:57:08 by irhett            #+#    #+#             */
/*   Updated: 2017/06/05 18:30:29 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_window *win, int x, int y)
{
	float	new_zoom;
	float	zoom_change;
	float	offset_x;
	float	offset_y;

	new_zoom = win->size * 0.9;
	zoom_change = new_zoom - win->size;
	offset_x = (((float)((WINDOW_SIZE / 2) - x) / WINDOW_SIZE) * zoom_change);
	offset_y = (((float)((WINDOW_SIZE / 2) - y) / WINDOW_SIZE) * zoom_change);
	win->center_x = win->center_x + offset_x;
	win->center_y = win->center_y + offset_y;
	win->size = new_zoom;
}

void	zoom_out(t_window *win, int x, int y)
{
	float	new_zoom;
	float	zoom_change;
	float	offset_x;
	float	offset_y;

	new_zoom = win->size * 1.1;
	zoom_change = new_zoom - win->size;
	offset_x = (((float)((WINDOW_SIZE / 2) - x) / WINDOW_SIZE) * zoom_change);
	offset_y = (((float)((WINDOW_SIZE / 2) - y) / WINDOW_SIZE) * zoom_change);
	win->center_x = win->center_x + offset_x;
	win->center_y = win->center_y + offset_y;
	win->size = new_zoom;
}
