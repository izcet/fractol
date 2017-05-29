/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:18:37 by irhett            #+#    #+#             */
/*   Updated: 2017/05/29 15:44:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bloody_princess(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 24));
	p[pi].colors[0] = 0x0041055A;
	p[pi].colors[1] = 0x004C1258;
	p[pi].colors[2] = 0x00582056;
	p[pi].colors[3] = 0x00642E54;
	p[pi].colors[4] = 0x00703C52;
	p[pi].colors[5] = 0x007C4950;
	p[pi].colors[6] = 0x0088574E;
	p[pi].colors[7] = 0x0094654C;
	p[pi].colors[8] = 0x00A0734B;
	p[pi].colors[9] = 0x00AB8049;
	p[pi].colors[10] = 0x00B78E47;
	p[pi].colors[11] = 0x00C39C45;
	p[pi].colors[12] = 0x00CFAA43;
	p[pi].colors[13] = 0x00DBB741;
	p[pi].colors[14] = 0x00E7C53F;
	p[pi].colors[15] = 0x00F3D33D;
	p[pi].colors[16] = 0x00FFE13C;
	p[pi].colors[17] = 0x00F9D03C;
	p[pi].colors[18] = 0x00F3C03C;
	p[pi].colors[19] = 0x00EDAF3C;
	p[pi].colors[20] = 0x00E89F3C;
	p[pi].colors[21] = 0x00E28E3C;
	p[pi].colors[22] = 0x00DC7E3C;
	p[pi].colors[23] = 0x00D76E3C;
}

void	jeskai(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 16));
	p[pi].colors[0] = 0x000A236E;
	p[pi].colors[1] = 0x00242F69;
	p[pi].colors[2] = 0x003F3C65;
	p[pi].colors[3] = 0x005A4960;
	p[pi].colors[4] = 0x0074565C;
	p[pi].colors[5] = 0x008F6257;
	p[pi].colors[6] = 0x00AA6F53;
	p[pi].colors[7] = 0x00C47C4E;
	p[pi].colors[8] = 0x00DF894A;
	p[pi].colors[9] = 0x00FA9646;
	p[pi].colors[10] = 0x00FAA764;
	p[pi].colors[11] = 0x00FBB983;
	p[pi].colors[12] = 0x00FCCAA2;
	p[pi].colors[13] = 0x00FDDCC1;
	p[pi].colors[14] = 0x00FEEDE0;
	p[pi].colors[15] = 0x00FFFFFF;
}

void	absurdity(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 12));
	p[pi].colors[0] = 0x00500A78;
	p[pi].colors[1] = 0x005F1487;
	p[pi].colors[2] = 0x006E1E96;
	p[pi].colors[3] = 0x00055F32;
	p[pi].colors[4] = 0x00197D37;
	p[pi].colors[5] = 0x002D9B3C;
	p[pi].colors[6] = 0x00C8AF3C;
	p[pi].colors[7] = 0x00E1D23C;
	p[pi].colors[8] = 0x00FAF53C;
	p[pi].colors[9] = 0x00CD730A;
	p[pi].colors[10] = 0x00C56605;
	p[pi].colors[11] = 0x00BE5A00;
}

void	forgotten(t_palette *p, unsigned char pi)
{
	p[pi].colors = malloc(sizeof(unsigned int) * (p[pi].num_colors = 24));
	p[pi].colors[0] = 0x00344DA0;
	p[pi].colors[1] = 0x002C599C;
	p[pi].colors[2] = 0x00246599;
	p[pi].colors[3] = 0x001C7196;
	p[pi].colors[4] = 0x00147D92;
	p[pi].colors[5] = 0x000C898F;
	p[pi].colors[6] = 0x0005968C;
	p[pi].colors[7] = 0x000C898F;
	p[pi].colors[8] = 0x00147D92;
	p[pi].colors[9] = 0x001C7196;
	p[pi].colors[10] = 0x00246599;
	p[pi].colors[11] = 0x002C599C;
	p[pi].colors[12] = 0x00344DA0;
	p[pi].colors[13] = 0x003C41A3;
	p[pi].colors[14] = 0x004435A6;
	p[pi].colors[15] = 0x004C29AA;
	p[pi].colors[16] = 0x00541DAD;
	p[pi].colors[17] = 0x005C11B0;
	p[pi].colors[18] = 0x006405B4;
	p[pi].colors[19] = 0x005C11B0;
	p[pi].colors[20] = 0x00541DAD;
	p[pi].colors[21] = 0x004C29AA;
	p[pi].colors[22] = 0x004435A6;
	p[pi].colors[23] = 0x003C41A3;
}
