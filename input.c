#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
bool next_token(char *s, int *index, char *buf) {
    char cur;
    if(s[*index] == ' ') {
        (*index) ++;
    } else if(s[*index] == '\0') {
        return false;
    }
    int counter = 0;
    do{
        cur = s[(*index)++];
        buf[counter++] = cur;
    }
    while(s[*index] != ' ' && s[*index] != '\0'); 

    buf[counter] = '\0';
    return true;
}

char *get_input(char *buf) {
}
