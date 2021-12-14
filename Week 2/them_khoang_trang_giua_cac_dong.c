#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * fin = NULL;
	FILE * fout = NULL;
	
	fin = fopen("class1EF.txt", "r");
	fout = fopen("class1EF_out.txt", "w+");
	if(fin == NULL || fout == NULL)
	{
		printf("Kiem tra ten file dau vao va dau ra");
		exit(0);
	}
	char c;
	int i = 0;
	while((c = fgetc(fin)) != EOF)
	{
		i++;
		fputc(c, fout);
		if(c == '\n')
			fputc('\n', fout);
		if(i > 10000) break; // Chong tran bo nho neu co loi
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}