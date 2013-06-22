#include <stdio.h>
#define SIZE 5

void flood(int (*a)[SIZE], int i, int j)
{
	if(i >= SIZE || j >= SIZE)
		return;
	if(i < 0 || j < 0)
		return;
	if(a[i][j] == 0) {
		a[i][j] = 1;
		flood(a, i-1, j-1);
		flood(a, i-1, j);
		flood(a, i-1, j+1);
		flood(a, i, j-1);
		flood(a, i, j+1);
		flood(a, i+1, j-1);
		flood(a, i+1, j);
		flood(a, i+1, j+1);
	}
}

int main()
{
	int i, j;
	int a[SIZE][SIZE] = {
		0, 0, 0, 0, 1,
		1, 1, 1, 1, 1,
		0, 1, 0, 1, 1,
		1, 1, 0, 0, 1,
		0, 0, 0, 0, 1,
	};

	flood(a, 0, 0);

	for(i=0;i<SIZE;i++) {
		for(j=0;j<SIZE;j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
