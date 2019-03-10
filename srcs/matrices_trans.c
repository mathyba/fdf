/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:51:12 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:23:14 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_getm_height(ENV *e, double (*dest)[4][4])
{
	ft_44minit(dest, 1);
	(*dest)[2][3] = e->uinput.height;
}

void	ft_getm_heightinit(ENV *e, double (*dest)[4][4])
{
	ft_44minit(dest, 1);
	if (e->maxheight > 55)
		(*dest)[2][2] = 55.0 / e->maxheight;
	else if (e->minheight < -55)
		(*dest)[2][2] = 55.0 / e->minheight;
	e->minheight *= (*dest)[2][2];
	e->maxheight *= (*dest)[2][2];
}

void	ft_getm_move(ENV *e, double (*dest)[4][4])
{
	ft_4vinit(&e->shift, e->uinput.mv_hor, e->uinput.mv_ver, 0);
	ft_getm_trans(e, dest);
}

void	ft_getm_trans(ENV *e, double (*dest)[4][4])
{
	ft_44minit(dest, 1);
	(*dest)[0][3] = e->shift.x;
	(*dest)[1][3] = e->shift.y;
}
