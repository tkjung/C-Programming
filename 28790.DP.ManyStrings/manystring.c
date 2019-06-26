#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char *av[])
{
    char **str;
    int num;

    scanf("%d", &num);

    str = (char**)malloc(sizeof(char*) * num);

    for( int i = 0 ; i < num ; i++)
    {
        char buffer[100];

        scanf("%s", buffer);

        str[i] = (char*)malloc( strlen(buffer) +1 );
        strcpy(str[i], buffer);
    }

    for( int i = num - 1 ; i >= 0 ; i--)
    {
        printf("%s\n", str[i]);
    }

}
