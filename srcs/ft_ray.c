/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:01:00 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 10:01:02 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void					ft_drawwall(t_env *e, int texnum, int texx)
{
	static int				d;
	static int				texy;
	static unsigned int		color;

	while (e->drawstart <= e->drawend)
	{
		d = e->drawstart * 256 - HEIGHT * 128 + e->lineheight * 128;
		texy = ((d * (e->text)[texnum].height) / e->lineheight) / 256;
		if (!(color = ft_getxpmcolor((e->text)[texnum].ptr + texy *
			(e->text)[texnum].size_line + ((e->text)[texnum].bpp / 8) * texx)))
			return ;
		if (e->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		if (e->side == 2)
		{
			color = (color >> 1) & 0x7F7F7F;
			color = (color >> 1) & 0x7F7F7F;
		}
		ft_put_pixel_to_screen(e, e->x, e->drawstart, color);
		e->drawstart++;
	}
}

static void					ft_drawfloor(t_env *e)
{
	static int				y;
	static int				t;

	if ((t = e->map[e->mapy][e->mapx] - 1 - '0') <= 4 || t == 8)
		t = 5;
	y = e->drawend + 1;
	e->distwall = e->perpwalldist;
	e->distplayer = 0.0;
	if (e->drawend < 0)
		e->drawend = HEIGHT;
	while (y < HEIGHT)
	{
		ft_drawfloor2(e, y, t);
		y++;
	}
}

static void					ft_preparefloor(t_env *e)
{
	if ((e->side == 0 || e->side == 1) && e->raydirx > 0)
	{
		e->floorxwall = e->mapx;
		e->floorywall = e->mapy + e->wallx;
	}
	else if ((e->side == 0 || e->side == 1) && e->raydirx < 0)
	{
		e->floorxwall = e->mapx + 1.0;
		e->floorywall = e->mapy + e->wallx;
	}
	else if ((e->side == 2 || e->side == 3) && e->raydiry > 0)
	{
		e->floorxwall = e->mapx + e->wallx;
		e->floorywall = e->mapy;
	}
	else
	{
		e->floorxwall = e->mapx + e->wallx;
		e->floorywall = e->mapy + 1.0;
	}
}

static void					ft_applytext(t_env *e)
{
	static int				texnum;
	static int				texx;

	texnum = e->map[e->mapy][e->mapx] - 1 - '0';
	if (e->side == 2 || e->side == 3)
		e->wallx = e->rayposx + ((e->mapy - e->rayposy +
			(1 - e->stepy) / 2) / e->raydiry) * e->raydirx;
	else
		e->wallx = e->rayposy + ((e->mapx - e->rayposx +
			(1 - e->stepx) / 2) / e->raydirx) * e->raydiry;
	e->wallx -= floor(e->wallx);
	texx = (int)(e->wallx * (double)TEXT_WIDTH);
	if ((e->side == 0 || e->side == 1) && e->raydirx > 0)
		texx = (e->text)[texnum].width - texx - 1;
	if ((e->side == 2 || e->side == 3) && e->raydiry < 0)
		texx = (e->text)[texnum].width - texx - 1;
	ft_drawwall(e, texnum, texx);
	ft_preparefloor(e);
	ft_drawfloor(e);
}

void						ft_draw(t_env *e)
{
	ft_raylen(e);
	ft_getcolor(e);
	ft_applytext(e);
}
