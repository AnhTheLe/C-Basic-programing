#include <stdio.h>
int numExecute = 0;
int binarySearch(int A[], int target, int start, int end)
{
	int mid = (start + end) / 2;
	if(start == end)
	{
		if(A[mid] == target)
			return mid;
		else
			return -1;
	}
	
	if(A[mid] > target)
		binarySearch(A, target, start, mid - 1);
	else if(A[mid] < target)
		binarySearch(A, target, mid + 1, end);
	else
		return mid;
	numExecute++;
	
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
	int result = binarySearch(A, num, 0, 99);
	printf("Tim thay o vi tri %d sau %d lan chay", result, numExecute);
	return 0;
}