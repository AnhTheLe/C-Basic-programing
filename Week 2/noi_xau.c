#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[255];
	char s2[255];
	char * result = NULL;
	printf("Nhap chuoi ky tu 1: ");
	fflush(stdin);
	scanf("%s", s1);
	printf("Nhap chuoi ky tu 2: ");
	fflush(stdin);
	scanf("%s", s2);
	
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	result = (char *)malloc( (len1 + len2 + 1)*sizeof(char) );
	if(result == NULL)
	{
		printf("Loi cap phat bo nho ");
		exit(0);
	}
	strcpy(result, s1);
	strcpy(result + len1, s2);
	printf("Ket qua la: %s", result);
	
	free(result);
	return 0;
}