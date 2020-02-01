/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:28:03 by vinguyen          #+#    #+#             */
/*   Updated: 2019/12/06 18:57:03 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fill_lines(t_coords *rc, int fd, t_piece *piece, int *c_hash)
{
	int		ret;
	char	*line;

	while (rc->row < 4 && (ret = get_next_line(fd, &line) > 0) && line[0])
	{
		rc->col = 0;
		piece->data[rc->row] = ft_strdup(line);
		free(line);
		if (record_tetris_locations(piece, rc->row++, &rc->col, c_hash) == -1)
			return (INVALID_FILE);
		if (rc->col != 4)
			return (INVALID_FILE);
	}
	return (ret);
}
