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

	yoil = (total_last_sum + total_this_sum) % 7;
 84
 85     printf("요일: %d (0=일,1=월,2=화, .. , 6=토)\n\n", yoil);
 86
 87     printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat");
 88     printf("\n====================================================\n");
 89
 90
 91     for( int k = 0  ; k < 7 ; k++)
 92     {
 93         if(yoil == k)
 94         {
 95             for( int m = 1 ; m <= k ; m++)
 96             {
 97                 printf("\t");
 98             }
 99         }
100     }
101
102
103     if(month == 2)
104     {
105         for( int i = 1 ; i <= 28; i++)
106         {
107             printf("%d\t", i);
108
109             yoil++;
110
111             if( yoil == 7)
112             {
113                 printf("\n");
114                 yoil %= 7;
115             }
116
117         }
118     }
	
	else if ( month == 1 || month == 3 || month == 5 ||
121               month == 7 || month == 8 || month == 10 ||
122               month == 12)
123     {
124
125         for( int i = 1; i <= 31; i++)
126         {
127             printf("%d\t", i);
128             yoil++;
129
130             if( yoil == 7 )
131             {
132                 printf("\n");
133                 yoil %= 7;
134             }
135         }
136     }
137
138     else
139     {
140         for( int i = 1; i <= 30; i++)
141         {
142
143             printf("%d\t", i);
144
145             yoil++;
146
147             if( yoil == 7)
148             {
149                 printf("\n");
150                 yoil %= 7;
151             }
152         }
153     }
154
155     printf("\n");

