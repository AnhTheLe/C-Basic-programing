#include <stdio.h>
#define Max 50

typedef struct address {
	char name[65];
	char phone[11];
	char email[129];	
} address;

typedef address StackType[Max];
int top;

void Initialze()
{
	top = 0;
}

int empty()
{
	return top == 0;
}

int full()
{
	return top == Max;
}

void push(address info, StackType stack)
{
	if(full(*stack))
		printf("Stack overflow");
	else stack[top++] = info;
}

address pop(StackType stack)
{
	if(empty(stack))
		printf("stack underflow");
	else 
		return stack[--top];
}

int main()
{
	StackType stack;
	Initialze();
	address info = {
		"Duy Doanh",
		"0123456789",
		"doanh@gmail.com"
	};
	
	push(info, stack);
	address tmp = pop(stack);
	printf("%s", tmp.name);
	
}