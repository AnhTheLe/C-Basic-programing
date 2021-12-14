#include <stdio.h>
#include <stdlib.h>

void BlockReadWrite(FILE *fin, FILE *fout)
{
	int len =  0;
	char tmp[256];
	while(!feof(fin))
	{
		len = fread(tmp, sizeof(char), 255, fin);
		tmp[len] = '\0';
		
		printf("%s", tmp);
		fwrite(tmp, sizeof(char), len, fout);
	}
}

int main()
{
	FILE * fin;
	FILE * fout;
	
	fin = fopen("lab1.txt", "r+");
	fout = fopen("lab1a.txt", "w+");
	
	if(fin == NULL)
	{
		printf("Kiem tra tep dau vao ");
		exit(0);	
	}		
	
	if(fout == NULL)
	{
		printf("Kiem tra tep dau ra");
		exit(0);
	}
	
	BlockReadWrite(fin, fout);
	fclose(fin);
	fclose(fout);
	return 0;
}