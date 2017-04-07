/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:00:45 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:54:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

static int		point_set_color(t_zcp *p, char *str)
{
	(*p).c = make_col_from_str(str + 1);
	return (9);
}

static void		fill_row(t_zcp **p, unsigned int wid, char *str)
{
	unsigned int	i;

	i = 0;
	while (i < wid)
	{
		while (*str == ' ')
			str++;
		(*p[i]).z = ft_atoi(str);
		while ((ft_isdigit(*str)) || (*str == '-'))
			str++;
		if (*str == ',')
			str += point_set_color(p[i], str);
		i++;
	}
}

static t_zcp	***populate_zcp_2d_arr(int fd, t_data *data)
{
	t_zcp			***p;
	char			*line;
	unsigned int	row;
	int				br;

	p = init_zcp_2d_arr(D.len, D.wid);
	if (!p)
		return (NULL);
	row = 0;
	while (row < D.len)
	{
		br = get_next_line(fd, &line);
		if (br < 0)
		{
			del_zcp_2d_arr(p, row, D.wid);
			return (NULL);
		}
		fill_row(p[row], D.wid, line);
		free(line);
		row++;
	}
	return (p);
}

int				populate_map(t_data *data, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("Unable to reopen file."));
	if (!data)
		return (ft_error("NULL pointer passed to populate_map()"));
	D.map = populate_zcp_2d_arr(fd, data);
	close(fd);
	if (!D.map)
		return (1);
	return (0);
}
