/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 21:20:34 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:21:53 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_getm_setcenter(ENV *e, double (*dest)[4][4])
{
	e->shift.x = (e->win_w + MENU_END) * 0.5;
	e->shift.y = e->win_h * 0.5;
	e->shift.z = 0;
	ft_getm_trans(e, dest);
}

void	ft_getm_center_to_origin(ENV *e, double (*dest)[4][4])
{
	ft_44minit(dest, 1);
	e->shift.x = -(e->max.x - e->min.x) * 0.5 - e->min.x;
	e->shift.y = -(e->max.y - e->min.y) * 0.5 - e->min.y;
	e->shift.z = 0;
	ft_getm_trans(e, dest);
}
