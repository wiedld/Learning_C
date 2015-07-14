#include <stdio.h>


main()
{

    int c;

    while( (c = getchar()) != '\n')
    {
        if (c == ' '){
            printf("'\\b'");
        }
        else if (c == '\t'){
            printf("\\t'");

        }else{
            putchar(c);
        }

    }
    printf("\n");

}
