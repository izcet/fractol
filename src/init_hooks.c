/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:47:03 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 18:34:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_window *win)
{
	mlx_do_key_autorepeatoff(win->mlx);
	mlx_hook(win->ptr, 2, 0, key_press_hook, win);
	mlx_hook(win->ptr, 3, 0, key_release_hook, win);
	mlx_hook(win->ptr, 4, 0, mouse_press_hook, win);
	mlx_hook(win->ptr, 5, 0, mouse_release_hook, win);
	mlx_hook(win->ptr, 6, 0, motion_hook, win);
	mlx_hook(win->ptr, 12, 0, expose_hook, win);
	mlx_hook(win->ptr, 17, 0, exit_hook, win);
}
