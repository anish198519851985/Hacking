int total=0;
#define SIZE(a) sizeof(a)/sizeof(a[0])
int arr[] = {1, 2, 3};
int visited[100];

void IsSubArray(int n, int N, int sum) // N is the number of elements in the array 
{
	visited[n] = 1;
	if(sum == N) {
		total++;
		visited[n] = 0;
		return;
	}

	if((n <= (SIZE(arr)-1)) && arr[n]+sum <= N) {
		IsSubArray(n+1, N, sum+arr[n]);
	}

	if((n <= (SIZE(arr)-1)) && arr[n+1]+sum <= N) {
		visited[n] = 0;
		IsSubArray(n+1, N, sum);
	}
}

int main()
{
	int j, i;
	int target_sum=3;

	memset(visited, 0, sizeof(int)*100);
	IsSubArray(0, target_sum, 0);
	printf("total %d\n", total);
	return 0;
}
