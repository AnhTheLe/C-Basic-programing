#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Address {
	char name[30];
	char phone[11];
	char email[40];
} ElementType;
// Queue
typedef struct Node {
	ElementType Element;
	struct Node * Next;
} Node;

typedef Node* Position;
typedef struct {
	Position Front, Rear;
} Queue;

Queue listDanhBa;

void MakeNullQueue(Queue *Q) {
	Position Header;
	Header = (Node * )malloc(sizeof(Node));
	Header->Next = NULL;
	Q->Front = Header;
	Q->Rear = Header;

}

int EmptyQueue(Queue * Q) {
	return (Q->Front == Q->Rear);
}

void EnQueue(ElementType X, Queue *Q) {
	Q->Rear->Next = (Node*)malloc(sizeof(Node));
	Q->Rear = Q->Rear->Next;
	Q->Rear->Element = X;
	Q->Rear->Next = NULL;
}

ElementType DeQueue(Queue *Q) {
	if(!EmptyQueue(Q)) {
		ElementType data;
		Position T;
		T = Q->Front;
		data = T->Element;
		Q->Front = Q->Front->Next;
		free(T);
		return data;
	} else {
		printf("Error: Queue is empty.");
	}
}

// Random String
static char *randomString(char *str, size_t size)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK1234567890";

    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    
    return str;
}

// Doc du lieu mau
void readDataFromFile(const char file_name[])
{
	FILE *fout = NULL;
	fout = fopen(file_name, "rb");
	if(fout == NULL) {
		printf("\nKhong the doc file danh_ba.dat\n");
		return ;
	}
	
	for(int i = 0; i < 20; i++)
	{
		ElementType data;
		fread(&data, sizeof(ElementType), 1, fout);
		printf("\nNguoi thu: %d\n", i);
		printf("Ho ten: %s\n", data.name);
		printf("Dien thoai: %s\n", data.phone);
		printf("Email: %s\n", data.email);
		printf("\n");
	}
	
	fclose(fout);
}
// Tao du lieu mau va luu file
void generateData() {
	FILE *fout = NULL;
	fout = fopen("danh_ba.dat", "w+b");
	if(fout == NULL) {
		printf("\nKhong the tao file danh_ba.dat\n");
		return ;
	}
	
	for(int i = 0; i < 20; i++)
	{
		ElementType data;
		randomString(data.email, 25); // random email
		randomString(data.phone, 10); // random phone
		randomString(data.name, 15); // random name
		fwrite(&data, sizeof(ElementType), 1, fout);
	}
	
	fclose(fout);
	readDataFromFile("danh_ba.dat");
}

void readData()
{
	FILE *fout = NULL;
	fout = fopen("danh_ba.dat", "rb");
	if(fout == NULL) {
		printf("\nKhong the doc file danh_ba.dat\n");
		return ;
	}
	
	for(int i = 0; i < 20; i++)
	{
		ElementType data;
		fread(&data, sizeof(ElementType), 1, fout);
		EnQueue(data, &listDanhBa);
	}
	
	fclose(fout);
}

void coppyData()
{
	FILE *fout = NULL;
	fout = fopen("danh_ba_out.dat", "w+b");
	if(fout == NULL) {
		printf("\nKhong the tao file danh_ba.dat\n");
		return ;
	}
	
	for(int i = 0; i < 20; i++)
	{
		ElementType data;
		data = DeQueue(&listDanhBa);
		fwrite(&data, sizeof(ElementType), 1, fout);
	}
	
	fclose(fout);
	readDataFromFile("danh_ba_out.dat");
}

int main()
{
	srand(time(0));
//	generateData(); // chua co du lieu thi bo comment dong nay
	MakeNullQueue(&listDanhBa);
	readData();
	coppyData();
	return 0;
}