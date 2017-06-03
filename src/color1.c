/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:18:37 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:47:30 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	izzet_burn(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x00A00A1E;
	p[pi].colors[1] = 0x00930A28;
	p[pi].colors[2] = 0x00860A32;
	p[pi].colors[3] = 0x00790A3C;
	p[pi].colors[4] = 0x006C0A46;
	p[pi].colors[5] = 0x005F0A50;
	p[pi].colors[6] = 0x00520A5A;
	p[pi].colors[7] = 0x00460A64;
	p[pi].colors[8] = 0x004B0A69;
	p[pi].colors[9] = 0x00450B6C;
	p[pi].colors[10] = 0x003F0C70;
	p[pi].colors[11] = 0x003A0D74;
	p[pi].colors[12] = 0x00340E78;
	p[pi].colors[13] = 0x002F0F7C;
	p[pi].colors[14] = 0x00291080;
	p[pi].colors[15] = 0x00241184;
	p[pi].colors[16] = 0x001E1288;
	p[pi].colors[17] = 0x0019148C;
	p[pi].colors[18] = 0x001E1987;
	p[pi].colors[19] = 0x00652E5A;
	p[pi].colors[20] = 0x00AD442D;
	p[pi].colors[21] = 0x00F55A00;
	p[pi].colors[22] = 0x00FA5F00;
	p[pi].colors[23] = 0x00FF6400;
}

void	simic_synergy(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x001E5A1E;
	p[pi].colors[1] = 0x001C5628;
	p[pi].colors[2] = 0x001A5232;
	p[pi].colors[3] = 0x00184E3C;
	p[pi].colors[4] = 0x00164A46;
	p[pi].colors[5] = 0x00144650;
	p[pi].colors[6] = 0x000F4650;
	p[pi].colors[7] = 0x000D3F52;
	p[pi].colors[8] = 0x000C3854;
	p[pi].colors[9] = 0x000B3256;
	p[pi].colors[10] = 0x000A2B58;
	p[pi].colors[11] = 0x0009245B;
	p[pi].colors[12] = 0x00081E5D;
	p[pi].colors[13] = 0x0007175F;
	p[pi].colors[14] = 0x00061061;
	p[pi].colors[15] = 0x00050A64;
	p[pi].colors[16] = 0x000A0F5F;
	p[pi].colors[17] = 0x003A3254;
	p[pi].colors[18] = 0x006A5549;
	p[pi].colors[19] = 0x009A783E;
	p[pi].colors[20] = 0x00CA9B33;
	p[pi].colors[21] = 0x00FABE28;
	p[pi].colors[22] = 0x00FFB428;
	p[pi].colors[23] = 0x00FFA528;
}

void	waroyale(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x000A3278;
	p[pi].colors[1] = 0x000F2D79;
	p[pi].colors[2] = 0x0015287B;
	p[pi].colors[3] = 0x001B247D;
	p[pi].colors[4] = 0x00211F7F;
	p[pi].colors[5] = 0x00271B81;
	p[pi].colors[6] = 0x002D1682;
	p[pi].colors[7] = 0x00331284;
	p[pi].colors[8] = 0x00390D86;
	p[pi].colors[9] = 0x003F0988;
	p[pi].colors[10] = 0x0045048A;
	p[pi].colors[11] = 0x004B008C;
	p[pi].colors[12] = 0x00500091;
	p[pi].colors[13] = 0x0067239B;
	p[pi].colors[14] = 0x007F46A6;
	p[pi].colors[15] = 0x009669B1;
	p[pi].colors[16] = 0x00AE8CBB;
	p[pi].colors[17] = 0x00C5AFC6;
	p[pi].colors[18] = 0x00DDD2D1;
	p[pi].colors[19] = 0x00F5F5DC;
	p[pi].colors[20] = 0x00F0F0D7;
	p[pi].colors[21] = 0x00EBCDA0;
	p[pi].colors[22] = 0x00E6AA69;
	p[pi].colors[23] = 0x00E18732;pp
}

void	amber(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x001E0500;
	p[pi].colors[1] = 0x00270502;
	p[pi].colors[2] = 0x00300505;
	p[pi].colors[3] = 0x00390508;
	p[pi].colors[4] = 0x0043050B;
	p[pi].colors[5] = 0x004C050E;
	p[pi].colors[6] = 0x00550511;
	p[pi].colors[7] = 0x005F0514;
	p[pi].colors[8] = 0x00640A14;
	p[pi].colors[9] = 0x00781A14;
	p[pi].colors[10] = 0x008C2B14;
	p[pi].colors[11] = 0x00A03C14;
	p[pi].colors[12] = 0x009B0A14;
	p[pi].colors[13] = 0x00910914;
	p[pi].colors[14] = 0x00870814;
	p[pi].colors[15] = 0x007D0714;
	p[pi].colors[16] = 0x00730714;
	p[pi].colors[17] = 0x00690614;
	p[pi].colors[18] = 0x005F0514;
	p[pi].colors[19] = 0x00550514;
	p[pi].colors[20] = 0x005A0A14;
	p[pi].colors[21] = 0x00853214;
	p[pi].colors[22] = 0x00B05A14;
	p[pi].colors[23] = 0x00DC8214;
}
