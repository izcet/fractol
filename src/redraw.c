/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:32:39 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:49:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	redraw(t_window *win)
{
	void	(*function)(t_window *);

	function = (void (*function)(t_window *))(win->draw_func);
	function(win);
}

void	reset(t_window *win)
{
	void	(*function)(t_window *);

	function = (void (*function)(t_window *))(win->reset_func);
	function(win);
}
