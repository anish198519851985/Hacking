#define REGIONS 4
#define SUM 4
int proposal[REGIONS] = {0, 4, 3, 3};
/*int cost[REGION][proposal[REGIONS]];*/
int cost[100][100];
/*int benifit[REGION][proposal[REGIONS]];*/
int benifit[100][100];
/*int result[REGIONS+1][SUM+1];*/
int result [100][100];

int main()
{
	int i, j, j1, k;
	/* fill the cost for all the regions */
	cost[1][0] = 0;cost[1][1] = 0;cost[1][2] = 1;cost[1][3] = 2;cost[1][4] = 4;
	cost[2][0] = 0;cost[2][1] = 0;cost[2][2] = 1;cost[2][3] = 3;
	cost[3][0] = 0;cost[3][1] = 0;cost[3][2] = 1;cost[3][3] = 2;
	benifit[0][0] = 0;benifit[0][1] = 2;benifit[0][2] = 4;benifit[0][3] = 10;
	benifit[1][0] = 0;benifit[1][1] = 3;benifit[1][2] = 9;
	benifit[2][0] = 0;benifit[2][1] = 2;benifit[2][2] = 5;

	result[0][0]=0;
	for(i=1;i<=REGIONS;i++) {
		for(j=0;j<=SUM;j++) {
			for(j1=0;j1<=j;j1++) {
				for(k=0;k<=proposal[i-1];k++) {
					printf("%d %d\n", i-1, k);
					if(cost[i-1][k]+j1==j && benifit[i-1][k]+result[i-1][j1]>result[i][j]) {
						result[i][j] = benifit[i-1][k]+result[i-1][j1];
					}
				}
			}
		}
	}	

	for(i=0;i<6;i++) {
		for(j=0;j<6;j++) {
			printf("%4d,", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
