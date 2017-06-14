/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:50:49 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 13:43:20 by irhett           ###   ########.fr       */
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
	fire(p, 3);
	ice(p, 4);
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

void			del_colors(t_palette *p)
{
	unsigned int	i;

	if (p)
	{
		i = 0;
		while (i < NUM_PALETTE)
		{
			if (p[i].colors)
				free(p[i].colors);
			else
				ft_error("NULL palette found in del_colors()");
			i++;
		}
		free(p);
	}
	else
		ft_error("NULL passed to del_colors()");
}

unsigned int	select_color(t_window *win, unsigned int i)
{
	unsigned int	color;
	unsigned char	palette;
	unsigned char	index;

	palette = win->p_index;
	index = (i + win->p_offset) % (win->colors[palette].num);
	color = win->colors[palette].colors[index];
	return (color);
}

void			init_palette(t_palette *p, unsigned char i, unsigned char n)
{
	p[i].colors = malloc(sizeof(unsigned int) * n);
	p[i].num = n;
}

void			switch_palette(int keycode, t_window *win)
{
	if (keycode == KEY_A)
	{
		if (win->p_index == 0)
			win->p_index = NUM_PALETTE - 1;
		else
			win->p_index--;
		win->changed = 1;
	}
	else
	{
		if (win->p_index == NUM_PALETTE - 1)
			win->p_index = 0;
		else
			win->p_index++;
		win->changed = 1;
	}
}
