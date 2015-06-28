#include <stdio.h>


main()
{

    int c, tabs, blanks;

    tabs = 0;
    blanks = 0;

    while( (c = getchar()) != '\n'){
        if (c == '\t')
            ++tabs;
        if (c == ' ')
            ++blanks;

    }

    printf("%d tabs \n", tabs);
    printf("%d blanks \n", blanks);

}
