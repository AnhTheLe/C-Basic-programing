#include <stdio.h>
#include <string.h>
typedef struct Address {
	char name[32];
	char phone[11];
	char email[40];
} Address;

int soLienHe = 10;
Address danhBa[100];
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
	for(int i = 0; i < soLienHe; i++)
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

void docDanhBa()
{
	FILE * fin = fopen("danh_ba.dat", "rb");
	if(fin == NULL)
	{
		printf("Khong mo duoc file danh_ba.dat");
		return ;
	}
	Address lienHe;
	for(int i = 0; i < soLienHe; i++)
	{
		fread(&lienHe, sizeof(struct Address), 1, fin);
		strcpy(danhBa[i].email, lienHe.email);
		strcpy(danhBa[i].name, lienHe.name);
		strcpy(danhBa[i].phone, lienHe.phone);
	}
}

void sapXepTheoTen()
{
	for(int i = 0; i < soLienHe - 1; i++)
	{
		for(int j = i + 1; j < soLienHe; j++)
		{
			if(strcmp(danhBa[i].name, danhBa[j].name) > 0)
			{
				Address tmp = danhBa[j];
				danhBa[j] = danhBa[i];
				danhBa[i] = tmp;
			}
		}
	}
}

void inDanhBa()
{
	for(int i = 0; i < soLienHe; i++)
	{
		printf("Thong tin lien lac nguoi thu %d: \n", i + 1);
		printf("\tHo ten: %s\n", danhBa[i].name);
		printf("\tEmail: %s\n", danhBa[i].email);
		printf("\tPhone: %s\n", danhBa[i].phone);
	}
}

void ghiKetQua(Address * thongTin)
{
	FILE * fin = fopen("danh_ba_out.txt", "w+");
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
	printf("\nNhap ten can tim: ");
	fflush(stdin);
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	
	int Low, Mid, High;
	int index = -1;
	Low = 0;
	High = soLienHe - 1;
	
	while(Low <= High)
	{
		Mid = (Low + High) / 2;
		if(strcmp(danhBa[Mid].name, name) < 0)
			Low = Mid + 1;
		else if(strcmp(danhBa[Mid].name, name) > 0)
			High = Mid - 1;
		else 
		{
			ghiKetQua(&danhBa[Mid]);
			printf("\nTim thay nguoi nay trong danh ba.Hay xem file ket qua\n");
			index = Mid;
			break;
		}
	
	}

	if(index == -1)
	{
		printf("\nKhong tim thay ten nay trong danh ba\n");
	}
	
}

int main()
{
//	taoDuuLieu(); // Neu chua co duu lieu thi bo comment dong nay
	docDanhBa();
	inDanhBa();
	sapXepTheoTen();
	printf("\nSau khi sap xep\n");
	inDanhBa();
	timKiemDanhBa();
	
}