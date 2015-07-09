#include <stdio.h>


void *reverse_string_literal(char *text)
{
    int len = strLength(text);
    char *output = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++){
        output[(len-1)-i] = text[i];
    }
    output[len] = '\0';

    return output;
}


int strLength(char *str)
{
    int length = 0;
    do{
        length++;
    } while (str[length] != '\0');
    return length;
}


main()
{
    char *test = "a large amount of text all tested together";
    char *result = reverse_string_literal(test);

    printf("output is %s \n", result);
}