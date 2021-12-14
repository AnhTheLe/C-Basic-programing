#include <stdio.h>
#include "stack.c"
StackType stack1;
StackType stack2;
StackType result;
void addNumbertoStack(long long num, StackType * stack)
{
	int i = 0;
	int arr[20];
	while(num > 0)
	{
		arr[i] = num % 10;
		num /= 10;
		i++;
	}
	
	for(int j = i - 1; j >= 0; --j)
	{
		push(arr[j], stack);
	}
}

void tinhTong()
{
	int num1, num2;
	int sum = 0;
	int nho = 0;
	while(!empty(stack1) || !empty(stack2))
	{
		num1 = !empty(stack1) ? pop(&stack1) : 0;
		num2 = !empty(stack2) ? pop(&stack2) : 0;
		sum = num1 + num2 + nho;
		if(sum >= 10)
		{
			push(sum - 10, &result);
			nho = 1;
		}
		else
		{
			push(sum, &result);
			nho = 0;
		}
	}
	
	if(nho)
	{
		push(nho, &result);
	}
	
}
void main()
{
	Initialze(&stack1);
	Initialze(&stack2);
	Initialze(&result);
	long long num1, num2;
	printf("Nhap so thu 1 va so thu 2: ");
	fflush(stdin);
	scanf("%llu %llu", &num1, &num2);
	addNumbertoStack(num1, &stack1);
	addNumbertoStack(num2, &stack2);
	tinhTong();
	printf("%llu + %llu = ", num1, num2);
	while(!empty(result))
	{
		printf("%d", pop(&result));
	}
}