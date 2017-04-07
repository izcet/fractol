/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xyzcp_1d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:27:56 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:00:50 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void		del_xyzcp_1d_arr(t_xyzcp **p, unsigned int wid)
{
	unsigned int	i;

	if (p)
	{
		i = 0;
		while (i < wid)
		{
			if (p[i])
				del_xyzcp(p[i]);
			else
				ft_error("Point in del_xyzcp_1d_arr() is NULL");
			i++;
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyzcp_2d_arr()");
}

t_xyzcp		**init_xyzcp_1d_arr(unsigned int wid)
{
	t_xyzcp			**p;
	unsigned int	i;

	p = (t_xyzcp**)malloc(sizeof(t_xyzcp*) * wid);
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xyzcp**");
		return (NULL);
	}
	i = 0;
	while (i < wid)
	{
		p[i] = init_xyzcp();
		if (!p[i])
		{
			del_xyzcp_1d_arr(p, i);
			return (NULL);
		}
		i++;
	}
	return (p);
}
