#include <stdio.h>


int find(int data[], int size, int needle)
{	
	
	if ( size <= -1 )
	{
		return 0;
	}

	if ( data[size] == needle ) 	
	{
		return 1;
	}

	else
	{
		return find(data,size-1,needle);
	}

}

int main(int ac, char *av[])
{
	int data[10] = { 1,3,6,7,9,  11,12,13,16,17 };
	int needle;  // 찾으려는 정수
	
	scanf("%d", &needle);


	if (    find(data, 10, needle)    )  // find의 반환값이 1이라면,  
	{
		printf("Yes\n");
	}

	else  // find의 반환값이 0 이라면,
	{
		printf("No\n");
	}

}
