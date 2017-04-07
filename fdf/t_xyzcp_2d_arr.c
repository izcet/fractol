/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xyzcp_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:59:24 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:01:19 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void		del_xyzcp_2d_arr(t_xyzcp ***p, unsigned int len, unsigned int wid)
{
	unsigned int	i;

	if (p)
	{
		i = 0;
		while (i < len)
		{
			if (p[i])
				del_xyzcp_1d_arr(p[i], wid);
			else
				ft_error("Row pointer in del_xyzcp_2d_arr() is NULL");
			i++;
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyzcp_2d_arr()");
}

t_xyzcp		***init_xyzcp_2d_arr(unsigned int len, unsigned int wid)
{
	t_xyzcp			***p;
	unsigned int	i;

	p = (t_xyzcp***)malloc(sizeof(t_xyzcp**) * len);
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xyzcp***");
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		p[i] = init_xyzcp_1d_arr(wid);
		if (!p[i])
		{
			del_xyzcp_2d_arr(p, i, wid);
			return (NULL);
		}
		i++;
	}
	return (p);
}
