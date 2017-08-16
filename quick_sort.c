//Author: Rachit Ajitsari (@rtg500)

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
	return;
}
int Partition(int A[], int l, int h)
{
	int pivot = A[h];
	int pIndex = 0;
	int i;
	for(i=0; i<=h; i++)
	{
		if(A[i]<pivot)
		{
			swap(&A[i], &A[pIndex++]);
		}
	}
	swap(&A[pIndex], &A[h]);
	return pIndex;
}

void QuickSort(int A[], int l, int h)
{
   if(l<h)
   {
   		int pIndex = Partition(A, l, h);
   		QuickSort(A, l, pIndex-1);
   		QuickSort(A, pIndex+1, h);
   }
   return;
}


void PrintArr(int A[], int n)
{
    int i = 0;
    for(i=0; i<n; i++) printf("%d", A[i]);
    printf("\n");
    return;
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
    QuickSort(arr, 0, n-1);
    PrintArr(arr, n);
    return 0;
}
