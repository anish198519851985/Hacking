#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE(x) sizeof(x)/sizeof(x[0])

int maxi(int a,int b)
{
	return a>b?a:b;
}
int a[] = {857, -838, 84, 763, 245, 799, -457, 989, -349, 174, -151, -392, -621, -625, 507, -101, -921, -367, 734, 661};

/* LIS using constructing a DAG */
void DAG()
{
	int i, j, max=0,index;
	int d[100];
	int dag[100][100];
	int prev[100];

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

	for(i=0;i<SIZE(a);i++)
		for(j=0;j<SIZE(a);j++) {
			if(dag[i][j] == 1) {
				if(d[j] <= 1+d[i]) {
					d[j] = 1+d[i];
					prev[j] = i;
				}
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
		printf("index %d\n", index);
		index = prev[index];
		printf("%d\n", a[index]);
	}
}

int main()
{
	DAG();
}
