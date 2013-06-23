#include <stdio.h>
#define TARGET 23
#define BIG_VALUE 9999
int comb[] = {3, 5};
int min(int x, int y, int z)
{
	int a = x<y?x:y;
	int b = a<z?a:z;
	return b;
}

int min_(int x, int y)
{
	int a = x<y?x:y;
	return a;
}

int min_change(int x)
{
	printf("%s\n", __func__);
	if(x <= 0)
		return 0;
	if(x == 0)
		return 0;
	else
		return 1 + min_(min_change(x-3), min_change(x-5));
}

int result[100];
int m_c_dp(int sum)
{
	int i, j;

	result[0]=0;
	for(i=1;i<=sum;i++) {
		for(j=0;j<sizeof(comb)/sizeof(comb[0]);j++) {
			if(i >= comb[j] && result[i-comb[j]]+1 < result[i]) {
				result[i] = 1 + result[i-comb[j]];
			}
		}
	}
	return result[sum];
}

int main()
{
	int i;
	for(i=0;i<100;i++)
		result[i] = BIG_VALUE;
	printf("%d\n", m_c_dp(TARGET));
	return 0;
} 
