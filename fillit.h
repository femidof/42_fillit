/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:13:50 by vinguyen          #+#    #+#             */
/*   Updated: 2019/12/06 18:37:50 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	Header files and libraries to include
*/
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/*
**	MACROS
*/
# define INVALID_FILE -1
# define SUCCESS 1
# define END_OF_FILE 0

/*
**	Structs
*/
typedef	struct		s_coords
{
	int				row;
	int				col;
}					t_coords;

typedef	struct		s_piece
{
	char			*data[4];
	char			name;
	struct s_coords	x_locs[4];
	struct s_piece	*next;
}					t_piece;

/*
** Found in file: norm.c
*/
void				normalize_coords(t_coords *x_locs);
void				xy_tetris(t_piece **piece, int x, int y);

/*
** Found in file: output.c
*/
void				print_coords(t_piece *iter);
void				print_pieces(t_piece *head);
void				print_board(char **map, int b_size);

/*
** Found in file: validity.c
*/

t_piece				*create_blank_piece(void);
int					check_adjacency(char **data, t_coords *x_locs);
int					record_tetris_locations
						(t_piece *piece, int row, int *col, int *count_hash);
int					create_piece(int fd, t_piece *piece);
t_piece				*join_pieces(int fd);
int					fill_lines
						(t_coords *rc, int fd, t_piece *piece, int *c_hash);

/*
** Found in file: map.c
*/
int					find_sqrt(int n);
int					get_board_size(int tetra_pieces);
char				**create_empty_board(int b_size);
char				**resize_map(char **map, int map_size);
int					get_num_pieces(t_piece *head);

/*
** Found in file: solve.c
*/
void				solve(t_piece *piece, char **map, int b_size);
char				**algo(char **tetris_map, t_piece *piece, int b_size);
char				**place_tetris(char **map, t_piece *piece, int b_size);
char				**remove_tetris(char **map, t_piece *piece, int b_size);
int					check_tetris(char **map, t_piece *piece, int size);

/*
** Found in file: free.c
*/
void				free_list(t_piece *head);
void				free_map(char **head, int map_size);
#endif
