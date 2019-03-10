/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:39:45 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/21 17:10:55 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_merge_transformations(ENV *e, double (*m)[4][4], int index)
{
	static double	temp1[4][4];
	static double	temp2[4][4];
	static void		(*trans[TRANS])(ENV *e, double (*trans)[4][4]) = {
		&ft_getm_center_to_origin,
		&ft_getm_scaledown,
		&ft_getm_rot,
		&ft_getm_scaleup,
		&ft_getm_zoom,
		&ft_getm_setcenter,
		&ft_getm_move,
	};

	if (index == TRANS)
		return ;
	ft_44mcpy(&temp1, *m);
	trans[index](e, &temp2);
	ft_44mtrxmtrx_mul(m, temp2, temp1);
	ft_merge_transformations(e, m, index + 1);
}

static void	ft_initialize_height(ENV *e, double (*m)[4][4], int row, int col)
{
	e->points[row][col].p = ft_4mtrxvect_mul(m, &e->points[row][col].p);
	e->points[row][col].init.z = e->points[row][col].p.z;
}

static void	ft_apply_height_and_color(ENV *e, int row, int col)
{
	double m_height[4][4];

	if (e->points[row][col].row_size && e->points[row][col].p.z && e->newheight)
	{
		ft_getm_height(e, &m_height);
		e->points[row][col].p =
			ft_4mtrxvect_mul(&m_height, &e->points[row][col].p);
	}
	if (e->uinput.color_map)
		e->points[row][col].color =
			ft_get_altcolor(e, e->points[row][col].init.z);
	else
		e->points[row][col].color =
			ft_get_nicecolor(e, e->points[row][col].init.z);
}

static int	ft_apply_transformation(ENV *e, double (*m)[4][4])
{
	int			row;
	int			col;
	double		m_heightinit[4][4];
	static int	iteration;

	row = 0;
	if (!iteration)
		ft_getm_heightinit(e, &m_heightinit);
	while (row < e->height)
	{
		col = 0;
		while (e->points[row][col].row_size && col < e->points[row][0].row_size)
		{
			if (!iteration && e->points[row][col].row_size)
				ft_initialize_height(e, &m_heightinit, row, col);
			ft_apply_height_and_color(e, row, col);
			e->points[row][col].p = ft_4mtrxvect_mul(m, &e->points[row][col].p);
			++col;
		}
		++row;
	}
	++iteration;
	e->newheight = 0;
	return (0);
}

int			ft_transform_points(ENV *e)
{
	double		ftrans[4][4];

	ft_44minit(&ftrans, 1);
	ft_setextremes(e);
	ft_merge_transformations(e, &ftrans, 0);
	if (e->revert || e->newheight != 0)
	{
		e->revert = 1;
		ft_back_to_default(e);
		ft_44minit(&ftrans, 1);
		ft_setextremes(e);
		ft_merge_transformations(e, &ftrans, 0);
		e->revert = 0;
	}
	ft_apply_transformation(e, &ftrans);
	ft_points_to_img(e);
	ft_display_menu(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	ft_menu_txt(e);
	return (1);
}
