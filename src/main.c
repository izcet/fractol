/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:56:40 by irhett            #+#    #+#             */
/*   Updated: 2017/04/06 18:24:37 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define NUM_FRACTALS 6

void	available_fractals(void)
{
	int		i;

	ft_putendl("The available fractals are:");
	ft_putendl(" - mandelbrot");
	ft_putendl(" - julia");
	ft_putendl(" - serpinski");
	ft_putendl(" - apollonian");
	ft_putendl(" - dragon");
	ft_putendl(" - pinwheel");
}

void	fractol_error(char *str)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" is not a valid fractal.\n");
	available_fractals();
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		return (ft_usage("fractol", "[fractal]..."));
	i = 0;
	while (++i < argc)
	{
		if (is_valid(argv[i]))
		{
			; // fork and do fractal stuff with it
		}
		else
			fractol_error(argv[i]);
	}
	return (0);
}
