#include <stdio.h>


// EOF means End of File.

// c must be able to hold any cahracter which gets redturned by the file read. ints are 4 bytes (versus char are 1 byte). so use an int.

main()
{
    char c;
    int nc;

    c = getchar();

    while (c != '\n') {
        putchar(c);
        c = getchar();
    }
}