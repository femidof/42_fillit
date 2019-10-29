/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 04:16:04 by oldurosi          #+#    #+#             */
/*   Updated: 2019/10/21 05:16:59 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
# define INVALID_FILE -1;
# define VALID_FILE 0;
# define NO_FILE_DIRECTORY 2;

typedef struct 		t_hash
{
	int				x;
	int				y;
}					hash;

typedef struct 		t_tetris
{
	char			*data[4]; //Array of 4 strings
	hash			coords[4] //Array of 4 hash structs
}					tetris;

int	create_tetriminos(int fd, t_list **tetriminos)
{
	char *line;
	int col;
	int row = 0;
	int newline_count = 0;
	int	coords_count = 0;
	int tetris_count = 0;
	int gnl_res;
	int c_i = 0;
	tetris *new = malloc(sizeof(*new));

	while ((gnl_res = get_next_line(fd, &line)) == 1)
	{		
		if (row >= 26)
			return INVALID_FILE;
		if ((strlen(line) != 4) && !(ft_strcmp(line, "") == 0))
			return (-1);
		col = 0;
		while (line[col])
		{
			if (line[col] != '.' && line[col] != '#')
				return INVALID_FILE;
			if (line[col] == '#')
			{
				hash xy = {row, col};
				new->coords[c_i] = xy;
				coords_count++;
				c_i++;
			}
			col++;
		}
		if (ft_strcmp (line, "") == 0)
		{
			if (row != 4 || newline_count != 1)
				return INVALID_FILE;
			ft_lstadd(tetriminos, ft_lstnew(new, sizeof(new)));
			tetris_count++;
		
		}
		else
		{
			
		}
	}
	if (gnl_res == -1)
		return INVALID_FILE;
	return VALID_FILE;
}

int main(int argc, char **argv)
{
	int fd;
	t_list *tetriminos = NULL;	
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return NO_FILE_DIRECTORY;
	}
	if (fd = open(argv[1], O_RDONLY))
		return INVALID_FILE;
	create_tetriminos(fd, &tetriminos);
	// solve_tetriminos (tetriminos);
	close(fd);
	return (0);
}
