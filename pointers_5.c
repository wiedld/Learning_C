#include <stdio.h>


void *reverse_string_literal(char *text)
{
    int len = strLength(text);
    char *output = malloc(sizeof(char) * (len + 1));

    int *posIndeces;
    posIndeces = findNL(text, len);

    // should be 43
    printf("%d ", posIndeces[0]);

    for (int i = 0; i < len; i++){
        output[(len-1)-i] = text[i];
    }
    output[len] = '\0';

    // free(output);    // this will work, because is heap memory.
    return output;      // is returned to new variable in other funct, which is not heap, and therefore cannot be freed there.
}


int strLength(char *str)
{
    int length = 0;
    do {
        length++;
    } while (str[length] != '\0');
    return length;
}


int findNL(char *str, int n)
{
    int count = 0;
    for (int pos = 0; pos < n; pos++){
        if (str[pos] == '\n')
            count++;
    }

    int *posIndeces[sizeof(int) * count];

    int i = 0;
    for (int pos = 0; pos < n; pos++){
        if (str[pos] == '\n'){
            posIndeces[i] = pos;                 // heap mem can use this indexing
            i++;
        }
    }

        // should be 43
    printf("%d \n", posIndeces[0]);

    return posIndeces;
}


main()
{
    char *test = "A large amount of text all tested together \nand dealing with new line characters as a \ntest of handling conditions in a C program.";
    char *output = reverse_string_literal(test);

    printf("%s \n", output);
}

