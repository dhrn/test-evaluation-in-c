
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>

 /************************************************************************/
 /*                                                                      */
 /*              	     Mouse Related Functions                     */
 /*                                                                      */
 /************************************************************************/

void init_mouse()
{
	union REGS iregs, oregs;

	iregs.x.ax = 0;
	int86 (0x33, &iregs, &oregs);

	if (oregs.x.ax == 0)
	{
		cleardevice();
		printf("mouse not installed\n");
		getch();
		exit(1);
	}
       iregs.x.ax = 1;
       int86 (0x33, &iregs ,&oregs);
}
/*************************************************************/

void mouse()
{
	int button,x1,y1;
	union REGS iregs, oregs;

	iregs.x.ax = 3;
	int86 (0x33, &iregs ,&oregs);

	button = oregs.x.bx & 3;
	x1 = oregs.x.cx;
	y1 = oregs.x.dx;

	if(oregs.x.bx & 1)
	{
		X = x1 ; Y = y1;
	}

	if(button == 3)
		exit(0);
}



/*************************************************************/

void hide_mouse()
{
	union REGS ioRegs;
	ioRegs.x.ax=2;
	int86(0x33,&ioRegs,&ioRegs);
}



/*************************************************************/
void show_mouse()
{
	union REGS ioRegs;
	ioRegs.x.ax=1;
	int86(0x33,&ioRegs,&ioRegs);
}

/*************************************************************/
void remove_mouse()
{
	union REGS ioRegs;
	ioRegs.x.ax=0;
	int86(0x33,&ioRegs,&ioRegs);
}

//Way to use the mouse (clicked)

char input()
	  {
	  X=0;Y=0;
	  char ch;
	  show_mouse();
	  do
	  {
	  mouse();
	  if (X>=350 && X<=380 && Y>=205 && Y<=225) // Condition For 7
	  {
		//Clicked on the specified area
	  }


	//**********************************************

	 if (X>=390 && X<=420 && Y>=205 && Y<=225) // Condition For 8
	 {
		//Clicked on the specified area
	 }



	}while(kbhit() == 0);
	
		
	}
