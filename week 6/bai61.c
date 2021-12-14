#include <stdio.h>

int main()
{
	int numbers[10];
	int num;
	int ok = 0;
	
	fflush(stdin);
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	scanf("%d", &num);
	for(int i = 0; i < 10; i++)
	{
		if(numbers[i] == num)
		{
			printf("%d ", i);
			ok = 1;
			break;
		}
	}
	
	if(ok == 0)
		printf("\nKhong tim thay\n");
}