struct a{
int a;
char b;
};

void foo(int (*b)[3]);

main()
{
int a[] = {0};
int b[2][3] = {1,2,3,
	       4,5,6};
int *p[3]; //array of integer pointers
int (*q)[3] = b; //pointer to an integer array
p[0] = &a[0];
p[1] = &a[0];
p[2] = &a[0];
printf("%d %d %d \n",*p[0],*p[1],*p[2]);
foo(b);
}

void foo(int (*b)[3])
{
	printf("%d \n",b[0][0]);
}
