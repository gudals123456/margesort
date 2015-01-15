#include <stdio.h>

void swap(int * a, int * b);
void printarr(int * arr,int size);
void mergeSort(int *arr, int *copyArr, int start, int end,int size);
void mergeSplit(int * arr,int * copyArr,int start,int end,int size);
void merge(int * arr, int * copyArr, int start, int middle, int end);
void funCopyArr(int * arr,int * copyArr,int start,int end);

void main() {

	printf("hello C world!\n");
	printf("Merge sort\n\n");

	int arr[] = {34,27,35,1,23,19,85,67,4,10};
	int copyArr[10] = {0};
	printarr(arr,sizeof(arr)/4);
	printf("\n\n");

	mergeSort(arr,copyArr,0,sizeof(arr)/4 -1,sizeof(arr)/4);

	printarr(arr,sizeof(arr)/4);

}

void mergeSort(int *arr, int *copyArr, int start, int end, int size)
{
	mergeSplit(arr,copyArr,0,size,size);
}

void mergeSplit(int * arr,int * copyArr,int start,int end,int size)
{
	
	if((end-start) < 2)
		return;
	int middle = (start + end) /2;

	printf("start = %d, middle = %d, end = %d\n",start,middle,end);

	mergeSplit(arr,copyArr,start,middle,size);
	mergeSplit(arr,copyArr,middle,end,size);
	merge(arr,copyArr,start,middle,end);
	funCopyArr(arr,copyArr,start,end);

	printarr(arr,size);
	printf("\n");
}

void merge(int * arr, int * copyArr, int start, int middle, int end)
{
	int i0 = start,i1 = middle;
	for(int j = start; j<end; j++)
	{
		if(i0<middle && (i1>=end || arr[i0]<=arr[i1]))
		{
			copyArr[j] = arr[i0];
			i0++;
		}
		else
		{
			copyArr[j] = arr[i1];
			i1++;
		}

	}

}

void funCopyArr(int * arr,int * copyArr,int start,int end)
{
	for(int i = start; i<end; i++)
	{
		arr[i] = copyArr[i];
	}
}

void swap(int * a, int * b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;

}

void printarr(int * arr, int size)
{
	printf("arr = {");
	for(int i = 0; i<size; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("}\n");
}