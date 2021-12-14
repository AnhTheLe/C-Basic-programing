#include <stdio.h>

int binSearch(int A[], int Target, int Size)
{
	int Low, Mid, High;
	Low = 0;
	High = Size - 1;
	while(Low <= High)
	{
		Mid = (Low + High) / 2;
		if(A[Mid] < Target)
		{
			Low = Mid + 1;
		}
		else if(A[Mid] > Target)
		{
			High = Mid - 1;
		}
		else 
		{
			return Mid;
		}
	}
	
	return -1;
	
}

int main()
{
	int A[] = {1, 3, 5, 7, 9, 13, 15};
	int SizeofA = sizeof(A)/sizeof(A[0]);
	for(int i = 0; i < 20; i++)
	{
		printf("BinarySearch of %d returns %d\n", i, binSearch(A, i, SizeofA));
	}
	return 0;
}