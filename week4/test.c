#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *link;
} node;

struct node * push(struct node *p, int value)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Loi cap phat bo nho\n");
		exit(0);
	}
	
	temp->data = value;
	temp->link = p;
	p = temp;
	return p;
}

struct node *pop(struct node *p, int *value)
{
	struct node *temp;
	if(p == NULL)
	{
		printf("Stack rong");
		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->link;
	free(temp);
	return p;
}

void main()
{
	struct node *top = NULL;
	int n, value;
	do 
	{
		do 
		{
			printf("Nhap phan tu can them vao stack\n");
			scanf("%d", &value);
			top = push(top, value);
			printf("Nhap 1 neu muon tiep tuc them\n");
			scanf("%d", &n);	
		} while(n == 1);
		
		printf("Nhap 1 neu muon lay 1 phan tu cua stack");
		scanf("%d", &n);
		while(n == 1)
		{
			top = pop(top, &value);
			printf("The value poped is %d\n", value);
			printf("Nhap 1 neu muon lay ra phan tu ke tiep\n");
			scanf("%d", &n);
		}
		
		printf("Nhap 1 de tiep tuc\n");
		scanf("%d", &n);
	} while(n == 1);
	
}