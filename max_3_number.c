#include <stdio.h>

int main()
{
	int a[] = {4, 5, 6, 7, 3, 10, 11};
	int first=-1;int second=-1;int third=-1;
	int t_f, t_s, i;

	if(first == -1)
		first = a[0];
	for(i=0;i<sizeof(a)/sizeof(a[0])-1;i++) {
		if(a[i+1] > a[i]) {
			t_f = first;
			first = a[i+1];
			if(second == -1) {
				second = a[i];
			} else {
				t_s = second;
				second = t_f;
				third = t_s;
			}
		}
	}
	printf("first %d secodn %d third %d\n", first, second, third);
	return 0;
}
