/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:41:46 by vinguyen          #+#    #+#             */
/*   Updated: 2019/12/07 21:53:56 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_piece	*head;
	char	**map;
	int		fd;
	int		num_pieces;
	int		b_size;

	fd = 0;
	if (argc != 2 || ((fd = open(argv[1], O_RDONLY)) < 0))
	{
		(fd < 0) ? ft_putendl("usage: file does not exist") :
			ft_putendl("usage: ./fillit [input_file]");
		return (INVALID_FILE);
	}
	if (!(head = join_pieces(fd)))
	{
		ft_putendl("error");
		return (INVALID_FILE);
	}
	num_pieces = get_num_pieces(head);
	b_size = get_board_size(num_pieces);
	map = create_empty_board(b_size);
	solve(head, map, b_size);
	close(fd);
	return (0);
}
