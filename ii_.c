int q[20],visited[20],n,f=0,r=-1,max=0;
int a[20000][20000];
int m[20000][20000];
static int inc=0;
int track[10000];
int cost_1, cost_2;
int p=0;
int count[100];

struct t_
{
	int count;
	int list[100];
};
struct t_ t[100];

int operations[4][2] = {{1, -1}, {-1, -1}, {1, 1}, {-1, 1}};
void bfs(int i, int j)
{
	if(track[i][j] == 1)
		return;
	track[i][j]=1;
	for(k=0;k<4;k++)
		bfs(i+operations[k][k], j+operations[k+][k+1])
}

int main()
{
	int v, t_1, t_2, ma, min;
	int target, start_1, start_2;
	int i, j, index;
	printf("jafajfdsf");
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
