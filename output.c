/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:52:09 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/26 09:52:11 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_coords(t_piece *iter)
{
	int		i;

	ft_putstr("Name: ");
	ft_putchar(iter->name);
	ft_putstr("\nNormalized Coords: ");
	i = 0;
	while (i < 4)
	{
		ft_putstr("(");
		ft_putnbr(iter->x_locs[i].row);
		ft_putstr(", ");
		ft_putnbr(iter->x_locs[i].col);
		ft_putstr(") ");
		i++;
	}
	ft_putstr("\n");
}

void	print_pieces(t_piece *head)
{
	t_piece		*iter;
	int			i;

	iter = head;
	i = 0;
	while (iter != NULL)
	{
		print_coords(iter);
		i = 0;
		while (i < 4)
		{
			ft_putstr(iter->data[i]);
			ft_putstr("\n");
			i++;
		}
		iter = iter->next;
		ft_putstr("\n");
	}
}

void	print_board(char **map, int b_size)
{
	int i;
	int j;

	i = 0;
	while (i < b_size)
	{
		j = 0;
		while (j < b_size)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
