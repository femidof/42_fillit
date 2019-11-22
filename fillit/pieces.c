#include <unistd.h>

// piece1[4][4] = {"####","....","....","...."};
// piece2[4][4] = {"#...","#...","#...","#..."};
// piece3[4][4] = {"##..","##..","....","...."};
// piece4[4][4] = {"##..",".##.","....","...."};
// piece5[4][4] = {".##.","##..","....","...."};
// piece6[4][4] = {"#...","##..",".#..","...."};
// piece7[4][4] = {".#..","##..","#...","...."};
// piece8[4][4] = {".#..","###.","....","...."};
// piece9[4][4] = {"###.",".#..","....","...."};
// piece10[4][4] = {".#..","##..",".#..","...."};
// piece11[4][4] = {"#...","##..","#...","...."};
// piece12[4][4] = {"###.","#...","....","...."};
// piece13[4][4] = {"###.","..#.","....","...."};
// piece14[4][4] = {"#...","###.","....","...."};
// piece15[4][4] = {"..#.","###.","....","...."};
// piece16[4][4] = {"##..","#...","#...","...."};
// piece17[4][4] = {"##..",".#..",".#..",".#.."};
// piece18[4][4] = {"#...","#...","##..","...."};
// piece19[4][4] = {".#..",".#..","##..","...."};

// check for min row 
// move row until minrow is 0 
// do same to column

int ft_sqrt(int n)
{
    int x = n; 
    int y = 1; 
    while (x > y) { 
        x = (x + y) / 2; 
        y = n / x; 
    } 
    return (x); 
}

int tetramino_board(int tetra_pieces)
{
    int all;
    int board;
    all = 4 * tetra_pieces;
    board = ft_sqrt(all);
    if (board <= 4)
        board = 4;
    // write(1, &board,2);
    
    return board;
}

// #include <stdio.h>
// int main(void)
// {
//     printf("AM I HERE\n");
//     char x = 'A';//ft_sqrt(4);
//     write(1, &x, 1);
//     return 0;
// }
int main(void)
{
    int board;
    board = tetramino_board(7);
    
    int i;
    int j;
    i = 0;
    char map[board][board];
    while (i < board)
    {
        j = 0;
        while (j < board)
        {
            map[i][j] = '.';
            write(1,&map[i][j],1);
            j++;
        }
        write(1,"\n",1);
        i++;
    }
    return (0);
}