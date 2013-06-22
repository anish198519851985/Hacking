int power(int x)
{
	printf("%d\n", x);
	if(x==0)
		return 0;
	if(x==2)
		return 1;
	return ((2*power(x/2))+2);
}

int main()
{
	printf("%d+\n", power(32));
	return 0;
}
