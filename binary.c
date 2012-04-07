#include <stdio.h>

void binary(int x)
{
	int temp = 0x1;
	int temp1,temp2 = 1;
	int i = 0;

	while(x > temp1) {
		temp1 = temp << i;
		i++;
	}
	temp =  temp1 >> 1;
	x = x - temp;
	printf("1");
	temp2 = temp >> 1;	
	while(temp2) {
		if(x < temp2) {
			printf("0");	
		}
		else {
			printf("1");
			x = x - temp2;
		}
		temp2 = temp2 >> 1;	
	}
	printf("\n");
}

void binary_easy(int num)
{
	int temp;
	int mul = 1, final = 0;
	while(num > 0) {
		temp = num%2;
		temp = temp * mul;
		final = temp + final;
		mul = mul * 10;
		num = num/2;	
	}
	printf("%d\n", final);
}

main()
{
	int x,y;
	printf("enter the number\n");
	scanf("%d",&x);
	binary(x);
	binary_easy(x);
} 
