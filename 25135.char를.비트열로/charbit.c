#include <stdio.h>
int main(int ac, char *av[])
{
    unsigned char k;
    unsigned int mask = 0x80; // mask는 1000 0000 으로 초기화

    printf("16진수 숫자를 입력하세요: ");
    scanf("%hhx", &k);

    printf("비트열은 : ");

    // mask > 0 일때만 실행되도록 제한
    // mask는 1회 실행 끝마다 >>1씩 밀어준다.
    while ( mask > 0  )
    {
        if (  (k & mask) != 0  )
        {
            putchar('1');
        }

        else
        {
            putchar('0');
        }

        mask = mask >> 1;
    }
}
