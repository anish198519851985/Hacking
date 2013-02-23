#include <stdio.h>
#define SIZE 5

struct point {
	int i;
	int j;
	struct point *next;
};
typedef struct point point;
struct point *parent;

void push(point **last, int i, int j)
{
	/* base case when stack is empty */
	if(*last == NULL) {
		point *temp = malloc(sizeof(*temp));
		temp->i = i;
		temp->j = j;
		temp->next = NULL;
		*last = temp;
	} else {
		point *temp = malloc(sizeof(*temp));
		temp->i = i;
		temp->j = j;
		temp->next = *last;
		*last = temp;
	}
}

point *pop(point **last)
{
	point *temp = *last;
	*last = (*last)->next;
	return temp;
}

int stack_empty(point *last)
{
	if(last == NULL)
		return 1;
	else
		return 0;
}
static int path[SIZE][SIZE];

int dfs(int mat[SIZE][SIZE], int i, int j, point **last)
{
	int count = 0;

	if(mat[i][j] == 0)
		return 0;
	/* push 0,0 on the stack */
	push(last, 0, 0);

	while(!stack_empty(*last)) {
		point *co = pop(last);
		if(co->i == SIZE-1 && co->j == SIZE-1) {
			path[co->i][co->j] = 1;
			printing(co);
			count++;
		}
		/* check for neigbours of x*/
		if(co->j +1 < SIZE && mat[co->i][co->j+1] == 1) {
			push(last, co->i, co->j+1);
		}
		if(co->i+1 < SIZE && mat[co->i+1][co->j] == 1) {
			push(last, co->i+1, co->j);
		}
	}
	return count;
}

int k, l;

int dfs_recur(int i, int j, int mat[SIZE][SIZE], point **temp)
{
	if(i >= SIZE || j >= SIZE)
		return 0;
	if(i == SIZE-1 && j == SIZE-1) {
		path[i][j] = 1;
		//		return 1;
		for(k=0;k<SIZE;k++) {
			for(l=0;l<SIZE;l++) {
				if(path[k][l] == 1)
					printf("%d %d\n", k, l);
			}
		}
		printf("starting new\n");
	}
	if(mat[i][j] == 1) {
		path[i][j] = 1;
		if(dfs_recur(i, j+1, mat, temp)) {
			return 1;
		}
		if(dfs_recur(i+1, j, mat, temp)) {
			return 1;
		}
		return 0;
	}
	return 0;
}

int main()
{
	int i, j;
	point *last;
	point *parent;
	last = NULL;
	int mat[SIZE][SIZE] = {
		1, 1, 1, 1, 1,
		1, 0, 0, 0, 1,
		1, 0, 0, 0, 1,
		1, 0, 0, 0, 1,	
		1, 1, 1, 1, 1,	
	};
	//	printf("%d\n", dfs(mat, 0, 0, &last));
	dfs_recur(0, 0, mat, &last);
#if 0
	for(i=0;i<SIZE;i++) {
		for(j=0;j<SIZE;j++) {
			if(path[i][j] == 1)
				printf("%d %d\n", i, j);
		}
	}
#endif
}
