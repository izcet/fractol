/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xyzcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:34:31 by irhett            #+#    #+#             */
/*   Updated: 2017/03/11 00:38:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define P (*p)

void	set_xyzcp(t_xyzcp *p, float x, float y, float z)
{
	if (p)
	{
		P.x = x;
		P.y = y;
		P.z = z;
	}
	else
		ft_error("NULL passed to set_xyzcp()");
}
