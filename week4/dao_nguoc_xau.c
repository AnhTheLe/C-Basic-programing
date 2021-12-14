#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char data[65];
	struct node *link;
} node;

struct node * push(struct node *p, char value[])
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Loi cap phat bo nho\n");
		exit(0);
	}
	
	strcpy(temp->data, value);
	temp->link = p;
	p = temp;
	return p;
}

struct node *pop(struct node *p, char *value[])
{
	struct node *temp;
	if(p == NULL)
	{
		printf("Stack rong");
		exit(0);
	}
	strcpy(value, p->data);
	temp = p;
	p = p->link;
	free(temp);
	return p;
}

void daoNguocXau(char string[])
{
	int i = 0;
	int j = 0;
	char c;
	int count = strlen(string);
	while(i != count/2)
	{
		c = string[i];
		string[i] = string[count - i - 1];
		string[count - i - 1] = c;
		i++;
	}
	printf("%s", string);
}

void main()
{
	struct node *top = NULL;
	int n;
	char value[65];
	do 
	{
		do 
		{
			printf("Nhap xau can them vao stack\n");
			fflush(stdin);
			scanf("%s", value);
			top = push(top, value);
			printf("Nhap 1 neu muon tiep tuc them\n");
			fflush(stdin);
			scanf("%d", &n);	
		} while(n == 1);
		
		printf("\nNhap 1 neu muon lay 1 phan tu cua stack\n");
		fflush(stdin);
		scanf("%d", &n);
		while(n == 1)
		{
			top = pop(top, &value);
			printf("\nXau lay ra: %s\n", value);
			printf("\nXau duoc dao nguoc: ");
			daoNguocXau(value);
			printf("\nNhap 1 neu muon lay ra phan tu ke tiep\n");
			fflush(stdin);
			scanf("%d", &n);
		}
		
		printf("Nhap 1 de tiep tuc\n");
		fflush(stdin);
		scanf("%d", &n);
	} while(n == 1);
	
}