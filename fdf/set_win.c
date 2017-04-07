/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:57:48 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 21:37:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)
#define D (*data)

void	set_win(t_data *data, unsigned int range, char *str, t_win *win)
{
	W.wid = range;
	W.len = range;
	if (D.wid > D.len)
		W.scale = range / (D.wid + 2);
	else
		W.scale = range / (D.len + 2);
	W.center_x = (range / 2);
	W.center_y = (range / 2);
	W.true_z = 0;
	W.data = data;
	W.ptr = mlx_new_window(D.mlx, W.wid, W.len, str);
}
