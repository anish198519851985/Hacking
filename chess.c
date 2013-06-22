#define SIZE 8
#define VISITED 567

int KnightMove(int (*a)[SIZE], int m, int n, int currx, int curry)
{
	if(currx<0 || curry <0)
		return 0;
	if(currx >= SIZE || curry >= SIZE)
		return;
	//checking if 3,3 is reachable or not as we are starting
	//from 0,0 index.
	if(currx == 3  && curry == 3) {
		a[currx][curry] = VISITED;
		printf("%d %d\n", currx, curry);
		return 1;
	} if(a[currx][curry] == VISITED)
		return 0;
	else
	{
		printf("%d %d\n", currx, curry);
		a[currx][curry] = VISITED;
		//move forward
		if(KnightMove(a, m, n, currx-1, curry+2) == 1)
			return 1;
		if(KnightMove(a, m, n, currx+1, curry+2) == 1)
			return 1;
		//move sideways
		if(KnightMove(a, m, n, currx-2, curry+1) == 1)
			return 1;
		if(KnightMove(a, m, n, currx-2, curry-1) == 1)
			return 1;
		if(KnightMove(a, m, n, currx+2, curry+1) == 1)
			return 1;
		if(KnightMove(a, m, n, currx+2, curry-1) == 1)
			return 1;
		if(KnightMove(a, m, n, currx-1, curry-2) == 1)
			return 1;
		if(KnightMove(a, m, n, currx+1, curry-2) == 1)
			return 1;
	}
} 

void printSolution(int sol[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			printf("%8d", sol[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[SIZE][SIZE] = {0};
	memset(a, 0, sizeof(int)*SIZE*SIZE);
	KnightMove(a, SIZE, SIZE, 0, 0);
	printSolution(a);	
	return 0;
}
