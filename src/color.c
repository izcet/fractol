/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:50:49 by irhett            #+#    #+#             */
/*   Updated: 2017/05/29 15:53:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_palette		*init_colors(void)
{
	t_palette	*p;

	p = (t_palette*)malloc(sizeof(t_palette) * NUM_PALETTE);
	if (!p)
	{
		ft_error("Unable to allocate memory for t_palette");
		return (NULL);
	}
	izzet_burn(p, 0);
	simic_synergy(p, 1);
	waroyale(p, 2);
	amber(p, 3);
	azorius(p, 4);
	vendetta(p, 5);
	attednev(p, 6);
	tmobile(p, 7);
	bloody_princess(p, 8);
	jeskai(p, 9);
	absurdity(p, 10);
	forgotten(p, 11);
	america(p, 12);
	rgb(p, 13);
	starbucks(p, 14);
	rave(p, 15);
	return (p);
}

unsigned int	new_color(char a, char r, char g, char b)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char)b;
	color += ((unsigned char)g * 256);
	color += ((unsigned char)r * 256 * 256);
	color += ((unsigned char)a * 256 * 256 * 256);
	return (color);
}