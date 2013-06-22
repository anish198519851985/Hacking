#include <limits.h>
#define T_I 0
#define T_J 4

#define TARGET(i, j) ((i==T_I && j== T_J)?1:0)

int min(int a, int b)
{
	return a>b?b:a;
}
int track[100][100]={0};

int foo(int i, int j)
{
	int value1, value2, value3, value4;
	value1=value2=value3=value4=0;
	if(i<0||j<0 ||i>7||j>7)
		return 99999;
	if(track[i][j]==1)
		return 99999;
	printf("%d %d\n", i, j);
	track[i][j]=1;
	if(TARGET(i, j)) {
		printf("got it->>>>>>>>>\n");
		track[i][j]=0;
		return 1;
	}
	value1 = 1+ foo(i+1,j+1);
	value2 = 1+ foo(i-1,j-1);
	value3 = 1+ foo(i+1,j-1);
	value4 = 1+ foo(i-1, j+1);

	printf("%d %d %d %d\n", value1, value2, value3, value4);
	return min(value1, min(value2, min(value3, value4)));
}

int main()
{
	printf("--> %d\n", foo(1, 1));
}
