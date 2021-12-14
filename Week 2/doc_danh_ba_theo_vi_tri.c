#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[50];
	char phone[20];
	char email[100];
} thong_tin_lien_lac;

int main()
{

	printf("Thong tin danh ba o vi tri thu 2 va vi tri thu 3 \n");
	FILE * fin;
	fin = fopen("danh_ba.dat", "r+b");
	if(fin == NULL)
	{
		printf("Loi mo file\n");
		exit(0);
	}
	
	thong_tin_lien_lac * danh_ba;
	danh_ba = malloc(sizeof(thong_tin_lien_lac) * 2);
	if(danh_ba == NULL)
	{
		printf("Loi cap phat bo nho");
		exit(0);
	}
	fseek(fin, 1 * sizeof(thong_tin_lien_lac), SEEK_SET);
	fread(danh_ba, sizeof(thong_tin_lien_lac), 2, fin);
	for(int i = 0; i < 2; i++)
	{
		printf("Thong tin lien he cua nguoi thu: %d \n", i);
		printf("\tHo ten: %s\n", danh_ba[i].name);
		printf("\tSDT: %s\n", danh_ba[i].phone);
		printf("\tEmail: %s\n", danh_ba[i].email);
	}
	
	strcpy(danh_ba[1].name, "BN2002");
	strcpy(danh_ba[1].phone, "01234567756");
	strcpy(danh_ba[1].email, "doanhcms@gmail.com");
	fseek(fin, 1 * sizeof(thong_tin_lien_lac), SEEK_SET);
	fwrite(danh_ba, sizeof(thong_tin_lien_lac), 2, fin);
	
	fclose(fin);
	return 0;
}