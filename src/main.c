/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:56:40 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 17:57:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	available_fractals(void)
{
	ft_putendl("The available fractals are:");
	ft_putendl(" - mandelbrot");
/*	ft_putendl(" - julia");
	ft_putendl(" - serpinski");
	ft_putendl(" - apollonian"); // curves/circles?
	ft_putendl(" - dragon");
	ft_putendl(" - pinwheel");*/
}

static void	fractol_error(char *str)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" is not a valid fractal.\n", 2);
}

static int	is_valid(char *str)
{
//	ft_putstr("Checking validity of ");
//	ft_putendl(str);
	if (equals(str, "mandelbrot"))
		return (1);
	/*	if (equals(str, "julia"))
		return (1);
		if (equals(str, "serpinski"))
		return (1);
		if (equals(str, "apollonian"))
		return (1);
		if (equals(str, "dragon"))
		return (1);
		if (equals(str, "pinwheel"))
		return (1);*/
	return (0);
}

int			main(int argc, char **argv)
{
	int			i;
	int			error;

	if (argc < 2)
		return (ft_usage("fractol", "[fractal] ..."));
	i = 0;
	error = 0;
	while (++i < argc)
	{
		ft_strtolower(argv[i]);
		if (is_valid(argv[i]))
			spawn(argv[i]);
		else
		{
			fractol_error(argv[i]);
			error++;
		}
	}
	if (error)
		available_fractals();
	return (0);
}
