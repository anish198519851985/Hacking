int foo(int N, int k)
{
	if(N==0)
		return 1;
	if(N==1)
		return k-1;
	return (k-1)*(foo(N-1,k)+foo(N-2, k));
}

int main()
{
	printf("%d\n", foo(2, 10));
}
