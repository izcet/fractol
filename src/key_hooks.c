/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:57:43 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 18:58:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	toggle_keys(t_window *win, int keycode, int state)
{
	if (keycode == KEY_W)
		win->keys->w = state;
	else if (keycode == KEY_E)
		win->keys->e = state;
	else if (keycode == KEY_R)
		win->keys->r = state;
	else if (keycode == KEY_D)
		win->keys->d = state;
	else if (keycode == KEY_F)
		win->keys->f = state;
	else if (keycode == KEY_UP)
		win->keys->up = state;
	else if (keycode == KEY_DOWN)
		win->keys->down = state;
	else if (keycode == KEY_LEFT)
		win->keys->left = state;
	else if (keycode == KEY_RIGHT)
		win->keys->right = state;
}

int		key_press_hook(int keycode, t_window *win)
{
	if (keycode == KEY_ESCAPE)
		exit_hook(win);
	else if (keycode == KEY_SPACEBAR)
		reset(win);
	else if (keycode == KEY_A || keycode == KEY_S)
		switch_palette(keycode, win);
	else if (keycode == KEY_Q)
	{
		win->keys->q = !(win->keys->q);
		if (win->tri)
			win->changed = 1;
	}
	else
		toggle_keys(win, keycode, 1);
	return (0);
}

int		key_release_hook(int keycode, t_window *win)
{
	if (keycode == KEY_ESCAPE)
		;
	else if (keycode == KEY_SPACEBAR)
		;
	else if (keycode == KEY_A || keycode == KEY_S)
		;
	else
		toggle_keys(win, keycode, 0);
	return (0);
}
