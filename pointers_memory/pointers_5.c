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
            posIndeces[i] = pos;       // heap mem can use indexing
            i++;
        }
    }

    return posIndeces;
}


void *reverse_string_literal(char *text)
{
    int str_len = strLength(text);

    // make heap memory, so can pass pointer btwn functions
    char *output = malloc(sizeof(char) * (str_len + 1));

    // pointer gets set to heap memory, array of ints
    int *posIndeces;
    posIndeces = findNL(text, str_len);

    int j = 0;
    int start = 0;
    int end = posIndeces[j];
    int len_posIdx = sizeof(posIndeces)/sizeof(posIndeces[0]);

    for (int i = 0; i < str_len; i++){
        // swap 1st line, up to \n char
        output[end - i + start - 1] = text[i];
        // once hit end of first row in paragraph
        if (i == end - 1) {
            output[start] = '\n';
            j++;    // get index of next \n char
            start = end;
            end = posIndeces[j];
            // if hit end of posIndeces of '\n'
            if (j >= len_posIdx){
                end = str_len;
            }
        }
    }
    output[str_len] = '\0';

    // free heap memory
    free(posIndeces);
    posIndeces = NULL;

    return output;
}


int main(int argc, char *argv[])
{
    char *test = "A large amount of text all tested together\nand dealing with new line characters as a\ntest of handling conditions in a C program.\n";
    char *output = reverse_string_literal(test);


    printf("%s", output);

    free(output);   // is heap memory
    return 0;
}

