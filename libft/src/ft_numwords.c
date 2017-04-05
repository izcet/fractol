/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:16 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 16:55:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_numwords(char *str, char del)
{
	unsigned int	num;
	unsigned int	i;

	num = 0;
	i = 0;
	while (str && str[i] != '\0')
	{
		if ((str[i] != del) && ((str[i + 1] == del) || (str[i + 1] == '\0')))
			num++;
		i++;
	}
	return (num);
}
