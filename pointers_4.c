#include <stdio.h>


// Generalized function, using pointers & pointer math

void * reverse_1 (int *base, int *output, int n, int elemSize, int(*swapFn) (void *, void *))
{
    // make pointer for output array, and allocate memory

    for (int i = 0; i < n; i++){
        // find pointer to each element in array
        // normalize pointer math
        void *oldElemIdx = (char *)base + i * elemSize;

        void *newElemIdx = (char *)output + (n -1 - i) * elemSize;

        // use swap function, dependent on elemSize;
        swapFn(oldElemIdx, newElemIdx);
    }
}


// swap function for integers
void swapInt(int *ap, int *bp){
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}


// swap function for strings
void swapChar(char *ap, char *bp){
    char temp = *ap;
    *ap = *bp;
    *bp = temp;
}


// Testing
void main()
{
    //  test with array of int
    int array[] = {4,2,3,7,11,6};
    int arraySize = 6;
    int output[6] = {};

    reverse_1(array, output, arraySize, sizeof(int), swapInt);
    for (int idx = 0; idx < arraySize; idx++){
        printf("%d ", output[idx]);
    }
    printf("\n");

    // test with string (array of char)
    char *goat = "mountain goat";
    int str_size = 13;
    char str_rev[14] = {};

    reverse_1(goat, str_rev, str_size, sizeof(char), swapChar);
    for (int idx = 0; idx < str_size; idx++){
        printf("%d ", str_rev[idx]);
    }
    printf("\n");

}

