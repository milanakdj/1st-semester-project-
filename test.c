#include <stdio.h>
#include <ctype.h>

struct std{ // initialize Structure for Student's informations
	int id;
	char name[40];
	char lname[40];
	char fields[40];
	int semester;
	float gpa;
}a;

int main(){
	printf("enter student's first name, last name, semester, id, field\n");
	int ret = scanf("%s%s%d%d%s",a.name,a.lname,&a.semester,&a.id,a.fields);
	printf("\n%d", ret);
	return 0;
}
