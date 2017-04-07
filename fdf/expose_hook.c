/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 02:10:53 by irhett            #+#    #+#             */
/*   Updated: 2017/02/28 11:18:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)
#define D (*W.data)

int		expose_hook(void *param)
{
	t_win	*win;

	win = (t_win*)param;
	mlx_clear_window(D.mlx, W.ptr);
	draw_grid(win);
	(void)win;
	return (0);
}
