/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:47:03 by irhett            #+#    #+#             */
/*   Updated: 2017/06/04 22:00:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_window *win, int track_mouse)
{
	mlx_do_key_autorepeatoff(win->mlx);
	mlx_hook(win->ptr, 2, 0, key_press_hook, win);
	mlx_hook(win->ptr, 3, 0, key_release_hook, win);
	mlx_hook(win->ptr, 4, 0, mouse_press_hook, win);
	mlx_hook(win->ptr, 5, 0, mouse_release_hook, win);
	if (track_mouse)
		mlx_hook(win->ptr, 6, 0, motion_hook, win);
	mlx_hook(win->ptr, 12, 0, expose_hook, win);
	mlx_hook(win->ptr, 17, 0, exit_hook, win);
	mlx_loop_hook(win->mlx, loop_hook, win);
}
