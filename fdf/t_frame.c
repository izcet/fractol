/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_frame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:01:25 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 23:01:38 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define F (*frame)

t_frame	*init_frame(void)
{
	t_frame	*frame;

	frame = (t_frame*)malloc(sizeof(t_frame));
	if (!frame)
	{
		ft_error("Unable to allocate memory for t_frame");
		return (NULL);
	}
	ft_bzero(frame, sizeof(t_frame));
	return (frame);
}

void	del_frame(t_frame *frame, int len, int wid)
{
	if (frame)
	{
		if (F.p)
			del_xyzcp_2d_arr(F.p, len, wid);
		if (F.pos)
			del_xyzcp(F.pos);
		if (F.ang)
			del_xyzcp(F.ang);
		free(frame);
		frame = NULL;
	}
	else
		ft_error("Passed NULL to del_frame()");
}
