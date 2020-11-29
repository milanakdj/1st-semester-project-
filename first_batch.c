#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include<stdbool.h>

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
void mainmenu(void); // Main Menu
void studentinfo(void); // Getting data from existing student's records
void teacherinfo(void); // Getting data from existing teacher's records
void examinfos(); // Getting new notices
void routineinfo(void); // Getting routine for today's day
int t(void); // time function
void headMessage(char *message);
void welcomeMessage();
void Password();


void mainroutineedit(); // edit function for routine
void studentinfoedit(); // editing existing student's record
void teacherinfoedit(); // editing existing teacher's record
void examinfosedit(); // Adding new notices to the board
void resultedit(); // Edit the result of exiting student
void deleteteach(); // for deleting existing teacher's record
void deletestd(); // for deleting existing student's record

FILE *fp,*ft,*fs;

int s;
char password[20]={"fjfj"};



struct meroDate // Struct for date format
{
int mm,dd,yy;
};

struct std{ // initialize Structure for Student's informations
	int id;
	char name[40];
	char lname[40];
	char fields[40];
	int semester;
	float gpa;
}a;



struct teach{ // initialize Structure for teacher's informations
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
    printf("\n\t\t\t############      Student Assistance System Project in C       ############");
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
    printf("\n\t\t\t        =            Student Assistance             =");
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

void mainroutineedit(){ // For Editing the routine of certain Period
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

void teacherinfoedit() // For editing the data of existing teacher's record
{
	system("cls");
	FILE *fp;
	fp=fopen("Data_Teacher.dat","a+b");
	char cont;
	do
	{
		printf("Enter teacher's first name, last name, id, field\n");
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

void studentinfoedit() // For editing the data of existing student's record
{
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
}


void examinfosedit() // For Adding new notices for the Students
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

void studentinfo() // For Getting all the information of the students
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
	gotoxy(20,9); printf("\xB2");  gotoxy(38,9); printf("\xB2");
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
		int d=0,j=5;
		int x=20;
	
		
		while(fread(&a,sizeof(a),1,fp)==1)
			{
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
	default :
	getch();
	studentinfo();
	}
	fclose(fp);
}

void teacherinfo(){ // Get the records of Teachers
	
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
	fclose(fp);
	
	printf("\n\n\n");
	printf("Goto Main Menu?(Y/N)");
	if(getch()=='y' || getch()=='Y')
	mainmenu();
	else
	exit(0);
}

void deleteteach() // for deleting a record of certain teacher
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

void deletestd() // For deleting a record of certain student
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

void edit() // For Editing the data of existing records
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
			mainroutineedit();
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


void resultedit() // For editing the result of existing student
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

void result(){ // For displaying the result of the students
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


void mainmenu()  // For Main Menu after login success
{
	system("cls");
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
			
			printf("Student Assistance System");
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
			Sleep(3000);
			exit(0);
		}
		default:
		{
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
		printf("\n");
		
		printf("\t\t\t\t");
		printf("Password match");
		printf("\n");
		
		printf("\t\t\t\t");
		printf("Press any key to continue.....");
		getch();
		mainmenu();
	}
	else
	{		
		printf("\n\t\t\t\t");
		printf("\aWarning!! Incorrect Password");
		getch();
		Password();
	}
}

