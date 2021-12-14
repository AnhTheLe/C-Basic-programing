#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, *p;
	
	printf("Nhap so phan tu cua mang: ");
	fflush(stdin);
	scanf("%d", &n);
	p = malloc(n * sizeof(int));
	
	if(p == NULL)
	{
		printf("Loi cap phat bo nho ");
		exit(0);
	}
	
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
		fflush(stdin);
	}
	
	// Dao nguoc mang
	for(i = n - 1; i >= 0; --i)
	{
		printf("%d ", p[i]);
	}
	free(p);
	return 0;
}