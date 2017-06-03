/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:21:18 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:48:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		del_mouse(t_mouse *m)
{
	if (m)
		free(m);
	else
		ft_error("NULL passed to del_mouse()");
}

t_mouse		*init_mouse(void)
{
	t_mouse		*m;

	m = (t_mouse*)malloc(sizeof(t_mouse));
	if (!m)
	{
		ft_error("Unable to allocate space in init_mouse()");
		return (NULL);
	}
	ft_bzero(m, sizeof(t_mouse));
	return (m);
}

void		del_keys(t_keys *k)
{
	if (k)
		free(k);
	else
		ft_error("NULL passed to del_mouse");
}

t_keys		*init_keys(void)
{
	t_keys	*k;

	k = (t_keys*)malloc(sizeof(t_keys));
	if (!k)
	{
		ft_error("Unable to allocate space in init_keys()");
		return (NULL);
	}
	ft_bzero(k, sizeof(t_keys));
	return (k);
}
