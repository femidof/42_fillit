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

int is_4x4(char **tetris)
{
	int x;
	
	x = 0;
	while (tetris[x])
	{
		if (ft_strlen(tetris[x]) != 4)
			return (0);
	}
	return (1);
}

int is_valid_symbols(char **tetris)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tetris[x])
	{
		while(tetris[x][y])
		{
			if (tetris[x][y] != '.' && tetris[x][y] != '#')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	count_tetris(int argc, char **argv)
{
	// fd = open(argv[argc - 1], O_RDONLY);
	return 1;
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	char **store;
	int total_chars;
	int total_lines;
	int i = 0;

	total_lines = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (2);
	}
	else
	{
		fd = open(argv[argc - 1], O_RDONLY);
		while(get_next_line(fd, &line))
		{
			total_chars += ft_strlen(line); //90 chars
			total_lines++; //22 lines
		}
		close(fd);
		printf("%d", total_lines);
		fd = open(argv[argc - 1], O_RDONLY);
		store = ft_memalloc((total_lines + 1)* sizeof(char *));
		while(get_next_line(fd, &line))00
		{
			store[i] = ft_strdup(line);
			printf("%s", store[i]);
			i++;
		}
		close(fd);
	}
	// close(fd);
	// i = 0;
	// // while(store[i])
	// // {
	// // 	printf("%s\n", store[i]);
	// // 	i++;
	// // }
	return (0);
}
