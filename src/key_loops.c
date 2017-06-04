/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:55:00 by irhett            #+#    #+#             */
/*   Updated: 2017/06/04 14:36:51 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


int		cycle_color_offset(t_window *win)
{
	if (win->keys->d && !(win->keys->f))
	{
		if (win->p_offset == 0)
			win->p_offset = win->colors[win->p_index].num - 1;
		else
			win->p_offset--;
	}
	else if (win->keys->f && !(win->keys->d))
	{
		win->p_offset++;
		if (win->p_offset == win->colors[win->p_index].num)
			win->p_offset = 0;
	}
	else
		return (0);
	return (1);
}

int		shift_window_position(t_window *win)
{
	char	vertical;
	char	horizontal;

	vertical = 1;
	horizontal = 1;
	if (win->keys->up && !win->keys->down)
		win->center_y += (((win->size * 4) / WINDOW_SIZE));
	else if (win->keys->down && !win->keys->up)
		win->center_y -= (((win->size * 4) / WINDOW_SIZE));
	else
		vertical = 0;
	if (win->keys->right && !win->keys->left)
		win->center_x -= (((win->size * 4) / WINDOW_SIZE));
	else if (win->keys->left && !win->keys->right)
		win->center_x += (((win->size * 4) / WINDOW_SIZE));
	else
		horizontal = 0;
	if (vertical || horizontal)
		return (1);
	return (0);
}

void	check_keys(t_window *win)
{
	if (cycle_color_offset(win))
		win->changed = 1;
	if (shift_window_position(win))
		win->changed = 1;

}
