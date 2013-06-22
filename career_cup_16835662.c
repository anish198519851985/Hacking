#include <stdio.h>
int max[100] = {-1};
int k[100] = {-1};

int search(int *a, int check, int size, int from)
{
	int i;
	for(i=from;i<=size;i++) {
		if(a[i] > check)
			return a[i];
	}
	return 0;
}

int maxi(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int a[] = {2,14,10,8,9,53,1};
	int i, ret;

	for(i=sizeof(a)/sizeof(a[0])-1;i>=1;i--) {
		printf("i %d i-1 %d\n", i, i-1);
		if(a[i] > a[i-1]) {
			k[i-1] = a[i];
		} else {
			/*find out in the right max array*/
			if(ret=search(max, a[i-1], sizeof(a)/sizeof(a[0])-1, i+1))	
				k[i-1] = ret;
			else	
				k[i-1] = -1;
		}
		max[i] = maxi(a[i], a[i-1]);
	}

	k[sizeof(a)/sizeof(a[0])-1] = -1;
	for(i=0;i<(sizeof(a)/sizeof(a[0]))-1;i++)
		printf("%d ,", k[i]);
	printf("\n");

	return 0;
}
