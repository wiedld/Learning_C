#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c;

    while ((c = getchar()) != '\n')
    {

        if (c == ' ' || c == '\t')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }

    printf("\n");
}