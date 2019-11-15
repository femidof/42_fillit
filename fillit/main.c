/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:16:02 by vinguyen          #+#    #+#             */
/*   Updated: 2019/10/29 02:16:05 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
# define INVALID_FILE -1;

typedef struct		t_points
{
	int				row;
	int				col;
}					points;

typedef struct		t_list
{
	char			*data[4];
	points 			pts[4];
	struct t_list	*next;
	
}					tetris;

void	append_node(tetris **head, tetris *add)
{
	tetris *temp;
	if (!head)
		return ;
	if (*head == NULL)
	{
		*head = add;
		(*head)->next = NULL;	//what do you think about this line
	}
	else
	{
		*temp = **head;
		while (temp->next != NULL)
			temp = temp->next;
		add->next = *head; // I THINK THIS SHOULD BE HEAD->NEXT COS WE ARE SPPOSED TO MOVE TO NEXT HEAD OF TETRIS OR WHAT DO YOU THINK
		*head = add;	
	}
}

void	print_linkedlist(tetris *head)
{
	tetris *tmp;
	
	tmp = head;
	int row = 0;
	while (tmp)
	{
		while((tmp->data)[row])
		{
			printf("%s\n", (tmp->data)[row]);
			row++;
		}
		tmp = tmp->next;
	}
	free (tmp);
}

void	free_linkedlist(tetris **list)
{
	tetris	*current;
	tetris	*next;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

int		create_tetriminos(int fd, tetris **linked_list)
{
	char *line;
	int col;
	int row = 0;
	int total_lines = 0;
	int newline_count = 0;
	int pieces_count = 0;
	while (get_next_line(fd, &line))
	{
		if ((strlen(line) != 4) && !(ft_strcmp(line, "") == 0))
		{
			printf("if ((strlen(line) != 4) && !(ft_strcmp(line, "") == 0))");
		 	return (-1);
		}
		 col = 0;	// resetting the column back to zero after every counts for each line
		// while (line[col])
		// {
		// 	if (line[col] != '.' && line[col] != '#')
		// 	{
		// 		printf("if (line[col] != '.' && line[col] != '#')");
		// 		return INVALID_FILE;
		// 	}
		// 	(*linked_list)->pts[col].col = col; // assigning each colomn to x
		// 	col++;
		// }
		// total_lines++;
		// 	// printf("%d \n",(*linked_list)->pts[row].x);
		printf("%s, %d, %d, %d\n", line, newline_count, (*linked_list)->pts[row].col, row);
		// if (total_lines > 26)
		// {
		// 	printf("if (total_lines > 26)");
		// 	return INVALID_FILE;
		// }
		// if (ft_strcmp (line, "") == 0)
		// {
		// 	if (newline_count == 1)
		// 	{
		// 		printf("if (newline_count == 1)");
		// 		return INVALID_FILE;
		// 	}
		// 	newline_count++;
		// }
		// else if (newline_count == 1)
		// {
		// 	if (row != 3)
		// 	{	
		// 		printf("%d", row);
		// 		printf("	if (row != 3)");
		// 		return INVALID_FILE;
		// 	}
		// 	tetris *new = malloc(sizeof(*new));
		// 	append_node(linked_list, new);
		// 	newline_count = 0;
			
		// 	pieces_count++;
		// 	row = 0;
		// }
	    // else 
		// {
		// 	((*linked_list)->data)[row] = line;
		// 	row++;
		// }
	}
	free(line);
	return (0);
}

int		main(int argc, char **argv)
{
	int	fd;
	tetris *linked_list; 

	linked_list = malloc(sizeof(*linked_list));
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (-1);
	}
	fd = open (argv[1], O_RDONLY);
	if (fd != -1)
	{
		create_tetriminos(fd, &linked_list);
	}
	else
	{
		ft_putstr("usage: no such input_file\n");
		return (-1);
	}
	
	// print_linkedlist(linked_list);
	// if (create_tetriminos(fd, &linked_list) == -1)
	// {
	// 	ft_putstr("Invalid File");
	// 	return INVALID_FILE;
	// }
	// solve(t_list);
	// free_linkedlist(&t_list);
	close(fd);
	return (0);
}