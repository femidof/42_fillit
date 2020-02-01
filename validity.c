/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:34:22 by oldurosi          #+#    #+#             */
/*   Updated: 2019/12/06 18:46:27 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece			*create_blank_piece(void)
{
	t_piece	*new_piece;

	new_piece = (t_piece*)malloc(sizeof(t_piece));
	new_piece->next = NULL;
	return (new_piece);
}

int				check_adjacency(char **data, t_coords *x_locs)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (x_locs[i].row != 0 && data[x_locs[i].row - 1][x_locs[i].col] == '#')
			count++;
		if (x_locs[i].row != 3 && data[x_locs[i].row + 1][x_locs[i].col] == '#')
			count++;
		if (x_locs[i].col != 3 && data[x_locs[i].row][x_locs[i].col + 1] == '#')
			count++;
		if (x_locs[i].col != 0 && data[x_locs[i].row][x_locs[i].col - 1] == '#')
			count++;
		i++;
	}
	if (count >= 6)
		return (SUCCESS);
	return (INVALID_FILE);
}

int				record_tetris_locations(t_piece *piece, int row,
				int *col, int *count_hash)
{
	while ((*piece).data[row][*col] != '\0')
	{
		if ((*piece).data[row][*col] == '#')
		{
			(*piece).x_locs[*count_hash] = (t_coords){row, *col};
			(*count_hash)++;
		}
		else if ((*piece).data[row][*col] != '.')
			return (INVALID_FILE);
		(*col)++;
	}
	return (SUCCESS);
}

int				create_piece(int fd, t_piece *piece)
{
	static char	letter = 'A';
	t_coords	rc;
	int			ret;
	int			c_hash;

	c_hash = 0;
	rc = (t_coords){0, 0};
	if ((ret = fill_lines(&rc, fd, piece, &c_hash)) == -1)
		return (INVALID_FILE);
	if (letter > 'Z' && ret != 0)
		return (INVALID_FILE);
	(*piece).name = letter++;
	if (rc.row == 4 && c_hash == 4 && ret > 0)
	{
		if (check_adjacency((*piece).data, (*piece).x_locs) == INVALID_FILE)
			return (INVALID_FILE);
		normalize_coords((*piece).x_locs);
		return (SUCCESS);
	}
	return (INVALID_FILE);
}

t_piece			*join_pieces(int fd)
{
	t_piece		*new_piece;
	t_piece		*head;
	t_piece		*tail;
	char		buf;
	int			ret;

	new_piece = create_blank_piece();
	head = new_piece;
	tail = new_piece;
	while (new_piece && (ret = create_piece(fd, new_piece)) == SUCCESS)
	{
		buf = '\0';
		read(fd, &buf, 1);
		if (buf == '\0')
			return (head);
		else if (buf != '\n')
			return (NULL);
		new_piece = create_blank_piece();
		tail->next = new_piece;
		tail = new_piece;
	}
	if (ret == -1)
		return (NULL);
	return (head);
}
