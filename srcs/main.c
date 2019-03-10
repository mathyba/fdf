/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:12:28 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 20:26:46 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "/System/Library/Frameworks/Tk.framework/Headers/X11/X.h"

int	main(int argc, char **argv)
{
	ENV e;

	ft_getenv(&e);
	if (argc == 2)
	{
		if (!ft_getmap(&e, argv[1]))
		{
			free_list(e.map_input);
			return (ft_display_error("reading file"));
		}
		if (!ft_getpoints(&e))
			return (ft_display_error("fail alloc"));
		if (!ft_init_win(&e) || !ft_get_img(&e))
			return (ft_display_error("graphic environment set-up"));
		ft_display_menu(&e);
		mlx_hook(e.win, KeyPress, KeyPressMask, &ft_dealkey, (void *)&e);
		mlx_expose_hook(e.win, &ft_transform_points, (void *)&e);
		mlx_loop(e.mlx);
		free_tab(&e, e.points);
		return (0);
	}
	return (ft_display_error("wrong number of arguments"));
}
