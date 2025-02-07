#include<stdio.h>
#include<string.h>

void strcopy(char *a, char *t){
    while(*t++)
        *a++ = *t;

}

int main(){

    char s[30]="#@Hello World!";
    strcopy(s,s+2);

    printf("%s",s);

}