#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
//#include<bios.h>

#define RETURNTIME 15

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void returnfunc(void);
void menu(void);
void studentinfo(void);
void teacherinfo(void);
void classinfo(void);
void routineinfo(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);

void Password();
void issuerecord();
void loaderanim();


FILE *fp,*ft,*fs;



int s;
//char studentinfo;
char password[20]={"notpassword"};



struct meroDate
{
int mm,dd,yy;
};

struct books
{
int id;
char stname[20];
char name[20];
char Author[20];
int quantity;
float Price;
int count;
int rackno;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};

struct books a;


int main()
{
Password();
getch();
return 0;

}


void studentinfo()
{
	printf("hello world");
}
void teacherinfo(){
	printf("hello world");
}
void routineinfo(){
	printf("hello world");
}
void examinfos()   {
	printf("hello world");
}
void attendance() {
	printf("hello world");
}
void result() 	{
	printf("hello world");
}



void mainmenu()
{
//loaderanim();
system("cls");
//    textbackground(13);
int i;
//gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

printf("\n");
//gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Student info   ");
printf("\n");

//gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Teacher info");
printf("\n");

//gotoxy(20,9);

printf("\xDB\xDB\xDB\xDB\xB2 3. Routine ");
//gotoxy(20,11);
printf("\n");

printf("\xDB\xDB\xDB\xDB\xB2 4. Exam ");
//gotoxy(20,13);
printf("\n");

printf("\xDB\xDB\xDB\xDB\xB2 5. Attendance");
//gotoxy(20,15);
printf("\n");

printf("\xDB\xDB\xDB\xDB\xB2 6. Result");
//gotoxy(20,17);
printf("\n");

printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
//gotoxy(20,19);
printf("\n");

printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//gotoxy(20,20);
printf("\n");

t();
//gotoxy(20,21);
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
attendance();
break;
case '6':
result();
break;
case '7':
{
system("cls");
//gotoxy(16,3);
printf("\n");

printf("Student Management System");
//gotoxy(16,4);
printf("\tMini Project in C");
//gotoxy(16,5);
printf("\t this brought to you by");
//gotoxy(16,7);
printf("\tMilan Shrestha");
//gotoxy(16,8);
printf("\n");

printf("******************************************");
//gotoxy(16,10);
printf("\n");

printf("*******************************************");
//gotoxy(16,11);
printf("\n");

printf("*******************************************");
//gotoxy(16,13);
printf("\n");

printf("********************************************");
//gotoxy(10,17);
printf("\n");

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
for(j=0;j<20;j++)
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

//gotoxy(10,10);
//gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
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

printf("Password match");
//gotoxy(17,10);
printf("\n");

printf("Press any key to continue.....");
getch();
mainmenu();
}
else
{
//gotoxy(15,16);
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
//}
