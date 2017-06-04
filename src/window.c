/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 21:22:44 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 17:57:26 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		del_window(t_window *win)
{
	if (win)
	{
		if (win->ptr && win->mlx)
			mlx_destroy_window(win->mlx, win->ptr);
		if (win->colors)
			del_colors(win->colors);
		if (win->keys)
			del_keys(win->keys);
		if (win->mous)
			del_mouse(win->mous);
		if (win->image)
			del_image(win);
		ft_bzero(win, sizeof(t_window));
		free(win);
		win = NULL;
	}
	else
		ft_error("NULL passed to del_window()");
}

t_window	*init_window(char *str)
{
	t_window	*win;

	win = (t_window*)malloc(sizeof(t_window));
	if (!win)
	{
		ft_error("Unable to allocate memory for window.");
		return (NULL);
	}
	ft_bzero(win, sizeof(t_window));
	win->mlx = mlx_init();
	win->ptr = mlx_new_window(win->mlx, WINDOW_SIZE, WINDOW_SIZE, str);
	win->colors = init_colors();
	win->keys = init_keys();
	win->mous = init_mouse();
	init_image(win);
	win->changed = 1;
	return (win);
}

void		set_window_view(t_window *win, float f[3])
{
	win->size = f[0];
	win->center_x = f[1];
	win->center_y = f[2];
}
