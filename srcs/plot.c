/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:38:49 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:23:50 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_progress_on_axis(int *coord, double *error, int step, int delta)
{
	*coord += step;
	*error += delta;
}

static void	ft_inner_drawline(ENV *e, double error, int *step)
{
	int x;
	int y;

	x = e->coord.x0;
	y = e->coord.y0;
	if (e->coord.dx >= e->coord.dy)
		while (ft_abs(x - e->coord.x1))
		{
			ft_put_to_img(e, (size_t)y, (size_t)x, e->color);
			error -= e->coord.dy;
			if (error < 0)
				ft_progress_on_axis(&y, &error, step[Y], e->coord.dx);
			x += step[X];
		}
	else
		while (ft_abs(y - e->coord.y1))
		{
			ft_put_to_img(e, (size_t)y, (size_t)x, e->color);
			error -= e->coord.dx;
			if (error < 0)
				ft_progress_on_axis(&x, &error, step[X], e->coord.dy);
			y += step[Y];
		}
	ft_put_to_img(e, e->coord.y1, e->coord.x1, e->color);
}

void		ft_drawline(ENV *e)
{
	double	error;
	int		step[2];

	e->coord.dx = ft_abs(e->coord.x1 - e->coord.x0);
	e->coord.dy = ft_abs(e->coord.y1 - e->coord.y0);
	if (e->coord.dx > e->coord.dy)
		error = (double)((double)e->coord.dx * 0.5);
	else
		error = (double)((double)e->coord.dy * 0.5);
	step[X] = e->coord.x1 >= e->coord.x0 ? 1 : -1;
	step[Y] = e->coord.y1 >= e->coord.y0 ? 1 : -1;
	ft_inner_drawline(e, error, step);
}
