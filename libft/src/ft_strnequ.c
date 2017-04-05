/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:50:47 by irhett            #+#    #+#             */
/*   Updated: 2016/11/20 12:08:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (n == 0)
			return (1);
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
		return (0);
	}
	else
	{
		if (s1 == s2)
			return (0);
		return (1);
	}
}
