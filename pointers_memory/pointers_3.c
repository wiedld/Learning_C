#include <stdio.h>

void strcpy_2 (char *dest, char *src){
    do {
        *dest = *src;
        dest++;
        src++;
    } while (*src != '\0');
}


void strcat_2(char *dest, char *src){
    // get to end of 1st str (to concat onto end)
    while (*dest != '\0'){
        dest++;
    }
    // copy src to the end of dest, and
    // change value of where dest points to
    do {
        *dest = *src;
        dest++;
        src++;
    } while (*src != '\0');
}


void strcat_3(char *dest, char *src, char* output){
    // copy 1st half of string
    do {
        *output = *dest;
        dest++;
        output++;
    } while (*dest != '\0');
    // copy 2nd half of string
    do {
        *output = *src;
        output++;
        src++;
    } while (*src != '\0');
}


main(){
    char *sam = "Sam";
    char sam_2[4] = {};
    strcpy_2(sam_2, sam);
    printf ("%s should be equal to %s \n", sam, sam_2);

    // this give "Bus error: 10" which usually means a mis-aligned memory
    char *mc = "Mc";
    char *end = "Donalds";
    // strcat_2(mc, end);
    // printf ("%s is disturbing \n", mc);

    // try it this way, treating the string pointer as going to
    // a new space in memory. (Like we treat immutable strings when
    // concat in higher languages.)
    char result[10] = {};
    strcat_3(mc, end, result);
    printf ("%s is disturbing \n", result);

}