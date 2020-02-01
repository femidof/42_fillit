/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:10:15 by vinguyen          #+#    #+#             */
/*   Updated: 2019/12/06 21:24:04 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_piece *head)
{
	t_piece	*tmp;
	int		i;

	i = 0;
	while (head != NULL)
	{
		tmp = head;
		i = 0;
		while (i < 4)
		{
			free(tmp->data[i]);
			i++;
		}
		head = head->next;
		free(tmp);
	}
}

void	free_map(char **map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
