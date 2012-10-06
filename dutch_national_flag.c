/*dutch national flag problem
 * http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Sort/Flag/
 */
#define ARRAY_SIZE(array) sizeof(array)/sizeof(array[0])

int main()
{
	int array[] = {1, 1, 2, 1, 2, 2, 2, 2, 0, 1};	
	int low, mid, high, i;

	low = 0;
	mid = 0;
	high = ARRAY_SIZE(array) - 1;
	printf("high %d\n", high);
	
	while(mid <= high) {
		if(array[mid] == 1)
			mid++;
		else if(array[mid] == 0){
			int temp;
			temp = array[low];	
			array[low] = array[mid];
			array[mid] = temp;
			low++; mid++;
		} else {
			int temp;
			temp = array[mid];	
			array[mid] = array[high];
			array[high] = temp;
			high--;
		}
	}
	
	i = 0;
	while(i < ARRAY_SIZE(array))
		printf("%d\n", array[i++]);
	return 0;
}
