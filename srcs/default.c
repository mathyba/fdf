/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 21:41:41 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:17:36 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_back_to_default(ENV *e)
{
	int row;
	int col;

	row = 0;
	while (row < e->height)
	{
		col = 0;
		while (col < e->points[row][col].row_size)
		{
			ft_4vcpy(&e->points[row][col].p, e->points[row][col].init);
			++col;
		}
		++row;
	}
	e->uinput.rotx = 0;
	e->uinput.roty = 0;
	e->uinput.mv_hor = 0;
	e->uinput.mv_ver = 0;
	e->maxzoomin = 0;
	e->maxzoomout = 0;
	e->mesh_size = e->mesh_init;
	return (0);
}
