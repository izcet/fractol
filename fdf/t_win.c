/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_win.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:57:48 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 21:37:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)

t_win	*init_win(void)
{
	t_win	*win;

	win = (t_win*)malloc(sizeof(t_win));
	if (!win)
	{
		ft_error("Unable to allocate memory for t_win");
		return (NULL);
	}
	ft_bzero(win, sizeof(t_win));
	return (win);
}

void	del_win(t_win *win, void *mlx)
{
	if (win)
	{
		if (W.ptr && mlx)
			mlx_destroy_window(mlx, W.ptr);
		ft_bzero(win, sizeof(t_win));
		free(win);
		win = NULL;
	}
	else
		ft_error("Passed NULL to del_win()");
}
