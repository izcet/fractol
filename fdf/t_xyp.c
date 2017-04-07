/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xyp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:46:28 by irhett            #+#    #+#             */
/*   Updated: 2017/03/09 19:47:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	del_xyp(t_xyp *p)
{
	if (p)
	{
		ft_bzero(p, sizeof(t_xyp));
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyp()");
}

t_xyp	*init_xyp(void)
{
	t_xyp	*p;

	p = (t_xyp*)malloc(sizeof(t_xyp));
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xyp");
		return (NULL);
	}
	ft_bzero(p, sizeof(t_xyp));
	return (p);
}
