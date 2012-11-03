#include <stdio.h>
#include <stdlib.h>

int McNuggets(int n)
{
	int ret = 0;

	printf("%d\n", n);
	if (n < 1)
		return 0;

	if ((n % 6 == 0) ||
			(n % 9 == 0) ||
			(n % 20 == 0))
		return 1;

	if (ret == 0 && n > 20)
		ret = McNuggets(n - 20);

	printf("I am here+ n %d ret %d\n", n, ret);
	if (ret == 0 && n > 9)
		ret = McNuggets(n - 9);
	printf("I am here++ %d ret %d\n", n, ret);

	if (ret == 0 && n > 6)
		ret = McNuggets(n - 6);

	return ret;
}

int main()
{
	printf("--%d\n", McNuggets(21));
	return 0;

}
