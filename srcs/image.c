/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 10:56:35 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/21 17:34:05 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_get_img(ENV *e)
{
	e->img.img = mlx_new_image(e->mlx, e->win_w, e->win_h);
	e->img.ptr = mlx_get_data_addr(
			e->img.img, &e->img.bpp, &e->img.size, &e->img.endian);
	return (1);
}

void			ft_put_to_img(ENV *e, int row, int col, int color)
{
	if (col >= 0 && col <= e->win_w - 1 && row >= 0 && row <= e->win_h - 1)
		*(int *)(e->img.ptr + (row * e->win_w + col) * 4) = color;
}

static void		ft_setcoor(ENV *e, int dest_row, int dest_col)
{
	if (e->points[dest_row][dest_col].init.z > e->points[e->row][e->col].init.z)
		e->color = e->points[dest_row][dest_col].color;
	else
		e->color = e->points[e->row][e->col].color;
	e->coord.x0 = e->points[e->row][e->col].p.x;
	e->coord.y0 = e->points[e->row][e->col].p.y;
	e->coord.z0 = e->points[e->row][e->col].init.z;
	e->coord.x1 = e->points[dest_row][dest_col].p.x;
	e->coord.y1 = e->points[dest_row][dest_col].p.y;
	e->coord.z1 = e->points[dest_row][dest_col].init.z;
}

static void		ft_line_orientndraw(ENV *e, int dest_row, int dest_col)
{
	ft_setcoor(e, dest_row, dest_col);
	ft_drawline(e);
}

void			*ft_points_to_img(ENV *e)
{
	e->row = 0;
	while (e->row < e->height - 1)
	{
		e->col = 0;
		while (e->points[e->row][0].row_size && e->col
				< (e->points[e->row][0].row_size - 1))
		{
			if (e->points[e->row][0].row_size && e->col
					< e->points[e->row + 1][0].row_size)
				ft_line_orientndraw(e, e->row + 1, e->col);
			ft_line_orientndraw(e, e->row, e->col + 1);
			++e->col;
		}
		if (e->points[e->row + 1][0].row_size && e->col
				< e->points[e->row + 1][0].row_size)
			ft_line_orientndraw(e, e->row + 1, e->col);
		++e->row;
	}
	e->col = -1;
	while (++e->col < e->points[e->row][e->col].row_size - 1)
		ft_line_orientndraw(e, e->row, e->col + 1);
	return (NULL);
}
