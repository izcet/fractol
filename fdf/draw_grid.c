/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:23:04 by irhett            #+#    #+#             */
/*   Updated: 2017/03/01 01:19:06 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)
#define D (*W.data)
#define P (*p)

/*
** get_window_point
*/

static t_xyzcp	*gwp(unsigned int row, unsigned int col, t_win *win)
{
	t_xyzcp	*p;

	p = init_xyzcp();
	if (!p)
		return (NULL);
	P.x = (W.center_x) + (W.scale * (*D.map3d[row][col]).x);
	P.y = (W.center_y) + (W.scale * (*D.map3d[row][col]).y);
	if (W.true_z)
		P.y -= (W.scale * (*D.map3d[row][col]).z);
	else
		P.y -= (*D.map3d[row][col]).z;
	P.c = (*(D.map[row][col])).c;
	return (p);
}

static void		draw_grid_in_win(t_win *win, unsigned int row, unsigned int col)
{
	t_xyzcp			*p1;

	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			p1 = gwp(row, col, win);
			if (row < D.len - 1)
				draw_line(p1, gwp(row + 1, col, win), win);
			if (col < D.wid - 1)
				draw_line(p1, gwp(row, col + 1, win), win);
			free(p1);
			col++;
		}
		row++;
	}
}

void			draw_grid(t_win *win)
{
	if (win)
		draw_grid_in_win(win, 0, 0);
	else
		ft_error("NULL passed to draw_grid()");
}
