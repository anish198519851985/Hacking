int main()
{
	static int i=0;
	if(i < 1001)
		printf("%d\n", i++);
	else
		exit(0);
	main();
}
