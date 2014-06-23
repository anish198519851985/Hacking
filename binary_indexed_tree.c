#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000010
signed long long int *heap;

signed long long int query(signed long long int u)
{
	signed long long int sum = 0;
	for(;u>0;u-=(u&-u)) {
		sum += heap[u];
	}
	return sum;
}

void update_(signed long long int u, signed long long k)
{
	for(;u<MAX;u+=(u&-u))
		heap[u] += k;
}

void update(signed long long int u, signed long long v, signed long long k)
{
	update_(u, k);
	update_(v+1, -k);
}

/* This is just a replacement of pow(x,y) function in c*/
int power(int a, int b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b%2 == 0)
		return power(a*a, b/2);
	else
		return a*power(a*a, (b-1)/2);
}

int main()
{
	signed long long int n, u, v, k, p, exp;
	int m, c;
	char pc[2];

	exp = sizeof(signed long long int)*power(10, 6);
	heap = malloc(exp);
	memset(heap, 0, exp);
	scanf("%lld %d %d", &n, &m, &c);
	while(m)
	{
		scanf("%s", pc);
		if (pc[0] == 'Q') {
			scanf("\n%lld", &p);
			printf("%lld\n", query(p)+c);
		} else {
			scanf("%lld %lld %lld", &u, &v, &k);
			update(u, v, k);
		}
		m--;	
	}	
}
