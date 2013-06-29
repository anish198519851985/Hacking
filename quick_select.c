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
		while(a[left] > element)
			left++;
		while(a[right] < element)
			right--;
		if(left < right)
			swap(a, left, right);
	}
	swap(a, left, copy);
	return left;
}

int q_s(int a[], int left, int right, int k)
{
	if(left < right) {
		int pivot = partition(a, left, right);
		printf("%d %d %d %d\n", left, right, pivot, k);
		if(pivot == k) {
			printf("found it\n");
			return a[pivot];
		}
		if(pivot < k)
			q_s(a, pivot+1, right, k);
		else
			q_s(a, left, pivot-1, k);
	}
}

int main()
{
	int i;
	int a[] = {2, -4, 5, 6, 0, 7, -1, 10, 9};
	int k = 2; //if you want to find out 1 largest then give 0
	printf("%d\n", q_s(a, 0, sizeof(a)/sizeof(a[0]) -1, k));
}
