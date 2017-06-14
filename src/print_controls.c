/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:56:40 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 15:00:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	basic_type(int *type, int n, int i, char breaker)
{
	while (i < n && !breaker)
	{
		if (type[i++] > 0)
		{
			ft_putendl("\nBasic Controls:");
			ft_putendl(" - Scroll up/down to zoom in/out");
			ft_putendl(" - Left click to increase iterations");
			ft_putendl(" - Right click to decrease iterations");
			ft_putendl(" - A/S to change color palettes");
			ft_putendl(" - D/F to cycle within color palette");
			breaker = 1;
		}
	}
}

static void	julia_type(int *type, int n, int i, char breaker)
{
	while (i < n && !breaker)
	{
		if (type[i++] == 2)
		{
			ft_putendl("\nJulia Set Type Controls:");
			ft_putendl(" - Q to toggle freeze");
			breaker = 1;
		}
	}
}

static void	sierp_type(int *type, int n, int i, char breaker)
{
	while (i < n && !breaker)
	{
		if (type[i++] == 3)
		{
			ft_putendl("\nSierpinski Set Type Controls:");
			ft_putendl(" - Q to toggle displaying lower iterations");
			breaker = 1;
		}
	}
}

void		print_controls(int *type, int n)
{
	basic_type(type, n, 0, 0);
	julia_type(type, n, 0, 0);
	sierp_type(type, n, 0, 0);
	ft_putendl("");
}
