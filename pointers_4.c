#include <stdio.h>
#include <stdlib.h>


// Generalized function, using pointers & pointer math

void *reverse_1 (void *base, int n, int elemSize, void(*swapFn) (void *, void *))
{
    void *output = malloc(elemSize * n);

    for (int i = 0; i < n; i++){
        // find pointer to each element in array
        // normalize pointer math
        void *newElemIdx = (char *)output + i * elemSize;

        void *oldElemIdx = (char *)base + (n -1 - i) * elemSize;

        // use swap function, dependent on elemSize;
        swapFn(newElemIdx, oldElemIdx);
    }

    return output;
}


// swap function for integers
void swapInt(int *ap, int *bp){
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}


// swap function for strings
void swapChar(char *ap, char *bp){
    // char temp = *ap;
    *ap = *bp;
    // *bp = temp;
}


// Testing
int main()
{
    //  TEST with array of int
    int array[] = {4,2,3,7,11,6};
    int arraySize = 6;

    int *result = reverse_1(array, arraySize, sizeof(int), swapInt);
    for (int idx = 0; idx < arraySize; idx++){
        printf("%d ", result[idx]);
    }
    printf("\n");

    // TEST with string (array of char)
    char goat[] = {'m','o','u','n','t','a','i','n',' ','g','o','a','t'};
    int str_size = 13;

    char *result2 = reverse_1(goat, str_size, sizeof(char), swapChar);

    for (int idx = 0; idx < str_size; idx++){
        printf("%c", result2[idx]);
    }
    printf("\n");

}

