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

int main(int argc, char * argv[])
{
	FILE * fin;
	FILE * fout;
	if(argc < 3)
	{
		printf("%s <file1> <file2>n",argv[0]);
		exit(0);
	}
	fin = fopen(argv[1], "r+");
	fout = fopen(argv[2], "w+");
	
	if(fin == NULL)
	{
		printf("Kiem tra tep dau vao: %s", argv[1]);
		exit(0);	
	}		
	
	if(fout == NULL)
	{
		printf("Kiem tra tep dau ra: %s ", argv[2]);
		exit(0);
	}
	
	BlockReadWrite(fin, fout);
	fclose(fin);
	fclose(fout);
	return 0;
}