#include <stdio.h>

int getSize( int *pStu, int *pCourse )
{
	int numStu2 = -1; // 입력받는 학생 수
	int numCourse2 = -1; // 입력받는 과목 수

	printf("학생 수를 입력하세요: ");
	scanf("%d", &numStu2 );  
	
	printf("과목 수를 입력하세요: ");
	scanf("%d", &numCourse2 );


	// 학생수= 1 ~ 100명, 과목수= 1 ~ 10개
	if (  (1 <= numStu2 && numStu2 <= 100) && ( 1 <= numCourse2 && numCourse2 <= 10 ) ) 
	{
		*pStu = numStu2;
		*pCourse = numCourse2; 
		return 1;
	}

	else if (  (numStu2 < -2 || numStu2 == 0 || numStu2 > 100) // 학생수= 0이하 or 100초과
			   || (numCourse2 < -2 || numCourse2 == 0 || numCourse2 > 10)  ) // 과목수=0이하 or 10초과
	{
		getSize(&numStu2, &numCourse2);
		
		*pStu = numStu2;
		*pCourse = numCourse2; 
		return 1;
	}

	else if ( numStu2 == EOF || numCourse2 == EOF ) // 학생수=EOF가 되면, 0을 돌려줌으로써 종료
	{
		return 0;
	}
	
	else // 학생수=숫자가 아닌 문자가 되면, 0을 돌려줌으로써 종료
	{
		return 0;
	}
}

int main(int ac, char *av[])
{
	int numStu = 0;  // 학생 수
	int numCourse = 0; // 과목 수

	if (  getSize( &numStu, &numCourse )  == 1  )
	{
		printf("학생 수: %d, 과목 수: %d\n", numStu, numCourse);
	}

	else
	{
		printf("실패\n");
	}

}
