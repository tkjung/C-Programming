#include <stdio.h>
int main()
{
    char data;
    scanf("%hhx", &data) ;  // 작은 정수니까 hhx 로 입력

    if ( data & 0x80 )
    {
        printf("남자\n");
    }
    else
    {
        printf("여자\n");
    }

    if ( data & 0x40 )
    {
        printf("사병\n");
    }
    else
    {
        printf("장교\n");
    }

    if( data & 0x20 )
    {
        printf("현역\n");
    }
    else
    {
        printf("예비역\n");
    }

    return 0;
}
