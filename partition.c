int s[] = {1,5,11,5};
#define SIZE (sizeof(s)/sizeof(s[0]))

int main()
{
	int **m;
	int i, j, k=0;

	/* calcuated the size */
	for(i=0;i<SIZE;i++)
		k = k + s[i];

	if(k%2 != 0)
		return printf("%s+\n", k%2!=0?"No":"Yes");

	m = malloc(sizeof(int *)*((k/2)+1));
	for(i=0;i<=(k/2);i++) {
		m[i] = malloc(sizeof(int)*(SIZE+1));
	}

	/* make all the 0 row as true */
	for(i=0;i<=k/2;i++)
		m[0][i] = 1;
	/* except first row and column make all column zero */
	for(j=1;j<=SIZE;j++)
		m[j][0] = 0;

	for(i=1;i<=k/2;i++) {
		for(j=1;j<=SIZE;j++) {
			m[i][j] = m[i][j-1];
			if(i-s[j-1] >= 0)
				m[i][j] = m[i][j] || m[i-s[j-1]][j-1];
		}
	}
	printf("%s->\n", m[k/2][SIZE]==1?"Yes":"No");
	return 0;
}
