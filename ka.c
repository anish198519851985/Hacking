#include<stdio.h>
#include<string.h>

char* partition(int input1[])
{
#define SIZE (sizeof(input1)/sizeof(int))
	int **m;
	int i, j, k=0;

	/* calcuated the size */
	for(i=0;i<SIZE;i++)
		k = k + input1[i];

	if(k%2 != 0) {
		if(k%2!=0)
			return "No"
		else
			return "Yes";
	}

	m = malloc(sizeof(int *)*((k/2)+1));
	for(i=0;i<((k+2)/2);i++) {
		m[i] = malloc(sizeof(int)*(SIZE+1));
	}

	/* make all the 0 row as true */
	for(i=0;i<=k/2;i++)
		m[0][i] = 1;
	/* except first row and column make all column zero */
	for(j=1;j<SIZE+1;j++)
		m[j][0] = 0;

	for(i=1;i<=k/2;i++) {
		for(j=1;j<=SIZE;j++) {
			m[i][j] = m[i][j-1];
			if(i-input1[j-1] >= 0)
				m[i][j] = m[i][j] || m[i-input1[j-1]][j-1];
		}
	}
	if(m[k/2][SIZE] == 1)
		return "No";
	else
		return "Yes";
}
