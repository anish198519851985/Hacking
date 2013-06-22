#include <stdio.h>
#include <string.h>

void printPerm(int *num, int len_so_far,int actual_len) 
{ 
	int start,i; 

	printf("anish %d\n", len_so_far);
	if(len_so_far == actual_len) 
	{ 
		int i;
		len_so_far = 0;
		for(i=0;i<actual_len;i++)
			printf("%d\n",num[i]); 
	} 
	if(len_so_far == 0) 
		start = 1; 
	else 
		start = 0; 
	for(i=start;i<9;i++) 
	{
		printf("anish+ %d\n", len_so_far);
		num[len_so_far] = i; 
		printPerm(num, len_so_far + 1, actual_len); 
	} 
}

int main()
{
	int num[1000] = {0};
	memset(num, 0, sizeof(int)*1000);
	printPerm(num, 0, 4);
}
