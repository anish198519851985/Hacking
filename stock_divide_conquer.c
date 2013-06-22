#include <stdio.h>

int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int m_left, m_right;

int foo_c(int left, int right, int mid)
{
	int l_sum,r_sum;
	int sum = 0, i;

	l_sum = -111111; //big negative number
	printf("l %d r %d\n", left, right);
	for(i=left;i <= mid;i++) {
		sum = sum + a[i];
		if(sum > l_sum) {
			l_sum = sum;
			m_left = i;
		} else
			break;
	}
	sum = 0;
	r_sum = -111111; //big negative number
	for(i=mid+1;i<right;i++) {
		sum = sum + a[i];
		if(sum > r_sum) {
			r_sum = sum;
			m_right = i;
		} else
			break;
	}
	return r_sum + l_sum;
}

int foo(int left, int right, int sum)
{
	int l_sum, r_sum, c_sum, mid;

	if(left == right)
		return a[left];
	mid = ((left+right)/2);
	/*check for left to mid*/
	l_sum = foo(left, mid, sum);

	/*check for mid+1 to right*/
	r_sum = foo(mid+1, right, sum);
	c_sum = foo_c(left, right, mid);
	if(l_sum > r_sum  && l_sum > c_sum)
		return l_sum;
	if(r_sum > l_sum  && r_sum > c_sum)
		return r_sum;
	if(c_sum > r_sum  && c_sum > l_sum)
		return c_sum;
}

int main()
{
	printf("%d\n", foo(0, sizeof(a)/sizeof(a[0]), 0));
	return 0;
}
