#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getLongString()
{
    char *p;
    int c;
    int i = 0;
    int curSize = 10;

    p = (char*)malloc(10);

    c = getchar();

    while ( c == ' ' || c == '\t' || c == '\n' )
    {
        c = getchar();
    }

    while ( c != ' ' && c != '\t' && c != '\n' && c != EOF )
    {
        if ( i >= curSize-1 )
        {
            p = (char*)realloc(p, curSize * 2);
            curSize = curSize * 2;
            printf("크기를 %d로 늘렸다.", curSize);
        }

        p[i] = c;
        i++;
        c = getchar();
    }

    p[i] = 0;

    return p;
}


int main(int ac, char *av[])
{
    char *p;
    p = getLongString();
    printf("%s\n", p);
}

