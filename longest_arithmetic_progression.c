#include <stdio.h>

int max_len = 1;
int array[] = {1, 3, 4, 5, 6, 7};
#define SIZE(a) sizeof(a)/sizeof(a[0])
int map[100][100];

int main()
{
	int i, j;

	memset(map, 0, sizeof(int)*100*100);
	for(i=1;i<SIZE(array);i++) {
		for(j=0;j<i;j++) {
			int diff = array[i] - array[j];
			if(map[j][diff] == 0) {
				map[i][diff] = 2;
			} else {
				int new_len = map[j][diff] + 1;
				printf("%d %d--\n", j, diff);
				map[i][diff] = new_len;
				max_len = new_len > max_len ? new_len : max_len;
			}
		}
	}
	printf("%d\n", max_len);
	return 0;
}

