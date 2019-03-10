/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:06:00 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 14:21:00 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_cpy;
	char	*src_cpy;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)(unsigned long)src;
	if (dst < src)
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	else
		while (len)
		{
			dst_cpy[len - 1] = src_cpy[len - 1];
			len--;
		}
	return ((void *)dst_cpy);
}
