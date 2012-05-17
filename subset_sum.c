#include <stdio.h>

/*
url:http://www.cs.utsa.edu/~wagner/CS3343/dp/subsetsum.html

Dynamic Programming Approach: The techniques of dynamic programming will let us tackle this problem. Consider first an extremely simple example, 
 where A = {1, 9, 5, 3, 8}, and the sum of a subset is 13. Below I show contents of a work array W, where W[k] != -1 means that k is the sum of elements of A. 
 Notice that indexes of elements in the W array correspond to sums of elements of the A array.
 
Possible #s  <--------------------  W Array Index  ---------------------------------------->
 in sum      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

Initial:     0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
{1}:         0  1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
{1,9}:       0  1 -1 -1 -1 -1 -1 -1 -1  9  9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
{1,9,5}:     0  1 -1 -1 -1  5  5 -1 -1  9  9 -1 -1 -1  5  5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
{1,9,5,3}:   0  1 -1  3  3  5  5 -1  3  9  9 -1  3  3  5  5 -1  3  3 -1 -1 -1 -1 -1 -1 -1 -1 
{1,9,5,3,8}: 0  1 -1  3  3  5  5 -1  3  9  9  8  3  3  5  5  8  3  3 -1  8  8  8  8 -1  8  8 

This displays the sums that are possible using the elements of A in turn:

In the 0th row, initial values for W, empty seet yields sum of 0.
In the 1st row, possible elements {1} yield sums of 0,1.
In the 2nd row, possible elements {1,9} yield sums of 0,1,9,10.
In the 3rd row, possible elements {1,9,5} yield sums of 0,1,5,6,9,10,14,15.
In the 4th row, possible elements {1,9,5,3} yield sums of 0,1,3,4,5,6,8,9,10,12,13,14,15,17,18.
In the 5th row, possible elements {1,9,5,3,8} yield sums of all but 2,7,19,24.
*/

void populate_work(int *copy_work, int *work, int work_total, int orig_total)
{
	int i, j, k, a;
	work[0] = 0;	

	for (k = 1; k < work_total; k++) 
		work[k] = -1;

	for (j = 0; j < orig_total; j++) {
		a = copy_work[j];
		for (k = 0; k < work_total; k++) {
			if ((work[k] != -1) && (work[k] !=  a) && (k + a < work_total) && (work[k + a] == -1))
				work[k + a] = a;
		}
	}
}

main()
{
	int *work;
	int total, copy_total, i = 0, sum = 0;
	int *work_copy;

	printf("enter the total elements\n");
	scanf("%d", &total);
	copy_total = total;

	work = malloc(sizeof(int)*(total));

	while(i < total)
	{
		scanf("%d", &work[i]);
		i++;
	}

	i = 0;
	while(i < total)
	{
		sum = sum + work[i];
		i++;
	}

	work_copy = malloc((sizeof(int)*sum)+1);
	populate_work(work, work_copy, sum+1, total);

	printf("sum %d\n", sum);
	i = 0;
	while(i < sum+1)
	{
		printf("%d\n", work_copy[i]);
		i++;
	}
}
