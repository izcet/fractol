/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 21:22:44 by irhett            #+#    #+#             */
/*   Updated: 2017/05/25 22:57:46 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		del_window(t_window *win)
{
	if (win->ptr && win->mlx)
		mlx_destroy_window(win->mlx, win->ptr);
	//if (win->title)
	//	free(win->title);
	//
	//free colors
	ft_bzero(win, sizeof(t_window));
	free(win);
	win = NULL;
}

t_window	*init_window(unsigned int wid, unsigned int len, char *str)
{
	t_window	*win;

	win = (t_window*)malloc(sizeof(t_win));
	if (!win)
	{
		ft_error("Unable to allocate memory for window.");
		return (NULL);
	}
	ft_bzero(win, sizeof(t_window));
	win->mlx = mlx_init();
	win->width = wid;
	win->length = len; // do I want these and not just a macro?
	win->title = str;
	win->ptr = mlx_new_window(win->mlx, wid, len, str);
	// init colors
	return (win);
}

void		set_window_view(t_widow *win, float f[4])
{
	win->view_width = f[0];
	win->view_height = f[1];
	win->view_center_x = f[2];
	win->view_center_y = f[3];
}
