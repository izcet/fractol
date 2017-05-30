/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:58:02 by irhett            #+#    #+#             */
/*   Updated: 2017/05/29 21:56:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

# define NUM_THREADS	8
# define WINDOW_SIZE	500
# define NUM_PALETTE	16

// (char*)&i
typedef struct			s_palette
{
		unsigned char	num_colors;
		unsigned int	*colors;
}						t_palette;

typedef struct			s_thread
{
		t_window		*win;
		int				num; // must be zero indexed
}						t_thread;

typedef struct			s_window
{
	void				*mlx;
	void				*ptr;
	float				view_size;
	float				view_center_x;
	float				view_center_y;
	unsigned char		max_iterations;
	unsigned char		p_index;
	unsigned char		p_offset;
	t_palette			*colors;

	// color array for cycling
	void 				*function;
	void				*data;
}						t_window;

typedef struct			s_triangle;
{
	// stuff for triangles
	;
}						t_triangle;

t_window				*init_window(/*  ?  */);
void					set_window_view(t_window *win, float f[4]);
void					del_window(t_window *win);
void					spawn(char *name, t_palette *p);
int						equals(char *whoneeds, char *strcompare);

void					zoom_in(t_window *win, int x, int y);
void					zoom_out(t_window *win, int x, int y);


/*
** FRACTALS **
*/

void					mandelbrot(void);
void					reset_mandelbrot(t_window *win);
void					man_compute_rows(void *thread);
unsigned char			man_compute_point(t_window *win, double r, double i);

void					julia(void);
void					reset_julia(t_window *win);
void					jul_compute_rows(void *thread);
unsigned char			jul_compute_point(t_window *win, double r, double i);

void					serpinski(void);
void					reset_serpinski(t_window *win);
void					ser_compute_rows(void *thread);
unsigned char			ser_compute_point(t_window *win, double r, double i);

void					apollonian(void);
void					reset_apollonian(t_window *win);
void					apo_compute_rows(void *thread);
unsigned char			apo_compute_point(t_window *win, double r, double i);

void					dragon(void);
void					reset_dragon(t_window *win);
void					dra_compute_rows(void *thread);
unsigned char			dra_compute_point(t_window *win, double r, double i);

void					pinwheel(void);
void					reset_pinwheel(t_window *win);
void					pin_compute_rows(void *thread);
unsigned char			pin_compute_point(t_window *win, double r, double i);


/*
** COLORS **
*/

t_palette				*init_colors(void);
void					del_colors(t_palette *p);
unsigned int			select_color(t_window *win, unsigned int iteration);
unsigned int			new_color(char a, char r, char g, char b);

void					izzet_burn(t_palette *p, unsigned char pi);
void					simic_synergy(t_palette *p, unsigned char pi);
void					waroyale(t_palette *p, unsigned char pi);
void					amber(t_palette *p, unsigned char pi);
void					azorius(t_palette *p, unsigned char pi);
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
