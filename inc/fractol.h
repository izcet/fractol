/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:58:02 by irhett            #+#    #+#             */
/*   Updated: 2017/05/25 23:08:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define THREADS	8
# define PIXEL_WID	500
# define PIXEL_LEN	500

// (char*)&i
typedef union		u_color
{
	unsigned int	i;
	unsigned char	c[4];
	// something else for use in image string?
}					t_color;


// do I want to remove width and length and just always have the square macro?
typedef struct		s_window
{
	void			*mlx;
	void			*ptr;
	char			*title;
	unsigned int	width;
	unsigned int	height;
	float			view_width;
	float			view_height;
	float			view_center_x;
	float			view_center_y;
	unsigned char	max_iterations;

	// color array for cycling
	void 			*function;
	void			*data;
}					t_window;

typedef struct		s_line;
{

int					equals(char *whoneeds, char *strcompare);
void				spawn(char *name);

t_window			*init_window(/*  ?  */);
void				set_window_view(t_window *win, float f[4]);
void				del_window(t_window *win);

void				mandelbrot(void);

#endif
