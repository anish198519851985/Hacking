#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

/* Implement sliding window to find minimum */
struct min{
        int array[100];
        int size;
}minima;

/* returns the 0 based index */
int get_minimum(int *array, int size)
{
	int i = 0;
	int index = 0;
	int min;

	min = array[0];
	if(size == 1) {
	//	printf("anish %d\n", array[i + 1]);
		minima.array[minima.size] = array[0];
		minima.size++;
		return index;
	}

	while(i < (size - 1)) {
		if(min > array[i + 1]) {
	//		printf("anish %d\n", array[i + 1]);
			minima.array[minima.size] = array[i + 1];
			minima.size++;
			index = i + 1;
		}
		i++;
	}
	return index;
}

void shift()
{
	int i = 0;
	int size = minima.size;

	if(!minima.size) {
		printf("nothing to shift??????\n");
		return;
	}
	if(minima.size == 1)
		return;
	while(size) {
		minima.array[i] = minima.array[i + 1];
		i++;
		size--;
	}
	minima.size--;
	//printf("%s minima.size %d\n", __func__, minima.size);
}

void add_up(int new_element)
{
	int i;
	if(!minima.size) {
		minima.array[minima.size] = new_element;
		minima.size++;	
	}

	while(minima.size) {
		if(minima.array[minima.size - 1] >= new_element) {
		} else {
			minima.array[minima.size] = new_element;
			minima.size++;	
			return;
		}
		minima.size--;
	}
	if(!minima.size) {
		minima.array[minima.size] = new_element;
		minima.size++;	
	}
	return;
}

void get_first_minima(int *array, int size)
{
	int i = 0;
	int win_size = 4;
	int count = 0;
	int win_count = size - win_size + 1;
	
	while(i != 4) {
		int index = get_minimum(array + count, win_size);
		if(index == 0) {
			count++;
			win_size--;
		} else {
			count = count + index + 1;
			win_size = win_size - index - 1;
		}
		i++;
	}
}

int main()
{
	int array[] = {3, 10, 2, 9, 67, 6, 4, 7, 1, 0};
	int *min = malloc(sizeof(int *) * 100);
	int *min_start = min;
	int minima_size = 0;
	int i = 0;
	int size = SIZE(array);
	int count = 0;
	int win_size = 4;
	int win_size_copy = win_size;
	int win_count = SIZE(array) - win_size + 1;

	for(i = 0;i < SIZE(array);i++)
		printf("%d,", array[i]);
	printf("\n");

#if 1
	minima.size = 0;
	get_first_minima(array, size);
#if 1
	i = 1;
	while(i != win_count) {
		printf("min_start %d\n", minima.array[0]);
		/* we need to discard the first element of
		   minima if it is the first element in the
		   array for which first element we are going
		   to discard as window has to be moved right? */
		//printf("do we need to shift %d %d\n", array[i - 1], minima.array[0]);
		if(array[i - 1] == minima.array[0]) { /* checking discarded first element */
			printf("shifting happening\n");
			shift();
		}
		//printf("minima_szie %d new_element %d\n", minima.size, array[i + 3]);
		add_up(array[i + 3]);
		//printf("minima_szie %d new_element %d\n", minima.size, array[i + 3]);
		i++;
	}
	printf("min_start %d\n", minima.array[0]);
#endif
#endif
}
