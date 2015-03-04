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

void	ft_put_pixel_to_image(t_text *img, int x, int y, int color)
{
	static int i;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	i = x * ((*img).bpp / 8) + y * (*img).size_line;
	(*img).ptr[i]++;
	(*img).ptr[i] = (color & 0xFF);
	(*img).ptr[i + 1] = (color & 0xFF00) >> 8;
	(*img).ptr[i + 2] = (color & 0xFF0000) >> 16;
}	

void	ft_put_pixel_to_screen(t_env *e, int x, int y, int color)
{
	static int i;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	i = x * (e->bpp / 8) + y * e->size_line;
	e->pimg[i] = (color & 0xFF0000) >> 16;
	e->pimg[i + 1] = (color & 0xFF00) >> 8;
	e->pimg[i + 2] = (color & 0xFF);
}

int		ft_refresh(t_env *e)
{
	ft_update_img(e, ft_raycaster);
	return (0);
}

int 	ft_update_img(t_env *e, void f(t_env *e))
{
	static int first = 1;

	if (first)
	{
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->pimg = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &(e->endian));
		first = 0;
	}
	f(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	bzero(e->pimg, WIDTH * HEIGHT * 4);
	return (0);
}

int		ft_getimg(t_env *e, t_text *ptr, char *path)
{
	if (!(ptr->img = mlx_xpm_file_to_image(e->mlx, path, &(ptr->width), &(ptr->height))))
		return (0);
	if (!(ptr->ptr = mlx_get_data_addr (ptr->img, &(ptr->bpp), &(ptr->size_line), &(ptr->endian))))
		return (0);
	return (1);
}