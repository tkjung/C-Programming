#include <stdio.h>
// 디스크 1개를 이동할 때는 이 함수를 호출한다.
void move_one(int from, int to)
{
    printf("디스크 한개를 이동합니다. %d --> %d\n", from, to);
}

// 여기에 sohn 함수만 만들면 된다.
void sohn(int size, int from, int to)
{
	int temp;

	if ( size == 1 )
	{
		move_one(from,to);
	}

	else 
	{
		temp = 6 - from - to;
		
		sohn(size -1 , from, temp);

		sohn(1, from, to);

		sohn(size -1 , temp, to);
	}
}

int main()
{
    // 스님.
    int size;  scanf("%d", &size); // size = 하노이탑 블럭 층 수 
    sohn(size, 1, 3);
}
