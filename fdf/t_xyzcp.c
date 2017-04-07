/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xyzcp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:14:36 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 21:39:17 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_xyzcp	*init_xyzcp(void)
{
	t_xyzcp	*p;

	p = (t_xyzcp*)malloc(sizeof(t_xyzcp));
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xyzcp");
		return (NULL);
	}
	ft_bzero(p, sizeof(t_xyzcp));
	return (p);
}

void	del_xyzcp(t_xyzcp *p)
{
	if (p)
	{
		if ((*p).c)
			del_col((*p).c);
		ft_bzero(p, sizeof(t_xyzcp));
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyzcp()");
}
