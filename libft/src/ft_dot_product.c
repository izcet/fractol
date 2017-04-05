/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:37:58 by irhett            #+#    #+#             */
/*   Updated: 2017/03/09 21:45:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_dot_product(int *a, int *b, unsigned int len)
{
	unsigned int	i;
	int				ret;

	ret = 0;
	if (a && b)
	{
		i = 0;
		while (i < len)
		{
			ret += a[i] * b[i];
			i++;
		}
	}
	else
		ft_error("Null pointers passed to int_dot_product()");
	return (ret);
}

double	dub_dot_product(double *a, double *b, unsigned int len)
{
	unsigned int	i;
	double			ret;

	ret = 0;
	if (a && b)
	{
		i = 0;
		while (i < len)
		{
			ret += a[i] * b[i];
			i++;
		}
	}
	else
		ft_error("Null pointers passed to int_dot_product()");
	return (ret);
}
