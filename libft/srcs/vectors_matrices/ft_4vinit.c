/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4vinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:21:27 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 17:17:08 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_4vinit(t_4vect *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 1;
}
