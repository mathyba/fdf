/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:48:36 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 20:30:48 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		ft_input_rot_and_height(ENV *e, int key)
{
	if (key == KEY_XUP)
		e->uinput.rotx = M_PI / 24.0;
	else if (key == KEY_XDW)
		e->uinput.rotx = -M_PI / 24.0;
	else if (key == KEY_YUP)
		e->uinput.roty = -M_PI / 24.0;
	else if (key == KEY_YDW)
		e->uinput.roty = M_PI / 24.0;
	else if (key == KEY_HEIGHT_UP)
	{
		e->newheight = 1;
		e->uinput.height += 2;
	}
	else if (key == KEY_HEIGHT_DW)
	{
		e->newheight = 1;
		e->uinput.height += -2;
	}
}

static void		ft_input_move(ENV *e, int key)
{
	if (key == KEY_LF)
		e->uinput.mv_hor -= e->ppmove * e->uinput.invert;
	else if (key == KEY_RT)
		e->uinput.mv_hor += e->ppmove * e->uinput.invert;
	else if (key == KEY_UP)
		e->uinput.mv_ver -= e->ppmove * e->uinput.invert;
	else if (key == KEY_DW)
		e->uinput.mv_ver += e->ppmove * e->uinput.invert;
	else if (key == KEY_INVERT)
		e->uinput.invert *= -1;
	else if (key == KEY_ZMIN && e->maxzoomin < 5)
	{
		++e->maxzoomin;
		--e->maxzoomout;
		e->uinput.zoom = 2.0;
	}
	else if (key == KEY_ZMOUT && e->maxzoomout < 5)
	{
		++e->maxzoomout;
		--e->maxzoomin;
		e->uinput.zoom = 0.5;
	}
}

static void		ft_input_color(ENV *e, int key)
{
	if (key == KEY_COLOR)
	{
		e->uinput.color_map = 0;
		e->uinput.color = 1;
	}
	else if (key == KEY_COLOR_MAP)
	{
		e->uinput.rotcolor = 0;
		e->uinput.color = 0;
		e->uinput.color_map = 1;
	}
	else if (key == KEY_COLOR_UP)
		e->uinput.rotcolor += 1;
	else if (key == KEY_COLOR_DW)
		e->uinput.rotcolor -= 1;
	else if (key == KEY_VEGAS)
	{
		if (!e->uinput.vegas)
			e->uinput.vegas = 1;
		else
			e->uinput.vegas = 0;
		mlx_loop_hook(e->mlx, &ft_rotate_colors, e);
	}
}

static int		ft_isvalid_key(int key)
{
	return (key == 1
			|| key == KEY_XUP
			|| key == KEY_XDW
			|| key == KEY_YUP
			|| key == KEY_YDW
			|| key == KEY_LF
			|| key == KEY_RT
			|| key == KEY_UP
			|| key == KEY_DW
			|| key == KEY_ZMIN
			|| key == KEY_ZMOUT
			|| key == KEY_HEIGHT_UP
			|| key == KEY_HEIGHT_DW
			|| key == KEY_COLOR
			|| key == KEY_COLOR_MAP
			|| key == KEY_COLOR_UP
			|| key == KEY_COLOR_DW
			|| key == KEY_VEGAS
			|| key == KEY_INVERT
			|| key == KEY_DEFAULT);
}

int				ft_dealkey(int key, void *param)
{
	mlx_clear_window(((ENV *)param)->mlx, ((ENV *)param)->win);
	ft_bzero(((ENV *)param)->img.ptr,
			((ENV *)param)->win_w * ((ENV *)param)->win_h * 4);
	((ENV *)param)->uinput.rotx = 0;
	((ENV *)param)->uinput.roty = 0;
	((ENV *)param)->uinput.zoom = 1.0;
	((ENV *)param)->setextremes = 0;
	if (ft_isvalid_key(key))
	{
		ft_input_rot_and_height((ENV *)param, key);
		ft_input_move((ENV *)param, key);
		ft_input_color((ENV *)param, key);
		if (key == KEY_DEFAULT)
			((ENV *)param)->revert = 1;
		return (ft_transform_points((ENV *)param));
	}
	else if (key == KEY_ESC)
		return (ft_close_window((ENV *)param));
	ft_points_to_img(((ENV *)param));
	ft_display_menu((ENV *)param);
	mlx_put_image_to_window(((ENV *)param)->mlx, ((ENV *)param)->win,
			((ENV *)param)->img.img, 0, 0);
	ft_menu_txt((ENV *)param);
	return (0);
}
