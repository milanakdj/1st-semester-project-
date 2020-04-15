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
	routineinfo();
	int n;
	char ch;
	flag_check:
	do{
		printf("Which Period would you like to change: ");
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
	fflush(stdin);
	ch = getchar();
	if(toupper(ch) == 'Y')
	goto flag_check;
}

void teacherinfoedit()
{
	system("cls");
	FILE *fp;
	fp=fopen("C:\\Users\\user\\Documents\\KCC\\Project - 1st semester\\student management system\\Data_Teacher.dat","r+b");
	if(fp==NULL)
	{
		fp=fopen("C:\\Users\\user\\Documents\\KCC\\Project - 1st semester\\student management system\\Data_Teacher.dat","w+b");
		if(fp==NULL)
		printf("file cannot not be created");
		exit(0);
	}
	char cont;
	do
	{
		printf("enter student's first name, last name, id, field\n");
		scanf("%s%s%d%s",aa.name,aa.lname,&aa.id,aa.fields);
		fwrite(&aa,sizeof(struct teach),1,fp);
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
	system("cls");
	FILE *fp;
	fp=fopen("C:\\Users\\user\\Documents\\KCC\\Project - 1st semester\\student management system\\Data_Student.dat","r+b");
	if(fp==NULL)
	{
		fp=fopen("C:\\Users\\user\\Documents\\KCC\\Project - 1st semester\\student management system\\Data_Student.dat","w+b");
		if(fp==NULL)
		printf("file cannot not be created");
		exit(0);
	}
	char cont;
	do
	{
		printf("enter student's first name, last name, semester, id, field\n");
		scanf("%s%s%d%d%s",a.name,a.lname,&a.semester,&a.id,a.fields);
		fwrite(&a,sizeof(struct std),1,fp);
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
	char notice[200];
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
	printf("hello world\n");
}

void teacherinfo(){
	printf("hello world");
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
	char a[200];
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
	fseek(fp,-200,2);
	fread(&a,sizeof(a),1,fp);
	do
	{
		printf("---------------------------------------------------\n");
		printf("%s\n",a);
		fseek(fp,-400,1);
		printf("|||||||||||||||||||||||||||||||||||||||||||||||\n");
	}while(fread(&a,sizeof(a),1,fp)==1);
	fclose(fp);
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
	
	}

	}
void result(){
	printf("hello world");
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
	
	printf("\xDB\xDB\xDB\xDB\xB2 4. Exam ");
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
			gotoxy(65,3);
			
			printf("Student Management System");
			gotoxy(65,4);
			printf("Mini Project in C");
			gotoxy(65,5);
			printf("This brought to you by");
			gotoxy(65,7);
			printf("Milan Shrestha");
			gotoxy(55,8);
			
			printf("******************************************");
			gotoxy(55,10);
			
			printf("*******************************************");
			gotoxy(55,11);
			
			printf("*******************************************");
			gotoxy(55,13);
			
			printf("********************************************");
			gotoxy(65,17);
			
			printf("Exiting in 3 second...........>");
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
//
//void issuerecord()  //display issued book's information
//{
//system("cls");
////gotoxy(10,8);
//printf("The Book has taken by Mr. %s",a.stname);
////gotoxy(10,9);
//printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
////gotoxy(10,10);
//printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
//}/}
