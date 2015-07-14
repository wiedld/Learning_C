#include <stdio.h>


// Generalized function, using pointers & pointer math

void * lsearch (void *key, int *base, int n, int elemSize, int(*cmpFn) (void *, void *))
{
    for (int i = 0; i < n; i++){
        // find pointer to each element in array
        // normalize pointer math
        void *elemAddr = (char *)base + i * elemSize;

        // use compare function, to see if item in array match the key you are seeking
        if (cmpFn(key, elemAddr) == 0)
            return elemAddr;
    }
    return NULL;
}


// compare function for integers

int IntCmp (void *elem1, void *elem2)
{
    // Questions: since this is int compare, why not feed in elem1 & elem2 as int * pointers? Why generalize?
    int *ip1 = elem1;
    int *ip2 = elem2;

    return *ip1 - *ip2;
}


// Testing
void main()
{
    int array[] = {4,2,3,7,11,6};
    int arraySize = 6;
    int find = 13;

    int *positionKey = lsearch(&find, array, arraySize, sizeof(int), IntCmp);

    if (positionKey == NULL)
        printf("%d is not found in the array. \n", find);
    else
        printf("%d was found! \n", find);
}

