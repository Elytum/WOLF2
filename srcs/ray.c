#include "wolf3d.h"

void 		ft_init_step(t_env *e)
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

void		ft_loop_hit(t_env *e)
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
		if ((e->map[e->mapy][e->mapx] != '0') &&
			((e->map[e->mapy][e->mapx] <= '4') ||
			(e->map[e->mapy][e->mapx] == '9')))
			e->hit = 1;
	}
}

void ft_raylen(t_env *e)
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

static void ft_getcolor(t_env *e)
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

unsigned int ft_getxpmcolor(char *ptr)
{
	static unsigned int color;

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

static void	ft_drawwall(t_env *e, int texnum, int texx)
{
	static int d;
	static int texy;
	static unsigned int color;

	while (e->drawstart <= e->drawend)
      {
      	d = e->drawstart * 256 - HEIGHT * 128 + e->lineheight * 128;
      	texy = ((d * (e->text)[texnum].height) / e->lineheight) / 256;
      	if (!(color = ft_getxpmcolor((e->text)[texnum].ptr + texy * (e->text)[texnum].size_line + \
      		((e->text)[texnum].bpp / 8) * texx)))
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

static void ft_drawfloor(t_env *e)
{
	static int y;
	static int texnum;
	static unsigned int color;

	// dprintf(1, "Pos %i %i\n", e->mapx, e->mapy);
	if ((texnum = e->map[e->mapy][e->mapx] - 1 - '0') <= 4 || texnum == 8)
		texnum = 5;

	// texnum = 0;
	// dprintf(1, "Testing %i\n", texnum);
	y = e->drawend + 1;
	e->distwall = e->perpwalldist;
    e->distplayer = 0.0;
	if (e->drawend < 0)
		e->drawend = HEIGHT;
	while (y < HEIGHT)
	{
		e->currentdist = HEIGHT / (2.0 * y - HEIGHT);

        e->weight = (e->currentdist - e->distplayer) / (e->distwall - e->distplayer);
        e->currentfloorx = e->weight * e->floorxwall + (1.0 - e->weight) * e->posx;
        e->currentfloory = e->weight * e->floorywall + (1.0 - e->weight) * e->posy;
        e->floortexx = (int)(e->currentfloorx * (e->text)[texnum].width) % (e->text)[texnum].width;
        e->floortexy = (int)(e->currentfloory * (e->text)[texnum].height) % (e->text)[texnum].height;
        
        color = ft_getxpmcolor((e->text)[texnum].ptr + (e->text)[texnum].size_line * e->floortexy + \
        	((e->text)[texnum].bpp / 8) * e->floortexx);
        ft_put_pixel_to_screen(e, e->x, y, (color >> 1) & 0x7F7F7F);
        // ft_put_pixel_to_screen(e, e->x, HEIGHT - y, (color >> 1) & 0x7F7F7F);
        y++;
	}
}

static void ft_preparefloor(t_env *e)
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

static void ft_applytext(t_env *e)
{
	static int texnum;
	static int texx;

	texnum = e->map[e->mapy][e->mapx] - 1 - '0';
	if (e->side == 2 || e->side == 3) 
		e->wallx = e->rayposx + ((e->mapy - e->rayposy + (1 - e->stepy) / 2) / e->raydiry) * e->raydirx;
	else
		e->wallx = e->rayposy + ((e->mapx - e->rayposx + (1 - e->stepx) / 2) / e->raydirx) * e->raydiry;
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

void ft_drawskybox(t_env *e, int ox, int iy)
{
	static int y;
	static int x;
	static int ix;
	static int sc;
	static int img;

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
	return ;
}

static void	ft_draw(t_env *e)
{
	ft_raylen(e);
	ft_getcolor(e);
	ft_applytext(e);
}

void        ft_raycaster(t_env *e)
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
		e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) / (e->raydirx * e->raydirx));
		e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) / (e->raydiry * e->raydiry));
		e->hit = 0;
		ft_init_step(e);
		ft_loop_hit(e);
		ft_draw(e);
		e->x++;
	}
}