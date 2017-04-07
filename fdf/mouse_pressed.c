/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:09:14 by irhett            #+#    #+#             */
/*   Updated: 2017/03/01 20:16:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)
#define D (*W.data)

#define SCROLL_UP 4
#define SCROLL_DOWN 5

int		mouse_pressed(int button, int x, int y, void *param)
{
	t_win			*win;

	win = (t_win*)param;
	if (button == SCROLL_UP)
		W.scale += ((W.scale / 2) + 1);
	else if (button == SCROLL_DOWN && W.scale > 1)
		W.scale -= ((W.scale / 10) + 1);
	else if (button == 3)
	{
		W.center_x = x;
		W.center_y = y;
	}
	else if (button == 2)
		W.true_z ^= 1;
	return (0);
}
