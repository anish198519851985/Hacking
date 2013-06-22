#include <stdio.h>
int a[2][4] = {
        3, 44, 15, 13,
        100, 77, 88, 11
};
int dist[100][100];
int n, m;

#define max(a,b) ((a)>(b)?(a):(b))

int DepthSearch(int x, int y)
{
	printf("- %d\n", a[x][y]);
	printf("%d %d\n", x, y);
	int sum=0;

	if(dist[x][y])
		return dist[x][y];

	if(y-1 >= 0 && a[x][y] > a[x][y-1]) {
		sum = max(DepthSearch(x, y-1), sum);
	}

	if(y+1 < n && a[x][y] > a[x][y+1]) {
		sum = max(DepthSearch(x, y+1), sum);
	}

	if(x+1 < m && a[x][y] > a[x+1][y]) {
		sum = max(DepthSearch(x+1, y), sum);
	}

	if(x-1 >= 0 && a[x][y] > a[x-1][y]) {
		sum = max(DepthSearch(x-1, y), sum);
	}
	printf("ended\n");
	dist[x][y] = sum+1;
	return dist[x][y];
}

int solution()
{
	int mx = 0,i, j;
	for(i = 0; i < m; ++ i)
		for(j = 0; j < n; ++ j)
			mx = max(mx, DepthSearch(i, j));
	return mx;
}

int main()
{
	int i, j;
	m=2;
	n=4;

	for(i = 0; i < m; ++ i)
		for(j = 0; j < n; ++ j)
			dist[i][j] = 0;

	printf("%s: %d\n", "anish", solution());
	return 0;
}
