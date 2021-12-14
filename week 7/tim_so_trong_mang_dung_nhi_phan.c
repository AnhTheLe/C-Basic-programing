#include <stdio.h>
int numExecute = 0;
int binarySearch(int A[], int Target, int size)
{
	int start = 0;
	int mid = 0;
	while(start <= size)
	{
		mid = (start + size) / 2;
		if(A[mid] == Target)
			return mid;
		else if(A[mid] < Target)
			start = mid + 1;
		else
			size = mid - 1;
		numExecute += 1;
	}
	
	return -1;
}

int main()
{
	int A[100];
	int num;
	for(int i = 0; i < 100; i++)
	{
		A[i] = i + 1;
	}
	scanf("%d", &num);
	int result = binarySearch(A, num, 99);
	printf("Tim thay o vi tri %d sau %d lan chay", result, numExecute);
	return 0;
}