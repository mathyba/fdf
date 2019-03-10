/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:52:54 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:42:19 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int	ft_launch_window(ENV *e)
{
	e->mlx = mlx_init();
	if (!e->mlx)
		return (0);
	e->win = mlx_new_window(e->mlx, e->win_w, e->win_h, WIN_TITLE);
	if (!e->win)
		return (0);
	return (1);
}

int			ft_close_window(ENV *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

static void	ft_get_meshsize(ENV *e)
{
	while ((e->width * e->mesh_init > (e->win_w - PADDING))
			|| (e->height * e->mesh_init > (e->win_h - PADDING)))
		--e->mesh_init;
}

int			ft_init_win(ENV *e)
{
	if ((e->win_w = e->width * e->mesh_size + MIN_W) > SCREEN_W)
		e->win_w = SCREEN_W;
	if ((e->win_h = e->height * e->mesh_size + MIN_H) > SCREEN_H)
		e->win_h = SCREEN_H;
	if (e->win_h == SCREEN_H || e->win_w == SCREEN_W)
		ft_get_meshsize(e);
	ft_4vinit(&e->min, e->win_w, e->win_h, e->win_w * e->win_h);
	ft_4vinit(&e->max, 0, 0, 0);
	e->ppmove = e->win_h * e->win_w * PPMOVE_RATIO;
	if (!ft_launch_window(e))
		return (0);
	return (1);
}
