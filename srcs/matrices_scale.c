/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:52:20 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:22:21 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_getm_scaledown(ENV *e, double (*dest)[4][4])
{
	static int	iteration;
	double		ratio;

	if (!iteration || e->revert)
		e->mesh_size = 1;
	ft_44minit(dest, 1);
	ratio = 1.0 / e->mesh_size;
	(*dest)[0][0] = ratio;
	(*dest)[1][1] = ratio;
	(*dest)[2][2] = ratio;
	e->mesh_size = 1;
	++iteration;
}

void	ft_getm_scaleup(ENV *e, double (*dest)[4][4])
{
	ft_44minit(dest, 1);
	e->mesh_size = e->mesh_init;
	(*dest)[0][0] = e->mesh_size;
	(*dest)[1][1] = e->mesh_size;
	(*dest)[2][2] = e->mesh_size;
}

void	ft_getm_zoom(ENV *e, double (*dest)[4][4])
{
	ft_44minit(dest, 1);
	(*dest)[0][0] = e->uinput.zoom;
	(*dest)[1][1] = e->uinput.zoom;
	(*dest)[2][2] = e->uinput.zoom;
}
