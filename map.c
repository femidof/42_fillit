/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:37 by vinguyen          #+#    #+#             */
/*   Updated: 2019/12/06 20:37:14 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_num_pieces(t_piece *head)
{
	t_piece		*iter;
	int			tetra_pieces;

	iter = head;
	tetra_pieces = 0;
	while (iter != NULL)
	{
		tetra_pieces += 1;
		iter = iter->next;
	}
	return (tetra_pieces);
}

int		find_sqrt(int n)
{
	int		x;
	int		y;

	x = n;
	y = 1;
	while (x > y)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

int		get_board_size(int tetra_pieces)
{
	int		total_symbols;
	int		row_col;

	total_symbols = 4 * tetra_pieces;
	row_col = find_sqrt(total_symbols);
	while (row_col * row_col < total_symbols)
		row_col += 1;
	return (row_col);
}

char	**create_empty_board(int b_size)
{
	int		i;
	int		j;
	char	**map;
	char	*row;

	i = 0;
	map = malloc(sizeof(*map) * b_size);
	while (i < b_size)
	{
		j = 0;
		row = malloc(sizeof(*row) * b_size);
		while (j < b_size)
		{
			row[j] = '.';
			j++;
		}
		map[i] = row;
		i++;
	}
	return (map);
}

char	**resize_map(char **map, int map_size)
{
	char	**new_map;
	int		i;

	i = 0;
	free_map(map, map_size);
	new_map = create_empty_board(map_size + 1);
	return (new_map);
}
