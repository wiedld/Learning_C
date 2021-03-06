#include <stdio.h>
#include <stdlib.h>


// Generalized function, using pointers & pointer math

void reverse_1 (void *base, int n, int elemSize, void (*swapFn) (void *, void *))
{
    for (int i = 0; i < (n/2); i++){
        // find pointer to each element in array
        // normalize pointer math
        void *newElemIdx = (char *)base + i * elemSize;

        void *oldElemIdx = (char *)base + (n -1 - i) * elemSize;

        // use swap function, dependent on elemSize;
        swapFn(newElemIdx, oldElemIdx);
    }
}


// swap function for integers
void swapInt(void *ap, void *bp){
    int *_ap = (int *) ap;
    int *_bp = (int *) bp;

    int temp = *_ap;
    *_ap = *_bp;
    *_bp = temp;
}


// swap function for strings
void swapChar(void *ap, void *bp){
    char *_ap = (char *) ap;
    char *_bp = (char *) bp;

    char temp = *_ap;
    *_ap = *_bp;
    *_bp = temp;
}


// Testing.
int main()
{
    //  TEST with array of int
    int array[] = {4,2,3,7,11,6};
    int arraySize = 6;

    reverse_1(array, arraySize, sizeof(int), swapInt);
    for (int idx = 0; idx < arraySize; idx++){
        printf("%d ", array[idx]);
    }
    printf("\n");

    // TEST with string (array of char)
        // two identical ways to make string
    char goat[] = "mountain goat";
    // char goat[] = {'m','o','u','n','t','a','i','n',' ','g','o','a','t','\0'};
    int str_size = 14;

    reverse_1(goat, str_size, sizeof(char), swapChar);
    for (int idx = 0; idx < str_size; idx++){
        printf("%c", goat[idx]);
    }
    printf("\n");

    return 0;
}

