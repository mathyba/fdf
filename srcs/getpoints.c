/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpoints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:55:11 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:18:30 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int	ft_get_values(ENV *e)
{
	while (e->map_input && e->col < e->map_input->row_size)
	{
		e->points[e->row][e->col].p.z = e->map_input->row[e->col];
		e->points[e->row][e->col].p.w = 1;
		e->points[e->row][e->col].p.x = (double)e->col;
		e->points[e->row][e->col].p.y = (double)e->row;
		e->points[e->row][e->col].row_size = e->map_input->row_size;
		if (e->points[e->row][e->col].p.z > e->maxheight)
			e->maxheight = e->points[e->row][e->col].p.z;
		else if (e->points[e->row][e->col].p.z < e->minheight)
			e->minheight = e->points[e->row][e->col].p.z;
		if (e->row == e->height - 1
				&& e->col == e->points[e->row][e->col].row_size - 1)
		{
			MAX_Y = e->row;
			MAX_X = e->col;
		}
		ft_4vcpy(&e->points[e->row][e->col].init, e->points[e->row][e->col].p);
		++e->col;
	}
	return (0);
}

t_pinfo		**ft_getpoints(ENV *e)
{
	t_map *tmp;

	e->row = 0;
	tmp = e->map_input;
	if (!(e->points = (t_pinfo **)ft_memalloc(sizeof(t_pinfo *) * (e->height))))
		return (NULL);
	while (e->map_input && e->row < e->height)
	{
		e->col = 0;
		if (!(e->points[e->row] =
			(t_pinfo *)ft_memalloc(sizeof(t_pinfo) * (e->map_input->row_size))))
		{
			free(e->points);
			return (NULL);
		}
		ft_get_values(e);
		free(e->map_input->row);
		e->map_input->row = NULL;
		++e->row;
		e->map_input = e->map_input->next;
	}
	ft_setextremes(e);
	free_list(tmp);
	return (e->points);
}
