/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:46:27 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 17:45:18 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**sub_split(char c, char *tmp, unsigned int num)
{
	unsigned int	x;
	unsigned int	y;
	char			**ans;

	if (!(ans = (char **)malloc(sizeof(char*) * (num + 1))))
		return (NULL);
	x = 0;
	while (x < num)
	{
		y = 0;
		ans[x] = (char*)malloc(sizeof(char) * (ft_wordlen(tmp, c) + 1));
		if (!ans[x])
			return (NULL);
		while (*tmp == c)
			tmp++;
		while ((*tmp != c) && (*tmp != '\0'))
			ans[x][y++] = *(tmp++);
		ans[x++][y] = '\0';
	}
	ans[x] = NULL;
	return (ans);
}

char					**ft_strsplit(char const *s, char c)
{
	char			*tmp;
	unsigned int	num;

	if (!s)
		return (NULL);
	tmp = *((char**)&s);
	num = ft_numwords(tmp, c);
	return (sub_split(c, tmp, num));
}
