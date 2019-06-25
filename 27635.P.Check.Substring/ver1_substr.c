#include <stdio.h>




int find_first(char *haystack, char *needle )
{
	// *haystack == *needle;	
	// *(haystack + 1 ) == *(needle + 1);
	// ...

	while( *needle != 0 && *haystack == *needle )
	{
		haystack++;
		needle++;
	}
	
	// 1. *needle == 0 경우 -> 같은 스트링을 찾았다. return 1;
	// 2. 두 글자가 다르다. 없음  return 0;
	
	if( *needle == 0 )
	{
		return 1;
	}

	else
	{
		return 0;
	}

}

int find_str( char *haystack, char *needle)
{
	while(*haystack != 0)
	{	
		if ( find_first(haystack, needle) )
		{
			return 1;
		}

		haystack++;
	}
	
	return 0;

}


int main(int ac, char *av[])
{
	char one[100];
	char two[20];

	while ( scanf("%s %s", one, two) == 2 ) 
	{
		if( find_str(one, two) == 1 )
		{
			printf("있음\n");
		}
		
		else
		{
			printf("없음\n");
		}
	}

}
