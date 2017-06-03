/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:18:41 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:50:05 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_window *win)
{
	if (win->changed)
		; // redraw window
	return (0);
}

int		loop_hook(t_window *win)
{
	if (win->changed)
		; // redraw window
	else
	{
		; //check pressed keys and mouses
	}
	return (0);
}

int		exit_hook(t_window *win)
{
	del_window(win);
	exit(0);
}
