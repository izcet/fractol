/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:56:40 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:48:44 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	available_fractals(void)
{
	int		i;

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
	ft_putstr_fd("\" is not a valid fractal.\n");
}

static int	is_valid(char *str)
{
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
	t_palette	*p;

	if (argc < 2)
		return (ft_usage("fractol", "[fractal] ..."));
	i = 0;
	error = 0;
	p = init_colors();
	while (++i < argc)
	{
		if (is_valid(ft_strtolower(argv[i])))
			spawn(argv[i], p);
		else
		{
			fractol_error(argv[i]);
			error++;
		}
	}
	if (error)
		available_fractals();
	del_colors(p);
	return (0);
}
