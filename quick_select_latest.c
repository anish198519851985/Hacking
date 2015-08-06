#define SIZE(a) sizeof(a)/sizeof(a[0])
void swap(int *d, int i, int j)
{
    int a = d[i];
    int b = d[j];
    a ^= b;
    b ^= a;
    a ^= b;
    d[i] = a;
    d[j] = b;
}

int partition(int *a, int i, int j)
{
    int p = j;
    while (i <= j-1) {
        if (a[i] < a[p])
            i++;
        else {
            swap(a, i, j-1);
            j--;
        }   
    }
    if (i == j)
        if (a[i] < a[p])
            swap(a, i+1, p);
    swap(a, i, p);
    return i;
}

int q_select(int *a, int i, int j, int k)
{
    int p;
    if (i <= j) {
        int pivot = partition(a, i, j);
        if (pivot-i+1 == k) {
            return a[pivot];
        }
        if ((pivot-i+1) < k)
            return q_select(a, pivot+1, j, k-(pivot+1));
        if ((pivot-i+1) > k)
            return q_select(a, i, pivot-1, k);
    } else
        return -1;
}

int main()
{
    int a[] = {2, 44, 456, 5, 6, 224, 4342, 424};
    int b[100];
    int i, j = SIZE(a);
    printf("quickselection %d\n", q_select(a, 0, j-1, 8));
}
