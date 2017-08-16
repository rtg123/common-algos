#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int h)
{
    int* temp = (int*)malloc((h-l+1)*sizeof(int));
    int i=l, k=0, m = l + (h-l)/2, j = m+1;
    while(i<=m && j<=h)
    {
        if(A[i] <= A[j]) temp[k++] = A[i++];
        else temp[k++] = A[j++];
    }
    if(i > m)
        for(;k<=h; k++, j++) temp[k] = A[j];
    else if(j > h)
        for(; k<=h; k++, i++) temp[k] = A[i];
    for(i=l, k=0; i<=h; i++,k++) A[i] = temp[k];
    return;
}

void MergeSort(int A[], int l, int h)
{
   if(h-l<1) return;
   int m = l + (h-l)/2;
   MergeSort(A, l, m);
   MergeSort(A, m+1, h);
   merge(A, l, h);
   return;
}


int PrintArr(int A[], int n)
{
    int i = 0;
    for(i=0; i<n; i++) printf("%d", A[i]);
    printf("\n");
    return 0;
}

void getArr (int A[], int n)
{
    int i;
    for(i=0; i<n; i++) scanf("%d", (A+i));
}

int main(int argc, char** argv)
{
    int n, *arr;
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    getArr(arr, n);
    MergeSort(arr, 0, n-1);
    PrintArr(arr, n);
    return 0;
}

