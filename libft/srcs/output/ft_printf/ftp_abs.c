/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:15:32 by emuckens          #+#    #+#             */
/*   Updated: 2018/03/31 22:30:22 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf/ft_printf.h"

int		ftp_abs(int n)
{
	return (n > 0 ? n : -n);
}
