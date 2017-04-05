/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_concat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:05:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/15 18:00:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*gnl_concat(char *s1, char *s2, int free1, int free2)
{
	int		len1;
	int		len2;
	char	*ans;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ans)
		return (NULL);
	len1 = -1;
	len2 = -1;
	while (s1[++len1])
		ans[len1] = s1[len1];
	while (s2[++len2])
		ans[len1 + len2] = s2[len2];
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	ans[len1 + len2] = '\0';
	return (ans);
}
