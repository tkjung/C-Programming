#include <stdio.h>
int find_first(char *haystack, char *needle )
{
	return ( *needle == 0 ||  (  (*haystack == *needle) &&  find_first(haystack+1, needle+1) )  );
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
