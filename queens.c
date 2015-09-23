// OBJECTIVE:
// put 8 queens on a chessboard so that none of them attack each other, that is to say, no two of them are in the same column, row or diagonal

// CAVEAT:
// ignore symmetries (presumably meaning mirror images, along the x or y axis?)

// APPROACH:
// - board is a raster map (array of arrays, NxN, N=8)
// - queens are denoted as =1. absence as =0
// - test: result would require a sum function to see if any >1
//     - sum across:
//         - row (constant i)
//         - column (contant j)
//         - diagonal (constant difference, i-j)
// - how populate solution?
//     - could be random insertion.
//         > rand(0,7) inclusive.
//     - could be diminishing options.
//         > set_i = [0...7], remove each i
//         > set_j = [0...7], remove each j
//         > raster_map[i][j] = 1
//         > repeat until populate board
//         > then run check for passing test
// - not sure if I'm suppose to get all possible solutions, or only first found. Start with first found.


#include <stdio.h>
#include <stdlib.h>

int passTest(int **array)
{
    // sum rows & columns
    for (int i = 0; i < 8; i++){
        int sumJ = 0;
        for (int i = 0; i < 8; i++){
            sumJ += array[i][j]
        }
        if (sumJ > 1){
            return 0;
        }
    }



}


int main()
{
    int **chessBoard;
    chessBoard = malloc(sizeof(int *) * 8);
    for (int row = 0; row < 8; row++){
        chessBoard[row] = malloc(sizeof(int) * 8);
    }

    // run program


    for (int row = 0; row < 8; row++){
        free chessBoard[row];
    }
}