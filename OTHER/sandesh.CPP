#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>

#define MAX	10
#define BegPos   105
#define AuxPos   305
#define EndPos   505
int k=1;
char dis[10];
int width;
typedef struct disc
	   {
		 char val1[MAX];
		 char top,pos;
		};

void time(int x);
void push(disc *tt,int x);
int pop(disc *tt);
void tower(int,disc *,disc *,disc *);
void draw_stack(disc *beg,disc *,disc *);
int  main(void)
{

   int gdriver = DETECT, gmode, errorcode;
   int i,x=2,a;
   disc beg,end,aux;
   clrscr();
   printf("\t\t=======================================================");
   printf("\n\t\t\t\t*****TOWER OF HANOI*****\n");
   printf("\t\t=======================================================\n");
   enter:

   printf("\n\t\t\t\tHow Many Disks[1-9]:-  ");
   scanf("%d",&x);
     /* initgraph(&gdriver, &gmode, "..\\BGI");
   errorcode = graphresult(); */

   if(x>9)
   { printf("\nThis program specifies atmost 9 disks.\nSo enter the disk from 1-9");
   goto enter;
   }
else

 {    initgraph(&gdriver, &gmode, "..\\BGI");
	  errorcode = graphresult();

   if (errorcode != grOk)
   {

	  printf("Graphics error: %s", grapherrormsg(errorcode));
	  printf("Press any key to halt:");

	  getch();
	  exit(1);
   }
	width=50/x;

	beg.top=end.top=aux.top=0;
	beg.pos=1;end.pos=3;aux.pos=2;

	for(i=0;i<x;i++)
		push(&beg,(x-i)+1);

	draw_stack(&beg,&end,&aux);
	tower(x,&beg,&end,&aux);
	x=pow(2,x)-1;
	sprintf(dis,"%d",x);
	outtextxy(100,400,"Minimum time required for completion of the solution ");
	outtextxy(100,420,dis);
	outtextxy(110,420,"seconds");
outtextxy(200,50,"Program terminates in 7 seconds");
	int j=0;
	for(k=1;k<=7;k++){
	 outtextxy(280+j,80,"* ");
	 j+=10;
	 delay(1000);
	}
	closegraph();

return 0;
   }
//   getch();
}
void tower(int n,disc *beg,disc *aux,disc *end)
{

	if(n>0 && n<9)
	{
		tower(n-1,beg,end,aux);
		push(end,pop(beg));
		draw_stack(beg,end,aux);
		tower(n-1,aux,beg,end);
	}
}
void push(disc *tt,int x)
{
	tt->val1[tt->top]=x;
	tt->top++;
}

pop(disc *tt)
{
	int a;
	tt->top--;
	a=tt->val1[tt->top];
	tt->val1[tt->top]=0;
	return a;
}

void draw_stack(disc *beg,disc *end,disc *aux)
{
	int ypos=295,i,height=10,xpos;
       int ver=0;
	cleardevice();

	setfillstyle(1,3);
	bar(20,300,580,310);

	bar(100,100,110,300);
	bar(300,100,310,300);
	bar(500,100,510,300);

	rectangle(20,300,580,310);

	rectangle(100,100,110,300);
	rectangle(300,100,310,300);
	rectangle(500,100,510,300);
	setfillstyle(1,2);
	outtextxy(100,315,"S");
	outtextxy(300,315,"D");
	outtextxy(500,315,"T");

	/* END TOWER*/
	ypos=295;
	if(end->pos==1)
		xpos=BegPos;
	else if(end->pos==2)
		xpos=AuxPos;
	else if(end->pos==3)
		xpos=EndPos;

	for(i=0;i<end->top;i++)
	{
		setfillstyle(4,end->val1[i]);

bar(xpos-(end->val1[i]*width),ypos,xpos+(end->val1[i]*width),ypos-height);

rectangle(xpos-(end->val1[i]*width),ypos,xpos+(end->val1[i]*width),ypos-height);
		ypos-=(height+2);
	}
	ver=end->pos;

	/* BEG TOWER*/
	if(beg->pos==1)
		xpos=BegPos;
	else if(beg->pos==2)
		xpos=AuxPos;
	else if(beg->pos==3)
		xpos=EndPos;

	ypos=295;
	for(i=0;i<beg->top;i++)
	{
		setfillstyle(beg->val1[i],beg->val1[i]);

bar(xpos-(beg->val1[i]*width),ypos,xpos+(beg->val1[i]*width),ypos-height);

rectangle(xpos-(beg->val1[i]*width),ypos,xpos+(beg->val1[i]*width),ypos-height);
		ypos-=(height+2);
	}

	/* AUX TOWER*/
	ver=ver*10+beg->pos;

	if(ver<20)
	{
		if(ver%10==2)
			xpos=EndPos;
		else
			xpos=AuxPos;
	}
	else if(ver<30)
	{
		if(ver%10==1)
			xpos=EndPos;
		else
			xpos=BegPos;
	}
	else if(ver<40)
	{
		if(ver%10==1)
			xpos=AuxPos;
		else
			xpos=BegPos;
	}

	ypos=295;
	for(i=0;i<aux->top;i++)
	{
		setfillstyle(aux->val1[i],aux->val1[i]);

bar(xpos-(aux->val1[i]*width),ypos,xpos+(aux->val1[i]*width),ypos-height);

rectangle(xpos-(aux->val1[i]*width),ypos,xpos+(aux->val1[i]*width),ypos-height);
		ypos-=(height+2);
	}


	getch();

}

void time(int n)
{
 char b[10];
 int a;
 outtextxy(20,50,"Required Time:");
 a=pow(2,n)-1;
 sprintf(b,"%d",a);
 outtextxy(35,50,b);

}