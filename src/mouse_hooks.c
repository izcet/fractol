/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:24:19 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 16:32:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define LEFT_CLICK		1
#define RIGHT_CLICK		2
#define MIDDLE_CLICK	3
#define SCROLL_UP		4
#define SCROLL_DOWN		5

int		mouse_press_hook(int button, int x, int y, t_window *win)
{
	if (button == LEFT_CLICK)
	{
		win->max_iterations++;
		if (win->tri)
			win->tri = tri_more_iterations(win->tri);
	}
	else if (button == RIGHT_CLICK)
	{
		win->max_iterations--;
		if (win->tri)
			win->tri = tri_less_iterations(win->tri);
		if (win->max_iterations == 255)
			win->tri = start_triangles(255, 30.0, win);
	}
	else if (button == SCROLL_DOWN)
		zoom_out(win, x, y);
	else if (button == SCROLL_UP)
		zoom_in(win, x, y);
	else
		return (0);
	win->changed = 1;
	return (0);
}

int		mouse_release_hook(int button, int x, int y, t_window *win)
{
	(void)x;
	(void)y;
	(void)button;
	(void)win;
	char *str = ft_itoa(win->max_iterations);
	ft_putstr("\n\nMax iterations is now: ");
	ft_putendl(str);
	free(str);
	return (0);
}

int		motion_hook(int x, int y, t_window *win)
{
	if (!(win->keys->q))
	{
		win->mous->x = x;
		win->mous->y = y;
		win->changed = 1;
	}
	return (0);
}
