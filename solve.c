/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:09:41 by vinguyen          #+#    #+#             */
/*   Updated: 2019/12/06 21:23:29 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Assumes that the piece row and col are in accordance to location on the map.
** Iterate through the row. For each column...
** Checks to make sure row and col is less than b_size && the place on the
**		map is empty. If it is, increment i. If there are four empty spots,
**		return "TRUE"
*/

int		check_tetris(char **map, t_piece *piece, int b_size)
{
	int i;
	int col;
	int row;

	i = 0;
	row = 0;
	while (row < b_size)
	{
		col = 0;
		while (col < b_size)
		{
			if (piece->x_locs[i].row < b_size && piece->x_locs[i].col < b_size
				&& map[piece->x_locs[i].row][piece->x_locs[i].col] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

/*
** Assumes that the piece row and col are in accordance to location on the map.
** Iterate through the row. For each column...
** If the location on the map is the same as the piece name, place an empty "."
** at the location to clear out the piece
*/

char	**remove_tetris(char **map, t_piece *piece, int b_size)
{
	int col;
	int row;

	row = 0;
	while (row < b_size)
	{
		col = 0;
		while (col < b_size)
		{
			if (map[row][col] == piece->name)
				map[row][col] = '.';
			col++;
		}
		row++;
	}
	return (map);
}

/*
** Assumes that the piece row and col are in accordance to location on the map.
** Iterate through the row. For each column...
** If the row & col of the piece is the same as the row & col on the map, then
** place the piece down
*/

char	**place_tetris(char **map, t_piece *piece, int b_size)
{
	int col;
	int row;
	int i;

	i = 0;
	row = 0;
	while (row < b_size)
	{
		col = 0;
		while (col < b_size)
		{
			if (piece->x_locs[i].row == row && piece->x_locs[i].col == col)
			{
				map[row][col] = piece->name;
				i++;
			}
			col++;
		}
		row++;
	}
	return (map);
}

/*
**	Iterates through the rows and col. Normalizes to be on the map
**	If it can place the tetris, then places the tetris and assign
**	the new grid to the map. Repeat and set map to NULL again.
**	If there is something in map, return map.
**	If unable to place the piece down, iterate through until able to.
**	If next piece unable to, return NULL and then go back to the previous
**	piece and continue iteration
*/

char	**algo(char **tetris_map, t_piece *piece, int b_size)
{
	int		col;
	int		row;
	char	**map;

	if (piece == NULL)
		return (tetris_map);
	map = NULL;
	row = -1;
	while (++row < b_size)
	{
		col = 0;
		while (col < b_size)
		{
			xy_tetris(&piece, col++, row);
			if (check_tetris(tetris_map, piece, b_size))
			{
				map = algo(place_tetris(tetris_map, piece, b_size),
					piece->next, b_size);
			}
			if (map)
				return (map);
			tetris_map = remove_tetris(tetris_map, piece, b_size);
		}
	}
	return (NULL);
}

/*
**	If tried every combo and result is still NULL, then increase
**	the board size by 1. Repeat until you return tetris_map
*/

void	solve(t_piece *piece, char **map, int b_size)
{
	while (!algo(map, piece, b_size))
	{
		map = resize_map(map, b_size);
		b_size++;
	}
	print_board(map, b_size);
	free_map(map, b_size);
	free_list(piece);
}
