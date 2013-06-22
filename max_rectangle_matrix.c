#include <stdio.h>
#define SIZE 4

int sum[SIZE][SIZE] = {0};
int matrix[SIZE][SIZE] = {
	-1,  -1,  -3,  -4,
	1,  1,  -4,  -2,
	1,  1,  -3,  -4,
	1,  1,  -2,  -1,
};

int sumBetween(int leftCol, int rightCol, int row)
{
	int sum, i;
	sum = 0;
	for(i=leftCol;i<=rightCol;i++)
		sum = matrix[row][i] + sum;
	return sum;
}

int main()
{
	int i, j, t_s, c_b, c_b_s;
	int x, y, z;
	int totalBestSum = -10000000;
	int row, col, leftCol, rightCol, rowSum;

	for (row = 0; row < SIZE; row++) {	
		for (col = 0; col < SIZE; col++) {
			printf("%5d ", matrix[row][col]);
		}
		printf("\n");
	}

	for (leftCol = 0; leftCol < SIZE; leftCol++)
		for (rightCol = leftCol; rightCol < SIZE; rightCol++)
		{
			int curSum = 0, curBestSum = -10000000;
			for (row = 0; row < SIZE; row++) {
				int rowSum = sumBetween(leftCol, rightCol, row);
				curSum += rowSum;
				if (curSum > curBestSum) {
					curBestSum = curSum;
					x = row;
				}
				if (curSum < 0) curSum = 0;                   
			}
			if (curBestSum > totalBestSum) { 
				totalBestSum = curBestSum;
				y = leftCol;
				z = rightCol;
			}
		} 
	printf("%d x %d y %d z %d\n", totalBestSum, x, y, z);
	return 0;
}
