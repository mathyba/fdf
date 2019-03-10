/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_nullarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:29:00 by emuckens          #+#    #+#             */
/*   Updated: 2018/04/09 13:36:22 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf/ft_printf.h"

void		mng_nullarg(t_env *env)
{
	if (env->prec == -100 || env->prec > 0)
		env->tmpbuf[0] = '0';
	else
	{
		env->index = 0;
		env->tmpbuf[0] = 0;
	}
}
