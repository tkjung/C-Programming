#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *ps[3];
    char buf[80];

    for(int i = 0; i < 3; i++)
    {
        scanf("%s", buf);

        ps[i] = (char*)malloc(strlen(buf) + 1);
        strcpy(ps[i], buf);
    }

    for( int i = 2; i >= 0; i--)
    {
        printf("%s\n", ps[i]);
    }
