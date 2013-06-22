#define SIZE 7
#define INFINITY 9999
#define UNFILL 11
#define FILL 12
#define SHADE 13

int a[SIZE][SIZE] = {
	1,0,1,1,1,1,0,
	0,1,0,0,0,1,1,
	1,0,1,1,1,0,1,
	0,1,1,1,1,0,1,
	0,0,1,1,1,1,1,
	1,1,0,0,0,1,1,
	1,1,1,1,1,1,1,
};

struct queue{
	int x;
};
typedef struct queue qu;
qu q[100];
int size=0;

void enq(int e)
{
	q[size++].x = e;
}

int deq()
{
	size--;
	return q[size].x;
}

int iE()
{
	return size?1:0;		
}

int main()
{
	int i;
	int d[100];
	int previous[100];
	int color[100];

	for(i=0;i<SIZE;i++) {
		d[i] = INFINITY;
		color[i] = UNFILL;
		previous[i] = -1;
	}
	/* 3 is the starting source */
	color[4] = SHADE;
	d[4] = 0;
	previous[4] = -1;
	enq(4);

	while(iE(q)) {
		int flag=1;
		int i, j;
		int e = deq();
		printf("deq %d\n", e);
		for(i=e;flag;) {
			for(j=0;j<SIZE;j++) {
				if(a[i][j] == 0) {
					if(color[j] != FILL && color[j] != SHADE) {
						printf("j %d\n", j);
						color[j] = SHADE;
						d[j] = d[i] + 1;
						previous[j] = i;
						enq(j);
					}
				}
			}
			color[i] = FILL;
			flag=0;
		}
	}

	for(i=0;i<SIZE;i++) {
		printf("%d\n", d[i]);
	}
	return 0;
}
