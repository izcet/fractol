/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:58:02 by irhett            #+#    #+#             */
/*   Updated: 2017/06/09 12:59:15 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "mlx_keys_macos.h"
# include <math.h>
# include <pthread.h>

# define WINDOW_SIZE	1024
# define NUM_THREADS	20	
# define NUM_PALETTE	16

// (char*)&i
typedef struct			s_palette
{
		unsigned char	num;
		unsigned int	*colors;
}						t_palette;

typedef struct			s_keys
{
	char				a;
	char				s;
	char				d;
	char				f;
	char				q;
	char 				w;
	char				e;
	char				r;
	char				up;
	char				down;
	char				left;
	char				right;
	char				space;
}						t_keys;

typedef struct			s_mouse
{
	int					x;
	int					y;
	char				left;
	char				right;
	char				center;
	char				scroll_up;
	char				scroll_down;
}						t_mouse;

typedef struct			s_image
{
	void				*ptr;
	unsigned int		*pixels;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_window
{
	void				*mlx;
	void				*ptr;
	float				size;
	float				center_x;
	float				center_y;
	unsigned char		max_iterations;
	unsigned char		p_index;
	unsigned char		p_offset;
	t_palette			*colors;
	t_keys				*keys;
	t_mouse				*mous;
	t_image				*image;
	int					changed:1;
	void				*reset_func;
	void				*draw_func;
	struct s_triangle	*tri;
}						t_window;

typedef struct			s_thread
{
	t_window			*win;
	int					num;
}						t_thread;

typedef struct			s_xy
{
	float				x;
	float				y;
}						t_xy;

typedef struct			s_triangle
{
	t_xy				*p1;
	t_xy				*p2;
	t_xy				*p3;
	struct s_triangle	*t1;
	struct s_triangle	*t2;
	struct s_triangle	*t3;
	t_window			*win;
	unsigned char		i;
}						t_riangle;

t_window				*init_window(char *title);
void					set_window_view(t_window *win, float f[3]);
void					del_window(t_window *win);

t_mouse					*init_mouse(void);
void					del_mouse(t_mouse *m);
t_keys					*init_keys(void);
void					del_keys(t_keys *k);

void					init_image(t_window *win);
void					reset_image(t_window *win);
void					use_image(t_window *win);
void					del_image(t_window *win);
void					put_pixel(t_window *win, int x, int y, unsigned int c);

pthread_t				make_thread(t_window *win, int index, void *function);
void					del_thread(t_thread *t);

void					spawn(char *name);
int						equals(char *whoneeds, char *strcompare);


/*
** FRACTALS **
*/

void					mandelbrot(void);
void					julia();
void					badjulia();
void					sierpinski();
//void					apollonian();
//void					dragon();
//void					pinwheel();

/*
** TRIANGLES **
*/
t_riangle				*init_tri(unsigned char i, t_xy *p[3], t_window *w);
void					del_tri(t_riangle *t);
void					fill_triangle(t_xy *a, t_xy *b, t_xy *c, t_window *win,
		unsigned int i);
void					fill_midpoints(t_riangle *t);
void					draw_triangles(t_riangle *t);
void					del_children(t_riangle *t);

void					tri_spawn_children(t_riangle *t);
t_riangle				*start_triangles(unsigned char i, float l, t_window *w);
t_riangle				*tri_more_iterations(t_riangle *t);
t_riangle				*tri_less_iterations(t_riangle *t);

t_xy					*init_xy(double x, double y);
void					del_xy(t_xy *p);
t_xy					*get_x_intercept(t_xy *top, t_xy *bottom, float y);
t_xy					*get_midpoint(t_xy *a, t_xy *b);
t_xy					*xy_copy_of(t_xy *point);



/*
** HOOKS **
*/

void					init_hooks(t_window *win, int track_mouse);

int						key_press_hook(int keycode, t_window *win);
int						key_release_hook(int keycode, t_window *win);
void					toggle_keys(t_window *win, int keycode, int state);

int						mouse_press_hook(int button, int x, int y, t_window *w);
int						mouse_release_hook(int b, int x, int y, t_window *w);
int						motion_hook(int x, int y, t_window *win);

int						expose_hook(t_window *win);
int						exit_hook(t_window *win);
int						loop_hook(t_window *win);

void					check_keys(t_window *win);
int						cycle_color_offset(t_window *win);
int						shift_window_position(t_window *win);


void					zoom_in(t_window *win, int x, int y);
void					zoom_out(t_window *win, int x, int y);

void					redraw(t_window *win);
void					reset(t_window *win);

/*
** COLORS **
*/

t_palette				*init_colors(void);
void					del_colors(t_palette *p);
unsigned int			select_color(t_window *win, unsigned int iteration);
void					switch_palette(int keycode, t_window *win);
unsigned int			new_color(char a, char r, char g, char b);

void					izzet_burn(t_palette *p, unsigned char pi);
void					simic_synergy(t_palette *p, unsigned char pi);
void					waroyale(t_palette *p, unsigned char pi);
void					fire(t_palette *p, unsigned char pi);
void					ice(t_palette *p, unsigned char pi);
void					vendetta(t_palette *p, unsigned char pi);
void					attednev(t_palette *p, unsigned char pi);
void					tmobile(t_palette *p, unsigned char pi);
void					bloody_princess(t_palette *p, unsigned char pi);
void					jeskai(t_palette *p, unsigned char pi);
void					absurdity(t_palette *p, unsigned char pi);
void					forgotten(t_palette *p, unsigned char pi);
void					america(t_palette *p, unsigned char pi);
void					rgb(t_palette *p, unsigned char pi);
void					starbucks(t_palette *p, unsigned char pi);
void					rave(t_palette *p, unsigned char pi);

#endif
