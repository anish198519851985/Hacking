#include <stdio.h>

int inversion_count;

void merge(int *a, int start, int mid, int end)
{
        int *c = malloc(sizeof(int)*(end-start+1));
        int i, j=0, k=0, left_track=start, right_track=mid+1, left_len, right_len;
        int left = mid-start+1, right=end-(mid+1)+1;
        while (left  && right) {
                while (left && a[left_track] <= a[right_track]) {
                        inversion_count++;
                        c[k++] = a[left_track++];
                        left--;
                }
                if (!left)
                        break;
                while (right && a[left_track] >= a[right_track]) {
                        inversion_count++;
                        c[k++] = a[right_track++];
                        right--;
                }
        }

        while (left) {
                c[k++] = a[left_track++];
                left--;
        }
        while (right) {
                c[k++] = a[right_track++];
                right--;
        }
        for (i=start;i<=end;i++) {
                a[i] = c[j++];
        }
        free(c);
}

void merge_sort(int *a, int start, int end) {
        if (start < end) {
                int pivot = (start + end)/2;
                merge_sort(a, start, pivot);
                merge_sort(a, pivot+1, end);
                merge(a, start, pivot, end);
        }
}

int main(void) {
        int a[] = {2, 4, 1, 3, 5}, i;

        for (i=0;i<sizeof(a)/sizeof(a[0]);i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
        merge_sort(a, 0, sizeof(a)/sizeof(a[0])-1);
        for (i=0;i<sizeof(a)/sizeof(a[0]);i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
        printf("inversion_count %d \n", inversion_count);
        return 0;
}
