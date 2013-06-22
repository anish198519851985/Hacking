#define SIZE 7
#define INFINITY 9999

struct q_i{
	int i;
	int j;
};
struct queue{
	struct q_i q[100];
	int size;
};
typedef struct queue qu;
int distance[100][100]={0};
void enq(qu *q, int i, int j)
{
	q->q[q->size].i = i;
	q->q[q->size].j = j;
	q->size++;
}

struct q_i *deq(qu *q)
{
	q->size--;
	return &q->q[q->size];
}

int iE(qu *q)
{
	return q->size?1:0;		
}
int po[] = {1, -1, 1, 1, -1, -1, -1, 1};
int main()
{
	int i, level=0,j;
	qu *q=malloc(sizeof(qu)*100);
	memset(q, 0, sizeof(qu)*100);

	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			distance[i][j]=INFINITY;
	enq(q, 0, 0);
	distance[0][0] = 0;
	while(iE(q)) {
		int i, j, x_, y_;
		struct q_i *e = deq(q);
		printf("%d %d\n", e->i, e->j);
		x_ = e->i;y_=e->j;
		if(e->i == 7 && e->j == 7) {
			printf("found %d\n", distance[7][7]+1);
			return;	
		}
		for(i=0;i+1<sizeof(po)/sizeof(po[0]);i+=2) {
			int x, y;
			x=x_+po[i];
			y=y_+po[i+1];
			if(x >= 0 && x < 8 && y >= 0 && y < 8) {
				if(distance[x][y] == INFINITY) {
					distance[x][y]	= 1+ distance[x_][y_];
					enq(q, x, y);
				}
			}
		}
	}
	return 0;
}
