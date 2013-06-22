#include <stdio.h>
#include <string.h>

void f(char *s, char *rev, int i, int j, int size)
{
	if(*(s+i) == '\0') {
		*(rev+i+size) = '\0';
		return;
	}
	f(s, rev, i+1, j-1, size);	
	*(rev+j) = *(s+i);	
}

int main()
{
	char s[] = {"this is test"};
	char *rev = malloc(strlen(s));
	f(s, rev, 0, strlen(s), strlen(s));
	rev++;
	printf("revers is %s\n", rev);
	return 0;
}
