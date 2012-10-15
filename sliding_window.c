#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

/* Implement sliding window to find minimum */
int get_minima(int *array, int *min, int size)
{
	int i = 0;
	int index = 0;

	printf("array %d size %d\n", array[0], size);
	*min = array[0];
	if(size == 0) {
		return 1;
	}
	while(i < size) {
		if(*min >= array[i + 1]) {
			*min = array[i + 1];
			index = i + 1;
		}
		i++;
	}
	return index;
}

int add_new(int *min, int size, int new_element)
{
	if(!size)
		min[size] = new_element;

	while(size) {
		if(min[size] >= new_element) {
			min[size] = new_element;
		} else {
			min[size + 1] = new_element;	
			break;
		}
		size--;
	}
	return size;
}

int main()
{
	int array[] = {3, 0, 111, 10, 5, 6, 4, 7};
	return 0;
}
