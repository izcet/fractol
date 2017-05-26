/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:31:33 by irhett            #+#    #+#             */
/*   Updated: 2017/05/25 23:05:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	spawn(char *str)
{
	pid_t	pid;

	pid = fork();
	if (!this_pid)
	{
		if (equals(str, "mandelbrot"))
			mandelbrot();
		if (equals(str, "julia"))
			julia();
		if (equals(str, "serpinski"))
			serpinski();
		if (equals(str, "apollonian"))
			apollonian();
		if (equals(str, "dragon"))
			dragon();
		if (equals(str, "pinwheel"))
			pinwheel();
		ft_error("Valid fractal is not spawnable?");
		_exit(0);
	}
}
