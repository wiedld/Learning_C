// OBJECTIVE:
// put 8 queens on a chessboard so that none of them attack each other, that is to say, no two of them are in the same column, row or diagonal

// CAVEAT:
// ignore symmetries (presumably meaning mirror images, along the x or y axis?)

// INITIAL APPROACH:
// - board is a raster map (array of arrays, NxN, N=8)
// - queens are denoted as =1. absence as =0
// - test: result would require a sum function to see if any >1
//     - sum across:
//         - row (constant i)
//         - column (contant j)
//         - diagonala:
//                - ascending.
//                - descending.
// - how populate solution?
//     - could be random insertion.
//         > rand(0,7) inclusive.
//     - could be diminishing options.
//         > i = [0...7], 1 of each
//         > j = [0...7], rand()
//         > raster_map[i][j] = 1
//         > then run check for passing test
// - not sure if I'm suppose to get all possible solutions, or only first found. Start with first found.

// OPTIMIZE:
// why do I need to build an entire raster map?
// why not just have 8x2 array? 8 queens, the the 2 values are for i & j on the imaginary chessboard?



#include <stdio.h>
#include <stdlib.h>

int passTest(int **queens)
{
    int rowPos[] = {0,0,0,0,0,0,0,0};
    int colPos[] = {0,0,0,0,0,0,0,0};

    int row;
    int col;
    // sum rows & columns
    for (int q = 0; q < 8; q++){
        row = queens[q][0];
        col = queens[q][1];
        rowPos[row] += 1;
        colPos[col] += 1;

        // check none are above 1
        if (rowPos[row] > 1 || colPos[col] > 1){
            return 0;   // False = failed.
        }
    }
    return 1;   // True = success

}


int main()
{
    // multidimensional array. use heap memory
        // (persist beyond function stack)
    // 8 queens.
    // queenPos[0] = 1st queen, [0][0] = row#, [0][1] = col#
    // queenPos[1] = 2nd queen, [1][0] = row#, [1][1] = col#
    // queenPos[2] = 3rd queen, [2][0] = row#, [2][1] = col#
    int **queenPos;
    queenPos = malloc(sizeof(int *) * 8);

    // using 8 queens, each has unique row, choose random col
    int row;    // make more explicit, what doing
    int col;
    for (int q = 0; q < 8; q++){
        queenPos[q] = malloc(sizeof(int) * 2);
        row = q;
        queenPos[q][0] = row;
        col = rand() % 8;
        queenPos[q][1] = col;
    }

    printf("working \n");


    // free up memory
    for (int q = 0; q < 8; q++){
        free(queenPos[q]);
    }
}