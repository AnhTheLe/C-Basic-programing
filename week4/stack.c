#include <stdio.h>
#include "stack.h"

void Initialze(StackType stack)
{
	top = 0;
}

int empty(StackType stack)
{
	return top == 0;
}

int full(StackType stack)
{
	return top == Max;
}

void push(Eltype el, StackType stack)
{
	if(full(*stack))
		printf("Stack overflow");
	else stack[top++] = el;
}

Eltype pop(StackType stack)
{
	if(empty(stack))
		printf("stack underflow");
	else 
		return stack[--top];
}