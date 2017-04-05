/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:33:09 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 18:12:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;
	int		length;

	i = 0;
	if (!str)
		return (NULL);
	length = ft_strlen(str);
	copy = (char*)malloc(sizeof(char) * (length + 1));
	if (copy)
	{
		while (str[i] != '\0')
		{
			copy[i] = str[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}
