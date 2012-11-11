/* http://en.wikipedia.org/wiki/Dynamic_programming */
#include <stdio.h>
#define SIZE 5
#define INFINITY 10000

int matrix[SIZE][SIZE] = { 11,  5, 0 , 7,  1,
			   1 , 11, 8,  5,  2,
			   31, 11, 11, 0,  3,
			   1 , 9,  1,  0,  1,
			   0,  1,  2,  3,  10};

int min(int a, int b, int c)
{
	int x = (a < b? a:b);
	int y = (x < c? x:c);
	return y;
}

int min_cost(int i, int j)
{
	if(j < 0 || (j > (SIZE-1)) || i < 0 || (i > SIZE-1))
		return 10000;
	if(i == SIZE-1)
		return matrix[i][j];
	return min(min_cost(i+1, j), min_cost(i+1, j-1), min_cost(i+1, j+1)) + matrix[i][j];
}

void print_path(int i, int j, int (*p)[SIZE])
{
	printf("%d\n", matrix[i][j]);
	if(i == 1)
		printf("%d,\n", matrix[0][j+p[i][j]]);
	else
		print_path(i-1, j+p[i][j], p);
}

void compute_shortest_path(int (*copy)[SIZE], int (*p)[SIZE])
{
	int min = copy[SIZE-1][0];
	int i = 0;
	int minIndex = 0;

	while(i < SIZE) {
		if(copy[SIZE-1][i] < min) {
			min = copy[SIZE-1][i];
			minIndex = i;
		}
		i++;
	}
	printf("index is i %d,j %d and value is %d\n", 0, minIndex, copy[SIZE-1][minIndex]);
	print_path(SIZE-1, minIndex, p);
}

void min_cost_with_dp()
{
	int i, j, m;
	int p[SIZE][SIZE] = {0};
	int copy[SIZE][SIZE] = {0};
	int k = 0;

	printf("added matrix\n");
	while(k < SIZE) {
		printf("%d,  ", matrix[0][k]);
		if(k != 1)
			copy[0][k] = INFINITY;
		else
			copy[0][1] = matrix[0][k];
		k++;
	}
	printf("\n");

	for(i=1;i<SIZE;i++){
		for(j=0;j<SIZE;j++) {

			if(j == 0)
				m = min(copy[i-1][j], copy[i-1][j+1], INFINITY);
			else if(j == (SIZE-1))
				m = min(copy[i-1][j], copy[i-1][j-1], INFINITY);
			else
				m = min(copy[i-1][j], copy[i-1][j-1], copy[i-1][j+1]);

			copy[i][j] = m + matrix[i][j];
			printf("%d, ", copy[i][j]);
			if(m == copy[i-1][j]) {
				p[i][j] = 0;
			} else if(m == copy[i-1][j-1]) {
				p[i][j] = -1;
			} else {
				p[i][j] = 1;
			}
		}
		printf("\n");
	}
	compute_shortest_path(copy, p);
}

int main()
{
	int i, j;
#if 0
	printf("%d\n", min_cost(0, 0));	
#endif
	for(i=0;i<SIZE;i++) {
		for(j=0;j<SIZE;j++){
			printf("%d   ", matrix[i][j]);
		}
		printf("\n");
	}
	min_cost_with_dp();	
	return 0;
}
