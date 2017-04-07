/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 22:17:59 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 03:26:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)
#define D (*W.data)

int		loop_hook(void *param)
{
	t_win	*win;

	win = (t_win*)param;
	mlx_clear_window(D.mlx, W.ptr);
	draw_grid(win);
	return (0);
}
