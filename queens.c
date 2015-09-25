// OBJECTIVE #1:
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
//         - diagonals:
//                 - descending \
//                         (0,0) = x - y = 0
//                         (1,1) = x - y = 0
//                         **are in same diagonol**
//                         (1,0) = x - y = 1
//                         (2,1) = x - y = 1
//                 - ascending /
//                         (0,3) = -y - x = -3
//                         (1,2) = -y - x = -3
//                         **are in same diagonol**
//                         (2,3) = -y - x = -5
//                         (3,2) = -y - x = -5
// - how populate solution?
//     - could be random insertion.
//         > rand(0,7) inclusive.
//     - could be diminishing options.
//         > i = [0...7], 1 of each
//         > j = [0...7], each j should be unique
//         > raster_map[i][j] = 1
//         > then run check for passing test
// - not sure if I'm suppose to get all possible solutions, or only first found. Start with first found.

// ABSTRACT:
// why do I need to build an entire raster map?
// why not just have 8x2 array? 8 queens, the the 2 values are for i & j on the imaginary chessboard?

////////////////////////////////////////////////////
////////////////////////////////////////////////////

// OBJECTIVE #2;  find all solutions, excluding mirror images.

// MIRRORS:
// reflection across the x axis, or y axis
//     - across y axis:
//         (x,y) --> (max_x - z, y)
//     - across x axis:
//         (x,y) --> (x, max_Y - y)

// HOW KNOW WHEN TO STOP?
//     - before was stopping at first solution found
//     - already trying all row permutations (loop 0->7)
//     - need to try in combination with all possible col permutations.
//     - recursive C.  oh-la-la. first attempt in C.
//     - 8! possible col arrangements
//     - 8! * 8 rows = 40320 * 8 = 322560



#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// HELPER FUNCTIONS

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permute(int *a, int l, int n, int **results, int *counter)
{
  int eaRes = counter[0];
  int i;
   if (l == (n-1)){
      // alloc memory for num array, to add
      results[eaRes] = malloc(sizeof(int) * n);
      // add values
      for (int id=0; id < n; id++){
        results[eaRes][id] = a[id];
      }
      // indexing result array, with a counter being updated by
      // all descendent recursive calls
      counter[0] = counter[0] + 1;
   } else {
       for (i = l; i < n; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, n, results, counter);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

int **makeQueensPos(int *colPos)
{
    // queenPos[0] = 1st queen, [0][0] = row#, [0][1] = col#
    // queenPos[1] = 2nd queen, [1][0] = row#, [1][1] = col#
    // queenPos[2] = 3rd queen, [2][0] = row#, [2][1] = col#
    int **queenPos = malloc(sizeof(int *) * 8);
    int row;
    int col;

    for (int i=0; i < 8; i++){
        queenPos[i] = malloc(sizeof(int*) * 2);
        queenPos[i][0] = i;
        queenPos[i][1] = colPos[i];
    }
    return queenPos;
}


int runTest(int **queens)
{
    int rowPos[] = {0,0,0,0,0,0,0,0};
    int colPos[] = {0,0,0,0,0,0,0,0};

    // range of diagonal operations:
    //     x - y can be -7:7
    //         therefore use array pos 0:14, pos = (x-y)+7
    //     -y - x can be 0:-14
    //         therefore use array pos 0:14, pos = -1 * (-y-x)
    int diaDesc[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int diaAsc[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int row;
    int col;
    int diaD;
    int diaA;
    // sum rows & columns
    for (int q = 0; q < 8; q++){
        row = queens[q][0];
        col = queens[q][1];
        rowPos[row] += 1;
        colPos[col] += 1;

        diaD = (row - col) + 7;
        diaA = ((col*-1) - row ) * -1;
        diaDesc[diaD] += 1;
        diaAsc[diaA] += 1;

        // check none are above 1
        if (rowPos[row] > 1 || colPos[col] > 1 || diaDesc[diaD] > 1 || diaAsc[diaA] > 1){
            return 0;   // False = failed.
        }
    }
    return 1;   // True = success
}


// TODO: getting a failure at possibleOutcome 40024
int main()
{
    // get all possible permutations of col
    int array[] = {0,1,2,3,4,5,6,7};
    int n = 8;
    int numPermu = 8*7*6*5*4*3*2;
    int **colPermu = malloc(sizeof(int *) * numPermu);
    int counter[] = {0};
    permute(array, 0, n, colPermu, counter);

    // for each of these, match with row[1...7] and test
    for (int poss = 0; poss < numPermu; poss++){
        // make row, col, pair
        int **possibleSoln = makeQueensPos(colPermu[poss]);
        // check if valid
        int success = runTest(possibleSoln);
        if (success == 1){
            printf(" \nSolution: ");
        }
        for (int q = 0; q < 8; q++){
            if (success == 1){
                printf("(%d, %d)  ", possibleSoln[q][0], possibleSoln[q][1]);
            }
            free(possibleSoln[q]);
        }
        free(possibleSoln);
    }
}



