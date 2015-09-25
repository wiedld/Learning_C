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
#include <string.h>

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
    // TEST #1 = QUEENS ARE ALL SAFE!

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
    // TEST #2 = removing any symmetries
    // assuming that "symmetry" is a mirrored reflection


    return 1;   // True = success
}


int main()
{
    // get all possible permutations of col
    int array[] = {0,1,2,3,4,5,6,7};
    int n = 8;
    int numPermu = 8*7*6*5*4*3*2;
    int **colPermu = malloc(sizeof(int *) * numPermu);
    int counter[] = {0};
    permute(array, 0, n, colPermu, counter);

    // place to store the winners
    int ***winners;
    int countWinners = 0;

    // for each of these, match with row[1...7] and test
    for (int poss = 0; poss < numPermu; poss++){
        // make row, col, pair
        int **possibleSoln = makeQueensPos(colPermu[poss]);
        // check if valid
        int success = runTest(possibleSoln);

// WHAT trying to fix
        // // what to do if successful
        if (success == 1){
            // if needed, make a larger winners -- copying (int **) pointers from the old winners
            int numElemToCopy = sizeof(winners); // size in bytes
            // int numElemToCopy = sizeof(winners)/sizeof(winners[0]);
            printf("\nnumElemToCopy: %d", numElemToCopy);

            // if (numElemToCopy > 0){
            // if (4 == 3) {

            int bitsToMove = numElemToCopy * sizeof(int **);

            int ***temp = malloc(bitsToMove);
            memcpy(temp, winners, bitsToMove);

  printf("\nWINNER: (%p)\n", winners[0][0]);
  printf("\tTEMP (%p),", temp[0][0]);
  printf("\nWINNERS (%d, %d)", winners[0][0][0], winners[0][0][1]);
  printf("\tTEMP(%d, %d),", temp[0][0][0], temp[0][0][1]);

            // free(winners);

    //         int ***winners =  malloc((numElemToCopy + 1) * sizeof(int **));
    //         memcpy(winners, temp, bitsToMove);
    //         memcpy(winners + numElemToCopy, &possibleSoln, sizeof(int**));


    // printf("\nTEMP (%p),", temp[0][0]);
    // printf("WINNER: (%p)\n", winners[0][0]);
    // printf("WINNERS (%d, %d)", winners[0][0][0], winners[0][0][1]);







            // printf("TEMP (%d, %d)", temp[0][0][0], temp[0][0][1]);
            // int ***winners = temp;
          // }
          // copy newest winners to the end.
            memcpy(winners, &possibleSoln, sizeof(int**));


   // // does this work?
   //        printf("\nrunning");
   //        int ***test;
   //        memcpy(test, &possibleSoln, sizeof(int**));

   //        // memcpy(winners, possibleSoln, sizeof(int**) * (numElemToCopy+1));
   //        printf("TEST (%d, %d)", winners[0][0][0], winners[0][0][1]);
   //  ////////////
        }

///// trying to get rid of this
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
/////////////////
    }


    // print winners, and free memory
    int numSolutions = sizeof(winners);
    printf(" %d\n", numSolutions);
    for (int i = 0; i < numSolutions; i++){
        printf(" \nSolution: ");
        for (int q = 0; q < 8; q++){
            // printf("(%d, %d)  ", winners[i][q][0], winners[i][q][1]);
            // free(winners[i][q]);
        }
        // free(winners[i]);
    }

}


