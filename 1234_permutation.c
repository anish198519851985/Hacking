#include <stdio.h>
#define SIZE 4

int count = 0;
int array[100] = {0};
int visited[100] = {0};

void permute(int path[SIZE][SIZE], int s_, int d_)
{
	//printf("%d %d\n", s_, d_);
	/* do sanity check for source and destination */
	if(s_ > 3 || d_ > 3) {
		printf("something fishy here\n");
		return;
	}
	array[count] = s_;
	count++;
	visited[s_] = 1;

	if(s_ == d_) {
		/* print the path */
		int i;
		if(count == 4) {
			for(i=0;i<count;i++)
				printf("%d", array[i]);
		}
		printf("\n");
		return;
	}
	int i;
	for(i=0;i<4;i++) {
		if(path[s_][i] == 1) {
			if(visited[i] == 0) {
				permute(path, i, d_);
				visited[i] = 0;
				count--;
			}
		}
	}
}

int main()
{
	int i, j=3;
	int path[SIZE][SIZE] = {
			0, 1, 1, 1,
			1, 0, 1, 1,
			1, 1, 0, 1,
			1, 1, 1, 0,
			};

	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			//printf("i %d j %d\n", i, j);
			permute(path, i, j);
			count = 0;
			memset(array, 0, sizeof(int)*100);
			memset(visited, 0, sizeof(int)*100);
		}
	}
#if 0
	for(i=0;i<4;i++) {
		permute(path, 3, i);
		count = 0;
		memset(array, 0, sizeof(int)*100);
		memset(visited, 0, sizeof(int)*100);
	}
#endif
	return 0;
}

/*0->1->2->3
  0->1->*/

