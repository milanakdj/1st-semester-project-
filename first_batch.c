#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include<stdbool.h>
//#include<bios.h>

#define RETURNTIME 15

bool sixp_flag = false;
bool isHoliday = false;
char firp[40] = "MATHS", secp[40] = "C PROGRAMMING", thp[40] = "BREAK", foup[40] = "COMPUTER FUNDAMENTALS", fifp[40] = "MODERN BUSINESS PRACTICE", sixp[40] = "NONE"; //DECLARATION FOR NORMAL PERIODS OF CURRENT DAY
char strEdit[40];


COORD coord = {0, 0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char categorie[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void returnfunc(void);
void mainmenu(void);
void studentinfo(void);
void teacherinfo(void);
void examinfos();
void classinfo(void);
void routineinfo(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void headMessage(char *message);
void welcomeMessage();
void Password();
void issuerecord();
void loaderanim();
void mainroutineedit();


void studentinfoedit();
void teacherinfoedit();
void routineedit();
void examinfosedit();
void resultedit();
void deleteteach();
void deletestd();

void routineedit_comp();

FILE *fp,*ft,*fs;



int s;
//char studentinfo;
char password[20]={"fjfj"};



struct meroDate
{
int mm,dd,yy;
};
//
//struct books
//{
//int id;
//char stname[20];
//char name[20];
//char Author[20];
//int quantity;
//float Price;
//int count;
//int rackno;
//char *cat;
//struct meroDate issued;
//struct meroDate duedate;
//};
//
//struct books a;


struct std{
	int id;
	char name[40];
	char lname[40];
	char fields[40];
	int semester;
	float gpa;
}a;



struct teach{
	int id;
	char name[40];
	char lname[40];
	char fields[40];
}aa;

void headMessage(char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t");
    printf(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welcomeMessage()
{
    headMessage("A Group Presentation");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
int main()
{
	welcomeMessage();
	headMessage("Login");
Password();
getch();
return 0;

}

void routineedit_comp()
{
	system("cls");
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT THE ONE THAT YOU WANT TO EDIT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Semester 1   ");
	
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Semester 2   ");

	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Semester 3   ");

	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Semester 4   ");
	
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Semester 5   ");
	
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Semester 6   ");
	
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Semester 7   ");
	
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Semester 8   ");
	
	
	gotoxy(20,21);
	printf("Enter your choice:");

	switch(getch())
	{
		case '1':
			mainroutineedit();
			break;
		case '2':
			teacherinfoedit();
			break;
		case '3':
			routineinfo();
			break;
		case '4':
			examinfos();
			break;
	
	}

	
}

void mainroutineedit(){
	int editFlag = 1;
	routineinfo();
	int n;
	flag_check:
	do{
		printf("\nWhich Period would you like to change: ");
		scanf("%d",&n);
	}while(n>6||n<1);
	if(n==6 & !sixp_flag)
	goto flag_check;
	printf("Enter Subject..");
	fflush(stdin);
	scanf("%[^\n]",strEdit);
	switch(n){
		case 1:
			strcpy(firp,strEdit);
			strupr(firp);
			break;
		case 2:
			strcpy(secp,strEdit);
			strupr(secp);
			break;
		case 3:
			strcpy(thp,strEdit);
			strupr(thp);
			break;
		case 4:
			strcpy(foup,strEdit);
			strupr(foup);
			break;
		case 5:
			strcpy(fifp,strEdit);
			strupr(fifp);
			break;
		case 6:
			strcpy(sixp,strEdit);
			strupr(sixp);
			break;
	}
	system("cls");
	routineinfo();
	printf("Would you like to edit more?(Y|N): ");
	if(getch()=='y'||getch()=='Y')
	goto flag_check;
	else
	mainmenu();
}

void teacherinfoedit()
{
	system("cls");
	FILE *fp;
	fp=fopen("Data_Teacher.dat","a+b");
//	if(fp==NULL)
//	{
//		fp=fopen("Data_Teacher.dat","w+b");
//		if(fp==NULL)
//		printf("file cannot not be created");
//		exit(0);
//	}
	char cont;
	do
	{
		printf("enter student's first name, last name, id, field\n");
		scanf("%s%s%d%s",aa.name,aa.lname,&aa.id,aa.fields);
		if(fwrite(&aa,sizeof(struct teach),1,fp)==1)
		printf("record has been sucessfully added\n");
		printf("do you want to enter more datas(Y\\N)?\n");
		fflush(stdin);
		cont=getchar();
		cont=tolower(cont);
	}while(cont=='y');
	fclose(fp);
	printf("enter m or M to go back to main menu\n");
	printf("_____________________________________\n");
	fflush(stdin);
	scanf("%c",&cont);
	printf("%c",cont);
	if(cont=='M' || cont =='m')
	{
			mainmenu();
	}
	
}

void studentinfoedit()
{
	/*
	FILE *fp;
	fp=fopen("this.dat",wb);
	rewind(fp);
	while((fread(&a,sizeof(a),1,fs)==1)// where a is a structure of the student
	whlie(fp != EOF)
	{
		printf("%",structure.attribute);
	}
	fclose(fp);
		
	*/
	
//	fp=fopen("C:\\Users\\user\\Documents\\KCC\\Project - 1st semester\\student management system\\Data_Student.dat","r+b");
//	if(fp==NULL)
//	{
//		fp=fopen("C:\\Users\\user\\Documents\\KCC\\Project - 1st semester\\student management system\\Data_Student.dat","w+b");
//		if(fp==NULL)
//		printf("file cannot not be created");
//		exit(0);
//	}
	system("cls");
	FILE *fp;
	fp=fopen("Data_Student.dat","a+b");
	char cont;
	do
	{
		printf("enter student's first name, last name, semester, id, field\n");
		scanf("%s%s%d%d%s",a.name,a.lname,&a.semester,&a.id,a.fields);
		if(fwrite(&a,sizeof(struct std),1,fp)==1)
		printf("record has been sucessfully added\n");
		printf("do you want to enter more datas(Y\\N)?\n");
		fflush(stdin);
		cont=getchar();
		cont=tolower(cont);
	}while(cont=='y');
	fclose(fp);
	printf("enter m or M to go back to main menu\n");
	printf("_____________________________________\n");
	fflush(stdin);
	scanf("%c",&cont);
	printf("%c",cont);
	if(cont=='M' || cont =='m')
	{
			mainmenu();
	}
	
//
//rewind(fp);
//
//while(fread(&a,sizeof(struct std),1,fp)==1)
//	{
//		printf("%s%s%d%d%s\n",a.name,a.lname,a.semester,a.id,a.fields);	
//	}
	
}

void routineedit()
{
	system("cls");
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT THE ONE THAT YOU WANT TO EDIT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. %s   ",categorie[0]);
	
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. %s",categorie[1]);

	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. %s",categorie[2]);

	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. %s ",categorie[3]);
	
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 3. %s",categorie[4]);

	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 4. %s ",categorie[5]);

	gotoxy(20,17);
	printf("Enter your choice:");

	switch(getch())
	{
		case '1':
			routineedit_comp();
			break;
		case '2':
			teacherinfoedit();
			break;
		case '3':
			routineinfo();
			break;
		case '4':
			examinfos();
			break;
	
	}
	
}


void examinfosedit()
{
	
	FILE *fp;
	char notice[500];
	fp=fopen("Notice.dat","a+b");
	printf("\nEnter what notice you would like to have on the notice board !!!!\n");
	fflush(stdin);
	gets(notice);
	fwrite(&notice,sizeof(notice),1,fp);
	fclose(fp);
	char a,cont;
	printf("do you want to enter again? (Y/N)");
	fflush(stdin);
	a=getchar();
	if(a=='y' || a=='Y')
	examinfosedit();
	
	else
	{
		printf("enter m or M to go back to main menu\n");
		printf("_____________________________________\n");
		fflush(stdin);
		scanf("%c",&cont);
		printf("%c",cont);
		if(cont=='M' || cont =='m')
		{
				mainmenu();
		}
		else
			exit(0);
	}
}

void studentinfo()
{
	/*
		add the following items
		search by field
		serach by semester
		search by name
		search by id 
		
		or view all the students
	*/
	
	system("cls");
	int d=0;
	printf("*****************************Search Students*********************************");
	gotoxy(20,6);
	printf("\xDB\xDB\xDB\xB2 1. Search By ID");
	gotoxy(20,8);
	printf("\xDB\xDB\xDB\xB2 2. Search By Name");
	gotoxy(20,10);
	printf("\xDB\xDB\xDB\xB2 3. Search By LName");
	gotoxy(20,12);
	printf("\xDB\xDB\xDB\xB2 4. Search By Field");
	gotoxy(20,14);
	printf("\xDB\xDB\xDB\xB2 5. Search By Semester");
	gotoxy(20,16);
	printf("\xDB\xDB\xDB\xB2 6. View all");
	gotoxy( 15,24);
	printf("Enter Your Choice");
	fp=fopen("Data_Student.dat","rb+"); //open file for reading propose
	rewind(fp);   //move pointer at the begining of file
	switch(getch())
	{
	case '1':
	{
	int d=0,j=5;
	system("cls");
	gotoxy(25,4);
	printf("****Search Student By Id****");
	gotoxy(20,5);
	printf("Enter the Student id:");
	scanf("%d",&d);
	gotoxy(20,7);
	printf("Searching........");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(a.id==d)
	{
		Sleep(2);
		system("cls");
		gotoxy(1,1);
		printf("*********************************Student List*****************************\n");
		gotoxy(2,2);
		printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER");
	
		gotoxy(3,j);
		printf("%s",a.name);
		gotoxy(16,j);
		printf("%s",a.lname);
		gotoxy(33,j);
		printf("%d",a.id);
		gotoxy(49,j);
		printf("%s",a.fields);
		gotoxy(64,j);
		printf("%d",a.semester);
		j++;
		j++;
		d++;
	}
	
	}
	
	if(d==0)
	{
	gotoxy(20,8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(22,9);printf("\aNo Record Found");
	}
	gotoxy(20,17);
	printf("Try another search?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	studentinfo();
	else
	mainmenu();
	break;
	
	
//	if(findstd!='t')  //checks whether conditiion enters inside loop or not
//	{
//	gotoxy(20,8);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
//	gotoxy(20,10);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	gotoxy(22,9);printf("\aNo Record Found");
//	}
//	gotoxy(20,17);
//	printf("Try another search?(Y/N)");
//	if(getch()=='y')
//	studentinfo();
//	else
//	mainmenu();
//	break;
	}
	
	
	
	case '2':
	{
	char s[15];
	system("cls");
	gotoxy(25,4);
	printf("****Search Student By Name****");
	gotoxy(20,5);
	printf("Enter Student Name:");
	scanf("%s",s);
	int d=0,j=5;
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
	{
//	gotoxy(20,7);
//	printf("The Student is available");
//	gotoxy(20,8);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	gotoxy(20,9);
//	printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
//	gotoxy(20,10);
//	printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
//	gotoxy(20,11);
//	printf("\xB2 LName:%s ",a.lname);gotoxy(47,11);printf("\xB2");
//	gotoxy(20,12);
//	printf("\xB2 Field:%s ",a.fields);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,13);
//	printf("\xB2 Semester:%d ",a.semester);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,14);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	d++;

		system("cls");
		gotoxy(1,1);
		printf("*********************************Student List*****************************\n");
		gotoxy(2,2);
		printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER");
	
		gotoxy(3,j);
		printf("%s",a.name);
		gotoxy(16,j);
		printf("%s",a.lname);
		gotoxy(33,j);
		printf("%d",a.id);
		gotoxy(49,j);
		printf("%s",a.fields);
		gotoxy(64,j);
		printf("%d",a.semester);
		j++;
		j++;
		d++;
	}
	
	}
	if(d==0)
	{
	gotoxy(20,8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(22,9);printf("\aNo Record Found");
	}
	gotoxy(20,17);
	printf("Try another search?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	studentinfo();
	else
	mainmenu();
	break;
	}
	
	case '3':
	{
	char s[15];
	system("cls");
	gotoxy(25,4);
	printf("****Search Student By LName****");
	gotoxy(20,5);
	printf("Enter Student LName:");
	scanf("%s",s);
	int d=0,j=5;
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(strcmp(a.lname,(s))==0) //checks whether a.name is equal to s or not
	{
//	gotoxy(20,7);
//	printf("The Student is available");
//	gotoxy(20,8);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	gotoxy(20,9);
//	printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
//	gotoxy(20,10);
//	printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
//	gotoxy(20,11);
//	printf("\xB2 LName:%s ",a.lname);gotoxy(47,11);printf("\xB2");
//	gotoxy(20,12);
//	printf("\xB2 Field:%s ",a.fields);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,13);
//	printf("\xB2 Semester:%d ",a.semester);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,14);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

		system("cls");
		gotoxy(1,1);
		printf("*********************************Student List*****************************\n");
		gotoxy(2,2);
		printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER");
	
		gotoxy(3,j);
		printf("%s",a.name);
		gotoxy(16,j);
		printf("%s",a.lname);
		gotoxy(33,j);
		printf("%d",a.id);
		gotoxy(49,j);
		printf("%s",a.fields);
		gotoxy(64,j);
		printf("%d",a.semester);
		j++;
		j++;
		d++;
	}
	
	}
	if(d==0)
	{
	gotoxy(20,8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(22,9);printf("\aNo Record Found");
	}
	gotoxy(20,17);
	printf("Try another search?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	studentinfo();
	else
	mainmenu();
	break;
	}
	
	case '4':
	{
	char s[15];
	system("cls");
	gotoxy(25,4);
	printf("****Search Student By Field****");
	gotoxy(20,5);
	printf("Enter Student Field:");
	scanf("%s",s);
	int d=0,j=5;
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(strcmp(a.fields,(s))==0) //checks whether a.name is equal to s or not
	{
//	gotoxy(20,7);
//	printf("The Student is available");
//	gotoxy(20,8);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	gotoxy(20,9);
//	printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
//	gotoxy(20,10);
//	printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
//	gotoxy(20,11);
//	printf("\xB2 LName:%s ",a.lname);gotoxy(47,11);printf("\xB2");
//	gotoxy(20,12);
//	printf("\xB2 Field:%s ",a.fields);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,13);
//	printf("\xB2 Semester:%d ",a.semester);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,14);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	d++;

		system("cls");
		gotoxy(1,1);
		printf("*********************************Student List*****************************\n");
		gotoxy(2,2);
		printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER");
	
		gotoxy(3,j);
		printf("%s",a.name);
		gotoxy(16,j);
		printf("%s",a.lname);
		gotoxy(33,j);
		printf("%d",a.id);
		gotoxy(49,j);
		printf("%s",a.fields);
		gotoxy(64,j);
		printf("%d",a.semester);
		j++;
		j++;
		d++;
	}
	
	}
	if(d==0)
	{
	gotoxy(20,8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(22,9);printf("\aNo Record Found");
	}
	gotoxy(20,17);
	printf("Try another search?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	studentinfo();
	else
	mainmenu();
	break;
	}
	
	case '5':
	{
	char s[15];
	int ss,j;
	system("cls");
	gotoxy(25,4);
	printf("****Search Student By Semester****");
	gotoxy(20,5);
	printf("Enter Student Semester:");
	scanf("%d",&ss);
	int d=0;
	j=4;
	system("cls");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(ss==a.semester) //checks whether a.name is equal to s or not
		{
//		gotoxy(20,7);
//	printf("The Students are available\n");
//	gotoxy(20,8);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//	gotoxy(20,9);
//	printf("\xB2 ID:%d\t",a.id);printf("\xB2 Name:%s\t",a.name);gotoxy(47,9);printf("\xB2 LName:%s\t",a.lname);printf("\xB2 Field:%s\t",a.fields);printf("\xB2 Semester:%d\t",a.semester);printf("\xB2");
//	printf("\n");
//	gotoxy(20,10);
//	printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
//	gotoxy(20,11);
//	printf("\xB2 LName:%s ",a.lname);gotoxy(47,11);printf("\xB2");
//	gotoxy(20,12);
//	printf("\xB2 Field:%s ",a.fields);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,13);
//	printf("\xB2 Semester:%d ",a.semester);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//	gotoxy(20,14);
//	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(1,1);
		printf("*********************************Student List*****************************\n");
		gotoxy(2,2);
		printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER");
	
		gotoxy(3,j);
		printf("%s",a.name);
		gotoxy(16,j);
		printf("%s",a.lname);
		gotoxy(33,j);
		printf("%d",a.id);
		gotoxy(49,j);
		printf("%s",a.fields);
		gotoxy(64,j);
		printf("%d",a.semester);
		j++;
		j++;
		d++;
		}
	
	}
	
	if(d>0)
	{
		printf("\n\n");
		printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	}
	if(d==0)
	{
	gotoxy(20,8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(22,9);printf("\aNo Record Found");
	}
	gotoxy(20,17);
	printf("Try another search?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	studentinfo();
	else
	mainmenu();
	break;
	}
	
	case '6':
	{
		int ss;
		system("cls");
//	gotoxy(25,4);
//	printf("****Whole student list****");
		int d=0,j=5;
		int x=20;
	
		
		while(fread(&a,sizeof(a),1,fp)==1)
			{
//		gotoxy(x,7);
//		printf("The Students available are: ");
//		gotoxy(x,8);
//		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//		gotoxy(x,9);
//		printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
//		gotoxy(x,10);
//		printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
//		gotoxy(x,11);
//		printf("\xB2 LName:%s ",a.lname);gotoxy(47,11);printf("\xB2");
//		gotoxy(x,12);
//		printf("\xB2 Field:%s ",a.fields);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//		gotoxy(x,13);
//		printf("\xB2 Semester:%d ",a.semester);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
//		
//		Sleep(300);
//		x=x+35;
//		d++;

			gotoxy(1,1);
			printf("*********************************Whole Student List*****************************\n");
			gotoxy(1,2);
			printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER");
			gotoxy(3,j);
			printf("%s",a.name);
			gotoxy(16,j);
			printf("%s",a.lname);
			gotoxy(33,j);
			printf("%d",a.id);
			gotoxy(49,j);
			printf("%s",a.fields);
			gotoxy(64,j);
			printf("%d",a.semester);
			j++;
			j++;
			d++;
			}
	
		if(d>0)
		{
			printf("\n\n");
			printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

		}
		
		if(d==0)
		{
		gotoxy(20,8);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
		gotoxy(20,10);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(22,9);printf("\aNo Record Found");
		}
		gotoxy(20,j+11);
		printf("Try another search?(Y/N)");
		if(getch()=='y' || getch()=='Y')
			studentinfo();
		else
			mainmenu();
		break;
		
	}
//	printf("\n");
//	while(d>=0)
//	{
//		gotoxy(d*10+10,15);
//		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//		d--;
//		Sleep(300);
//	}

	
	default :
	getch();
	studentinfo();
	}
	fclose(fp);
}

void teacherinfo(){
	
	/*
		add the following items
		search by class 
		search by field
		serach by semester
		search by name
		search by id 
		
		or view all the teacher
	*/
	
	char a[200];
	FILE *fp;
		
	int i=0,j;
	system("cls");
	gotoxy(1,1);
	printf("*********************************Teacher List*****************************");
	gotoxy(2,2);
	printf(" NAME\t\tLNAME\t\tID\t\tFIELD");
	j=4;
	fp=fopen("Data_Teacher.dat","rb");
	while(fread(&aa,sizeof(aa),1,fp)==1)
	{
		/* 		scanf("%s%s%d%s",aa.name,aa.lname,&aa.id,aa.fields); */
		gotoxy(3,j);
		printf("%s",aa.name);
		gotoxy(16,j);
		printf("%s",aa.lname);
		gotoxy(33,j);
		printf("%d",aa.id);
		gotoxy(49,j);
		printf("%s",aa.fields);
		printf("\n\n");
		j++;
	}
	fclose(fp);
	
	gotoxy(20,j+15);
	printf("Goto Main Menu?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	mainmenu();
	else
	exit(0);
}

void routineinfo(){
	/*
		AUTOMATIC RECOGNITION OF DAY OF THE WEEK 
		AND PRINT THE RESPECTIVE PERIODS OF THE RESPECTIVE DAY WITH TIME
	*/
	system("cls");
	time_t s;
	struct tm * cur_time;
	char * day; // THIS IS FOR PRINTING TODAYS DAY
	char * firp_t = "7:00 - 8:00" , * secp_t = "8:00 - 9:00", * thp_t = "9:00 - 9:30", * foup_t = "9:30 - 10:30", * fifp_t = "10:30 - 11:30", * sixp_t = "NONE"; // DECLARTION OF REGULAR PERIOD'S TIME OF CURRENT DAY
	s = time(NULL);
	cur_time = localtime(&s);
	switch(cur_time->tm_wday){
		case 0:
			day = "SUNDAY";
			isHoliday = true;
			break;
		case 1:
			sixp_flag = true;
			day = "MONDAY";
			strcpy(secp,"C PROGRAMMING - LAB");
			strcpy(thp,"C PROGRAMMING - LAB");
			thp_t = "9:00 - 10:00";
			foup_t = "10:00 - 10:30";
			strcpy(foup, "BREAK");
			strcpy(fifp, "TECHNICAL ENGLISH");
			sixp_t = "11:30 - 12:30";
			strcpy(sixp, "MODERN BUSINESS PRACTICE");
			break;
		case 2:
			day = "TUESDAY";
			strcpy(fifp, "TECHNICAL ENGLISH");
			break;	
		case 3:
			day = "WEDNESDAY";
			break;	
		case 4:
			day = "THRUSDAY";
			break;	
		case 5:
			day = "FRIDAY";
			foup, "TECHNICAL ENGLISH";
			fifp, "COMPUTER FUNDAMENTALS";
			break;	
		case 6:
			day = "SATURDAY";
			strcpy(firp, "CSC - LAB");
			strcpy(secp, "CSC - LAB");
			strcpy(foup,"TECHNICAL ENGLISH");
			break;	
	}
	if(isHoliday == true){
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 %s  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n",day);
		printf("\n");
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 HOLIDAY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	}else{
		printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ROUTINE FOR %s \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n",day);
		printf("|-----------------------------------------------------------------------------------------------------------------|\n");
		printf("|           TIME        |                                    PERIODS                                              |\n");
		printf("|-----------------------------------------------------------------------------------------------------------------|\n");
		printf("|\t%s\t|\t\t%s\t\t\n",firp_t,firp);
		printf("|\t%s\t|\t\t%s\t\t\n",secp_t,secp);
		printf("|\t%s\t|\t\t%s\t\t\n",thp_t,thp);
		printf("|\t%s\t|\t\t%s\t\t\n",foup_t,foup);
		printf("|\t%s\t|\t\t%s\t\t\n",fifp_t,fifp);
		if(sixp_flag == true){
			printf("|\t%s\t|\t\t%s\t\t\n",sixp_t,sixp);
			printf("|-----------------------------------------------------------------------------------------------------------------|\n");	
		}else{
			printf("|-----------------------------------------------------------------------------------------------------------------|\n");	
		}
	}	
}


void examinfos(){
	/*
		this show a list that basically updates the news and the latest update is kept at the top and this announcemnests are stored
		at the top i.e the newest is at the top 
	*/
	system("cls");
	char a[500];
//	FILE *fp;
//	fp=fopen("Notice.dat","rb");
//	rewind(fp);
//	while(fread(&a,sizeof(a),1,fp)==1)
//	{
//		printf("%s\n",a);
//	}
//	fclose(fp);

	FILE *fp;
	fp=fopen("Notice.dat","rb");
	fseek(fp,-500,2);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		printf("---------------------------------------------------\n");
		printf("%s\n",a);
		fseek(fp,-1000,1);
	
		printf("|||||||||||||||||||||||||||||||||||||||||||||||\n");
		if(ftell(fp)%500!=0)
		break;
	}
//
//	while (fread(&a,sizeof(a),1,fp)==1)
//	{
//		printf("%s\n",a);
//	}
	fclose(fp);
	
	printf("\n\n\n");
	printf("Goto Main Menu?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	mainmenu();
	else
	exit(0);
}

void deleteteach()
{

	int d=0;
	int id;
	char yes='y';
	char opt;
	while(yes=='y')
	{
		system("cls");
		printf("enter the id of the student that you want to delete\n");
		scanf("%d",&id);
		FILE *fp,*fp1;
		fp=fopen("Data_Teacher.dat","r+b");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(id==a.id)
			{
				d=1;
				printf("the required entry is \n id :%d\n name : %s\n",a.id,a.name);
				printf("do you want to delete this entry?(y/n)\n");
				if(getch()=='y'||getch()=='Y')
				{
					fp1=fopen("temp.dat","w+b");
					rewind(fp);
					while(fread(&a,sizeof(a),1,fp)==1)
					{
						if(id!=a.id)
							{
								fwrite(&a,sizeof(a),1,fp1);
							}
					}
				}
			}
		}
		if(d==1)
			printf("record sucessfully deleted \n");	
		if(d==0)
			printf("record not found \n");		
		d==0;
		fclose(fp1);
		fclose(fp);
		remove("Data_Teacher.dat");
		rename("temp.dat","Data_Teacher.dat");
		printf("do you want to delete another entry?(y/n)\n");
		scanf("%c",&yes);
		yes=tolower(yes);
	}
	mainmenu();
}

void deletestd()
{

	int d=0;
	int id;
	char yes='y';
	char opt;
	while(yes=='y')
	{
		system("cls");
		printf("enter the id of the student that you want to delete\n");
		scanf("%d",&id);
		FILE *fp,*fp1;
		fp=fopen("Data_Student.dat","r+b");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(id==a.id)
			{
				d=1;
				printf("the required entry is \n id :%d\n name : %s\n",a.id,a.name);
				printf("do you want to delete this entry?(y/n)\n");
				if(getch()=='y'||getch()=='Y')
				{
					fp1=fopen("temp.dat","w+b");
					rewind(fp);
					while(fread(&a,sizeof(a),1,fp)==1)
					{
						if(id!=a.id)
							{
								fwrite(&a,sizeof(a),1,fp1);
							}
					}
				}
			}
		}
		if(d==1)
			printf("record sucessfully deleted \n");	
		if(d==0)
			printf("record not found \n");		
		d==0;
		fclose(fp1);
		fclose(fp);
		remove("Data_Student.dat");
		rename("temp.dat","Data_Student.dat");
		printf("do you want to delete another entry?(y/n)\n");
		scanf("%c",&yes);
		yes=tolower(yes);
	}
	getch();
	mainmenu();
}

void edit() 
	{

	system("cls");
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT THE ONE THAT YOU WANT TO EDIT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Student info   ");
	
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Teacher info");

	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Routine ");

	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Exam ");
	
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Result ");
	
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Delete Student ");
	
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Delete Teacher ");
	
	

	gotoxy(20,22);
	printf("Enter your choice:");

	switch(getch())
	{
		case '1':
			studentinfoedit();
			break;
		case '2':
			teacherinfoedit();
			break;
		case '3':
			routineedit();
			break;
		case '4':
			examinfosedit();
			break;
		case '5':
			resultedit();
			break;
		case '6':
			deletestd();
			break;
		case '7':
			deleteteach();
			break;
			
	
	}

	}


void resultedit()
{
	struct std b;
	system("cls");
	int d=0,c=0;
	float gg;
	printf("*****************************Search Students*********************************");
	gotoxy(20,6);
	printf("\xDB\xDB\xDB\xB2 1. Search By ID");
	gotoxy(20,8);
	scanf("%d",&d);
	FILE *fp,*fp1;
	fp=fopen("Data_Student.dat","rb");
	fp1=fopen("Data_Student_Result.dat","a+b");
	rewind(fp1);
	long l;
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		printf("this is entering the while loop atleast\n");
		if(d==a.id)
		{
//			l=sizeof(a);
//			if(fseek(fp,-l,1)==0){
			printf("enter the gpa for the student\n");
			fflush(stdin);
			b=a;
			scanf("%f",&b.gpa);
			
//			printf("this is the value of the result : %f\n",a.gpa);
			if(fwrite(&b,sizeof(b),1,fp1)==1)
			printf("result sucessfully update!!!\n");
			else
			printf("error");
			c++;
			break;
			
			
		}
		
	}
	if(c==0)
		{
			printf("no such record found\n");
		}
	fclose(fp);
	fclose(fp1);
	gotoxy(20,17);
	printf("Edit another?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	resultedit();
	else
	mainmenu();
	
}

void result(){
	/* i guess something similar to the notice board or something that will publish 
		the result of the whole of semester students and so on*/
//	printf("hello world");

//	int i=0,j;
//	system("cls");
//	gotoxy(1,1);
//	printf("*********************************Student List*****************************");
//	gotoxy(2,2);
//	printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER\t\tGPA");
//	j=4;
//	FILE *fp;
//	fp=fopen("Data_Student.dat","a+b");
//	rewind(fp);
//	while(fread(&a,sizeof(a),1,fp)==1)
//		{
//		
//		gotoxy(3,j);
//		printf("%s",a.name);
//		gotoxy(16,j);
//		printf("%s",a.lname);
//		gotoxy(33,j);
//		printf("%d",a.id);
//		gotoxy(49,j);
//		printf("%s",a.fields);
//		gotoxy(62,j);
//		printf("%d",a.semester);
//		gotoxy(79,j);
//		printf("%f",a.gpa);
//		printf("\n\n");
//		j++;
//		j++;
//	}
//	fclose(fp);
//	
//	gotoxy(20,j+15);
//	printf("Goto Main Menu?(Y/N)");
//	if(getch()=='y' || getch()=='Y')
//	mainmenu();
//	else
//	exit(0);

	
		FILE *fp;
		fp=fopen("Data_Student_Result.dat","rb");
		int ss;
		system("cls");
		int d=0,j=5;
		int x=20;
	
		
		while(fread(&a,sizeof(a),1,fp)==1)
			{

			gotoxy(1,1);
			printf("*********************************Whole Student List*****************************\n");
			gotoxy(1,2);
			printf(" NAME\t\tLNAME\t\tID\t\tFIELD\t\tSEMESTER\t\tGPA");
			gotoxy(3,j);
			printf("%s",a.name);
			gotoxy(16,j);
			printf("%s",a.lname);
			gotoxy(33,j);
			printf("%d",a.id);
			gotoxy(49,j);
			printf("%s",a.fields);
			gotoxy(64,j);
			printf("%d",a.semester);
			gotoxy(79,j);
			printf("%f",a.gpa);
			j++;
			j++;
			d++;
			}
	fclose(fp);
	gotoxy(20,j+15);
	printf("Goto Main Menu?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	mainmenu();
	else
	exit(0);
}


void mainmenu()
{
	//loaderanim();
	system("cls");
	//    textbackground(13);
	int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Student info   ");
	
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Teacher info");
	
	gotoxy(20,9);
	
	printf("\xDB\xDB\xDB\xDB\xB2 3. Routine ");
	gotoxy(20,11);
	
	printf("\xDB\xDB\xDB\xDB\xB2 4. Notice ");
	gotoxy(20,13);
	
	printf("\xDB\xDB\xDB\xDB\xB2 5. Edit");
	gotoxy(20,15);
	
	printf("\xDB\xDB\xDB\xDB\xB2 6. Result");
	gotoxy(20,17);
	
	printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
	gotoxy(20,19);

	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,20);
	
	
	t();
	gotoxy(20,21);
	printf("Enter your choice:");
	switch(getch())
	{
		case '1':
			studentinfo();
			break;
		case '2':
			teacherinfo();
			break;
		case '3':
			routineinfo();
			break;
		case '4':
			examinfos();
			break;
		case '5':
			edit();
			break;
		case '6':
			result();
			break;
		case '7':
		{
			system("cls");
			gotoxy(35,3);
			
			printf("Student Management System");
			gotoxy(35,4);
			printf("Mini Project in C");
			gotoxy(35,5);
			printf("This brought to you by");
			gotoxy(35,7);
			printf("Milan Shrestha");
			gotoxy(35,9);
			printf("Bishal Subedi");
			gotoxy(35,10);
			printf("Benzene Lama");
			
			gotoxy(20,12);
			printf("******************************************");
			
			gotoxy(20,13);
			printf("*******************************************");
			
			gotoxy(20,14);
			printf("*******************************************");
			
			gotoxy(20,17);
			printf("********************************************");
			
			gotoxy(20,19);
			printf("Exiting in 3 second...........>\n\n\n");
			//flushall();
			Sleep(3000);
			exit(0);
		}
		default:
		{
			//gotoxy(10,23);
			printf("\aWrong Entry!!Please re-entered correct option");
			if(getch())
			mainmenu();
		}
	
	}
}
	
	
	
int t(void) //for time
{
	time_t t;
	time(&t);
	printf("Date and time:%s\n",ctime(&t));
	
	return 0 ;
}
	
void Password(void) //for password option
{
	
	system("cls");
	headMessage("Password");
	printf("\n");
	printf("\t\t\t\t");
	char d[25]="Password Protected";
	
	char ch,pass[10];
	int i=0,j;
	//textbackground(WHITE);
	//textcolor(RED);
	//gotoxy(10,4);
	for(j=0;j<20;j++)
	{
	Sleep(50);
	printf("*");
	}
	for(j=0;j<18;j++)
	{
	Sleep(50);
	printf("%c",d[j]);
	}
	for(j=0;j<20;j++)
	{
	Sleep(50);
	printf("*");
	}
	printf("\n");
	
	printf("\t\t\t\t");
	//gotoxy(10,10);
	//gotoxy(15,7);
	printf("Enter Password:");
	
	while(ch!=13)
	{
		ch=getch();
		
		if(ch!=13 && ch!=8)
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
	}
	pass[i] = '\0';
	if(strcmp(pass,password)==0)
	{
	
		//gotoxy(15,9);
		//textcolor(BLINK);
		printf("\n");
		
		printf("\t\t\t\t");
		printf("Password match");
		//gotoxy(17,10);
		printf("\n");
		
		printf("\t\t\t\t");
		printf("Press any key to continue.....");
		getch();
		mainmenu();
	}
	else
	{
		//gotoxy(15,16);
		
		printf("\n\t\t\t\t");
		printf("\aWarning!! Incorrect Password");
		getch();
		Password();
	}
}

