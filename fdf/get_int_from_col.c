/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_from_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:13:51 by irhett            #+#    #+#             */
/*   Updated: 2017/03/04 17:11:19 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define C (*c)

unsigned int	get_int_from_col(t_col *c)
{
	return (get_int_from_chars(C.a, C.r, C.g, C.b));
}
