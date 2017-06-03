/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:57:43 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:48:38 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	toggle_keys(t_window *win, int keycode, int state)
{
	if (keycode == KEY_Q)
		win->keys->q = state;
	else if (keycode == KEY_W)
		win->keys->w = state;
	else if (keycode == KEY_E)
		win->keys->e = state;
	else if (keycode == KEY_R)
		win->keys->r = state;
	else if (keycode == KEY_A)
		win->keys->a = state;
	else if (keycode == KEY_S)
		win->keys->s = state;
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
	{
		del_window(win);
		exit(0);
	}
	else if (keycode == KEY_SPACE)
	{
		reset(t_window *win);
	}
	else
		toggle_keys(win, keycode, 1);
}

int		key_release_hook(int keycode, t_window *win)
{
	if (keycode == KEY_ESCAPE)
	{
		exit(1);
	}
	else if (keycode == KEY_SPACE)
	{
		;
	}
	else
		toggle_keys(win, keycode, 0);
}
