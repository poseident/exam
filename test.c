#include <stdio.h>

int main()
{
    char j[4] = "für";
    //j[3] = '\0';
    printf("%d\n", j[1]);
     printf("%d\n", j[2]);
    printf("%c\n", j[0]);
    printf("%c\n", j[1]);
    printf("%c\n", j[2]);
    printf(" prout%c%c\n", -43, -68);
    printf(" prout%c\n", -68);
    printf("%s\n", j);
}