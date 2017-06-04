/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:24:19 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 17:48:38 by irhett           ###   ########.fr       */
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
	(void)x;
	(void)y;
	(void)button;
	(void)win;
	return (0);
}

int		mouse_release_hook(int button, int x, int y, t_window *win)
{
	(void)x;
	(void)y;
	(void)button;
	(void)win;
	return (0);
}

int		motion_hook(int x, int y, t_window *win)
{
	(void)x;
	(void)y;
	(void)win;
	return (0);
}
