#include <stdio.h>

int search(int key, int r[], int n)
{
	int i, j;
	int tempr;
	for(i = 0; i < n - 1 && r[i] != key; i++);
	if(key == r[i])
	{
		if(i > 0)
		{
			int temp;
			tempr =  r[i];
			for(j = i - 1; j >= 0; j--)
			{
				r[j + 1] = r[j];
			}
			r[0] = tempr;
		}
		return (i);
	}
	else
	{
		return (-1);
	}
}
int main()
{
	int a[4] = {1, 2, 3, 4};
	printf("%d ", search(4, a, 4));
	printf("\n");
	for(int i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}