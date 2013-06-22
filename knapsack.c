#define TOTAL 50
int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int w[] = {10, 20, 30};
	int v[] = {60, 100, 120};
	int r[100] = {0};
	int i, j;

	memset(r, 0, sizeof(int)*100);
	for(i=0;i<=TOTAL;i++) {
		for(j=0;j<=3;j++) {
			if(i >= w[j]) {
				r[i] = max(r[i-1], r[i-w[j]]+v[j]);
			} else {
				if(i>=1)
					r[i] = max(r[i], r[i-1]);
			}
		}
	}

	printf("%d\n", r[TOTAL]);
	return 0;
}
