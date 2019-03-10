/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:52:22 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 20:25:29 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

int	ft_rotate_colors(ENV *e)
{
	struct timespec tim;
	struct timespec tim2;

	tim.tv_sec = 0;
	tim.tv_nsec = 80000000;
	e->uinput.rotx = 0;
	e->uinput.roty = 0;
	e->uinput.zoom = 1;
	if (e->uinput.vegas)
	{
		e->uinput.rotcolor += 1;
		nanosleep(&tim, &tim2);
	}
	ft_dealkey(1, e);
	return (0);
}

int	ft_get_altcolor(ENV *e, double alt)
{
	int			index;
	static int	pos_alt[19][2] = {{GREEN0, 0}, {GREEN1, 1}, {GREEN2, 2},
		{GREEN3, 3}, {GREEN4, 4}, {EARTH0, 5}, {EARTH1, 7}, {EARTH2, 9},
		{EARTH3, 11}, {EARTH4, 13}, {EARTH5, 15}, {EARTH6, 17}, {EARTH7, 19},
		{GREY0, 21}, {GREY1, 25}, {GREY2, 29}, {GREY3, 33}, {GREY4, 37},
		{OFFWHITE, 40}};
	static int	neg_alt[10][2] = {{BLUE0, 0}, {BLUE1, 1}, {BLUE2, 2},
		{BLUE3, 5}, {BLUE4, 10}, {BLUE5, 15}, {BLUE7, 20}, {BLUE8, 35},
		{BLUE9, 45}, {BLUE10, 55}};

	index = 0;
	(void)e;
	if (alt > 0)
	{
		while (alt > pos_alt[index][1] && index < 18)
			++index;
		return (pos_alt[index][0]);
	}
	else
	{
		while (alt < -neg_alt[index][1] && index < 9)
			++index;
		return (neg_alt[index][0]);
	}
}

int	ft_get_nicecolor(ENV *e, double alt)
{
	int			index;
	static int	color[19] = {RED, PINK, PURPLE, INDIGO, BLUE, BGREY, LBLUE,
		CYAN, TEAL, GREEN, LGREEN, LIME, YELLOW, AMBER, ORANGE, DORANGE, BROWN,
		GREY, WHITE};

	(void)e;
	index = ft_abs(((int)alt + e->uinput.rotcolor) % 19);
	return (color[index]);
}
