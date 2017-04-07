/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_win_1d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:30:46 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 21:37:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	del_win_1d_arr(t_win **p, int size, void *mlx)
{
	int		i;

	if (p)
	{
		i = -1;
		while (++i < size)
		{
			if (p[i])
				del_win(p[i], mlx);
			else
				ft_error("Point in del_win_1d_arr() is NULL");
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("NULL passed to del_win_1d_arr()");
}

t_win	**init_win_1d_arr(int size)
{
	t_win	**p;
	int		i;

	p = (t_win**)malloc(sizeof(t_win*) * size);
	if (!p)
	{
		ft_error("Unable to allocate memory for t_win**");
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		p[i] = init_win();
		if (!p[i])
		{
			del_win_1d_arr(p, i, NULL);
			return (NULL);
		}
	}
	return (p);
}
