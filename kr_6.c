#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c, nw, nc, state;

    state = OUT;
    nw = nc = 0;

    while ((c = getchar()) != '\n')
    {
        ++nc;

        if (c != ' ' && c != '\t')
        {
            if (state == OUT)
            {
                ++nw;
                state = IN;
            }
        }
        else
        {
            state = OUT;
        }
    }

    printf("%d words and %d characters \n", nw, nc);

}