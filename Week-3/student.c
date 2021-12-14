#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student_t {
	char id[11];
	char name[65];
	int grade;
	struct Student_t *next;
} Student;

Student * G_sinhVien;

Student *add_student(Student *root, Student *to_add)
{
	Student *curr_std, *prev_std = NULL;
	if(root == NULL)
		return to_add;
	
	if(to_add->grade > root->grade)
	{
		to_add->next = root;
		return to_add;
	}
	curr_std = root;
	while(curr_std != NULL && to_add->grade <= curr_std->grade)
	{
		prev_std = curr_std;
		curr_std = curr_std->next;
	}
	prev_std->next = to_add;
	to_add->next = curr_std;
	
	return root;
}
void danhSachMenu()
{
	printf("Cac tinh nang cua chuong trinh\n");
	printf("0.Liet ke danh sach sinh vien\n");
	printf("1.Them sinh vien\n");
	printf("2.Tim sinh vien\n");
	printf("3.Xoa sinh vien\n");
	printf("4.Thoat chuong trinh\n");
	printf("Vui long nhap lua chon cua ban: ");
}

void themSinhVien()
{
	Student * tmp;
	tmp = (Student *)malloc(sizeof(Student));
	char name[65];
	char id[11];
	int grade;
	printf("Nhap thong tin sinh vien can them\n");
	printf("\tHo ten: ");
	fflush(stdin);
	fgets(name, 64, stdin);
	name[strlen(name) - 1] = '\0';
	printf("\tID: ");
	fflush(stdin);
	scanf("%10s", id);
	printf("\tDiem: ");
	fflush(stdin);
	scanf("%d", &grade);

	strcpy(tmp->name, name);
	strcpy(tmp->id, id);
	tmp->grade =  grade;
	G_sinhVien = add_student(G_sinhVien, tmp);
	printf("Sinh vien ban vua them: ");
	printf("\n\tHo ten: %s", tmp->name);
	printf("\n\tID: %s", tmp->id);
	printf("\n\tDiem: %d\n", tmp->grade);
}

Student *find_student(Student *root, char * id)
{
	Student * tmp = root;
	while(tmp != NULL)
	{
		if(strcmp(tmp->id, id) == 0)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	
	return NULL;
	
}

void timSinhVien()
{
	if(G_sinhVien == NULL)
	{
		printf("Chua co sinh vien nao\n");
		return ;
	}
	char id[11];
	printf("\nNhap ID sinh vien can tim: ");
	fflush(stdin);
	scanf("%s", id);
	Student * result = find_student(G_sinhVien, id);
	if(result)
	{
		printf("\nTim thay sinh vien.Thong tin sinh vien: ");
		printf("\n\tHo Ten: %s", result->name);
		printf("\n\tIDn: %s", result->id);
		printf("\n\tDiem: %d\n", result->grade);
	}
	else
	{
		printf("Khong tim thay sinh vien co ID: %s\n", id);
	}
}

Student *remove_student(Student *root, char * id)
{
	Student *cur, *prev;
	if(root == NULL)
		return root;
	cur = root;
	if(strcmp(cur->id, id) == 0)
	{
		root = root->next;
		free(cur);
		return root;
	}
	
	while(cur != NULL && strcmp(cur->id, id) != 0)
	{
		prev = cur;
		cur = cur->next;
	}
	if(cur != NULL)
	{
		printf("\nDa xoa sinh vien co ID: %s\n", id);
		prev->next = cur->next;
		free(cur);
	}
	else
	{
		printf("\nKhong tim thay sinh vien nay\n");
	}
	
	return root;
}

void lietKeSinhVien()
{
	if(G_sinhVien == NULL)
	{
		printf("Chua co sinh vien nao\n");
		return ;
	}
	Student * tmp = G_sinhVien;
	int i = 1;
	while(tmp != NULL)
	{
		printf("Sinh vien %d: \n", i);
		printf("\tHo ten: %s\n", tmp->name);
		printf("\tID: %s\n", tmp->id);
		printf("\tDiem: %d\n", tmp->grade);
		tmp = tmp->next;
		i++;
	}
}
void xoaSinhVien()
{
	if(G_sinhVien == NULL)
	{
		printf("Chua co sinh vien nao\n");
		return ;
	}
	char id[11];
	printf("\nNhap ID sinh vien can xoa: ");
	fflush(stdin);
	scanf("%s", id);
	G_sinhVien = remove_student(G_sinhVien, id);
}

int main()
{
	int chucNang = 0;
	while(chucNang != 4)
	{
		danhSachMenu();
		fflush(stdin);
		scanf("%d", &chucNang);
		switch(chucNang)
		{
			case 0:
				lietKeSinhVien();
				break;
			case 1:
				themSinhVien();
				break;
			case 2:
				timSinhVien();
				break;
			case 3:
				xoaSinhVien();
				break;
			case 4:
				break;
			default :
				printf("So ban nhap vao khong hop le\n");
				break;
		}
	}
	return 0;
}