#include <stdio.h>
#include <stdlib.h>

void BlockRead(FILE *fin)
{
	int len =  0;
	char tmp[256];
	while(!feof(fin))
	{
		len = fread(tmp, sizeof(char), 255, fin);
		tmp[len] = '\0';
		printf("%s", tmp);
	}
}

int main(int argc, char * argv[])
{
	FILE * fin;
	FILE * fout;
	if(argc < 2)
	{
		printf("%s <file1> ", argv[0]);
		exit(0);
	}
	fin = fopen(argv[1], "r+");
	if(fin == NULL)
	{
		printf("Kiem tra tep dau vao: %s", argv[1]);
		exit(0);	
	}		
	
	
	BlockRead(fin);
	fclose(fin);
	return 0;
}