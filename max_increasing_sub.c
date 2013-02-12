int main()
{
	int array[] = {13,12,5,6,0,7};
	int n = sizeof(array)/sizeof(array[0]);
	int largest = 0, i, j;
	int msis[100];

	for(i=0;i<n;i++)
		msis[i] = array[i];

	for(i=1;i<n;i++) {
		for(j=0;j<i;j++)
			if(array[i] > array[j] && (msis[i] < array[i]+msis[j]))
				msis[i] = msis[j] + array[i];

	}

	for(i=0;i<n;i++) {
		if(largest < msis[i])
			largest = msis[i];
	}
	printf("sum is %d\n", largest);
	return 0;
}
