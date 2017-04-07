/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 02:10:53 by irhett            #+#    #+#             */
/*   Updated: 2017/02/28 11:18:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define A (*p1)
#define B (*p2)
#define W (*win)
#define D (*W.data)
#define F (float)

static void		draw_ax(t_xyzcp *p1, t_xyzcp *p2, t_win *win)
{
	int				n;
	int				m;
	unsigned int	col;

	n = A.x;
	while (n < B.x)
	{
		col = gradient_col(A.c, B.c, (n - A.x), (B.x - A.x));
		m = (int)(F(F(B.y - A.y) / F(B.x - A.x)) * F(n - A.x)) + A.y;
		mlx_pixel_put(D.mlx, W.ptr, n, m, col);
		n++;
	}
}

static void		draw_bx(t_xyzcp *p1, t_xyzcp *p2, t_win *win)
{
	int				n;
	int				m;
	unsigned int	col;

	n = B.x;
	while (n < A.x)
	{
		col = gradient_col(B.c, A.c, (n - B.x), (A.x - B.x));
		m = (int)(F(F(A.y - B.y) / F(A.x - B.x)) * F(n - B.x)) + B.y;
		mlx_pixel_put(D.mlx, W.ptr, n, m, col);
		n++;
	}
}

static void		draw_ay(t_xyzcp *p1, t_xyzcp *p2, t_win *win)
{
	int				n;
	int				m;
	unsigned int	col;

	n = A.y;
	while (n < B.y)
	{
		col = gradient_col(A.c, B.c, (n - A.y), (B.y - A.y));
		m = (int)(F(F(B.x - A.x) / F(B.y - A.y)) * F(n - A.y)) + A.x;
		mlx_pixel_put(D.mlx, W.ptr, m, n, col);
		n++;
	}
}

static void		draw_by(t_xyzcp *p1, t_xyzcp *p2, t_win *win)
{
	int				n;
	int				m;
	unsigned int	col;

	n = B.y;
	while (n < A.y)
	{
		col = gradient_col(B.c, A.c, (n - B.y), (A.y - B.y));
		m = (int)(F(F(A.x - B.x) / F(A.y - B.y)) * F(n - B.y)) + B.x;
		mlx_pixel_put(D.mlx, W.ptr, m, n, col);
		n++;
	}
}

void			draw_line(t_xyzcp *p1, t_xyzcp *p2, t_win *win)
{
	if (A.x < B.x)
		draw_ax(p1, p2, win);
	else
		draw_bx(p1, p2, win);
	if (A.y < B.y)
		draw_ay(p1, p2, win);
	else
		draw_by(p1, p2, win);
	free(p2);
}
