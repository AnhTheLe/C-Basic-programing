#include <stdio.h>
#include <string.h>
#define Max 100
typedef char Eltype;
typedef Eltype StackType[Max];
int top_stack;
void Initialize(StackType stack)
{
	top_stack = 0;
}

int empty(StackType stack)
{
	return top_stack == 0;
}

int full(StackType stack)
{
	return top_stack == Max;
}

void push(Eltype el, StackType stack)
{
	if(full(stack))
		printf("Stack overflow");
	else 
	{
		stack[top_stack++] = el;	
	}
		
}

Eltype pop(StackType stack)
{
	if(empty(stack))
		printf("stack underflow");
	else
		return stack[--top_stack];	
}

Eltype getTop(StackType stack)
{
	if(!empty(stack))
	{
		return stack[top_stack];	
	}
}

// End Stack
int layDoUuTien(char kyTu)
{
	if(kyTu == '*' || kyTu == '/')
		return 2;
	if(kyTu == '+' || kyTu == '-')
		return 1;
	
	return 0;
}

int kiemTraCoPhaiToanHangKhong(char kyTu)
{
	if(kyTu >= '0' && kyTu <= '9')
		return 1;
		
	return 0;
}

int kiemTraDauMoNgoac(char kyTu)
{
	if(kyTu == '(' || kyTu == '[')
		return 1;
		
	return 0;
}

int kiemTraDauDongNgoac(char kyTu)
{
	if(kyTu == ')' || kyTu == ']')
		return 1;
		
	return 0;
}

int kiemTraCoPhaiToanTuKhong(char kyTu)
{
	if(kyTu == '+' || kyTu == '-' || kyTu == '*' || kyTu == '/')
		return 1;
		
	return 0;
}

int main(int argc, char *argv[])
{
	char *a = argv[1];
	StackType myStack;
	Initialize(myStack);
	
	for(int i = 0; i < strlen(a); i++)
	{
		char kyTuHienTai = a[i];
		if(kiemTraCoPhaiToanHangKhong(kyTuHienTai))
		{
			printf("%c ", kyTuHienTai);
		}
		else if(kiemTraDauMoNgoac(kyTuHienTai))
		{
			push(kyTuHienTai, myStack);
		}
		
		else if(kiemTraDauDongNgoac(kyTuHienTai))
		{
			char tmp_ngoac = pop(myStack);
			while(!kiemTraDauMoNgoac(tmp_ngoac))
			{
				printf("%c ", tmp_ngoac);
				if(empty(myStack))
					break;
				tmp_ngoac = pop(myStack);
			}
		}
		else
		{
			while(!empty(myStack) && layDoUuTien(kyTuHienTai) <= layDoUuTien(getTop(myStack)))
			{
					char tmp = pop(myStack);
					if(kiemTraDauMoNgoac(tmp))
						continue;
					printf("%c ", tmp);
			}

			push(kyTuHienTai, myStack);
		}
		
	}
	
	
	while(!empty(myStack))
	{
		if(top_stack < 0)
			break;
		printf("%c ", pop(myStack));
	}
	return 0;
}