#include<stdio.h>
/*This is called Forward declaration of function */
void Merge(int * , int , int , int );
/* Logic: This is divide and conquer algorithm. This works as follows.
   (1) Divide the input which we have to sort into two parts in the middle. Call it the left part 
   and right part.
Example: Say the input is  -10 32 45 -78 91 1 0 -16 then the left part will be  
-10 32 45 -78 and the right part will be  91 1 0 6.
(2) Sort Each of them seperately. Note that here sort does not mean to sort it using some other
method. We already wrote fucntion to sort it. Use the same.
(3) Then merge the two sorted parts.
 */
/*This function Sorts the array in the range [left,right].That is from index left to index right inclusive
 */
void MergeSort(int *array, int left, int right)
{
	int mid = (left+right)/2;
	/* We have to sort only when left<right because when left=right it is anyhow sorted*/
	if(left<right)
	{
		/* Sort the left part */
		MergeSort(array,left,mid);
		/* Sort the right part */
		MergeSort(array,mid+1,right);
		/* Merge the two sorted parts */
		Merge(array,left,mid,right);
	}
}

/* Merge functions merges the two sorted parts. Sorted parts will be from [left, mid] and [mid+1, right].
 */
void Merge(int *array, int left, int mid, int right)
{
	/*We need a Temporary array to store the new sorted part*/
	int tempArray[right-left+1];
	int pos=0,lpos = left,rpos = mid + 1;
	while(lpos <= mid && rpos <= right)
	{
		if(array[lpos] < array[rpos])
		{
			tempArray[pos++] = array[lpos++];
		}
		else
		{
			tempArray[pos++] = array[rpos++];
		}
	}
	while(lpos <= mid)  tempArray[pos++] = array[lpos++];
	while(rpos <= right)tempArray[pos++] = array[rpos++];
	int iter;
	/* Copy back the sorted array to the original array */
	for(iter = 0;iter < pos; iter++)
	{
		array[iter+left] = tempArray[iter];
	}
	return;
}

void swap(int *array, int first, int second)
{
	int temp;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}

int partition(int *array, int left, int right, int pivotIndex)
{
	int i;
	int storeIndex;
	int pivotValue = array[pivotIndex];
	swap(array, pivotIndex, right);		
	storeIndex = left;
	for (i = left;i < right;i++) {
		if (array[i] < pivotValue) {
			swap(array, i, storeIndex);	
			storeIndex++;
		}
	}
	swap(array, storeIndex, right);
	return storeIndex;
}

void quickSort(int array[], int left, int right)
{
	int pivotIndex;
	if (left < right) {
		pivotIndex = (left + right)/2;
		pivotIndex = partition(array, left, right, pivotIndex);
		quickSort(array, left, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, right);
	}
}

int main()
{
	int number_of_elements;
	scanf("%d",&number_of_elements);
	int array[number_of_elements]; 
	int iter;
	for(iter = 0;iter < number_of_elements;iter++)
	{
		scanf("%d",&array[iter]);
	}
	/* Calling this functions sorts the array */
	quickSort(array,0,number_of_elements-1); 
	for(iter = 0;iter < number_of_elements;iter++)
	{
		printf("%d ",array[iter]);
	}
	printf("\n");
	return 0;
}


