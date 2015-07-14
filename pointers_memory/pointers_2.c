#include <stdio.h>

main()
{
    int x = 1, y = 2, z[10];
    int *ip;

    // ip is now the address value of (points to) x.
    ip = &x;

    // dereference ip, and get the value.
    y = *ip;

    // address in memory for x, is not set to 0
    *ip = 0;

    // ip now points to the array
    ip = &z[10];

    printf("value of x is %d \n", x);
}

