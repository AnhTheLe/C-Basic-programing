#include <stdio.h>
#include <stdlib.h>
#include <string>
typedef struct Student_t {
	char id[11];
	char name[40];
	int grade;
	
	struct Student_t * next;
} Student;