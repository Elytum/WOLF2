#include "wolf3d.h"

void			ft_drawskybox(t_env *e, int ox, int iy)
{
	static int	y;
	static int	x;
	static int	ix;
	static int	sc;
	static int	img;

	y = 0;
	while (y < HEIGHT)
	{
		ix = ox;
		while (iy > e->background.height)
			iy -= e->background.height;
		x = 0;
		while (x < WIDTH)
		{
			while (ix > e->background.width)
				ix -= e->background.width;
			while (ix < 0)
				ix += e->background.width;
			sc = y * e->size_line + x * (e->bpp / 8);
			img = iy * e->background.size_line + ix * (e->background.bpp / 8);
			e->pimg[sc++] = e->background.ptr[img++];
			e->pimg[sc++] = e->background.ptr[img++];
			e->pimg[sc] = e->background.ptr[img];
			x++;
			ix++;
		}
		y++;
		iy++;
	}
}

void			ft_raylen(t_env *e)
{
	if (e->side == 0 || e->side == 1)
		e->perpwalldist = fabs((e->mapx - e->rayposx + (1 - e->stepx) / 2) / e->raydirx);
	else
		e->perpwalldist = fabs((e->mapy - e->rayposy + (1 - e->stepy) / 2) / e->raydiry);
	e->lineheight = ABS((int)(HEIGHT / e->perpwalldist));
	e->drawstart = (HEIGHT / 2) - (e->lineheight / 2);
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = (HEIGHT / 2) + (e->lineheight / 2);
	if (e->drawend >= HEIGHT)
		e->drawend = HEIGHT - 1;
}

void			ft_loop_hit(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			if (e->stepx < 0)
				e->side = 0;
			else
				e->side = 1;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			if (e->stepy < 0)
				e->side = 2;
			else
				e->side = 3;
		}
		if (e->map[e->mapy][e->mapx] != '0')
			e->hit = 1;
	}
}

void 			ft_init_step(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}
