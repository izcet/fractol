/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:44:44 by irhett            #+#    #+#             */
/*   Updated: 2017/03/04 21:21:56 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_col	*init_col(void)
{
	t_col	*c;

	c = (t_col*)malloc(sizeof(t_col));
	if (!c)
	{
		ft_error("Unable to allocate memory for t_col");
		return (NULL);
	}
	ft_bzero(c, sizeof(t_col));
	return (c);
}

void	del_col(t_col *c)
{
	if (c)
	{
		ft_bzero(c, sizeof(t_col));
		free(c);
		c = NULL;
	}
	else
		ft_error("Passed NULL to del_c()");
}
