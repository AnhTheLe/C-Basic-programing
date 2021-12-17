#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NotFound (-1)
#define nameLength 15
#define emailLength 25
#define phoneLength 11
typedef struct Address
{
    char name[nameLength];
    char phone[phoneLength];
    char email[emailLength];
    struct Address *next;
} ad;

ad AddressList[100];
FILE *input = fopen("input1.txt", "r");
FILE *fptr = fopen("output2.txt", "w+");
// Ghi danh sách vào biến
void push(ad *address, int i, char name[], char phone[], char email[])
{
    strcpy((address + i)->name, name);
    strcpy((address + i)->phone, phone);
    strcpy((address + i)->email, email);
}
// Tìm kiếm Nhị Phân sử dụng mảng
void Binary_Find(ad *address, char name[], int n) {
   int l = 0, r = n - 1;
   while (l <= r) {
      int m = (l + r) / 2;
      int compare = strcmp(name, (address + m)->name);
      if (compare == 0) {
         printf("Found!\n%s %s %s\n", (address + m)->name, (address + m)->phone, (address + m)->email);
         return;
      }
      if (compare > 0)
         l = m + 1;
      if (compare < 0)
         r = m - 1;
   }
   printf("NOT FOUND!");
}

void find(ad *address, char tmp[], int n) {
   for (int i = 0; i < n; i++) {
      if (strcmp((address + i)->name, tmp) == 0) {
        printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
        // fprintf(fptr, "%s\n%s\n%s", (address + i)->name, (address + i)->phone, (address + i)->email);
        // fclose(fptr);
         return;
      }
   }
}   
// sử dụng linklist
ad *linklist(char X[], ad *ro)
{
    for (ad *k = ro; k != NULL; k = k->next)
    {
        if (strcmp(k->next->name, X) == 0)
            return k;
    }
}

ad *front;
ad *rear;
// sử dụng queue
void EnQueue(char *name1, char *phone1, char *email1)
{
    ad *neww;
    neww = (ad *)malloc(sizeof(ad));
    strcpy(neww->name, name1);
    strcpy(neww->phone, phone1);
    strcpy(neww->email, email1);
    neww->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = neww;
        rear = neww;
    }
    else
    {
        rear->next = neww;
        rear = neww;
    }
}

ad DeQueue(void)
{
    ad tmp = *front;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
        return tmp;
    }
    else
    {
        front = front->next;
        return tmp;
    }
}

ad Queue(char a[], ad *fr)
{
    for (ad *k = fr; k != rear; k = k->next)
    {
        if (strcmp(k->name, a) == 0)
            return *k;
    }
}

void In(void)
{
    for (ad *k = front; k != rear; k = k->next)

        printf("%s\t%s\t%s\n", k->name, k->email, k->phone);
    printf("%s\t%s\t%s\n", rear->name, rear->email, rear->phone);
}

int main()
{
    int n;
    FILE *input = fopen("input1.txt", "r");
    FILE *fptr = fopen("output2.txt", "w+");
    fscanf(input, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        char name[nameLength], email[emailLength], phone[phoneLength];
        fscanf(input, "%s", name);
        fscanf(input, "%s", phone);
        fscanf(input, "%s", email);
        push(AddressList, i, name, phone, email);
    }
    printf("Read Successfully! \n");

    ad *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        ad *Newnode;
        Newnode = (ad *)malloc(sizeof(ad));
        strcpy(Newnode->name, AddressList[i].name);
        strcpy(Newnode->phone, AddressList[i].phone);
        strcpy(Newnode->email, AddressList[i].email);
        Newnode->next = root;
        root = Newnode;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
    }

    front = NULL;
    rear = NULL;

    for (int i = 0; i < n; i++)
    {
        EnQueue(AddressList[i].name, AddressList[i].phone, AddressList[i].email);
    }

    int c;
    do
    {
        printf("\n\nOptions: \n0. Exit\n1. Array\n2. Singly-linked List \n3. Queue\n4. Nhap them phan tu\n5. In Queue\n");
        printf("Chose option: ");
        scanf("%d", &c);
        char tmp[emailLength];
        switch (c)
        {
        case 1:
            char tmp[nameLength];
            printf("Option 1 use array\nPlease enter the name to search:");
            scanf("%s", tmp);
            Binary_Find(AddressList, tmp, n);
            break;
        case 2:
        {
            char name2[nameLength];
            printf("Option 2 use linked list\nPlease enter the name to search:");
            
            fflush(stdin);
            gets(name2);
            ad *bf = linklist(name2, root);
            ad *move = bf->next;
            bf->next = move->next;
            move->next = root;
            root = move;
            Binary_Find(AddressList, name2, n);
            break;
        }

        case 3:
        {
            char name3[nameLength];
            printf("Option 3 use queue!\nPlease enter the name to search:");
            fflush(stdin);
            gets(name3);
            Queue(name3, front);
            ad oo = Queue(name3, front);
            printf("\n%s\n%s\n%s", Queue(name3, front).name, Queue(name3, front).phone, Queue(name3, front).email);
            break;
        }
        
        case 4:
        {
            char name3[nameLength];
            char phone3[phoneLength];
            char email3[emailLength];
            fflush(stdin);
            gets(name3);
            fflush(stdin);
            gets(phone3);
            fflush(stdin);
            gets(email3);
            EnQueue(name3, phone3, email3);
            DeQueue();
        }
        case 5:
            In();
            break;

        default:
            break;
        }
    } while (c != 0);

    fclose(input);
}