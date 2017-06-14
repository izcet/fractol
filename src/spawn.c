/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:31:33 by irhett            #+#    #+#             */
/*   Updated: 2017/06/14 00:51:44 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	spawn(char *str)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		if (equals(str, "mandelbrot"))
			mandelbrot();
		if (equals(str, "julia"))
			julia();
		if (equals(str, "badjulia"))
			badjulia();
		if (equals(str, "sierpinski"))
			sierpinski();
		if (equals(str, "mandelcube"))
			mandelcube();
		if (equals(str, "juliacube"))
			juliacube();
		ft_error("Valid fractal is not spawnable?");
		_exit(0);
	}
}
