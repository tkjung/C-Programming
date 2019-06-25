#include <stdio.h>

void append (char *one, char *two  )
{
	while ( *one != 0  )
	{
		one++;
	}

	while (   (*one++ = *two++)   )
	{	
	}

}

int main()
{
	char one[100]; // Hello  
	char two[100]; // World
	
	scanf("%s %s", one, two);
	
	append(one, two);
	
	printf("%s\n", one);  // HelloWorld
	
	return 0;
}
