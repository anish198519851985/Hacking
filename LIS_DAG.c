#include <stdio.h>

#define SIZE(x) (sizeof(x)/sizeof(x[0]))
int maxi(int a,int b)
{
	return a>b?a:b;
}

int a[] = {10,5,2,5,2,13,17,15,16,19,20,21};

/* LIS using constructing a DAG */
void DAG()
{
	int i, j, max=0,index;
	int d[100] = {0};
	int dag[100][100] = {0};
	int prev[100] = {0};

	for(i=0;i<SIZE(a);i++) {
		d[i]=1;prev[i]=0;
	}
	for(i=0;i<SIZE(a);i++)
		for(j=0;j<SIZE(a);j++)
			dag[i][j] = 0;
	for(i=0;i<SIZE(a);i++)
		for(j=i+1;j<SIZE(a);j++)
			if(a[i] <= a[j])
				dag[i][j] = 1;

	d[0]=1;
	for(i=0;i<SIZE(a);i++)
		for(j=0;j<SIZE(a);j++) {
			if(dag[i][j] == 1) {
				d[j] = maxi(d[j], 1+d[i]);
				prev[j] = i;
			}
		}

	for(i=0;i<SIZE(a);i++)
		if(max < d[i]) {
			index = i;
			max = d[i];
		}
	printf("max index %d and greatest total elements %d\n", index, max);
	printf("%d\n", a[index]);
	while(--max){
		index = prev[index];
		printf("%d\n", a[index]);
	}
}

int main()
{
	DAG();
}
