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

typedef struct t_node
{
	char			*data[4][5];
	char			**points;
	struct	t_node	*next;
}					node;


// int check
node *create_node()
{
	node *new = ft_memalloc(sizeof(*new));

	new->next = NULL;
	new->points = ft_memalloc(sizeof(new->points) * 4);
	return new;
}

void	append_node(node **head, node *add)
{
	if (!head)
		return ;
	if (*head == NULL)
		*head = add;
	else
	{
		add->next = *head;
		*head = add;
	}
}

void	print_linkedlist(node *tetriminos)
{
	node *head;
	int line; 
	int row;
	
	head = ft_memalloc(sizeof(*head));
	head = tetriminos;
	line = 0;
	row = 0;
	while (head)
	{
		while(head->data)
		{
			printf("%s\n", head->data);
			row++;
		}
		head = head->next;
	
	}
}

int	create_tetriminos(int fd, node **tetriminos)
{
	char *line;
	int col = 0;
	int row = 0;
	int tetris_line_count = 0;
	int tetris_count = 0;
	node *new;
	ft_lstnew(,4);
	while (get_next_line(fd, &line))
	{		
		if ((strlen(line) != 4) && !(ft_strcmp(line, "") == 0))
		{
			// printf("\n---Line: %s\n", line);
			// printf("\n---Chars: %zu\n", strlen(line));
			// printf("\n---Cmp: %d\n", ft_strcmp(line, ""));
			// printf("\nReturned @ if (!(strlen(line) == 4) && !(ft_strcmp(line, "") == 0))\n");`
			return (-1);
		}
		while (line[col])
		{
			if (line[col] != '.' && line[col] != '#')
			{
				// printf("\nReturned @ if (line[col] != '.' && line[col] != '#')\n");
				return INVALID_FILE;
			}
			col++;
		}
		row++;
		if (row > 26)
			return INVALID_FILE;
		if (ft_strcmp (line, "") == 0)
		{
			if (tetris_line_count == 1)
			{
				// printf("\nReturned @ if (tetris_line_count == 1)\n");
				return INVALID_FILE;
			}
			tetris_line_count++;
			node *new = create_node();
			append_node(tetriminos, new);
			tetris_line_count = 0;
			tetris_count++;
			if (row != 5)
			{
				// printf("\nReturned @ if (row != 5)\n");
				return INVALID_FILE;
			}
			row = 0;
		}
		else
		{
			(*tetriminos->data)[row] = ft_strjoin((*tetriminos->data)[row], line);
		}
	}
	return (0);
}

// int is_valid_line(char *line)
// {
// 	if ((int)ft_strlen(line) != 4)
// 	{
// 		return (0);
// 	}
// 	return (1);	
// }

int main(int argc, char **argv)
{
	int fd;
	node *tetriminos = create_node();
	
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (2);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		// check_file(fd, &tetriminos);
		create_tetriminos(fd, &tetriminos);
		print_linkedlist(tetriminos);
		// solve_tetriminos (tetriminos);
		close(fd);
	}
	return (0);
}
