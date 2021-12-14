#include <stdio.h>
#include <stdlib.h>
int main() {
	int n = 0;
	printf("Nhap du lieu: ");
	fflush(stdin);
	scanf("%d", &n);
	
	int * numbers = NULL;
	numbers = malloc(n * sizeof(int));
	if(numbers == NULL)
	{
		printf("Loi cap phat bo nho");
		return 1;
	}
		
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	FILE *fout = NULL;
	fout = fopen("out.txt", "w+");
	if(fout == NULL)
	{
		printf("Loi mo file");
		return 1;
	}
	
	int sum = 0;
	
	for(int i = n - 1; i >= 0; i--)
	{
		sum += numbers[i];
		fprintf(fout, "%d ", numbers[i]);
	}
	
	fprintf(fout, "%d ", sum);
	
	printf("Hoan thanh.Kiem tra file out.txt");
	fclose(fout);
	
	return 0;
}