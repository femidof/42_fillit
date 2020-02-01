/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:51:27 by vinguyen          #+#    #+#             */
/*   Updated: 2019/11/26 09:51:28 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	normalize_coords(t_coords *x_locs)
{
	int		lowest_row_val;
	int		lowest_col_val;
	int		i;

	lowest_row_val = x_locs[0].row;
	lowest_col_val = x_locs[0].col;
	i = 1;
	while (i < 4)
	{
		if (x_locs[i].row < lowest_row_val)
			lowest_row_val = x_locs[i].row;
		if (x_locs[i].col < lowest_col_val)
			lowest_col_val = x_locs[i].col;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		x_locs[i].row -= lowest_row_val;
		x_locs[i].col -= lowest_col_val;
		i++;
	}
}

/*
**	Finds the smallest row, col positions and shifts
**	to the map x, y locations
*/

void	xy_tetris(t_piece **piece, int x, int y)
{
	int		pos_x;
	int		pos_y;
	int		i;

	i = 1;
	pos_x = (*piece)->x_locs[0].col;
	pos_y = (*piece)->x_locs[0].row;
	while (i < 4)
	{
		if ((*piece)->x_locs[i].col < pos_x)
			pos_x = (*piece)->x_locs[i].col;
		if ((*piece)->x_locs[i].row < pos_y)
			pos_y = (*piece)->x_locs[i].row;
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*piece)->x_locs[i].col = (*piece)->x_locs[i].col - pos_x + x;
		(*piece)->x_locs[i].row = (*piece)->x_locs[i].row - pos_y + y;
		i--;
	}
}
