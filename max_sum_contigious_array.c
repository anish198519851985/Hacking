#include <stdio.h>
#include <stdlib.h>

int maxSubArraySum(int a[], int size,int *begin,int *end)
{
   int max_so_far = 0, max_ending_here = 0;
   int i,current_index = 0;
  
   for(i = 0; i < size; i++)
   { 
     max_ending_here = max_ending_here + a[i];
    
     if(max_ending_here <= 0)
        {
         max_ending_here = 0;
         current_index=i+1;
        }
     else if (max_so_far < max_ending_here)
         {
          max_so_far = max_ending_here;
          *begin = current_index;
          *end=i;
          }
   }
   return max_so_far;
}

int main()
{
  int arr[] = {-1, -2, -5, -1, -1, -1, -9, -2, -3, -3};
  //int arr[] = {5,2,-1,-2,-4,3,5,-6};
  int begin=0,end=0;
  int size=sizeof(arr)/sizeof(arr[0]);

  printf(" The max sum is %d",maxSubArraySum(arr,size,&begin,&end));
  printf(" The begin and End are %d & %d",begin,end);
  getchar();
  return 0;
}

