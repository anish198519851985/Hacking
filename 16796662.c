#if 0
#include <stdio.h>

int main()
{
	int no = 12, i, j, k,count=0,sum;

	for(i=0;i<=no;i++) {
		for(j=0;j<=no;j++) {
			for(k=0;k<=no;k++) {
				sum = i*1 + j*2 + k*3;
				if(sum == no) {
					count++;
				}
			}
		}
	}
	printf("count %d\n", count);
	return 0;
}
#endif
int arr[] = {1, 2, 3};
void count_ways(int N, int* ways, int i)
{     
	int j;
	if(N==0)
	{
		*ways = *ways + 1;
		return;
	}
	if(i == sizeof(arr)/sizeof(arr[0]))
		return;

	for(j = 0; j*arr[i] <= N; j++)
		count_ways(N-(arr[i]*j), ways, i+1);
}


int main()
{
	int N=8, ways = 0;

	count_ways(N, &ways, 0);
	printf("%d\n", ways);

	return 0;
}
