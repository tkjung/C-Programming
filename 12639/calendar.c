#include <stdio.h>

int yoonyear(int year)
{
	if ( year % 4 == 0 )
	{
		if ( year % 100 == 0 )
		{
			if ( year % 400 == 0)
			{
				return 1;
			}

			return 0;
		}
		return 1;
	}

	else 
	{
		return 0;
	}
}

int main(int ac, char *av[])
{
	int yearsum = 365; // 그 해의 총 일 수
	int total_last_sum = 0; // 1970.1.1 ~ 2018.12.31  총 일 수
	int total_this_sum = 0; // 2019.1.1 ~ 2019.6.31 총 일 수
	int yoil = 0;

	//                        1   2   3   4   5   6   7   8   9  10  11 12
	int numDays[12] =       { 31, 28, 31, 30, 31, 30, 31, 31, 30,31, 30,31 };
	int year; // 입력받는 년
	int month; // 입력받는 월
	int boolyoon = 0; // 윤년: 1, 평년: 0
	
	// 년 월 입력
	scanf("%d %d", &year, &month);

	// 윤년 평년 체크
	boolyoon = yoonyear(year);
	
	
	// 1970 ~ 2018 
	for( int i = 1970 ; i < year  ; i++)
	{
		if ( boolyoon == 1 )  // 366으로 만든다.
		{			
			yearsum++;
		}

		total_last_sum = total_last_sum + yearsum; // 더해준 뒤

		if ( boolyoon == 1) // 다시 365로 만든다.
		{
			yearsum--;
		}
	}
	
	printf("이전 해까지 총 일 수 %d\n", total_last_sum);

	
	// 2019의 일수
	for( int j = 0 ; j < month ; j++)
	{
		
		if ( boolyoon == 1 )  // 2월 날짜수를 29로 만든다.
		{			
			numDays[1] = 29;
		}

		total_this_sum += numDays[j];  // 이번 해의 총 일수에 더해준다.
		
		if ( boolyoon == 1 )  // 2월 날짜수를 다시 28로 만든다.
		{			
			numDays[1] = 28;
		}
	}
	
	printf("이번 해의 1월~%d월까지 총 일수: %d\n\n", month, total_this_sum);

	printf("Sun Mon Tue Wed Thu Fri Sat Sun");
	printf("\n=============================\n");

	yoil = (total_last_sum + total_this_sum) % 7;
	
	if( yoil == 0 )
	{

	}

	else if( yoil == 1 )
	{
		printf("\t");
	}

	else if( yoil == 2 )
	{
		printf("\t\t");
	}
	else if( yoil == 3 )
	{
		printf("\t\t\t");
	}
	else if( yoil == 4 )
	{
		printf("\t\t\t\t");
	}
	else if( yoil == 5 )
	{
		printf("\t\t\t\t\t");
	}
	else if( yoil == 6 )
	{
		printf("\t\t\t\t\t\t");
	}
}
