/*
Lê Thế Anh
MSSV: 20200018
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int stackToanTu[100];
char stackSoHang[100];
int topToanTu = 0;
int topSoHang = 0;

// stack luu toan tu
char popToanTu()
{
	char result;
	result = stackToanTu[topToanTu];
	--topToanTu;
	return result;
}

char getToanTu()
{
	char result;
	result = stackToanTu[topToanTu];
	return result;
}

void pushToanTu(int num)
{
	++topToanTu;
	stackToanTu[topToanTu] = num;	
}

// stack luu so hang
int popSoHang()
{
	int result;
	result = stackSoHang[topSoHang];
	--topSoHang;
	return result;
}

void pushSoHang(int num)
{
	++topSoHang;
	stackSoHang[topSoHang] = num;	
}



// Kiem tra co phai so hang khong
int isNumber(char num)
{
	if(num >= '0' && num <= '9')                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	{
		return 1;
	}
	return 0;
}
// Kiem tra co phai phep toan khong
int isOp(char op)
{
	if(op == '+' || op == '-' || op == '*' || op == '/')
	{
		return 1;
	}
	return 0;
}

int thucHienPhepToan(int num1, int num2, char op)
{
	int result;
	switch(op) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
	}
	return result;
}


int getOrder(char op)
{
	if(op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;	
}


// Thuc hien tinh toan
int tinhToan()
{
	int num1, num2, result;
	
	while(topToanTu > 0)
	{
		char op = popToanTu();
		num2 = popSoHang();
		num1 = popSoHang();
		result = thucHienPhepToan(num1, num2, op);
		pushSoHang(result);
		printf("%c ", op);
	}

	return (popSoHang());
}

void chuyenHauTo(char string[])
{
	char c;
	for(int i = 0; i < strlen(string); i++)
	{
		c = string[i];
		if(isNumber(c))
		{
			
			pushSoHang((int)c - '0'); // chuyen ky tu sang dang int va push vao stack
			printf("%c ", c);
		}
		else if(isOp(c))
		{
			int order = getOrder(c);
			while(topToanTu > 0 && getOrder(getToanTu()) >= order)
			{
				char op = popToanTu();
				int num2 = popSoHang();
				int num1 = popSoHang();
				int result = thucHienPhepToan(num1, num2, op);
				pushSoHang(result);
				printf("%c ", op);
			}
			pushToanTu(c);
		}
	}
}

int main()
{
	char expression[100];
	int result;
	printf("Xau bieu thuc: ");
	fflush(stdin);
	scanf("%100s", expression);
	chuyenSangHauTo(expression);
	result = tinhToan();
	printf("\nGia tri: %d", result);
	return 0;
}
