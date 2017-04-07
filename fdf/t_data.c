/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:12:59 by irhett            #+#    #+#             */
/*   Updated: 2017/03/07 10:58:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

void	del_data(t_data *data)
{
	if (data)
	{
		if (D.win)
			del_win_1d_arr(D.win, D.num_win, D.mlx);
		if (D.map)
			del_zcp_2d_arr(D.map, D.len, D.wid);
		if (D.map3d)
			del_xyzcp_2d_arr(D.map3d, D.len, D.wid);
		if (D.col)
			del_col_1d_arr(D.col, D.num_col);
		if (D.mlx)
			free(D.mlx);
		ft_bzero(data, sizeof(t_data));
		free(data);
		data = NULL;
	}
	else
		ft_error("Passed NULL to del_data()");
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
	{
		ft_error("Unable to allocate memory for t_data");
		return (NULL);
	}
	ft_bzero(data, sizeof(t_data));
	D.mlx = mlx_init();
	return (data);
}
