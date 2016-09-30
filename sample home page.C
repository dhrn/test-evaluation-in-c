#include<graphics.h>
#include<conio.h>
#include<dos.h>

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
}
int mouse()
{
union REGS in,out;
int x,y,z,x1,y1,l,flag;
in.x.ax=3;
int86(0X33,&in,&out);
x=out.x.cx;
y=out.x.dx;
z=out.x.bx;
x1=getmaxx();
y1=getmaxy();
rectangle(0,0,x1,y1);
do
{
in.x.ax=3;
int86(0X33,&in,&out);
x=out.x.cx;
y=out.x.dx;
z=out.x.bx;
rectangle(30,230,80,280);
outtextxy(30,200,"for mouse click");
rectangle(30,110,80,160);
outtextxy(35,80,"for color change ");
if(x>=30&&x>=80&&y<=230&&y<=280&&z==1)
flag=1;
if(x>=30&&x<=80&&y>=110&&y<=160&&z==2)
flag=2;
}while(kbhit()==0);
if(flag==1)
return 1;
return 0;
}

void mousechange()
{
union REGS in,out;
int i,x3,y3,z3,c3,x2,y2;

cleardevice();
outtextxy(20,20,"welcome come to mouse click ");
x2=getmaxx();
y2=getmaxy();
rectangle(0,0,x2,y2);
c3=5;
//setbkcolor(RED);
do
{
in.x.ax=3;
int86(0X33,&in,&out);
z3=out.x.bx;
x3=out.x.cx;
y3=out.x.dx;
if(z3==1)
{
--c3;
cleardevice();
outtextxy(20,20,"welcome come to mouse click ");
setcolor(c3);
rectangle(0,0,x2,y2);
outtextxy(x3+20,y3+20,"left click");
//cleardevice();
}
else if(z3==2)
{
c3+=2;
cleardevice();
outtextxy(20,20,"welcome come to mouse click ");
setcolor(c3);
rectangle(0,0,x2,y2);
outtextxy(x3+20,y3+20,"right click");
}
}while(kbhit()==0);
getch();
}
void click()
{
union REGS in,out;
int i,x3,y3,z3,c3,x2,y2;
cleardevice();
outtextxy(20,20,"welcome come to mouse click ");
x2=getmaxx();
y2=getmaxy();
rectangle(0,0,x2,y2);
c3=15;
//setbkcolor(RED);
do
{
in.x.ax=3;
int86(0X33,&in,&out);
z3=out.x.bx;
x3=out.x.cx;
y3=out.x.dx;
if(z3==1)
{
//--c3;
//cleardevice();
outtextxy(20,20,"welcome come to mouse click ");
setcolor(c3);
rectangle(0,0,x2,y2);
for(i=0;i<5;i++)
{
delay(400);
circle(x3,y3,1+i);
//cleardevice();
}
//cleardevice();
}
else if(z3==2)
{
c3+=2;
//
//outtextxy(20,20,"welcome come to mouse click ");
//setcolor(c3);
rectangle(0,0,x2,y2);
for(i=0;i<5;i++)
{
delay(400);
circle(x3,y3,1+i);
delay(400);
//
}
//cleardevice();
}
}while(kbhit()==0);
getch();
}

void colorchange()
{

int x,y,c,x1,y1,z,l;
x1=getmaxx();
y1=getmaxy();
c=7;
cleardevice();
outtextxy(20,20,"welcome to color change ");
rectangle(0,0,x1,y1);
do
{
++c;
in.x.ax=3;
int86(0X33,&in,&out);
z=out.x.bx;
setcolor(c);
if(z==1)
{
for(l=0;l<300;l++)
line(50,100+l,600,100+l);
}
if(c==1||c==15)
c=6;
}while(kbhit()==0);//key board hit
getch();
}

void showmouse()
{
in.x.ax = 1;
int86(0X33,&in,&out);
}
void main()
{
int gd=DETECT,gm,c;
initgraph(&gd,&gm,"");
initmouse();
showmouse();
//c=mouse();
//cannot merge these function mousechange and color change
//if(c==1)
//getch();


mousechange(); //mouse click
//else
colorchange();  //    change rectcolor
click();      //  click function
getch();
}
