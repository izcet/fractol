/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:55:34 by irhett            #+#    #+#             */
/*   Updated: 2017/05/27 23:08:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractal_thread(void *passed)
{
	t_view		*v;
	t_thread	*thread;

	thread = (t_thread*)passed;
	v = thread->view;
	// for this threads range of values
	// calculate and modify the pixel
	// pixel will be back on clear screen so don't write black
}

pthread_t		make_thread(t_view *v, int index, int count)
{
	pthread_t	pth;
	t_thread	*thread;

	thread = malloc();
	thread->count = count;
	thread->num = index;
	thread->view = v;
	pthread_create(&pth, NULL, (void*)fractal_thread, thread);
	return (pth);
}

void			thread_fractal(t_view *v)
{
	pthread_t	threads[THREAD_COUNT];
	int			i;

	i = 0;
	while (++i < THREAD_COUNT + 1)
		threads[i - 1] = make_thread(v, i, THREAD_COUNT);
	i = 0;
	while (i < THREAD_COUNT)
		pthread_join(threads[i++], NULL);
}

void			show_fractal(t_view *v)
{
	// for each point do pixel without threading
}
