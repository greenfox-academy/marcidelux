#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{

    char totoro[255];
    gets(totoro);
    char *subber;
    subber = strtok(totoro, "- ");
    while (subber != NULL) {
        printf("%s\n", subber);
        subber = strtok(NULL, "- ");
    }

    char pisi[255];
    scanf()



}