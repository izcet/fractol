/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:18:50 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:26:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define A (*a)
#define B (*b)

static unsigned char	gcv(unsigned char a, unsigned char b, int v, int r)
{
	float			c1;
	float			c2;

	c1 = ((float)(a) * (float)((float)(r - v) / (float)(r)));
	c2 = (float)((float)(b) * (float)((float)(v) / (float)(r)));
	if ((unsigned char)(c1 + c2) > 255)
		return (255);
	if ((unsigned char)(c1 + c2) < 0)
	{
		ft_putendl("0");
		return (0);
	}
	return ((unsigned char)(c1 + c2));
}

unsigned int			gradient_col(t_col *a, t_col *b, int v, int r)
{
	unsigned char	fa;
	unsigned char	fr;
	unsigned char	fg;
	unsigned char	fb;

	fa = gcv(A.a, B.a, v, r);
	fr = gcv(A.r, B.r, v, r);
	fg = gcv(A.g, B.g, v, r);
	fb = gcv(A.b, B.b, v, r);
	return (get_int_from_chars(fa, fr, fg, fb));
}
