/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:18:37 by irhett            #+#    #+#             */
/*   Updated: 2017/06/02 20:47:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	azorius(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x000A78CD;
	p[pi].colors[1] = 0x000A6BC2;
	p[pi].colors[2] = 0x000A5EB7;
	p[pi].colors[3] = 0x000A51AD;
	p[pi].colors[4] = 0x000A44A2;
	p[pi].colors[5] = 0x000A3898;
	p[pi].colors[6] = 0x000A2B8D;
	p[pi].colors[7] = 0x000A1E83;
	p[pi].colors[8] = 0x000A1178;
	p[pi].colors[9] = 0x000A056E;
	p[pi].colors[10] = 0x00161378;
	p[pi].colors[11] = 0x00232282;
	p[pi].colors[12] = 0x002F308D;
	p[pi].colors[13] = 0x003C3F97;
	p[pi].colors[14] = 0x00484EA1;
	p[pi].colors[15] = 0x00555CAC;
	p[pi].colors[16] = 0x00616BB6;
	p[pi].colors[17] = 0x006E7AC0;
	p[pi].colors[18] = 0x007A88CB;
	p[pi].colors[19] = 0x008797D5;
	p[pi].colors[20] = 0x0093A6DF;
	p[pi].colors[21] = 0x00A0B4EA;
	p[pi].colors[22] = 0x00ACC3F4;
	p[pi].colors[23] = 0x00B9D2FF;
}

void	vendetta(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x00141414;
	p[pi].colors[1] = 0x00241924;
	p[pi].colors[2] = 0x00341E34;
	p[pi].colors[3] = 0x00452345;
	p[pi].colors[4] = 0x00552855;
	p[pi].colors[5] = 0x00662D66;
	p[pi].colors[6] = 0x00763276;
	p[pi].colors[7] = 0x00873787;
	p[pi].colors[8] = 0x0094666F;
	p[pi].colors[9] = 0x00A24657;
	p[pi].colors[10] = 0x00B0253F;
	p[pi].colors[11] = 0x00BE0528;
	p[pi].colors[12] = 0x00BA2B46;
	p[pi].colors[13] = 0x00B15264;
	p[pi].colors[14] = 0x00A87982;
	p[pi].colors[15] = 0x00A0A0A0;
	p[pi].colors[16] = 0x00ABABAB;
	p[pi].colors[17] = 0x00B7B7B7;
	p[pi].colors[18] = 0x00C3C3C3;
	p[pi].colors[19] = 0x00CFCFCF;
	p[pi].colors[20] = 0x00DBDBDB;
	p[pi].colors[21] = 0x00E7E7E7;
	p[pi].colors[22] = 0x00F3F3F3;
	p[pi].colors[23] = 0x00FFFFFF;
}

void	attednev(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[23] = 0x00141414;
	p[pi].colors[22] = 0x00241924;
	p[pi].colors[21] = 0x00341E34;
	p[pi].colors[20] = 0x00452345;
	p[pi].colors[19] = 0x00552855;
	p[pi].colors[18] = 0x00662D66;
	p[pi].colors[17] = 0x00763276;
	p[pi].colors[16] = 0x00873787;
	p[pi].colors[15] = 0x0094666F;
	p[pi].colors[14] = 0x00A24657;
	p[pi].colors[13] = 0x00B0253F;
	p[pi].colors[12] = 0x00BE0528;
	p[pi].colors[11] = 0x00BA2B46;
	p[pi].colors[10] = 0x00B15264;
	p[pi].colors[9] = 0x00A87982;
	p[pi].colors[8] = 0x00A0A0A0;
	p[pi].colors[7] = 0x00ABABAB;
	p[pi].colors[6] = 0x00B7B7B7;
	p[pi].colors[5] = 0x00C3C3C3;
	p[pi].colors[4] = 0x00CFCFCF;
	p[pi].colors[3] = 0x00DBDBDB;
	p[pi].colors[2] = 0x00E7E7E7;
	p[pi].colors[1] = 0x00F3F3F3;
	p[pi].colors[0] = 0x00FFFFFF;
}

void	tmobile(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num = 24));
	p[pi].colors[0] = 0x006E0241;
	p[pi].colors[1] = 0x00790247;
	p[pi].colors[2] = 0x0085024E;
	p[pi].colors[3] = 0x00900254;
	p[pi].colors[4] = 0x009B035B;
	p[pi].colors[5] = 0x00A60361;
	p[pi].colors[6] = 0x00B10368;
	p[pi].colors[7] = 0x00BC036E;
	p[pi].colors[8] = 0x00C70375;
	p[pi].colors[9] = 0x00D2047B;
	p[pi].colors[10] = 0x00DD0482;
	p[pi].colors[11] = 0x00E80488;
	p[pi].colors[12] = 0x00F3048F;
	p[pi].colors[13] = 0x00FF0596;
	p[pi].colors[14] = 0x00000000;
	p[pi].colors[15] = 0x000B0006;
	p[pi].colors[16] = 0x0016000D;
	p[pi].colors[17] = 0x00210013;
	p[pi].colors[18] = 0x002C001A;
	p[pi].colors[19] = 0x00370120;
	p[pi].colors[20] = 0x00420127;
	p[pi].colors[21] = 0x004D012D;
	p[pi].colors[22] = 0x00580134;
	p[pi].colors[23] = 0x0063013A;
}
