#include <stdio.h>
int main(){
	int arr[5] = {55, 22, 33, 44, 11};
	int *parr[5];  // 정수 포인터 5개로 구성된 배열이다.
	int i;
	for ( i=0; i < 5  ; i++  )
	{
		// parr의 각 요소가 arr의 각 요소를 순서대로 가리키도록 만든다.
		parr[i] = &arr[i]; 
	}

	int *temp;
	temp = parr[0];
	parr[0] = parr[4];
	parr[4] = temp;


	for (i=0; i < 5  ; i++  )
	{
		// parr 배열을 이용하여 55 부터 11까지 현재 순서대로 출력하도록 만든다.
		// arr은 사용하지 않는다.
		printf("%d\n", *parr[i ]  );

	}
	return 0;
}
