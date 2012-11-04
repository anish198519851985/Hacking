#include <stdio.h>
#include <stdlib.h>
#define SIZE(a) sizeof(a)/sizeof(a[0])

int mcNuggets(int combo[], int size, int num)
{
	int ret;
	int i;

	if(num < 0)
		return 0;

	if(num == 0)
		return 1;

	ret = 0;
	for(i = 0;i < size;i++) {
		if(num % combo[i] == 0)
			return 1;
	}

	for(i = 0;i < size;i++) {
		ret = ret | mcNuggets(combo, size, num - combo[i]);
	}
	return ret;
}

int main()
{
	int combo[] = {20, 9, 6};
	int num = 50;

	printf("%d\n", mcNuggets(combo, SIZE(combo), num));

	return 0;
}
