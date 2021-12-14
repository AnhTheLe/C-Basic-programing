#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Address {
	char name[32];
	char phone[11];
	char email[40];
} Address;

typedef struct danhBa {
	Address data;
	struct danhBa * next;
} danhBa;

danhBa * danhSachLienHe;

danhBa * themLienHe(danhBa * root, danhBa * lienLacMoi)
{
	if(root == NULL)
	{
		root =  lienLacMoi;
	}
	else
	{
		danhBa * curr_std = root;
		while(curr_std->next != NULL)
		{
			curr_std = curr_std->next;
		}
		curr_std->next = lienLacMoi;
	}

	return root;
}

void taoDuuLieu()
{
	FILE *fout = fopen("danh_ba.dat", "w+b");
	if(fout == NULL)
	{
		printf("Loi mo file danh_ba.dat\n");
		return ;
	}
	
	char tmp[40];
	Address lienHe;
	for(int i = 0; i < 10; i++)
	{
		printf("Thong tin lien lac nguoi thu %d: \n", i + 1);
		
		fflush(stdin);
		printf("\tEmail: ");
		fgets(tmp, sizeof(lienHe.email), stdin);
		tmp[strlen(tmp) - 1] = '\0';
		strcpy(lienHe.email, tmp);
		
		fflush(stdin);
		printf("\tHo Ten: ");
		fgets(tmp, sizeof(lienHe.name), stdin);
		tmp[strlen(tmp) - 1] = '\0';
		strcpy(lienHe.name, tmp);
		
		fflush(stdin);
		printf("\tPhone: ");
		fgets(tmp, sizeof(lienHe.phone), stdin);
		tmp[strlen(tmp) - 1] = '\0';
		strcpy(lienHe.phone, tmp);
		fwrite(&lienHe, sizeof(lienHe), 1, fout);
	}
	fclose(fout);
	
}

void docDanhBaTuFile()
{
	FILE * fin = fopen("danh_ba.dat", "rb");
	if(fin == NULL)
	{
		printf("Khong mo duoc file danh_ba.dat");
		return ;
	}
	
	danhBa * tmp;
	Address lienHe;
	// Luu data vao danh sach
	for(int i = 0; i < 10; i++)
	{
		tmp = (danhBa *)malloc(sizeof(danhBa));
		fread(&lienHe, sizeof(struct Address), 1, fin);
		tmp->data = lienHe;
		tmp->next = NULL;
		danhSachLienHe = themLienHe(danhSachLienHe, tmp);
	}
}

void docDanhBaTuDanhSach()
{
	//	Doc tu danh sach va in ra
	int i = 0;
	danhBa * tmp;
	tmp = danhSachLienHe;
	while(tmp != NULL)
	{
		printf("Thong tin lien lac nguoi thu %d: \n", i + 1);
		printf("\tHo ten: %s\n", tmp->data.name);
		printf("\tEmail: %s\n", tmp->data.email);
		printf("\tPhone: %s\n", tmp->data.phone);
		tmp = tmp->next;
		i++;
	}
}
void ghiKetQua(Address * thongTin)
{
	FILE * fin = fopen("danh_ba_out_b.txt", "w+");
	if(fin == NULL)
	{
		printf("Khong mo duoc file danh_ba_out.txt");
		return ;
	}
	
	fprintf(fin, "Ho ten: %s\n", thongTin->name);
	fprintf(fin, "Email: %s\n", thongTin->email);
	fprintf(fin, "Phone: %s\n", thongTin->phone);
	fclose(fin);
}

void timKiemDanhBa()
{
	char name[32];
	int index = -1;
	printf("Nhap ten can tim: ");
	fflush(stdin);
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	
	danhBa * tmp = danhSachLienHe;
	while(tmp != NULL)
	{
		if(strstr(tmp->data.name, name) != NULL)
		{
			ghiKetQua(&tmp->data);
			printf("\nTim thay nguoi nay trong danh ba.Hay xem file ket qua\n");
			index = 1;
			break;
		}
		tmp = tmp->next;
	}
		
	if(index == -1)
	{
		printf("\nKhong tim thay ten nay trong danh ba\n");
	}
	
}

int main()
{
//	taoDuuLieu(); // Neu chua co duu lieu thi bo comment dong nay
	docDanhBaTuFile();
	docDanhBaTuDanhSach();
	timKiemDanhBa();
	
}