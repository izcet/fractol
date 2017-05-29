/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:58:02 by irhett            #+#    #+#             */
/*   Updated: 2017/05/28 17:35:34 by irhett           ###   ########.fr       */
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
/*typedef union		u_color
{
	unsigned int	i;
	unsigned char	c[4];
	// something else for use in image string?
}					t_color;*/

typedef struct		s_palette
{
	unsigned char	num_colors;
	unsigned int	*colors;
}					t_palette;

typedef struct		s_thread
{
	t_window		*win;
	int				num; // must be zero indexed
}					t_thread;

typedef struct		s_window
{
	void			*mlx;
	void			*ptr;
	float			view_size;
	float			view_center_x;
	float			view_center_y;
	unsigned char	max_iterations;
	unsigned char	color_index;
	unsigned char	color_offset;

	// color array for cycling
	void 			*function;
	void			*data;
}					t_window;

typedef struct		s_triangle;
{
	// stuff for triangles
	;
}					t_triangle;

t_window			*init_window(/*  ?  */);
void				set_window_view(t_window *win, float f[4]);
void				del_window(t_window *win);

int					equals(char *whoneeds, char *strcompare);
void				spawn(char *name);i

void				mandelbrot(void);


void				zoom_in(t_window *win, int x, int y);
void				zoom_out(t_window *win, int x, int y);

#endif
