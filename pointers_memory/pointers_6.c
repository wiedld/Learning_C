#include <stdio.h>


int main()
{
    printf("INTEGERS\n");
    int x = 8;
    printf("x: %d \n", x);
    printf("&x: %p \n", &x);
    printf("sizeof(x): %lu \n", sizeof(x) );\
    printf("Cannot do *x \n\n\n");



    printf("ARRAY\n");
    int array[] = {1,2,3,4,5};
    printf("size of array: %lu \n", sizeof(array));
    printf("size of int: %lu \n", sizeof(int));
    printf("size of *array: %lu \n\n", sizeof(*array));

    printf("'array' is actually a pointer to the first value \n");
    // get first value
    printf("*(array): %d \n", *array);
    printf("array: %p \n", array);
    printf("&array: %p \n", &array);
    printf("*(&array): %p \n", *(&array) );
    printf("**(&array): %d \n\n", **(&array) );


    printf("Location of 2nd element in array: \n");
    // manually update address, to get second value
    printf("&(array[1]): %p \n", &(array[1]) );
    // manually update address, to get second value
    printf("*(&(array[1])): %d \n", *(&(array[1])) );
    // pointer math, to get second value
    printf("*(array+1): %d \n\n", *(array+1) );

    printf("Decaying the pointer: \n");
    printf("size of array: %lu \n", sizeof(array));
    int *newPointer;
    newPointer = array;
    printf("size of newPointer: %lu \n", sizeof(newPointer));


    return 0;
}
