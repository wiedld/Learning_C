#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to swap values at two pointers */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(int *a, int l, int r, int **results, int *counter)
{
  // printf("%d\n", counter[0]);
  int eaRes = counter[0];
  int i;
   if (l == r){
      printf("position in array: %d\n", eaRes);
      results[eaRes] = malloc(sizeof(int) * 4);
      printf("ADD");
      for (int id=0; id < 4; id++){
        results[eaRes][id] = a[id];
        printf("%d", results[eaRes][id]);
        // printf("added %d\n", *results[eaRes]);
      }
      printf("\n");
      counter[0] = counter[0] + 1;
   } else {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r, results, counter);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

/* Driver program to test above functions */
int main()
{
    int str[] = {1,2,3,4};
    int **outcome = malloc(sizeof(int *) * 24);

    int n = 4;
    int counter[] = {0};
    permute(str, 0, n-1, outcome, counter);

    for (int i=0; i < 24; i++){
      printf("permutation: ");
      for (int j=0; j < 4; j++){
        printf("%d", outcome[i][j]);
        // free(*startOutcome[i]);
      }
      printf("\n");
    }
    return 0;
}