#include <stdio.h>

#define SIZE 100
struct t_{
	int x;
	int y;
	int data;
};
typedef struct t_ t;
t heap[SIZE];
int count =1;

void swap(int x, int y)
{
	t *z = malloc(sizeof(*z));
	memcpy(z, &heap[x], sizeof(*z));
	memcpy(&heap[x], &heap[y], sizeof(*z));
	memcpy(&heap[y], z, sizeof(*z));
}

void i_heap(t ii)
{
	int temp, i;
	temp = count;
	heap[count].x = ii.x;
	heap[count].y = ii.y;
	heap[count].data = ii.data;
	count++;
	/* ok now it is inserted, let's do heap up */
	for(i=temp/2;i>=1;i=i/2) {
		if(heap[i].data > heap[temp].data) {
			swap(i, temp);
			temp = i;
		} else
			break;
	}
}

void delete(int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest = i;

	if(left < count && heap[left].data < heap[largest].data) {
		largest = left;
	}
	if(right < count && heap[right].data < heap[largest].data) {
		largest = right;
	}
	if(largest != i) {
		swap(largest, i);
		delete(largest);
	}
}

t * i_del()
{
	t *temp = malloc(sizeof(t));
	memcpy(temp, &heap[1], sizeof(t));
	if(count == 1)
		return NULL;
	swap(1, --count);
	delete(1);
	return temp;
}

int main()
{
#define M_X 3
#define M_Y 3
	int x[M_X][M_Y] = {
		{42, 32, 12,},
		{1, 1, 2,},
		{1, 1, 4,}
	};
	int out[9] = {0};
	int i;

	t origin;
	t *temp;

	origin.x = 0;origin.y = 0;origin.data = 42;
	i_heap(origin);
#if 1
	while(((temp = i_del()) != NULL) ? 1:0) {
		printf("data is %d\n", temp->data);
		x[temp->x][temp->y] = -1;
		/* start putting the neighbours */
		/*printf("start\n");
		  printf("%d %d\n", temp->x, temp->y);
		  printf("%d %d\n", temp->x+1, temp->y);
		  printf("%d %d\n", temp->x-1, temp->y);
		  printf("%d %d\n", temp->x, temp->y+1);
		  printf("%d %d\n", temp->x, temp->y-1);
		  printf("emd\n");*/
		if(temp->x+1 < M_X && x[temp->x+1][temp->y] != -1) {
			origin.x = temp->x+1;
			origin.y = temp->y;
			origin.data = x[temp->x+1][temp->y];
			i_heap(origin);
			x[temp->x+1][temp->y] = -1;
		}
		if(temp->x-1 >= 0 && x[temp->x-1][temp->y] != -1) {
			origin.x = temp->x-1;
			origin.y = temp->y;
			origin.data = x[temp->x-1][temp->y];
			i_heap(origin);
			x[temp->x-1][temp->y] = -1;
		}
		if(temp->y+1 < M_Y && x[temp->x][temp->y+1] != -1) {
			origin.x = temp->x;
			origin.y = temp->y+1;
			origin.data = x[temp->x][temp->y+1];
			i_heap(origin);
			x[temp->x][temp->y+1] = -1;
		}
		if(temp->y-1 >= 0 && x[temp->x][temp->y-1] != -1) {
			origin.x = temp->x;
			origin.y = temp->y-1;
			origin.data = x[temp->x][temp->y-1];
			i_heap(origin);
			x[temp->x][temp->y-1] = -1;
		}
	}
#endif
	return 0;
}
