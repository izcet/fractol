/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 22:17:59 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 03:26:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_F 3

#define KEY_Z 6
#define KEY_X 7
#define KEY_C 8
#define KEY_V 9

#define KEY_SPACE 49
#define KEY_ESC 53

#define W (*win)
#define D (*W.data)

static void		handle_local_adjustments(t_win *win, int keycode)
{
	if (keycode == KEY_Z)
		W.center_x -= (W.scale / 2);
	else if (keycode == KEY_X)
		W.center_y += (W.scale / 2);
	else if (keycode == KEY_C)
		W.center_y -= (W.scale / 2);
	else if (keycode == KEY_V)
		W.center_x += (W.scale / 2);
	else if (keycode == KEY_SPACE)
	{
		del_xyzcp_2d_arr(D.map3d, D.len, D.wid);
		make_3d_map_from_zcp(W.data);
		W.center_x = W.wid / 2;
		W.center_y = W.len / 2;
		if (D.wid > D.len)
			W.scale = W.wid / (D.wid + 2);
		else
			W.scale = W.len / (D.len + 2);
	}
}

int				key_pressed(int keycode, void *ptr)
{
	t_win	*win;

	win = (t_win*)ptr;
	if (keycode == KEY_ESC)
	{
		del_data(W.data);
		exit(0);
	}
	else if (keycode == KEY_S)
		rotate_grid_x_pos(W.data);
	else if (keycode == KEY_W)
		rotate_grid_x_neg(W.data);
	else if (keycode == KEY_A)
		rotate_grid_y_pos(W.data);
	else if (keycode == KEY_D)
		rotate_grid_y_neg(W.data);
	else if (keycode == KEY_Q)
		rotate_grid_z_pos(W.data);
	else if (keycode == KEY_E)
		rotate_grid_z_neg(W.data);
	else
		handle_local_adjustments(win, keycode);
	return (0);
}
