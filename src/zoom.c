/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:57:08 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:50:46 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_window *win, int x, int y)
{
	float	new_zoom;
	float	zoom_change;
	float	offset_x;
	float	offset_y;

	new_zoom = win->view_size * 0.9;
	zoom_change = new_zoom - win->view_size;
	offset_x = (x * zoom_change) * -1;
	offset_y = (y * zoom_change) * -1;
	win->view_center_x = win->view_center_x + offset_x;
	win->view_center_y = win->view_center_y + offset_y;
	win->view_size = new_zoom;
}

void	zoom_out(t_view *win, int x, int y)
{
	float	new_zoom;
	float	zoom_change;
	float	offset_x;
	float	offset_y;

	new_zoom = win->view_size * 1.1;
	zoom_change = new_zoom - win->view_size;
	offset_x = (x * zoom_change) * -1;
	offset_y = (y * zoom_change) * -1;
	win->view_center_x = win->view_center_x + offset_x;
	win->view_center_y = win->view_center_y + offset_y;
	win->view_size = new_zoom;
}
