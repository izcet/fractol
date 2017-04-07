/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_col_from_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:13:27 by irhett            #+#    #+#             */
/*   Updated: 2017/03/04 17:09:14 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_col	*make_col_from_int(unsigned int num)
{
	t_col	*col;

	col = init_col();
	if (!col)
		return (NULL);
	(*col).b = (num % 256);
	num = num / 256;
	(*col).g = (num % 256);
	num = num / 256;
	(*col).r = (num % 256);
	num = num / 256;
	(*col).a = (num % 256);
	return (col);
}
