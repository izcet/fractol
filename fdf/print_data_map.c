/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:48:25 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 15:53:07 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	print_data_map(t_data *data)
{
	unsigned int	i;
	char			*str;

	if (0)
	{
		i = 0;
		ft_putstr("Width: ");
		str = ft_itoa((*data).wid);
		ft_putendl(str);
		free(str);
		ft_putstr("Length: ");
		str = ft_itoa((*data).len);
		ft_putendl(str);
		free(str);
		while (i < (*data).len)
			print_data_row(i++, data);
	}
}
