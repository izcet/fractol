/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:02:51 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 13:40:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define P (*p)

static int		parse_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

static int		get_num(char *str)
{
	int		num;

	num = 0;
	str += parse_space(str);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		while (*str && ft_isdigit(*str))
			str++;
		if (*str == ',')
		{
			if (!is_valid_color((++str)))
				return (0);
			str += 8;
		}
		num++;
		if (*str && !ft_isspace(*str))
			return (0);
		str += parse_space(str);
	}
	return (num);
}

static t_xyp	*scan_file(int fd, t_xyp *p)
{
	int		ret;
	int		error;
	char	*line;

	error = 0;
	while (((ret = get_next_line(fd, &line)) > 0) && (!error))
	{
		if (P.y == 0)
			P.x = get_num(line);
		if (P.x <= 0 || (P.y > 0 && (P.x != get_num(line))))
			error = 1;
		free(line);
		(P.y)++;
	}
	if (ret < 0 || error)
	{
		ft_error("Invalid file.");
		del_xyp(p);
		return (NULL);
	}
	return (p);
}

t_xyp			*parse_file(char *file)
{
	int		fd;
	t_xyp	*dimensions;

	dimensions = init_xyp();
	if (!dimensions)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Unable to open file.");
		return (NULL);
	}
	dimensions = scan_file(fd, dimensions);
	close(fd);
	return (dimensions);
}
