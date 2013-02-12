int main()
{
	int i, j;
	int a[] = {1, 12, 5, 4, 3, 6, 73, 0};
	int LS[100] = {0};
	int n = sizeof(a)/sizeof(a[0]);
	int largest = 0;
	int b[100] = {0};
	int end = 0;

	for(i=0;i<n;i++) {
		printf("%d ,", a[i]);
	}
	printf("\n");

	LS[0] = 1;
	b[0] = a[0];
	for(i=1;i<n;i++) {
		b[i] = i;
		LS[i] = 1;
		printf("i %d\n", i);
		for(j=0;j<i;j++) {
			if(a[i] > a[j] && LS[i] < (LS[j] + 1)) {
				LS[i] = LS[j]+1;
				printf("j %d\n", j);
				b[j] = j;
			}
		}
	}

	for(i=0;i<n;i++) {
		if(largest < LS[i]) {
			end = i;
			printf("end %d\n", end);
			largest = LS[i];
		}
	}
	printf("largest is %d\n", largest);
#if 1
	for (j = 0; j < n; j++)  
	{  
		printf("%d, ", b[j]);  
	} 
#endif
	return 0;
}
