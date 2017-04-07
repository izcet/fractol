/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 22:17:59 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 03:26:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	print_keys(void)
{
	ft_putendl("Q and E to rotate on the Z axis.");
	ft_putendl("W and S to rotate on the X axis.");
	ft_putendl("A and D to rotate on the Y axis.");
	ft_putstr("\nZXCV to shift the grid along the X and Y axes. ");
	ft_putendl("(Local window only)");
	ft_putendl("Scroll mouse up/down to zoom in/out. (Local window only)");
	ft_putendl("Middle click to set the grid center. (Local window only)");
	ft_putendl("Right click to set 'true scale' on. (Local window only)");
	ft_putendl("Spacebar to reset view settings. (Local window only)");
}
