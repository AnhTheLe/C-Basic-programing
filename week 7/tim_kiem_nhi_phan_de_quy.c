#include <stdio.h>
int Target;
int binSearch(int A[], int Start, int End)
{
	int Mid = (Start + End) / 2;
	if(Start == End)
	{
		if(A[Mid] == Target)
		{
			return Mid;
		}
		else
		{
//			printf("Khong tim thay\n");
			return -1;
		}
	}
	if(A[Mid] > Target)
		binSearch(A, Start, Mid - 1);
	else if(A[Mid] < Target)
		binSearch(A, Mid + 1, End);
	else
		return Mid;
}

int main()
{
	int A[] = {1, 3, 5, 7, 9, 13, 15};
	int SizeofA = sizeof(A)/sizeof(A[0]);
	for(int i = 0; i < 20; i++)
	{
		Target = i;
		printf("BinarySearch of %d returns %d\n", i, binSearch(A, 0, SizeofA - 1));
	}
	return 0;
}