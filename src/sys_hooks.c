/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:18:41 by irhett            #+#    #+#             */
/*   Updated: 2017/06/04 14:45:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_window *win)
{
	if (win->changed)
		redraw(win);
	return (0);
}

int		loop_hook(t_window *win)
{
	check_keys(win);
	if (win->changed)
		redraw(win);
	return (0);
}

int		exit_hook(t_window *win)
{
	del_window(win);
	exit(0);
}
