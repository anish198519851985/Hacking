#include <stdio.h>
#define SIZE 10

int cache[SIZE+1];

int get_cache(int k)
{
	return cache[k];
}

unsigned int fib(int k) { 
	int res = get_cache(k); 
	if(res == -1) 
	{ 
		res = fib(k-1) + fib(k-2); 
		cache[k] = res;
		printf("res %d\n", res);
	} 
		printf("res %d\n", res);
	return res; 
}

int main()
{
	memset(cache, -1, (SIZE+1)*sizeof(int));
	cache[0] = 0;
	cache[1] = 1;
	printf("%d\n", fib(SIZE));
}
