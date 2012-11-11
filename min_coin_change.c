#include <stdio.h>
int comb[] = {1, 2, 5};

int min(int x, int y, int z)
{
	int a = x<y?x:y;
	int b = a<z?a:z;
	return b;
}

int min_change(int x)
{
	if(x <= 0)
		return 0;
	if(x == 0)
		return 0;
	else
		return 1 + min(min_change(x-1), min_change(x-2), min_change(x-5));
}

int main()
{
	printf("%d\n", min_change(21));
	return 0;
} 
