/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:18:37 by irhett            #+#    #+#             */
/*   Updated: 2017/05/29 21:51:15 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	america(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 7));
	p[pi].colors[0] = 0x00FF050A;
	p[pi].colors[1] = 0x00CD050A;
	p[pi].colors[2] = 0x00FFFFFF;
	p[pi].colors[3] = 0x00CDCDCD;
	p[pi].colors[4] = 0x000505C3;
	p[pi].colors[5] = 0x00140AAF;
	p[pi].colors[6] = 0x00202020;
}

void	rgb(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 16));
	p[pi].colors[0] = 0x00FF0000;
	p[pi].colors[1] = 0x0000FF00;
	p[pi].colors[2] = 0x000000FF;
	p[pi].colors[3] = 0x00FF0000;
	p[pi].colors[4] = 0x0000FF00;
	p[pi].colors[5] = 0x000000FF;
	p[pi].colors[6] = 0x00FF0000;
	p[pi].colors[7] = 0x0000FF00;
	p[pi].colors[8] = 0x000000FF;
	p[pi].colors[9] = 0x00FF0000;
	p[pi].colors[10] = 0x0000FF00;
	p[pi].colors[11] = 0x000000FF;
	p[pi].colors[12] = 0x00FF0000;
	p[pi].colors[13] = 0x0000FF00;
	p[pi].colors[14] = 0x000000FF;
	p[pi].colors[15] = 0x00FFFFFF;
}

void	starbucks(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 12));
	p[pi].colors[0] = 0x00FFFFFF;
	p[pi].colors[1] = 0x00DBECDA;
	p[pi].colors[2] = 0x00B7D9B6;
	p[pi].colors[3] = 0x0093C791;
	p[pi].colors[4] = 0x0070B46D;
	p[pi].colors[5] = 0x004CA248;
	p[pi].colors[6] = 0x00288F24;
	p[pi].colors[7] = 0x00057D00;
	p[pi].colors[8] = 0x00156000;
	p[pi].colors[9] = 0x00264400;
	p[pi].colors[10] = 0x00372800;
}

void	rave(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 24));
	p[pi].colors[0] = 0x00000000;
	p[pi].colors[1] = 0x0005FF05;
	p[pi].colors[2] = 0x00000000;
	p[pi].colors[3] = 0x00FF0505;
	p[pi].colors[4] = 0x00000000;
	p[pi].colors[5] = 0x003246FF;
	p[pi].colors[6] = 0x00000000;
	p[pi].colors[7] = 0x00FF0096;
	p[pi].colors[8] = 0x00000000;
	p[pi].colors[9] = 0x00780A8C;
	p[pi].colors[10] = 0x00000000;
	p[pi].colors[11] = 0x0064FA64;
	p[pi].colors[12] = 0x00000000;
	p[pi].colors[13] = 0x00FA6464;
	p[pi].colors[14] = 0x00000000;
	p[pi].colors[15] = 0x00FA7800;
	p[pi].colors[16] = 0x00000000;
	p[pi].colors[17] = 0x00FFFF05;
	p[pi].colors[18] = 0x00000000;
	p[pi].colors[19] = 0x000AFAE6;
	p[pi].colors[20] = 0x00000000;
	p[pi].colors[21] = 0x006464FA;
}
