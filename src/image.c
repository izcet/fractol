/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:33:34 by irhett            #+#    #+#             */
/*   Updated: 2017/06/13 14:58:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_image(t_window *win)
{
	t_image		*i;

	i = win->image;
	i->ptr = mlx_new_image(win->mlx, WINDOW_SIZE, WINDOW_SIZE);
	i->pixels = (unsigned int*)mlx_get_data_addr(i->ptr, &(i->bits_per_pixel),
			&(i->size_line), &(i->endian));
}

void		init_image(t_window *win)
{
	t_image		*i;

	if (!win)
		ft_error("NULL passed to init_image()");
	else
	{
		i = (t_image*)malloc(sizeof(t_image));
		if (!i)
		{
			ft_error("Unable to allocate memory in init_image()");
			win->image = NULL;
		}
		else
		{
			win->image = i;
			reset_image(win);
		}
	}
}

void		use_image(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->ptr, win->image->ptr, 0, 0);
	mlx_destroy_image(win->mlx, win->image->ptr);
	reset_image(win);
}

void		del_image(t_window *win)
{
	if (win && win->image)
	{
		mlx_destroy_image(win->mlx, win->image->ptr);
		free(win->image);
	}
	else
		ft_error("NULL passed to del_image()");
}

void		put_pixel(t_window *win, int x, int y, unsigned int color)
{
	int		i;

	i = (x + ((y * win->image->size_line) / 4));
	if (i >= 0 && i < (WINDOW_SIZE * WINDOW_SIZE))
		win->image->pixels[i] = color;
}
