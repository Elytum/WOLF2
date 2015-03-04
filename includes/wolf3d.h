/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 09:53:21 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 09:53:24 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include "X11/Xlib.h"
# include <math.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define WIDTH 1080
# define HEIGHT 720
# define TEXT_WIDTH 64
# define TEXT_HEIGHT 64
# define ABS(x) ((x >= 0) ? x : -(x))
# define MAP_FILE "./maps/map.wolf"
# define MS 0.3
# define RS 0.2
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
# define I 105
# define M 109

typedef struct		s_text
{
	int				width;
	int				height;
	void			*img;
	char			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_text;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pimg;
	int				bpp;
	int				size_line;
	int				endian;
	char			**map;

	int				mapx;
	int				mapy;
	int				x;

	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			bgx;
	double			bgy;

	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			camerax;

	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;

	int				stepx;
	int				stepy;
	int				hit;
	int				side;

	int				lineheight;
	int				drawstart;
	int				drawend;

	double			wallx;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			currentfloorx;
	double			currentfloory;
	double			weight;
	int				floortexx;
	int				floortexy;

	int				color;
	struct s_text	*text;
	struct s_text	background;
	int				**buffer;
}					t_env;

void				ft_put_pixel_to_screen(t_env *e, int x, int y, int color);
t_text				ft_resize(t_env *e, t_text t, int w, int h);
void				ft_init_step(t_env *e);
void				ft_loop_hit(t_env *e);
void				ft_raylen(t_env *e);
int					ft_update_img(t_env *e, void f(t_env *e));
void				ft_raycaster(t_env *e);
int					ft_click(int button, int x, int y, t_env *e);
void				draw(t_env *e);
void				left(t_env *e);
void				right(t_env *e);
void				down(t_env *e);
void				up(t_env *e);
int					ft_updatekey(int key, t_env *e);
void				get_map(t_env *e);
int					ft_getimg(t_env *e, t_text *ptr, char *path);
int					ft_refresh(t_env *e);
unsigned int		ft_getxpmcolor(char *ptr);
void				ft_raylen(t_env *e);
void				ft_getcolor(t_env *e);
void				ft_drawskybox(t_env *e, int ox, int iy);
void				ft_loop_hit(t_env *e);
void				ft_draw(t_env *e);
void				ft_drawfloor2(t_env *e, int y, int t);
#endif
