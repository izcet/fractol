/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:23:07 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:27:05 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static int	is_hex(char c)
{
	if (ft_isdigit(c))
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int			is_valid_color(char *str)
{
	int		i;

	if (*(str++) != '0')
		return (0);
	if (*(str++) != 'x')
		return (0);
	i = -1;
	while (++i < 6)
		if (!is_hex(str[i]))
			return (0);
	return (1);
}
