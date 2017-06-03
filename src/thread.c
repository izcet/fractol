/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:55:34 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:50:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			del_thread(t_thread *t)
{
	if (t)
		free(t);
	else
		ft_error("NULL passed to del_thread()");
}

pthread_t		make_thread(t_window *win, int index, void *function)
{
	pthread_t	pth;
	t_thread	*thread;

	thread = (t_thread*)malloc(sizeof(t_thread));
	thread->num = index;
	thread->win = win;
	pthread_create(&pth, NULL, function, thread);
	return (pth);
}
