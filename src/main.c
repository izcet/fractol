/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:56:40 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 17:56:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Fractals I wanted to add
**
** Apollonian Gasket - apollonian
** Dragon Curve - dragon
** Pinwheel Triangles - pinwheel
*/

static void	available_fractals(void)
{
	ft_putendl("\nThe available fractals are:");
	ft_putendl(" - mandelbrot");
	ft_putendl(" - julia");
	ft_putendl(" - badjulia");
	ft_putendl(" - sierpinski");
	ft_putendl(" - mandelcube");
	ft_putendl(" - juliacube");
	ft_putendl("");
}

static void	fractol_error(char *str)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" is not a valid fractal.\n", 2);
}

static int	is_valid(char *str)
{
	if (equals(str, "mandelbrot"))
		return (1);
	if (equals(str, "julia"))
		return (2);
	if (equals(str, "badjulia"))
		return (2);
	if (equals(str, "sierpinski"))
		return (3);
	if (equals(str, "mandelcube"))
		return (1);
	if (equals(str, "juliacube"))
		return (2);
	return (0);
}

int			main(int argc, char **argv)
{
	int			i;
	int			error;
	int			*type;

	if (argc < 2)
		return (ft_usage("fractol", "[fractal] ..."));
	i = 0;
	error = 0;
	type = (int*)malloc(sizeof(argc - 1));
	ft_putendl("");
	while (++i < argc)
	{
		ft_strtolower(argv[i]);
		if ((type[i - 1] = is_valid(argv[i])))
			spawn(argv[i]);
		else
		{
			fractol_error(argv[i]);
			error++;
		}
	}
	if (error)
		available_fractals();
	print_controls(type, argc - 1);
	return (0);
}
