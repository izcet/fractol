/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:32:39 by irhett            #+#    #+#             */
/*   Updated: 2017/06/03 18:43:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw(t_window *win)
{
	void	(*function)(t_window *);

	function = (void (*)(t_window *))(win->draw_func);
	function(win);
	win->changed = 0;
}

void	reset(t_window *win)
{
	void	(*function)(t_window *);

	function = (void (*)(t_window *))(win->reset_func);
	function(win);
	win->changed = 1;
	redraw(win);
}
