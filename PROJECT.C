#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
int i,j,x,y,x1,y1,z1,m;
void f();
void fans();
void user();
void check();
void count();
void admin();
union REGS in,out;
void initmouse()
{
in.x.ax = 0;
int86(0X33,&in,&out);
if(out.x.ax==0)
{
printf("NOT INSTALLED MOUSE ");
exit();
}
in.x.ax=1;
int86(0x33,&in,&out);
}
void admin()
{
int gd=DETECT,gm,x1,y1,z1,a,b,c;
initgraph(&gd,&gm,"");
initmouse();
setcolor(15);
rectangle(0,0,x,y);
for(i=0;i<40;i++)
line(540,i+20+10+10,575,i+20+10+10);
for(i=0;i<10;i++)
circle(556,30,1+i);
outtextxy(100,30,"WELCOME TO ADMINISTRATOR ");
line(0,100,1000,100);
//rectangle(100,100,500,500);
setcolor(9);
for(i=0;i<50;i++)
line(120,120+i,180,120+i);
setcolor(15);
outtextxy(200,140,"CHANGE CLOCK ");
setcolor(5);
for(i=0;i<20;i++)
line(120-i,120+i,180-i,120+i);
setcolor(15);
for(i=0;i<50;i++)
line(120,190+i,180,190+i);
setcolor(15);
outtextxy(200,220,"USER NAME AND PASSWORD");
}
void admin1()
{ int i;
char ch[10]="welcome";
char a[30],p[30]="welcome",c;
closegraph();
clrscr();
printf("\n   \n     \n   enter your name  \n   enter your password :welcome  \n\n\n\n\n press  enter to contineau   ");
getch();
clrscr();
printf("enter your name ");
scanf("%s",&a);
printf("enter your password ");
for(i=0;i<7;i++)
{
c=getch();
p[i]=c;
printf("*");
}
printf("%s",p);
if((strcmp(p,ch))==0)
admin();
else
{
printf("enter correct password  ");
delay(5000);
exit(2);
getch();
}
}
void user1()
{ int i;
char ch[10]="wel";
char a[30],p[30]="wel",c;
closegraph();
clrscr();
printf("\n   \n     \n   enter your name  \n    enter your password :wel \n\n\n\n\n  press  enter to contineau   ");
getch();
clrscr();
printf("\n\n\nenter user n name ");
scanf("%s",&a);
printf("\n\n\nenter your password ");
for(i=0;i<3;i++)
{
c=getch();
p[i]=c;
printf("*");
}
printf("%s",p);
if((strcmp(p,ch))==0)
user();
else
printf("enter correct password  ");
getch();
}

void user()
{
int gd=DETECT,gm,x1,y1,z1,a,b,c;
initgraph(&gd,&gm,"");
initmouse();
cleardevice();
setcolor(2);
rectangle(0,0,x,y);
for(i=0;i<40;i++)
line(540,i+20+10+10,575,i+20+10+10);
for(i=0;i<10;i++)
circle(556,30,1+i);
outtextxy(100,30,"welcome to write test ");
line(0,100,1000,100);
rectangle(100,100,500,500);
setcolor(9);
for(i=0;i<50;i++)
line(120,120+i,180,120+i);
outtextxy(200,140,"GENERAL");
setcolor(5);
for(i=0;i<20;i++)
line(120-i,120+i,180-i,120+i);
for(i=0;i<50;i++)
line(120,190+i,180,190+i);
outtextxy(200,220,"C");
setcolor(3);
for(i=0;i<20;i++)
line(120-i,190+i,180-i,190+i);
setcolor(8);
for(i=0;i<50;i++)
line(120,250+i,180,250+i);
//setcolor();
outtextxy(200,270,"DATASTRUCTURE ");
setcolor(9);
for(i=0;i<20;i++)
line(120-i,250+i,180-i,250+i);
do
{
in.x.ax=3;
int86(0x33,&in,&out);
x1=out.x.cx;
y1=out.x.dx;
z1=out.x.bx;
setcolor(15);
setbkcolor(BLACK);
if(x1<300&&x1>200&&y1>133&&y1<148&&z1==1)
{
cleardevice();
setbkcolor(BLACK);
closegraph();
f();
getch();
}
}while(kbhit()==0);
}

void f()
{
//closegraph();
int z,m;
FILE *f;
char ch;
closegraph();
clrscr();
printf(" \n\n\n\n1.first read all question in given 15 secs  \n2.type all answer after screen is hidden \n press enter to next  ");
getch();
clrscr();
f=fopen("tt.txt","r+");
clrscr();
if(f==0)
printf("unable to open");
do
{
ch=fgetc(f);
putch(ch);
}while(ch!=EOF);
fclose(f);
//getch();
//printf(" \n1.first read all question in given 15 secs  \n2.type all answer after screen is hidden \n press enter to next  ");
//getch();
count();
check();
clrscr();
printf("if u want to see the ans press 1 exit for any press ");
scanf("%d",&m);
printf("%d",m);
//if(m==0)
//m=1;
//if(m==1)
getch();
fans();
//printf("\n do you want to contineau press 2 or for exit 4");
//scanf("%d",&m);
//if(m==2)
clrscr();
printf("press enter to home  \n ");
//user();
getch();
user();
}
void count()
{
int i,j;
for(i=15;i>0;i--)
{
if(i<=15)
printf("\r secs left:%d ",i);
delay(1000);
}
}
void fans()
{
FILE *f1;
char ch;
clrscr();
f1=fopen("ttans.txt","r+");
if(f1==0)
printf("unable to open");
do
{
ch=fgetc(f1);
putch(ch);
}while(ch!=EOF);
fclose(f1);
getch();
}
void check()
{
int i,j;
char x[30];
char a[30]="daaa";
int flag,b;
float mark;
i=0;j=0,flag=0;
clrscr();
printf("\t Enter ans :   \t");
for(i=0;i<4;i++)
scanf("%c",&x[i]);
for(j=0;j<4;j++)
{
char c,v;
v=a[j];
c=x[j];
if(!strcmp(v,c))
++flag;
}
closegraph();
printf("\n\n\nyour score is : %d ",flag);
//mark=(4/flag)*100;
//printf("\n\n\nyour percentage is :  %d %  ",mark);
getch();
}

void main()
{
int gd=DETECT,gm,x1,y1,z1,a,b,c;
initgraph(&gd,&gm,"");
initmouse();
x=getmaxx();
y=getmaxy();
rectangle(0,0,x,y);
setbkcolor(BLUE);
settextstyle(0, HORIZ_DIR, 2);
outtextxy(150,20,"welcome to online test ");
setcolor(10);
for(i=0;i<60;i++)
line(150,100+i+20,200,100+i+20);
for(i=0;i<20;i++)
circle(174,100,1+i);
setcolor(5);
for(i=0;i<60;i++)
line(150,100+i+20+100+20,200,100+i+20+100+20);
for(i=0;i<20;i++)
circle(175,220,1+i);
settextstyle(0, HORIZ_DIR,2);
setcolor(10);
outtextxy(220,130,"Admin ");
setcolor(5);
outtextxy(220,250,"user ");
setbkcolor(BLACK);
setbkcolor(BLACK);
setcolor(15);
do
{
in.x.ax=3;
int86(0x33,&in,&out);
z1=out.x.bx;
x1=out.x.cx;
y1=out.x.dx;
//printf("%d%d",x1,y1);
if(x1<300&&x1>200&&y1>133&&y1<150&&z1==1)
{
cleardevice();
//setcolor(0);
admin1();
}
if(x1<270&&x1>220&&y1>255&&y1<257&&z1==1)
{
setcolor(0);
settextstyle(1, HORIZ_DIR,2);
user1();
}
}while(kbhit()==0);
//check();    */
//zzzzf();
//user();
//count();
getch();
}