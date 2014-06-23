/* 
x^n = {
	1 if n==0
	x*x^2*x^(n-1/2) if n is odd
	(x^2)^(n/2) if n is even
      }
*/
#include <stdio.h>
#include <stdlib.h>

int multiply_by_squaring(int number, int power)
{
	if(power ==0)
		return 1;
	if(power ==1)
		return number;
	if(power%2 == 0) {
		return multiply_by_squaring(number*number, power/2);
	} else {
		return number*multiply_by_squaring(number*number, (power-1)/2);
	}
}

int main()
{
	int number, power;

	printf("please enter the number and follow it up with the exponent\n");
	scanf("%d %d", &number, &power);

	printf("%d\n", multiply_by_squaring(number, power));
	return 0;
}
