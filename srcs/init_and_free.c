/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:13:25 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:20:30 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void			free_list(t_map *lst)
{
	t_map	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		if (tmp->row)
			free(tmp->row);
		free(tmp);
		lst = lst->next;
	}
}

void			free_tab(ENV *e, t_pinfo **tab)
{
	int i;

	i = 0;
	(void)e;
	while (tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
}

static void		ft_init_uinput(ENV *e)
{
	ft_44minit(&e->uinput.event_m, 1);
	e->uinput.rotx = 0;
	e->uinput.roty = 0;
	e->uinput.zoom = 1;
	e->uinput.mv_hor = 0;
	e->uinput.mv_ver = 0;
	e->uinput.invert = 1;
	e->uinput.height = 0;
	e->uinput.rotcolor = 0;
	e->uinput.color = 0;
	e->uinput.color_map = 0;
}

static void		ft_init_coord(ENV *e)
{
	e->coord.x0 = 0;
	e->coord.x1 = 0;
	e->coord.y0 = 0;
	e->coord.y1 = 0;
	e->setextremes = 0;
}

int				ft_getenv(ENV *e)
{
	ft_init_uinput(e);
	ft_init_coord(e);
	e->points = NULL;
	e->maxzoomin = 0;
	e->maxzoomout = 0;
	e->map_input = NULL;
	e->height = 0;
	e->width = 0;
	e->row = 0;
	e->col = 0;
	e->line = NULL;
	e->mlx = NULL;
	e->win = NULL;
	e->color = 1;
	e->newheight = 0;
	e->maxheight = 0;
	e->minheight = 0;
	e->index[0] = 1;
	e->index[1] = 1;
	e->ppmove = 0;
	e->revert = 0;
	e->mesh_size = 40;
	e->mesh_init = 40;
	return (0);
}
