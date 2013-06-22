#include <stdio.h>
#define SIZE 3
int a[SIZE][SIZE] = {
	10, 1, 1,
	1,  1, 1,
	1,  1, 7,			
};
int d[9] = {0};
int b[9][9] = {
	0, 1, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
};
int visited[100]={0};
int count=0;
struct path_{
	int i;
	int j;
};
struct path_ path[100];
static int l=0;
static int s_u[100];
static int p=0;

void dfs(int node, int destination)
{
	int i;
	/*found the path */
	if(node == destination) {
		int i, sum=0;
		for(i=0;i<l;i++) {
			if(i == 0)
				sum = sum + d[path[i].i] + d[path[i].j];
			else
				sum = sum + d[path[i].j];
		}
		s_u[p++] = sum;
		l--;
		return;
	}
	visited[node] = 1;
	for(i=0;i<(SIZE*SIZE);i++) {
		if(b[node][i] == 1 && !visited[i]) {
			path[l].i = node;
			path[l].j = i;
			l++;
			dfs(i, destination);
		}
	}
	visited[node] = 0;
	l--;
}

int main()
{
	int i, k, sum, min;
	memset(path, 0, sizeof(struct path_)*100);
	memset(visited, 0, sizeof(int)*100);
	for(i=0;i<(SIZE*SIZE);i++) {
		d[i] = a[i/SIZE][i%SIZE];	
	}
	dfs(0, 8);
	min = s_u[0];
	for(i=0;i<p;i++) {
		if(min > s_u[i])
			min = s_u[i];
	}	
	printf("sum %d\n", min);
	return 0;
}
