#include <stdio.h>

/* program uses the concept of binary search
 * by dividing the numbers based on the simple
 * concept: if the given number is from 1 to N
 * then from 1 to "x" you can have maximum number
 * in the array to be (x-1)+1 provided there is no
 * duplicates, if there are duplicates it would be
 * more then in that case we have to search from 1
 * to x and discard other numbers
 */
#define SIZE(A) sizeof(A)/sizeof(A[0])

int main()
{
	int a[] = {5, 3, 2, 4, 8, 6, 6, 7, 1};
	int low = 0;
	int high = SIZE(a), i;

	while(low < high)
	{
		int count = 0;
		int mid = (low + high)/2;
		for (i=0;i<SIZE(a);i++)
			if (mid >= a[i] && a[i] >= low)
				count++;
		if (count > (mid-low+1))
			high = mid;
		else
			low = mid+1;
	}
	printf("%d\n", low);
	return 0;
}
