int main()
{
	int i, j;
	int a[] = {1, 12, 5, 4, 3, 6, 73, 0};
	int LS[100] = {0};
	int n = sizeof(a)/sizeof(a[0]);
	int largest = 0;

	LS[0] = 1;
	for(i=1;i<n;i++) {
		LS[i] = 1;
		for(j=0;j<i;j++) {
			printf("a[i] %d a[j] %d\n", a[i], a[j]);
			if(a[i] > a[j] && LS[i]<=LS[j]) {
				LS[i] = LS[j]+1;
				printf("LS[i] %d\n", LS[i]);
			}
		}
	}

	for(i=0;i<n;i++) {
		if(largest < LS[i])
			largest = LS[i];
	}
	printf("largest is %d\n", largest);
	return 0;
}
