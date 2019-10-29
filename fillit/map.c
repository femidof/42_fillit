#include "fillit.h"

int ft_sqrt(int x)
{
    if (x == 0 || x == 1)
        return (x);
    int start;
    int end = x;
    int ans;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (mid * mid == x)
            return mid;
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return (ans);
}

int tetramino_board(int tetra_pieces)
{
    int all;
    int board;

    all = 4 * tetra_pieces;
    board = ft_sqrt(all);
    if (board <= 4)
        board = 4;
    return board;
}

/*
**  Makes the Board where the solution would would happen, the previous would check for size of board
**  Printed dots on the map as well
*/

t_map *new_map(int board)
{
    t_map *mapp;
    int i;

    mapp = (t_map*)ft_memalloc(sizeof(t_map));
    mapp->map =(char**)ft_memalloc(sizeof(char*) * board);
    i = 0;
    while (i < board)
    {
        mapp->map[i] = ft_strnew(board);
        ft_memset(mapp->map[i], ".", board);
        i++;
    }
    return (mapp);
}

