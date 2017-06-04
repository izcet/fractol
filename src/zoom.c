/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:57:08 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 17:40:34 by irhett           ###   ########.fr       */
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
	offset_x = (x * zoom_change) * -1;
	offset_y = (y * zoom_change) * -1;
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
	offset_x = (x * zoom_change) * -1;
	offset_y = (y * zoom_change) * -1;
	win->center_x = win->center_x + offset_x;
	win->center_y = win->center_y + offset_y;
	win->size = new_zoom;
}
