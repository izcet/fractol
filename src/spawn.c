/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:31:33 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 17:55:43 by irhett           ###   ########.fr       */
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
	/*	if (equals(str, "julia"))
			julia(p);
		if (equals(str, "serpinski"))
			serpinski(p);
		if (equals(str, "apollonian"))
			apollonian(p);
		if (equals(str, "dragon"))
			dragon(p);
		if (equals(str, "pinwheel"))
			pinwheel(p);*/
		ft_error("Valid fractal is not spawnable?");
		_exit(0);
	}
}
