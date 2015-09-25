#include <stdio.h>
#include <stdlib.h>


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


int main()
{
<<<<<<< HEAD
    int array[] = {1,2,3,4};
    int n = 4;
    int numPermu = 24;
=======
    int array[] = {0,1,2,3,4,5,6,7};
    int n = 8;
    int numPermu = 8*7*6*5*4*3*2;
>>>>>>> recursive_C
    int **outcome = malloc(sizeof(int *) * numPermu);
    int counter[] = {0};

    permute(array, 0, n, outcome, counter);

    for (int i=0; i < numPermu; i++){
      printf("permutation: ");
      for (int j=0; j < n; j++){
        printf("%d", outcome[i][j]);
      }
      printf("\n");
      free(outcome[i]);
    }
    return 0;
}