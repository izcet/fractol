/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_xy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:20:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/02 19:22:47 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)
#define P (*p)

void	set_data_xy(t_data *data, t_xyp *p)
{
	if (data && p)
	{
		D.wid = P.x;
		D.len = P.y;
		del_xyp(p);
	}
	else
		ft_error("NULL parameter(s) passed to set_data_xy()");
}
