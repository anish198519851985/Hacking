/* 
x^n = {
	1 if n==0
	1/(x^n) if n < 0
	x.x^(n-1/2)*2 if n is odd
	x.x^(n/2)*2 if n is even
      }
def power(x,n)
   result = 1
   while n.nonzero?
   if n[0].nonzero?
   result *= x
   n -= 1
   end
   x *= x
   n /= 2
   end
   return result
   end
 */
#include <stdio.h>
#include <stdlib.h>

int multiply_by_exponent(int number, int power, int result)
{
	if(power ==0)
		return result;
	if(power%2 == 0) {
		multiply_by_exponent(number*number, power/2, result);
	} else {
		--power;
		multiply_by_exponent(number*number, power/2, result*number);
	}
}

int main()
{
	int number, power;

	printf("please enter the number and follow it up with the exponent\n");
	scanf("%d %d", &number, &power);

	printf("%d\n", multiply_by_exponent(number, power, 1));
	return 0;
}
