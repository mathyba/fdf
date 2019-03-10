/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:31:49 by emuckens          #+#    #+#             */
/*   Updated: 2018/05/20 18:18:10 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

static int		ft_nbnb(unsigned char *str, int sep)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		while (str[i] == sep)
			++i;
		if (!str[i])
			break ;
		while (str[i] && str[i] != sep)
			++i;
		++count;
	}
	return (count);
}

static int		*fill_tab(int *tab, char *str, int nb_words, int c)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	(void)c;
	(void)nb_words;
	tmp = str;
	while (*str && i < nb_words)
	{
		count = 0;
		tab[i] = ft_atoi_index((unsigned char *)(str + count), &count);
		str += count;
		i++;
	}
	return (tab);
}

static int		*ft_strsplit_toint(char *s, char c, int *nb_words)
{
	int	*s_int;

	if (!s)
		return (NULL);
	s_int = NULL;
	while (*s == ' ')
		s++;
	*nb_words = ft_nbnb((unsigned char *)s, c);
	if (!(s_int = (int *)ft_memalloc(sizeof(int) * (*nb_words))))
	{
		ft_printf("error | fail alloc\n");
		return (NULL);
	}
	return (!*nb_words ? s_int : fill_tab(s_int, s, *nb_words, c));
}

static t_map	*ft_lst_addrow(ENV *e)
{
	t_map *tmp_lst;
	t_map *new;

	tmp_lst = NULL;
	new = NULL;
	if (!(new = (t_map *)ft_memalloc(sizeof(t_map))))
		return (ft_error_alloc(e));
	new->row_size = 0;
	if (!e->line || !e->line[0])
		return (ft_error_map());
	new->row = ft_strsplit_toint((char *)e->line, ' ', &new->row_size);
	if (e->line)
		new->next = NULL;
	if (new->row_size > e->width)
		e->width = new->row_size;
	if (!e->map_input)
	{
		e->map_input = new;
		return (e->map_input);
	}
	tmp_lst = e->map_input;
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = new;
	return (e->map_input);
}

t_map			*ft_getmap(ENV *e, char *file)
{
	int fd;

	fd = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_printf("error | wrong fd\n");
		return (NULL);
	}
	while (get_next_line2(fd, (char **)&e->line) == 1 && ++e->height)
		if (!(ft_lst_addrow(e)))
		{
			ft_strdel((char **)&e->line);
			close(fd);
			return (NULL);
		}
	close(fd);
	return (e->map_input);
}
