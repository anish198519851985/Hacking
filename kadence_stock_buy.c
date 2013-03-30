static int l_index = 0, h_index = 0;

int maximum_subarray(int* nums, int start_index, int end_index)
{
        int max_sum = 0;	
        int cur_index, cur_sum = 0, max_ending_here, max_so_far;
	
        for(cur_index = 0; cur_index < end_index; cur_index++) {
		cur_sum = cur_sum + nums[cur_index];
		if(cur_sum < 0) {
			cur_sum = 0;
			l_index = cur_index;
		}
		if(cur_sum > max_sum) {
			printf("%d\n", cur_index);
			max_sum = cur_sum;
			h_index = cur_index;
		}
        }
        return max_sum;
}

int main()
{
	int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	printf("sum %d\n", maximum_subarray(a, 0, sizeof(a)/sizeof(a[0])));
	printf("left %d right %d\n", l_index, h_index);
	return 0;
}
