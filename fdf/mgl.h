/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:42:11 by irhett            #+#    #+#             */
/*   Updated: 2017/03/13 17:13:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_H
# define MGL_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

# define WINDOW_SIZE	1600
# define COLOR_MAX		0x00FF0000
# define COLOR_MID		0x0000FF00
# define COLOR_MIN		0x000000FF
# define ROT_ANGLE		10

# define DTR(x) (x * M_PI / 180.0)
# define RTD(x) (x * 180.0 / M_PI)

typedef	struct			s_color
{
	unsigned char		a;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_col;

typedef struct			s_xypoint
{
	int					x;
	int					y;
}						t_xyp;

typedef	struct			s_zcpoint
{
	int					z;
	t_col				*c;
}						t_zcp;

typedef struct			s_xyzcpoint
{
	float				x;
	float				y;
	float				z;
	t_col				*c;
}						t_xyzcp;

/*
** I think I was going to use this for perspective projection windows
** but for now it does nothing
*/
typedef struct			s_frame
{
	t_xyzcp				***p;
	t_xyzcp				*pos;
	t_xyzcp				*ang;
}						t_frame;

/*
** Unincluded features, to be implemented for perspective projection
**
**	t_xyzcp		*pos;
**	t_xyzcp		*ang;
**	function pointers
*/
typedef struct			s_window
{
	void				*ptr;
	unsigned int		wid;
	unsigned int		len;
	unsigned int		scale;
	unsigned int		center_x;
	unsigned int		center_y;
	char				true_z;
	struct s_data		*data;
}						t_win;

typedef struct			s_data
{
	t_zcp				***map;
	t_xyzcp				***map3d;
	unsigned int		wid;
	unsigned int		len;
	int					z_min;
	int					z_max;
	t_win				**win;
	int					num_win;
	t_col				**col;
	int					num_col;
	t_frame				*frame;
	void				*mlx;
}						t_data;

t_col					*init_col(void);
t_xyp					*init_xyp(void);
t_zcp					*init_zcp(void);
t_xyzcp					*init_xyzcp(void);
t_frame					*init_frame(void);
t_win					*init_win(void);
t_data					*init_data(void);
t_zcp					**init_zcp_1d_arr(unsigned int wid);
t_zcp					***init_zcp_2d_arr(unsigned int l, unsigned int w);
t_xyzcp					**init_xyzcp_1d_arr(unsigned int wid);
t_xyzcp					***init_xyzcp_2d_arr(unsigned int l, unsigned int w);
t_col					**init_col_1d_arr(int size);
t_win					**init_win_1d_arr(int size);

void					del_col(t_col *c);
void					del_xyp(t_xyp *p);
void					del_zcp(t_zcp *p);
void					del_xyzcp(t_xyzcp *p);
void					del_frame(t_frame *grid, int p_rows, int p_cols);
void					del_win(t_win *win, void *mlx);
void					del_data(t_data *data);
void					del_zcp_1d_arr(t_zcp **p, unsigned int wid);
void					del_zcp_2d_arr(t_zcp ***p, unsigned int len,
										unsigned int wid);
void					del_xyzcp_1d_arr(t_xyzcp **p, unsigned int wid);
void					del_xyzcp_2d_arr(t_xyzcp ***p, unsigned int len,
										unsigned int wid);
void					del_col_1d_arr(t_col **c, int size);
void					del_win_1d_arr(t_win **win, int size, void *mlx);

t_col					*make_col_from_chars(char a, char r, char g, char b);
t_col					*make_col_from_int(unsigned int num);
t_col					*make_col_from_str(char *str);
t_col					**make_col_1d_arr(t_data *data, int argc, char **argv);
unsigned int			get_int_from_chars(char a, char r, char g, char b);
unsigned int			get_int_from_col(t_col *c);
int						is_valid_color(char *str);

t_xyp					*make_xyp(int x, int y);
t_zcp					*make_zcp(int z, t_col *c);
t_xyzcp					*make_xyz_from_z(t_data *d, unsigned int r,
										unsigned int c);

t_xyp					*parse_file(char *file);
void					set_z_range(t_data *data);
void					set_data_xy(t_data *data, t_xyp *p);
int						set_point_cols(t_data *data, int argc, char **argv);
int						populate_map(t_data *data, char *file);

t_col					*get_col_from_range(t_data *data, int row, int col);
unsigned int			gradient_col(t_col *a, t_col *b, int n, int val);

void					print_data_map(t_data *data);
void					print_data_row(int row, t_data *data);
void					rotate_point_by_matrix(t_xyzcp *p, t_dub_matrix *t);
void					set_xyzcp(t_xyzcp *p, float x, float y, float z);

void					rot_pox(t_xyzcp *p, double angle);
void					rot_poy(t_xyzcp *p, double angle);
void					rot_poz(t_xyzcp *p, double angle);
void					rot_ppx(t_xyzcp *p, t_xyzcp *offset, double angle);
void					rot_ppy(t_xyzcp *p, t_xyzcp *offset, double angle);
void					rot_ppy(t_xyzcp *p, t_xyzcp *offset, double angle);

int						make_3d_map_from_zcp(t_data *data);
void					draw_isometric(t_win *win);
void					set_win(t_data *d, unsigned int x, char *s, t_win *w);
void					set_window_hooks(t_data *data);
int						key_pressed(int keycode, void *param);
int						mouse_pressed(int button, int x, int y, void *param);
int						expose_hook(void *param);
int						loop_hook(void *param);

void					rotate_grid_x_pos(t_data *data);
void					rotate_grid_x_neg(t_data *data);
void					rotate_grid_y_pos(t_data *data);
void					rotate_grid_y_neg(t_data *data);
void					rotate_grid_z_pos(t_data *data);
void					rotate_grid_z_neg(t_data *data);

void					draw_grid(t_win *win);
void					draw_line(t_xyzcp *p1, t_xyzcp *p2, t_win *win);

void					print_keys(void);

#endif
