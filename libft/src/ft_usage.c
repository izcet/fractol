/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:58:33 by irhett            #+#    #+#             */
/*   Updated: 2017/04/06 18:07:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_usage(char *exec_name, char *args)
{
	ft_putstr("Usage: ");
	ft_putstr(exec_name);
	ft_putchar(' ');
	ft_putendl(args);
	return (0);
}
