// Reversing a text paragraph,
// learning about stack vs. heap memory,
// and returning pointers to heap memory.


#include <stdio.h>
#include <stdlib.h>


int strLength(char *str)
{
    int length = 0;
    do {
        length++;
    } while (str[length] != '\0');
    return length;
}


int *findNL(char *str, int n)
{
    int count = 0;
    for (int pos = 0; pos < n; pos++){
        if (str[pos] == '\n')
            count++;
    }

    // that line is the same as these two, which might be clearer
    int *posIndeces;
    posIndeces = malloc(sizeof(int) * count);

    int i = 0;
    for (int pos = 0; pos < n; pos++){
        if (str[pos] == '\n'){
            posIndeces[i] = pos;                 // heap mem can use this indexing
            i++;
        }
    }

    return posIndeces;
}


void *reverse_string_literal(char *text)
{
    int len = strLength(text);

    // start with stack memory, size going to reassign name
    char *output = malloc(sizeof(char) * (len + 1));

    int *posIndeces;
    posIndeces = findNL(text, len);

    // should be 43
    printf("%d ", posIndeces[0]);
    printf("%d \n", *posIndeces);

    for (int i = 0; i < len; i++){
        output[(len-1)-i] = text[i];
    }
    output[len] = '\0';

    // free heap memory
    free(posIndeces);
    posIndeces = NULL;

    // convert output to heap memory, so can return

    return output;
}


int main(int argc, char *argv[])
{
    char *test = "A large amount of text all tested together \nand dealing with new line characters as a \ntest of handling conditions in a C program.";
    char *output = reverse_string_literal(test);

    printf("%s \n", output);

    free(output);   // is heap memory

    return 0;
}

