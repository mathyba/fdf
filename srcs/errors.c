/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:26:37 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:17:45 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*ft_error_alloc(ENV *e)
{
	if (e->map_input)
		free_list(e->map_input);
	ft_printf("error | fail alloc\n");
	return (NULL);
}

void		*ft_error_map(void)
{
	ft_printf("error | empty line\n");
	return (NULL);
}
