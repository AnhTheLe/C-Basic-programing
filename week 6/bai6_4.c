#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fin = NULL;
	fin = fopen("words_list.txt", "r+");
	if(fin == NULL)
	{
		printf("Khong the mo file word_list.txt\n");
		return -1;
	}
	char tmp[31];
	char keyWord[31];
	int find = 0;
	printf("\nNhap tu can tim: ");
	fflush(stdin);
	scanf("%30s", keyWord);
	while(!feof(fin))
	{
		fgets(tmp, 30, fin);
		tmp[strlen(tmp) - 1] = '\0';
		if(strstr(tmp, keyWord) != NULL)
		{
			printf("%s \n", tmp);
			find = 1;
		}
	}
	
	if(find == 0)
	{
		printf("\nKhong tim thay tu nao tuong tu");
	}
	return 0;
}