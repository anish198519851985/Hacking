int q[20],visited[20],n,f=0,r=-1,max=0;
int **a;
int **m;
static int inc=0;
int track[10000];
int cost_1, cost_2;
int p=0;
int count[100];

struct t_
{
	int count;
	int list[10];
};
struct t_ t[10];

void bfs(int v, int ta)
{
	int i;
	track[inc++] = v;
	if(v == ta) {
		int k;
		t[p].count = inc-1;
		for(k=0;k<inc-1;k++) {
			t[p].list[k] = m[track[k]][track[k+1]];
		}
		p++;
	}
	visited[v] = 1;
	for(i=0;i<=max;i++) {
		if(a[v][i] == 1 && !visited[i]) {
			bfs(i, ta);
		}
	}
	visited[v] = 0;
	inc--;
}

int main()
{
	int v, t_1, t_2, ma, min;
	int target, start_1, start_2;
	int i, j, index;
	m = malloc(sizeof(int *)*20000);
	a = malloc(sizeof(int *)*20000);
	for(i=0;i<20000;i++) {
		m[i] = malloc(sizeof(int)*20000);
		memset(m[i], 0, sizeof(int)*20000);
		a[i] = malloc(sizeof(int)*20000);
		memset(a[i], 0, sizeof(int)*20000);
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d %d", &t_1, &t_2);
		a[t_1][t_2] = 1;
		ma = t_1 > t_2 ? t_1:t_2;
		m[t_1][t_2] = i;
		if(ma > max) {
			max = ma;
		}
	}
	scanf("%d %d %d", &target, &start_1, &start_2);
	bfs(start_1, target);
	memset(visited, 0, sizeof(int)*20);
	memset(track, 0, sizeof(int)*10000);
	bfs(start_2, target);
	min = t[0].count;
	index = 0;
	for(i=1;i<p;i++) {
		if(min > t[i].count) {
			min = t[i].count;
			index = i;
		}
	}
	if(min)
		printf("%d\n", min);
	else
		printf("IMPOSSIBLE");
	for(i=0;i<min;i++)
		printf("%d\n", t[index].list[i]);
	return 0;
}
