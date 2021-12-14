#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MaxLength 10
typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Front, Rear;
} Queue;
Queue danhSachSo;
void MakeNull_Queue(Queue *Q)
{
	Q->Front = -1;
	Q->Rear = -1;
}

int Empty_Queue(Queue Q) 
{
	return Q.Front == -1;
}

int Full_Queue(Queue Q)
{
	return (Q.Rear - Q.Front + 1) % MaxLength == 0;
}

ElementType DeQueue(Queue *Q)
{
	if(!Empty_Queue(*Q))
	{
		int tmp;
		tmp = Q->Elements[Q->Front];
		if(Q->Front == Q->Rear)
			MakeNull_Queue(Q);
		else
		{
			Q->Front = (Q->Front + 1) % MaxLength;
		}
		return tmp;
	}
	else
	{
		printf("Queue rong");
	}
}

void EnQueue(ElementType X, Queue *Q)
{
	if(Full_Queue(*Q))
	{
		printf("\n Queue day, xoa phan tu dau tien co gia tri: %d \n", DeQueue(Q));
	}
	
	if(!Full_Queue(*Q))
	{
		if(Empty_Queue(*Q))
			Q->Front = 0;
		Q->Rear = (Q->Rear + 1) % MaxLength;
		Q->Elements[Q->Rear] = X;
	}
}

void viewItemInQueue()
{
	printf("\n");
	for(int i = 0; i < MaxLength; i++)
	{
		printf("%d ", danhSachSo.Elements[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	MakeNull_Queue(&danhSachSo);
	for(int i = 0; i < 10; i++)
	{
		int num = rand();
		EnQueue(num, &danhSachSo);
	}
	printf("Danh sach queue hien tai: \n");
	viewItemInQueue();
	printf("Danh sach queue sau khi them phan tu co gia tri 12 \n");
	EnQueue(12, &danhSachSo);
	EnQueue(15, &danhSachSo);
	EnQueue(16, &danhSachSo);
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", DeQueue(&danhSachSo));
	}
	
	return 0;
}