/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col_1d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:09:32 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 21:34:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

void			del_col_1d_arr(t_col **c, int num_cols)
{
	int		i;

	if (c)
	{
		i = -1;
		while (++i < num_cols)
		{
			if (c[i])
				del_col(c[i]);
			else
				ft_error("Color Pointer in del_col_1d_arr() is NULL");
		}
		free(c);
		c = NULL;
	}
	else
		ft_error("NULL passed to del_col_1d_arr()");
}

t_col			**init_col_1d_arr(int size)
{
	t_col	**c;
	int		i;

	c = (t_col**)malloc(sizeof(t_col*) * size);
	if (!c)
	{
		ft_error("Unable to allocate memory for t_col**");
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		c[i] = init_col();
		if (!c[i])
		{
			del_col_1d_arr(c, i);
			return (NULL);
		}
	}
	return (c);
}

static t_col	**make_default_colors(void)
{
	t_col	**c;

	c = init_col_1d_arr(3);
	if (!c)
		return (NULL);
	c[0] = make_col_from_int(COLOR_MIN);
	if (!c[0])
	{
		del_col_1d_arr(c, 0);
		return (NULL);
	}
	c[1] = make_col_from_int(COLOR_MID);
	if (!c[1])
	{
		del_col_1d_arr(c, 1);
		return (NULL);
	}
	c[2] = make_col_from_int(COLOR_MAX);
	if (!c[2])
	{
		del_col_1d_arr(c, 2);
		return (NULL);
	}
	return (c);
}

static t_col	**make_colors_from_args(int argc, char **argv, int num_valid)
{
	t_col	**c;
	int		i;

	c = init_col_1d_arr(num_valid);
	if (!c)
		return (NULL);
	i = 1;
	while (++i < argc)
	{
		c[i - 2] = make_col_from_str(argv[i]);
		if (!c[i - 2])
		{
			del_col_1d_arr(c, i - 2);
			return (NULL);
		}
	}
	return (c);
}

t_col			**make_col_1d_arr(t_data *data, int argc, char **argv)
{
	int		num_valid;
	int		i;

	i = 1;
	num_valid = 0;
	while (++i < argc)
		if (is_valid_color(argv[i]))
			num_valid++;
	if (num_valid == 0)
	{
		D.num_col = 3;
		return (make_default_colors());
	}
	else
	{
		D.num_col = num_valid;
		return (make_colors_from_args(argc, argv, num_valid));
	}
}
