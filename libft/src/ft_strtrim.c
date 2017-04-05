/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:30:08 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 18:48:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	while (ft_isspace(s[--len]))
		;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	if (*s != '\0')
	{
		len = get_len((char*)s);
		str = (char*)malloc(sizeof(char) * (len + 2));
		if (str)
			while (i <= len)
				str[i++] = *(s++);
	}
	else
		str = (char*)malloc(sizeof(char) * 1);
	if (str)
		str[i] = '\0';
	return (str);
}
