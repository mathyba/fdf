/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4vcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:17:53 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 17:22:38 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_4vcpy(t_4vect *dest, t_4vect src)
{
	(*dest).x = src.x;
	(*dest).y = src.y;
	(*dest).z = src.z;
	(*dest).w = src.w;
}
