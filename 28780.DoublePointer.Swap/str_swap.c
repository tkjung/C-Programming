#include <stdio.h>
void swap(char **one, char **two){
	char *t;
	t = *one; *one = *two; *two = t;
}

int main(){
	char *p = "First string.";
	char *q = "Second stringgggggggggggggggggg.";;

	swap(&p, &q);
	printf("%s %s\n", p, q);
	return 0;
}
