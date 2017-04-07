/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 15:58:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

static int		cleanup(t_data *data, int ret)
{
	del_data(data);
	return (ret);
}

static void		start_graphics(t_data *data)
{
	print_keys();
	D.num_win = 3;
	D.win = init_win_1d_arr(D.num_win);
	set_win(data, 800, "800 Pixels", D.win[0]);
	set_win(data, 1000, "1000 Pixels", D.win[1]);
	set_win(data, WINDOW_SIZE, "WINDOW_SIZE macro", D.win[2]);
	set_window_hooks(data);
	mlx_loop((*data).mlx);
}

int				main(int argc, char **argv)
{
	t_data	*data;
	t_xyp	*dimen;

	if (argc < 2)
		return (ft_usage(argv[0], " <filename> [color min...max]"));
	data = init_data();
	if (!data)
		return (ft_error("Unable to allocate space for main memory struct."));
	dimen = parse_file(argv[1]);
	if (!dimen)
		return (cleanup(data, 1));
	set_data_xy(data, dimen);
	if (populate_map(data, argv[1]) != 0)
		return (cleanup(data, 1));
	if (set_point_cols(data, argc, argv) != 0)
		return (cleanup(data, 1));
	print_data_map(data);
	if (make_3d_map_from_zcp(data))
		start_graphics(data);
	return (cleanup(data, 0));
}
