#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<process.h>
//#include<dos.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define WHITE "\033[37m"
#define BLUE "\033[34m"

char puzzle0[9][9]= 	       {' ',' ',' ',	'2','6',' ',	'7',' ','1',
				'6','8',' ',	' ','7',' ',	' ','9',' ',
				'1','9',' ',	' ',' ','4',	'5',' ',' ',

				'8','2',' ',	'1',' ',' ',	' ','4',' ',
				' ',' ','4',	'6',' ','2',	'9',' ',' ',
				' ','5',' ',	' ',' ','3',	' ','2','8',
				' ',' ','9',	'3',' ',' ',	' ','7','4',
				' ','4',' ',	' ','5',' ',	' ','3','6',
				'7',' ','3',	' ','1','8',	' ',' ',' ',};

char puzzle1[9][9]= 	       {'1',' ',' ',	'4','8','9',	' ',' ','6',
				'7','3',' ',	' ',' ',' ',	' ','4',' ',
				' ',' ',' ',	' ',' ','1',	'2','9','5',

				' ',' ','7',	'1','2',' ',	'6',' ',' ',
				'5',' ',' ',	'7',' ','3',	' ',' ','8',
				' ',' ','6',	' ','9','5',	'7',' ',' ',

				'9','1','4',	'6',' ',' ',	' ',' ',' ',
				' ','2',' ',	' ',' ',' ',	' ','3','7',
				'8',' ',' ',	'5','1','2',	' ',' ','4',};

char puzzle2[9][9]= 	       {' ','2',' ',	'6',' ','8',	' ',' ',' ',
				'5','8',' ',	' ',' ','9',	'7',' ',' ',
				' ',' ',' ',	' ','4',' ',	' ',' ',' ',

				'3','7',' ',	' ',' ',' ',	'5',' ',' ',
				'6',' ',' ',	' ',' ',' ',	' ',' ','4',
				' ',' ','8',	' ',' ',' ',	' ','1','3',

				' ',' ',' ',	' ','2',' ',	' ',' ',' ',
				' ',' ','9',	'8',' ',' ',	' ','3','6',
				' ',' ',' ',	'3',' ','6',	' ','9',' ',};

char puzzle3[9][9]= 	       {'5','3',' ',	' ','7',' ',	' ',' ',' ',
				'6',' ',' ',	'1','9','5',	' ',' ',' ',
				' ','9','8',	' ',' ',' ',	' ','6','7',

				'8',' ',' ',	' ','6',' ',	' ',' ','3',
				'4',' ',' ',	'8',' ','3',	' ',' ','1',
				'7',' ',' ',	' ','2',' ',	' ',' ','6',

				' ','6',' ',	' ',' ',' ',	'2','8',' ',
				' ',' ',' ',	'4','1','9',	' ',' ','5',

				' ',' ',' ',	'2','8',' ',	' ','7','9',};

char puzzle4[9][9]= 	       {'9',' ','2',	' ',' ',' ',	' ','5','3',
				' ','8',' ',	' ',' ','2',	' ',' ',' ',
				' ',' ',' ',	' ',' ','4',	' ',' ','7',

				'2','6','3',	' ','6',' ',	' ',' ','3',
				'4',' ',' ',	'8',' ','3',	' ',' ','1',
				'7',' ',' ',	' ','2',' ',	' ',' ','6',

				' ','6',' ',	' ',' ',' ',	'2','8',' ',
				' ',' ',' ',	'4','1','9',	' ',' ','5',

				' ',' ',' ',	'2','8',' ',	' ','7','9',};





int x=1,y=1;
int o=107,p=59,q=132.88,r=85.88;
char puzzle[9][9];
char puzzletemp[9][9];
void graphics();
void display();
void up();
void down();
void left();
void right();
int column(char,int);
int row(char,int);
int box(char,int,int);


void edit();
int count=1,count2=1,state=1,co;
void secondmenu();
void graphics1();
void up1();
void down1();
void menu();
void temp();
void reset();
void random();


void about()
{ clrscr();
cleardevice();
		      printf(GREEN);
char s[2000];
ifstream fin;
fin.open("about.txt");
fin.read(s,2000);
cout<<s;
fin.close();
// rectangle(255,297,285,327);
  outtextxy(5,375,"Press    to exit");
  rectangle(75,378,120,410);

  outtextxy(77,379,"ESC");

}


void help()
{ clrscr();
cleardevice();
char s[2000];
printf(GREEN);
ifstream fin;
fin.open("help.txt");
fin.read(s,2000);
cout<<s;
fin.close();
gotoxy(30,18);
printf(RED "W");
//rectangle(510,262,540,292);
rectangle(220,262,250,292);
gotoxy(30,20);
printf(RED "S");
rectangle(220,297,250,327);
gotoxy(26,20);
printf(RED "A");
 rectangle(185,297,215,327);
 gotoxy(34,20);
 printf(RED "D");
  rectangle(255,297,285,327);
  outtextxy(5,375,"Press    to exit");
  rectangle(75,378,120,410);

  outtextxy(77,379,"ESC");

}

void random()
{ int k;
g:
ofstream value;
value.open("value.txt");
srand(time(NULL));
int g=rand()%10;
 if(g<=4)
 {
 k=g;
value<<k;
}
else
{
goto g;
}
value.close();
}

void temp()
{
ifstream value;
value.open("value.txt");
int k;
value>>k;
		 //initial display
int i,j;
for(i=0;i<=8;i++)
	{
	for(j=0;j<=8;j++)
	{
		if(k==0)
		{puzzle[i][j]=puzzle0[i][j];
		puzzletemp[i][j]=puzzle0[i][j];
		} //to keepthe initial puzzle and solving puzzle seperate
		else if(k==1)
		{puzzle[i][j]=puzzle1[i][j];
		puzzletemp[i][j]=puzzle1[i][j];
		}
		else if(k==2)
		{puzzle[i][j]=puzzle2[i][j];
		puzzletemp[i][j]=puzzle2[i][j];
		}
		else if(k==3)
		{puzzle[i][j]=puzzle3[i][j];
		puzzletemp[i][j]=puzzle3[i][j];
		}
		else if(k==4)
		{puzzle[i][j]=puzzle4[i][j];
		puzzletemp[i][j]=puzzle4[i][j];
		}
	}
}
value.close();
 }

void reset()
{
ifstream value;
value.open("value.txt");
int k;
value>>k;
int i,j;
x=1,y=1;
for(i=0;i<=8;i++)
{
	for(j=0;j<=8;j++)

	{
	puzzle[i][j]=puzzletemp[i][j];
	}
}

clrscr();
cleardevice();
display();
edit();
value.close();
}

void display()
{
int i,j;
gotoxy(5,1);
printf("\n\n\t");
for(int c=0;c<=9;c++)        //for x cordnate only
{
	printf(WHITE "%d   ",c);     //shows x-cordinate
	if(c==0||c==3||c==6)
	{
		printf(" ");
	}
}
//printf(WHITE "\n---------------------------");
printf("\n\n\t");
for(i=0;i<=8;i++)
	{
	printf(WHITE "%d  ",i+1);    //y-cordinate
	for(j=0;j<=8;j++)
	{
		if(puzzletemp[i][j]==' ')
		{
			printf(RED "   %c",puzzle[i][j]);
		}
		else
		{
			printf(GREEN "   %c" ,puzzle[i][j]);
		}
	}
	printf("\n\n\t");
	}
graphics();
 }

void edit()
{
char store;
int choice,t,a,b,c,over=1;
     x:
	 gotoxy(58,5);
	printf(WHITE "Location is::(%d,%d)",x,y);

	store=getche();

	  //temporary charecter variable to check

	  if(store=='1'||store=='2'||store=='3'||store=='4'||store=='5'||store=='6'||store=='7'||store=='8'||store=='9'||store=='s'||store=='S'||store=='w'||store=='W'||store=='d'||store=='D'||store=='A'||store=='a'||store==27)
	{
	if(store=='s'||store=='S'||store=='w'||store=='W'||store=='d'||store=='D'||store=='A'||store=='a')
	co=co+1;
	   if(store=='w'||store=='W')
	   up();
	   else if(store=='d'||store=='D')
	   right();
	   else if(store=='A'||store=='a')
	   left();
	   else if(store=='s'||store=='S')
	   down();
	   else if(store==27)
	   {
	   clrscr();
	   cleardevice();
	   menu();
	   }
	    else if(puzzletemp[y-1][x-1]!=' ')
	   {
	   clrscr();
	   cleardevice();
	   gotoxy(58,5);
	   printf(RED "Invalid location");
	   display();
	   }
	   else
	   {


	a=row(store,y);     //receives check of row value
	b=column(store,x);   //receives column check
	c=box(store,x,y);
	if(a==1)
	{
		if(b==1)
		{
			if(c==1)
			{
			clrscr();
			cleardevice();
					gotoxy(58,5);
			printf(GREEN "Accepted");
			puzzle[y-1][x-1]=store;
			display();
			}
			else
			{
			clrscr();
			cleardevice();
			gotoxy(58,5);
			printf(RED "%d is in same box",store-48);
			display();
			}
		}
		else
		{
		clrscr();
		cleardevice();
		gotoxy(58,5);
				printf(RED "%d is in same column",store-48);
				display();
		}

	}
	else
	{        clrscr();
		 cleardevice();
		 gotoxy(58,5);
		 printf(RED "%d is in same row",store-48);
				  display();
	}
	}
for(int i=0;i<=8;i++)                    //gameover
{
	for(int j=0;j<=8;j++)
	{
		if(puzzle[i][j]==' ')
		{
			over=over*0;
		}
		else
		{
			over=over*1;
		}
	}
}
if(over==0)
{       gotoxy(58,7);
	printf(WHITE"1.Edit");
	gotoxy(58,8);
     printf(WHITE"2.Reset");
     gotoxy(58,9);
	printf(WHITE"3.Menu");
	gotoxy(58,10);
    printf(WHITE"Choice?>");

	scanf("%d",&choice);
	clrscr();
	cleardevice();
	display();
	if(choice==1)
	{
	clrscr();
	cleardevice();
	display();
		edit();  //recursive,again calls edit
		}
	else if(choice==2)
	 {
	      reset();
    }
	else
	{
	gotoxy(55,5);

	printf(WHITE"Press ENTER for Exit!");

       getch();

	cleardevice();
	fflush(stdin);
		menu();
		}
}
else
{
clrscr();
cleardevice();
gotoxy(58,5);
printf("YOU WON THE GAME!!");
}
 }
 else
 {
 clrscr();
 cleardevice();
 gotoxy(58,5);
 printf("Invalid entry!");
 display();
 goto x;
 }
 }
	// for start menu
void menu()
{

int key;
char t;
 graphics1();

while(1)
{
if(kbhit())
{            key=getch();
switch(key)
{

case(72):
up1();
break;

case(80):
down1();
break;

case(77):

if(count==1)
{
if(state==2)
{
if(count2==1) //new game
{
o=107;
p=59;
q=132.88;
r=85.88;
state=1;
x=1;
y=1;
clrscr();
cleardevice();
random();
temp();
display();

edit();

     //here call function new game for count2=1 or restart for count2=2
}
if(count2==2)           //resume
{
state=1;
clrscr();
cleardevice();
display();

edit();
}
}
if(state==1)
{
state=2;    //for second menu
   // setfillstyle(1,3);

secondmenu();
}
}
if(count==5)
exit(0);
if(count==3)
{
clrscr();
cleardevice();
about();
dd:
t=getche();
if(t==27)
menu();
else
goto dd;
}
if(count==4)
{
clrscr();
cleardevice();

help();
ee:
t=getche();
if(t==27)
menu();
else
goto ee;
}

if(count==2)
{
clrscr();
cleardevice();

printf("Time elaplsed:%f secs",clock()/CLOCKS_PER_SEC);
 printf("\nNo. of movements:%d",co);
 printf("\npress esc to exit");
ff:
 t=getche();

 if(t==27)
 menu();
 else
 goto ff;
 }
break;

case(13):

if(count==1)
{
if(state==2)
{
if(count2==1) //new game
{
state=1;
x=1;
y=1;
clrscr();
cleardevice();
random();
temp();
display();

edit();     //here call function new game for count2=1 or restart for count2=2
}
if(count2==2)           //resume
{
state=1;
clrscr();
cleardevice();
display();

edit();
}
}
if(state==1)
{
state=2;    //for second menu
secondmenu();
}
}
if(count==5)
exit(0);
if(count==3)
{
clrscr();
cleardevice();
about();
bb:
t=getche();
if(t==27)
menu();
else
goto bb;
}
if(count==4)
{
clrscr();
cleardevice();
help();
cc:
t=getche();
if(t==27)
menu();
else
goto cc;
}

if(count==2)
{
clrscr();
cleardevice();
printf("Time elaplsed:%f secs",clock()/CLOCKS_PER_SEC);
 printf("\nNo. of movements:%d",co);
 printf("\npress esc to exit");
 aa:
 t=getche();
 printf("\t%d",t);
 if(t==27)
 menu();
 else
 goto aa;
 }


break;


case(75):
if(state==2)    //state 1 for main menu and state 2 ffor second menu
{
state=1;//if state=1 second menu

    setfillstyle(9,1);   // to delete/paint second menu for state 1
    bar(380,85,540,135);
    bar(380,145,540,195);
    }
break;

case(32):
exit(0);
}
}
}
}

void secondmenu()
{
if(count==1)
{
if(count2==1&&state==2)
setfillstyle(9,4);
else
setfillstyle(1,3);

bar(380,85,540,135);
settextstyle(8,HORIZ_DIR,3);
outtextxy(400,90,"PLAY");
if(count2==2&&state==2)
setfillstyle(9,4);
else
setfillstyle(1,3);
bar(380,145,540,195);
outtextxy(400,150,"RESUME");

			    }

}

void down1()
{
if(state==2)              //for state 2
 {
	if(count2>=2)
	{
		count2=1;
		secondmenu();
	}
	else
	{
		count2=count2+1;
		secondmenu();
	}
 }
else                                  //for state 1
 {
	if(count>=5)
	{
		count=1;
		graphics1();
	}
	else
	{
		count=count+1;
		//cleardevice();
		graphics1();
	}
 }
}

void up1()
{
 if(state==2)                    //for state 2
 {
	if(count2==1)
	{
		count2=2;
		secondmenu();
	}
	else
	{
	count2=count2-1;
	secondmenu();
	}
	}

else                             //for state 1
 {
	if(count==1)
	{
		count=5;
		graphics1();
	}
	else
	{
		count=count-1;
		//cleardevice();
		graphics1();
	}
 }
}

void graphics1()
{
char ch;
setfillstyle(9,1);
floodfill(215,160,1);
if(state==1)
 {
if(count==1)
{
setfillstyle(9,4);
}
else
setfillstyle(1,3);
bar(190,105,370,155);
settextstyle(8,HORIZ_DIR,3);
outtextxy(210,110,"START-->");
if(count==2)
{
setfillstyle(9,4);
}
else
setfillstyle(1,3);
bar(190,165,370,215);
outtextxy(210,170,"HIGHSCORE");
if(count==3)
{
setfillstyle(9,4);
}
else
setfillstyle(1,3);
bar(190,225,370,275);
outtextxy(210,230,"ABOUT");

if(count==4)
{
setfillstyle(9,4);
}
else

setfillstyle(1,3);
bar(190,285,370,335);
outtextxy(210,290,"HELP<?>");
if(count==5)
{
//printf("5th");
setfillstyle(9,4);
}
else
setfillstyle(1,3);
bar(190,345,370,395);
outtextxy(210,350,"EXIT");
}

 }
void graphics()
{
rectangle(o,p,q,r);
rectangle(104,57,381.92,334.92);
setcolor(1);
line(134.88,57,134.88,334.92);
line(165.76,57,165.76,334.92);
setcolor(7);
line(196.64,57,196.64,334.92);
	  setcolor(1);
line(227.52,57,227.52,334.92);
line(258.4,57,258.4,334.92);
setcolor(7);
line(289.28,57,289.28,334.92);
	    setcolor(1);
line(320.16,57,320.16,334.92);

line(351.04,57,351.04,334.92);

line(104,87.88,381.92,87.88);
line(104,118.76,381.92,118.76);
setcolor(7);
line(104,149.64,381.92,149.64);
setcolor(1);
line(104,180.52,381.92,180.52);
line(104,211.4,381.92,211.4);
setcolor(7);
line(104,242.28,381.92,242.28);
	    setcolor(1);
line(104,273.16,381.92,273.16);
line(104,304.04,381.92,304.04);
setcolor(7);
gotoxy(62,3);
{
printf(BLUE "Message box");
}
setcolor(2);
rectangle(420,57,getmaxx(),85);
rectangle(420,57,getmaxx(),200);
//line(420,202,getmaxx(),202);
setfillstyle(4,4);
bar(0,0,getmaxx(),5);
bar(0,0,5,getmaxy());
bar(0,getmaxy()-5,getmaxx(),getmaxy());
bar(getmaxx()-5,0,getmaxx(),getmaxy());
bar(415,0,420,getmaxy());
setcolor(2);
gotoxy(66,18);
printf(RED "W");
rectangle(510,262,540,292);
gotoxy(66,20);
printf(RED "S");
rectangle(510,297,540,327);
gotoxy(62,20);
printf(RED "A");
 rectangle(475,297,505,327);
 gotoxy(70,20);
 printf(RED "D");
  rectangle(545,297,575,327);
  gotoxy(58,23);
  printf(BLUE "GAMING CONTROLLER");
setcolor(15);

}
	    void up()
	    {
		//if(ch=='w'||ch=='W')
		//{
		   //case(32):
		   clrscr();
		   cleardevice();
		   if(y==1)
		   {
		   p=308.04;
		   r=332.92;
		   y=9;
		   cleardevice();
		   display();
		   edit();
		   }
		   else
		   {
		   p=p-30.88;
		   r=r-30.88;
		y=y-1;
		cleardevice();
		display();
		edit();
		}
		  }

		  void right()
		  {
		  clrscr();
		  cleardevice();

		   if(x==1)
		  {
		  o=136.88;
		  q=163.76;
		 }
		 else if(x==2)
		 {
		 o=167.76;
		 q=194.64;
		 }
		 else if(x==3)
		 {
		 o=198.64;
		 q=225.52;
		 }
		 else if(x==4)
		 {
		 o=229.52;
		 q=256.4;
		 }
		 else if(x==5)
		 {
		 o=260.4;
		 q=287.28;
		 }
		 else if(x==6)
		 {
		 o=291.28;
		 q=318.16;
		 }
		 else if(x==7)
		 {
		 o=322.16;
		 q=349.04;
		 }
		 else if(x==8)
		 {
		 o=352.04;
		 q=379.92;
		 }
		    else if(x==9)
		    {
		    o=106;
		    q=134.88;
		    }
		    if(x==9)
		    {
		    x=1;
		    clrscr();
		    cleardevice();

		    display();
		    edit();
		    }
		    else
		    {
		     x=x+1;

		     clrscr();
		    cleardevice();
		    display();
		    edit();
		    }
					  }
		  void left()
		  {
		  clrscr();
		  cleardevice();
		   if(x==3)
		  {
		  o=136.88;
		  q=163.76;
		 }
		 else if(x==4)
		 {
		 o=167.76;
		 q=194.64;
		 }
		 else if(x==5)
		 {
		 o=198.64;
		 q=225.52;
		 }
		 else if(x==6)
		 {
		 o=229.52;
		 q=256.4;
		 }
		 else if(x==7)
		 {
		 o=260.4;
		 q=287.28;
		 }
		 else if(x==8)
		 {
		 o=291.28;
		 q=318.16;
		 }
		 else if(x==9)
		 {
		 o=322.16;
		 q=349.04;
		 }
		 else if(x==1)
		 {
		 o=352.04;
		 q=379.92;
		 }
		    else if(x==2)
		    {
		    o=106;
		    q=132.88;
		    }

			if(x==1)
			{

			x=9;

			cleardevice();
			display();
			edit();

			}
			else
			{

		   x=x-1;
		   cleardevice();
		   display();
		   edit();
			 }
		  }

		  void down()
		  {
		  clrscr();
		  cleardevice();
		  if(y==1)
		  {
		  p=89.88;
		  r=116.76;
		  }
		  else if(y==2)
		  {
		  p=120.76;
		  r=147.64;
		  }
		  else if(y==3)
		  {
		  p=151.64;
		  r=178.52;
		  }
		  else if(y==4)
		  {
		  p=182.52;
		  r=209.4;
		  }
		  else if(y==5)
		  {
		  p=213.4;
		  r=240.28;
		  }
		  else if(y==6)
		  {
		  p=244.28;
		  r=271.16;
		  }
		  else if(y==7)
		  {
		  p=275.16;
		  r=302.04;
		  }
		  else if(y==8)
		  {
		  p=306.04;
		  r=332.92;
		  }
		  else if(y==9)
		  {
		  p=59;
		  r=85.88;
		  }
		   if(y==9)
		   {
		   y=1;
		   clrscr();
		   cleardevice();
		   display();
		   edit();
		   }
		   else
		   {

		  y=y+1;
		  clrscr();
		  cleardevice();
		  display();
		  edit();
		    }
  }
int row(char store,int y)
{
int r=1;
for(int i=0;i<=8;i++)
{
	if(store==puzzle[y-1][i]) //temporary value store to puzzle if nit repeated in row
	{
		r=r*0;
		//off/dont edit
	}
	else
	{
		r=r*1;//on,edit
	}
}
return(r);
}

int column(char store,int x)
{
int c=1,i;
for(i=0;i<=8;i++)
{
	if(store==puzzle[i][x-1])     //checks entered value with column
	{
		c=c*0;
	}
	else
	{
		c=c*1;
	}
}
return(c);  //if not repeated in column sends 1 else 0
}

int box(char store,int x,int y)
{
int bo=1;
if(x<=3)   //1st column of box


{
	if(y<=3)            //1st box
	{
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=2;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}

	else if(y>=4&&y<=6)          //4th box
	{
		for(int i=3;i<=5;i++)
		{
			for(int j=0;j<=2;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}
	else                                  //7th box
	{
		for(int i=6;i<=8;i++)
		{
			for(int j=0;j<=2;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}
}

else if(x>=4&&x<=6)   //2nd column of box
{
	if(y<=3)            //2nd box
	{
		for(int i=0;i<=2;i++)
		{
			for(int j=3;j<=5;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}
	else if(y>=4&&y<=6)          //5th box
	{
		for(int i=3;i<=5;i++)
		{
			for(int j=3;j<=5;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}
	else                                  //8th box
	{
		for(int i=6;i<=8;i++)
		{
			for(int j=3;j<=5;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}

	}
}

else  //3rd column of box
{
	if(y<=3)            //3RD box
	{
		for(int i=0;i<=2;i++)
		{
			for(int j=6;j<=8;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}

	else if(y>=4&&y<=6)          //6th box
	{
		for(int i=3;i<=5;i++)
		{
			for(int j=6;j<=8;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}
	else                                  //9th box
	{
		for(int i=6;i<=8;i++)
		{
			for(int j=6;j<=8;j++)
			{
				if(store==puzzle[i][j])
				{
					bo=bo*0;
				}

				else
				{
					bo=bo*1;
				}
			}
		}
	}
}
return(bo);
}

void main()
{

clrscr();
int gm,gd=DETECT;
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
setfillstyle(9,1);
floodfill(215,160,5);
settextstyle(5,HORIZ_DIR,6);
outtextxy(30,175,"WELCOME TO SUDOKU");
getch();
cleardevice();
menu();
getch();
}


