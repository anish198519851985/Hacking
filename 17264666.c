#include <stdio.h>

int main()
{
	int a[] = {1, 2, 3, 5, 6, 10, 11, 12};
	int b[] = {2, 3, 3, 6, 9, 10, 11};
	int c[100] = {0};
	int size, i, j, l, k, m, p;

	i = j = m = 0;
	size = (sizeof(a)/sizeof(a[0])) > (sizeof(b)/sizeof(b[0]))?(sizeof(a)/sizeof(a[0])):(sizeof(b)/sizeof(b[0]));
	memset(c, 0, sizeof(int)*100);
	for(;;) {
		if(a[i] > b[j]) {
			j++;
		} else if(a[i] < b[j]) {
			i++;
		} else if(a[i] == b[j]){
			c[m++] = a[i];
			i++;
		}
		if(i >= size || j >= size)
			break;
	}

	for(i=0;i<m;i++)
		printf("%d\n", c[i]);
	return 0;
}
