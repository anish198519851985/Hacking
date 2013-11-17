#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double sqrtt(double n) {
	double low = 0;
	double high = n;
	double mid = (high + low) / 2;

	while (high >= low) {
		if((mid*mid - n) <= 0.0000001) {
			printf("high %f low %f mid %f\n", high, low, mid);
			if ((mid * mid) > n) {
				high = mid;
			} else{
				low = mid;
			}
		}
	}
	return mid;
}

int main()
{
	printf("%f\n", sqrtt((double)10));
	printf("%f\n", sqrt((double)10));
	return 0;
}
