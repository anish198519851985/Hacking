#include <stdio.h>
int main()
{
	unsigned long long int n, num_factors, initial_n, power=0, rev=0,mul=1,sum=1,p,i_b;
	unsigned long long int j=0, total=10000000000;
	unsigned long long int i,k=0;
	unsigned long long int a[] = {9, 8, 7, 6, 5, 4 , 3, 2};
	unsigned long long int b[20000];

	scanf("%lld", &i);
	i_b = i;
	if(i<=9) {
		power=1;
		if(i==0)
			printf("10");
		else
			printf("%lld\n", i);
		goto end;
	}
	while(i)
	{
		if(j >= (sizeof(a)/sizeof(a[0])))
			break;
		if(i%a[j] == 0)	{
			power=1;
			rev = a[j]*mul+rev;
			b[k++] = a[j];
			mul=mul*10;
			i=i/a[j];
		} else
			j++;
	}
	for(p=0;p<k;p++){
		sum = sum*b[p];
	}
	if(power == 0 || (sum != i_b))
		printf("-1");
	else
		printf("%lld\n", rev);
end:
	return 0;
}
