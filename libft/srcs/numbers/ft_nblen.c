/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:27:06 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 14:41:36 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nblen(int n, int base)
{
	if (n < 0)
		return (n == -2147483648 ? 11 : ft_nblen(-n, base) + 1);
	return (n / base ? ft_nblen(n / base, base) + 1 : 1);
}