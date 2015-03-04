/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:13:13 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 10:13:16 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					left(t_env *e)
{
	static double		olddirx;
	static double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(RS) - e->diry * sin(RS);
	e->diry = olddirx * sin(RS) + e->diry * cos(RS);
	oldplanex = e->planex;
	e->planex = e->planex * cos(RS) - e->planey * sin(RS);
	e->planey = oldplanex * sin(RS) + e->planey * cos(RS);
	e->bgx -= e->background.width * RS / 6.2;
}

void					right(t_env *e)
{
	static double		olddirx;
	static double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(-RS) - e->diry * sin(-RS);
	e->diry = olddirx * sin(-RS) + e->diry * cos(-RS);
	oldplanex = e->planex;
	e->planex = e->planex * cos(-RS) - e->planey * sin(-RS);
	e->planey = oldplanex * sin(-RS) + e->planey * cos(-RS);
	e->bgx += e->background.width * RS / 6.2;
}

void					down(t_env *e)
{
	char				a;
	char				b;

	a = e->map[(int)(e->posy - e->diry * MS * 3)][(int)(e->posx)];
	b = e->map[(int)(e->posy)][(int)(e->posx - e->dirx * MS * 3)];
	if (a == '0' || a == '9' || (a >= '5' && a <= '8'))
		e->posy -= e->diry * MS;
	if (b == '0' || b == '9' || (b >= '5' && b <= '8'))
		e->posx -= e->dirx * MS;
}

void					up(t_env *e)
{
	char				a;
	char				b;

	a = e->map[(int)(e->posy + e->diry * MS * 3)][(int)(e->posx)];
	b = e->map[(int)(e->posy)][(int)(e->posx + e->dirx * MS * 3)];
	if (a == '0' || a == '9' || (a >= '5' && a <= '8'))
		e->posy += e->diry * MS;
	if (b == '0' || b == '9' || (b >= '5' && b <= '8'))
		e->posx += e->dirx * MS;
}
