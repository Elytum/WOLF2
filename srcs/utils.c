/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:13:55 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 10:13:57 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int			ft_getxpmcolor(char *ptr)
{
	static unsigned int	color;

	if (!ptr)
		return (0);
	if (*ptr)
	{
		color = *ptr << 16;
		if (*(ptr + 1))
		{
			color += *(ptr + 1) << 8;
			if (*(ptr + 2))
				color += *(ptr + 2);
		}
	}
	return (color);
}

void					ft_getcolor(t_env *e)
{
	if (e->map[e->mapy][e->mapx] == '1')
		e->color = 0xFF0000;
	else if (e->map[e->mapy][e->mapx] == '2')
		e->color = 0x00FF00;
	else if (e->map[e->mapy][e->mapx] == '3')
		e->color = 0x0000FF;
	else if (e->map[e->mapy][e->mapx] == '4')
		e->color = 0xFFFFFF;
	else
		e->color = 0xFFFF00;
	if (e->side == 1)
		e->color = e->color / 2;
	else if (e->side == 2)
		e->color = e->color * 2;
	else if (e->side == 3)
		e->color = e->color * 4;
}

void					ft_raycaster(t_env *e)
{
	e->x = 0;
	ft_drawskybox(e, e->bgx, 0);
	while (e->x < WIDTH)
	{
		e->rayposx = e->posx;
		e->rayposy = e->posy;
		e->camerax = 2 * (double)e->x / (double)WIDTH - 1;
		e->raydirx = e->dirx + e->planex * e->camerax;
		e->raydiry = e->diry + e->planey * e->camerax;
		e->mapx = (int)e->rayposx;
		e->mapy = (int)e->rayposy;
		e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) /
			(e->raydirx * e->raydirx));
		e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) /
			(e->raydiry * e->raydiry));
		e->hit = 0;
		ft_init_step(e);
		ft_loop_hit(e);
		ft_draw(e);
		e->x++;
	}
}

void					ft_drawfloor2(t_env *e, int y, int t)
{
	static unsigned int	color;

	e->currentdist = HEIGHT / (2.0 * y - HEIGHT);
	e->weight = (e->currentdist - e->distplayer) /
	(e->distwall - e->distplayer);
	e->currentfloorx = e->weight * e->floorxwall +
	(1.0 - e->weight) * e->posx;
	e->currentfloory = e->weight * e->floorywall +
	(1.0 - e->weight) * e->posy;
	e->floortexx = (int)(e->currentfloorx * (e->text)[t].width) %
	(e->text)[t].width;
	e->floortexy = (int)(e->currentfloory * (e->text)[t].height) %
	(e->text)[t].height;
	color = ft_getxpmcolor((e->text)[t].ptr + (e->text)[t].size_line *
		e->floortexy + ((e->text)[t].bpp / 8) * e->floortexx);
	ft_put_pixel_to_screen(e, e->x, y, (color >> 1) & 0x7F7F7F);
}
