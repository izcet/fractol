/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:50:25 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 15:58:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	print_data_row(int row, t_data *data)
{
	unsigned int	i;
	char			*str;

	i = 0;
	while (i < (*data).wid)
	{
		str = ft_itoa((*(*data).map[row][i]).z);
		ft_putstr(str);
		ft_putchar('\t');
		free(str);
		i++;
	}
	ft_putchar('\n');
}
