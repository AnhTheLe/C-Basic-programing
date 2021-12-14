#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[50];
	char phone[20];
	char email[100];
} thong_tin_lien_lac;


void nhap_thong_tin(int num)
{
	FILE * fin;
	fin = fopen("danh_ba.dat", "w+b");
	if(fin == NULL)
	{
		printf("Loi mo file");
		exit(0);
	}

	thong_tin_lien_lac * danh_ba;
	danh_ba = malloc(sizeof(thong_tin_lien_lac) * num);
	if(danh_ba == NULL)
	{
		printf("Loi cap phat bo nho ");
		exit(0);
	}
	for(int i = 0; i < num; i++)
	{
		printf("Nhap thong tin cua nguoi thu: %d \n", i + 1);
		fflush(stdin);
		printf("\t Ho ten: ");
		fflush(stdin);
		fgets(danh_ba[i].name, sizeof(danh_ba[i].name), stdin);
		danh_ba[i].name[strlen(danh_ba[i].name)] = '\0';
		printf("\t So dien thoai: ");
		fflush(stdin);
		scanf("%s", &danh_ba[i].phone);
		printf("\t Dia chi email: ");
		fflush(stdin);
		scanf("%s", &danh_ba[i].email);
	}
	
	int irc = fwrite(danh_ba, sizeof(thong_tin_lien_lac), num, fin);
	printf("Ma code tra ve: %d\n", irc);
	fclose(fin);
	
}

void doc_thong_tin(int num)
{
	printf("Thong tin danh ba \n");
	FILE * fin;
	fin = fopen("danh_ba.dat", "rb");
	if(fin == NULL)
	{
		printf("Loi mo file\n");
		exit(0);
	}
	
	thong_tin_lien_lac danh_ba[num];
	fread(danh_ba, sizeof(thong_tin_lien_lac), num, fin);
	for(int i = 0; i < num; i++)
	{
		printf("Thong tin lien he cua nguoi thu: %d \n", i);
		printf("\tHo ten: %s\n", danh_ba[i].name);
		printf("\tSDT: %s\n", danh_ba[i].phone);
		printf("\tEmail: %s\n", danh_ba[i].email);
	}
	
	fclose(fin);
}

int main()
{
	int num = 0;
	printf("Nhap so luong danh ba can them: ");
	fflush(stdin);
	scanf("%d", &num);
	if(num <= 0)
	{
		exit(0);
	}
	
	nhap_thong_tin(num);
	doc_thong_tin(num);
	return 0;
}