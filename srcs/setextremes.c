/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setextremes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:37:52 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/19 20:46:32 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_setextremes(ENV *e)
{
	e->min.x = e->points[0][0].p.x;
	e->min.y = e->points[0][0].p.y;
	e->max.x = e->points[MAX_Y][MAX_X].p.x;
	e->max.y = e->points[MAX_Y][MAX_X].p.y;
	return (0);
}
