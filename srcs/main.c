/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 06:39:11 by achazal           #+#    #+#             */
/*   Updated: 2015/02/23 06:39:14 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static int	expose_hook(t_env *e)
{
	ft_update_img(e, ft_raycaster);
	return (0);
}

static int	ft_init_env(t_env *e)
{
	e->posx = 2.5;
	e->posy = 2.5;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	if (!(ft_getimg(e, &(e->background), "imgs/bgtest.xpm")))
		return (0);
	e->bgx = 0;
	e->bgy = 0;
	return (1);
}

static int	ft_load_textures(t_env *e)
{
	if (!(ft_getimg(e, &(*e->text), "imgs/briques.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 1)), "imgs/briques.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 2)), "imgs/floor.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 3)), "imgs/Destroyed.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 4)), "imgs/curtain.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 5)), "imgs/parquet.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 6)), "imgs/curtain.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 7)), "imgs/curtain.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 8)), "imgs/curtain.xpm")) ||
		!(ft_getimg(e, &(*(e->text + 9)), "imgs/curtain.xpm")))
		return (0);
	return (1);
}

int			main(void)
{
	t_env			*e;

	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	get_map(e);
	if (!(e->mlx = mlx_init()) ||
		!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf-3D")) ||
		!(e->text = (t_text *)malloc(sizeof(t_text) * 10)) ||
		!ft_init_env(e) || !ft_load_textures(e))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, ft_click, e);
	mlx_hook(e->win, 2, 3, ft_updatekey, e);
	mlx_loop_hook(e->mlx, ft_refresh, e);
	mlx_loop(e->mlx);
	return (0);
}
