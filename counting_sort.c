#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int main()
{
	int i;
	int a[] = {3, 4, 3, 4, 3};
	static int count[SIZE]; /* make it equal to size of the biggest element of the array*/

	for(i = 0; i < SIZE;i++)
		count[a[i]]++;

	for(i = 0; i < SIZE;i++) {
		do{
			if(count[i]) {
				printf("%d\n", i);
				count[i]--;
			}
			if(count[i] == 0)
				break;
		}while(1);
	}
	return 0;
}
