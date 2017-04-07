/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_col_from_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:13:36 by irhett            #+#    #+#             */
/*   Updated: 2017/03/04 17:09:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static int		value_of(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	return (c - 55);
}

t_col			*make_col_from_str(char *str)
{
	t_col		*c;

	c = init_col();
	if (!c)
		return (NULL);
	str += 2;
	(*c).r += value_of(*(str++)) * 16;
	(*c).r += value_of(*(str++));
	(*c).g += value_of(*(str++)) * 16;
	(*c).g += value_of(*(str++));
	(*c).b += value_of(*(str++)) * 16;
	(*c).b += value_of(*(str++));
	return (c);
}
