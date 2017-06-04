/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:18:41 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 19:53:17 by irhett           ###   ########.fr       */
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
	if (win->changed)
		redraw(win);
	else
	{
		if (win->keys->d)
		{
			if (win->p_offset == 0)
				win->p_offset = win->colors[win->p_index].num - 1;
			else
				win->p_offset--;
		}
		else if (win->keys->f)
		{
			win->p_offset++;
			if (win->p_offset == win->colors[win->p_index].num)
				win->p_offset = 0;
		}
		win->changed = 1;
	}
	return (0);
}

int		exit_hook(t_window *win)
{
	del_window(win);
	exit(0);
}
