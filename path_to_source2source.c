#include <stdio.h>
//08022728386

#define SIZE 5
int a[SIZE][SIZE] = {// A, B, C, D, E
			0, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 0, 0, 1,
			1, 1, 0, 0, 1,
			1, 1, 0, 0, 0,
			};
int visited[5]={0};
int count=0;
int path[100]={0};

void dfs(int node, int destination)
{
	int i;

	path[count] = node;
	count++;
	if(visited[node] == 1) {
		/*found the path */
		if(node == destination) {
			int i;
			for(i=0;i<count;i++)
				printf("%d", path[i]);
		}
		printf("\n");
		return;
	}
	visited[node] = 1;
	for(i=0;i<SIZE;i++) {
		if(a[node][i] == 1) {
			dfs(i, destination);
			count--;
		}
	}
	visited[node] = 0;
}

int main()
{
	dfs(4, 4);
	return 0;
}
