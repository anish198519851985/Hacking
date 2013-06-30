#include <stdio.h>
void swap(int a[], int  i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int a[], int left, int right)
{
	int pivot = (left+right)/2;
	int element = a[pivot];
	int copy = right;
	swap(a, pivot, right);
	right--;
	while(left < right){
		while(a[left] <= element && left <= right)
			left++;
		while(a[right] > element)
			right--;
		if(left >= right)
			break;
		else
			swap(a, left, right);
	}
	swap(a, left, copy);
	return left;
}

int q_s(int a[], int left, int right, int k)
{
	if(left == right)
		return a[left];
	if(left < right) {
		int i;
		int pivot = partition(a, left, right);
		int newPivotDistance = pivot - left + 1;
		if(newPivotDistance == k) return a[pivot];
		if(newPivotDistance > k)
			q_s(a, left, pivot-1, k);
		else
			q_s(a, pivot+1, right, k-newPivotDistance);
	}
}

int main()
{
	int a[] = {50,  6, 5, 7, 40,  10, 10, 0, 5, 19,10};
	int k;
	scanf("%d", &k);
	printf("%d\n", q_s(a, 0, sizeof(a)/sizeof(a[0]) -1, k));
}
