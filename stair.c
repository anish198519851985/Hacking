int T[501][35];
int sum;
int n;
inline int max(int i,int j)
{
    return i>j?i:j;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    T[1][1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;((j*(j+1))>>1)<=i;j++)
        {
		printf("i %d j %d i-j %d j-1 %d\n", i, j, i-j, j-1);
            T[i][j]=T[i-j][j]+T[i-j][j-1];
		printf("result %d\n", T[i][j]);
        }
    }
    for(j=1;((j*(j+1))>>1)<=n;j++)
    {
	printf("n %d j %d\n", n, j);
        sum+=T[n][j];
    }
    printf("%10d\n",sum-1);
    return 0;
}
