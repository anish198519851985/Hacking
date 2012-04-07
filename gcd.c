#include <stdio.h>

int gcd(int x,int y)
{
	while(x > 0) {
		if (x < y) {
			int t;
			t = x;
			x = y;
			y = t;
		}
		x = x-y;
	}
	return y;
}

main()
{
	int x,y;
	printf("enter the numbers\n");
	scanf("%d%d",&x,&y);
	int t; 

	while(1){
		t = x%y;
		if(t != 0) {
			x = y;
			y = t;
			continue;
		}
		else {
			t = y;
			break;
		}
	}

	printf("gcd is %d\n", t);
} 
