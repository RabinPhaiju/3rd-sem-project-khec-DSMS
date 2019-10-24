#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<math.h>
#include<fstream.h>

void goup();
void godown();
void goright();
void goleft();
void gameover();
void start();
void mainscr();
void colorm(int );

void colorlevel(int );
void rect(int);
void level();
int speed=100;
int n=0,q=1,bcount;


int screenw=639;
int screenh=479;
int p,h,sc,m=0;
char a[20],a1[20];
int  x,y,ntail;
int prevx,prevy;
int tailx[500],taily[500];
int hs=0;

char z,ch;
int i;


 void file()
  {

     if(q==1)
       {  ifstream fin;
	 fin.open("Basic.txt");
	 fin>>hs;
	 fin.close();
       }
      else if(q==2)
       {
	 ifstream fin;
	 fin.open("Normal.txt");
	 fin>>hs;
	 fin.close();
       }
     else if(q==3)
       {
	  ifstream fin;
	  fin.open("Hard.txt");
	  fin>>hs;
	  fin.close();
       }
     else if(q==4)
       {
	ifstream fin;
	fin.open("Expert.txt");
	fin>>hs;
	fin.close();
      }

   if(sc>hs)
    {
      if(q==1)
	{
	  ofstream fout;
	  fout.open("Basic.txt");
	  fout<<sc;
	  fout.close();
	}
      else if(q==2)
	{
	  ofstream fout;
	  fout.open("Normal.txt");
	  fout<<sc;
	  fout.close();
	}
     else if(q==3)
	{
	  ofstream fout;
	  fout.open("Hard.txt");
	  fout<< sc;
	  fout.close();
	}
     else if(q==4)
	{
	 ofstream fout;
	 fout.open("Expert.txt");
	 fout<<sc;
	 fout.close();
	}
       setfillstyle(1,0);
       bar(600,300,630,325);

       sprintf(a1,"%d",sc);
       outtextxy(600,300,a1);

     }
   }
 void highsc() // function to print the high score in screen
  {
    int s1,s2,s3,s4;
    char s[20];
    cout<<endl<<endl<<endl;
    ifstream fin;
    fin.open("Basic.txt");
    fin>>s1;
    sprintf(s,"%d",s1);

     setfillstyle(10,1); //for backgoround
     bar(0,0,639,479);
     setcolor(4);
     settextstyle(1,0,4);
     outtextxy(200,80,"HIGH SCORE");
     setcolor(6);
     settextstyle(1,0,3);
     outtextxy(200,130,"Basic level :");
     outtextxy(370,130,s);
     fin.close();

    fin.open("Normal.txt");
    fin>>s2;
    sprintf(s,"%d",s2);
    outtextxy(200,160,"Normal level :");
    outtextxy(370,160,s);
    fin.close();

    fin.open("Hard.txt");
    fin>>s3;
    sprintf(s,"%d",s3);
    outtextxy(200,190,"Hard level :");
    outtextxy(370,190,s);
    fin.close();

    fin.open("Expert.txt");
    fin>>s4;
    sprintf(s,"%d",s4);
    outtextxy(200,220,"Expert level :");
    outtextxy(370,220,s);
    setcolor(7);
    outtextxy(150,400,"Press any key to go main menu");

    fin.close();

    getch();
    mainscr();

  }

 void gameover() // function for to restart the game after game over
 {

     while(1)
	{

	  setfillstyle(10,7);
	  bar(20,180,430,280);
	  settextstyle(0,0,3);
	  setcolor(2);
	  sound(600);
	  delay(200);
	  nosound();
	  outtextxy(40,200," RESTART GAME"); // display the choice for player
	  outtextxy(40,240,"YES(Y) or NO(N)");  //to restart the game
	  delay(200);
	  // setfillstyle(10,7);
	  // bar(20,200,430,280);
	 // file();
	     if(kbhit())
	       {
		  ch=getch();
		  if(ch==121 || ch==89)
		     {
		      start();      // restart the game
		      }
		  if(ch==110 || ch==78)
			{
			mainscr();   // open the main screen
			}

	       }
	 }

    }


 void score(int mode) // function for to calculate the score and print the score in screen


 { //clrscr();
   setcolor(BLACK);
   bar(555,250,580,290);
   setcolor(RED);
   if(mode==1)
     {
      sc = sc+5;
     }
   else if(mode==0)
      {
	  if(bcount<=20)
	    {
	    sc=sc+40;
	    }
	  else if(bcount<=40)
	    {
	     sc=sc+30;
	    }
	  else if(bcount<=60)
	    {
	     sc=sc+20;
	    }
	  else if(bcount<=80)
	     {
	     sc=sc+15;
	     }
	  else
	    {
	     sc=sc+10;
	    }

       }

   file();
  // if(sc>hs)
   sprintf(a," %d",sc); // store the score in char arry
   settextstyle(11,0,2);
   outtextxy(550,280,a);

  }
 void food_co(int mode) // for generat the food coordinate
 {
 //  int d;
   if(mode==1)// for food
      {
       p=(rand()%424+16);
       h=(rand()%387+16);
      }
    else if(mode==0)//
       {
	p=(rand()%410+23);
	h=(rand()%370+23);
	}
    //setcolor(BLUE);
    for(i=1;i<ntail-1;i++)
      {
	if(p== tailx[i] && h==taily[i])
	  {

	   food_co(mode);
	   }
     }
   }

 void eat_food(int mode)
   {
      char ch[20];
    if(mode==1)
       {
	  bcount=0;
	 if((pow((x-p),2)+pow((y-h),2))<=64) // condition for food

	    {
	      ntail++;  // it counts the tail of the snake body
	      setcolor(BLACK);
	      setfillstyle(SOLID_FILL,0);// change color
	      fillellipse(p,h,3,3);
	      // delay(10);
	      sound(400);
	      delay(50);
	      nosound();
	      score(1);  // call a function to caluclate the score
	      if(ntail%5==0)
		  {
		   food_co(0);// call a function to generate the food co ordinate
		  }
	       else
		  {
		   food_co(1);
		  }

	     }
       }

    if(mode==0 && bcount<100)
       {
	bcount++;
	    /* setfillstyle(1,0);
	     bar(240,420,290,430);
	     setcolor(4);
	     settextstyle(1,0,2);
	     sprintf(ch,"%d",bcount); //print the count of bonus time
	     outtextxy(245,430,ch);
	      delay(50);  */
	   if((pow((x-p),2)+pow((y-h),2))<=225) // condition for bonus

	    { ntail++;  // it counts the tail of the snake body
	      setcolor(BLACK);
	      setfillstyle(SOLID_FILL,0);// change color
	      fillellipse(p,h,10,10);
	      // delay(10);
	      sound(400);
	      delay(50);
	      nosound();
	      score(0);  // call a function to caluclate the score
	      food_co(1);// call a function to generate the food co ordinate

	     }
	   if(bcount==99)
	     {   ntail=ntail+1;
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,0);// change color
		fillellipse(p,h,10,10);

		food_co(1);
	      }

       }


   }


  void food_color(int mode) // change the color of the food in random order
  {

    setcolor(BLACK);
   // setfillstyle(SOLID_FILL,rand()%15+1);// change color
    if(mode==1)
      {
       setfillstyle(SOLID_FILL,rand()%15+1);// change color
       fillellipse(p,h,3,3);
      }
    else if(mode==0)
       {
	 setfillstyle(7,rand()%15+1);// change color
	 fillellipse(p,h,10,10);
       }

   }


  void snaketail() // store the co ordinate of snake tail
    {
      int prev2x,prev2y;
      prevx=tailx[0];
      prevy= taily[0];
      tailx[0]=x;
      taily[0]=y;


      for(int i=1;i<ntail;i++)
       {
	prev2x=tailx[i];
	prev2y=taily[i];
	tailx[i]=prevx;
	taily[i]=prevy;
	prevx=prev2x;
	prevy=prev2y;
	}

   }

  void snakehit() // function for to check the snake head hit or not to the body

    {
     for(int i=2;i<ntail;i++)
	{
	 if(tailx[i]== x && taily[i]==y)
	   {
	     gameover();
	     }
	     }
	     }




 void goup() // to move the snake up direction
  {
   for(i=0;i<40;i++)
      {
	 if(kbhit())
	 {  ch=getch();

	   if(ch==75)  //ascii value of left arrow key
	    {
	     goleft(); // call goleft function to move snake in left direction
	    }
	  else if(ch==77) // ascii value of right arrow key
	    {
	     goright();  // call function to move in right direction
	    }
	  else if(ch==32) //ascii value of 'space'
	    {
	    getch(); //stop the snake body

	   // continue;
	     }
	  else if(ch==27)  // ascii value of 'Esc'
	      {
	      exit(1);
	      }

	   }
      if(y<=21)   // condition for to check snake head hit the wall
	  {   gameover();

	  }
      snakehit(); // function call the snake head don't cut his body

      if(ntail%5==0)
	   {
	     food_color(0); //funcion call to change the color of the bonus
	   }
	 else
	   {
	    food_color(1); //function call to change the color of food
	   }

      if(ntail%5==0)
	   {
	    eat_food(0);
	   }
	 else
	   {
	    eat_food(1);
	   }

       y=y-10;  //move the snake coordinate in up direction



	 setfillstyle(1,4);  //rand()%15+1); // fill random color in snake body
	 fillellipse(x,y,5,5);

	 delay(speed);  //speed of snake

	snaketail(); // fucntion call for to store the coordinate of tail
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	fillellipse(tailx[ntail-1],taily[ntail-1],5,5);

       }
   }


void godown() // move snake in down direction
  {
     for(i=0;i<40;i++)
	{


	 if(kbhit())
	   {
	    ch=getch();

	  if(ch==75)
	      {
	       goleft();
	      }
	 else if(ch==77)
	      {
	       goright();
	      }
	 else if(ch==32)
	      {
	       getch();

	       continue;
	      }
	  else if(ch==27)
	       {
	       exit(1);
	       }
	}
      if(y>=416-20)
	 {  gameover();

	 }

	snakehit();
       //	food_color();
	 if(ntail%5==0)
	   {
	     food_color(0); //funcion call to change the color of the bonus
	   }
	  else
	   {
	    food_color(1); //function call to change the color of food
	   }


      if(ntail%5==0)
	 {
	  eat_food(0);
	 }
       else
	 {
	  eat_food(1);
	 }

       y=y+10;


	  setfillstyle(1, 4);//rand()%15+1);
	  fillellipse(x,y,5,5);
	  delay(speed);

	  snaketail();
	   setcolor(BLACK);
	  setfillstyle(1,BLACK);
	  fillellipse(tailx[ntail-1],taily[ntail-1],5,5);


     }

  }

 void goleft()
  {
     for(i=0;i<45;i++)
	{


	if(kbhit())
	  {
	     ch=getch();
	     if(ch==80)
		{
		 godown();
		}
	     else if(ch==72)
	       {
		goup();
	       }

	     else if(ch==32)
	       {

	       getch();
	       continue;
	       }
	    else if(ch==27)
		{
		exit(1);
		 }
	     }
	 if(x<=21)
	    {  gameover();

	     }
	   snakehit();
	 //  food_color();

	   if(ntail%5==0)
	     {
	     food_color(0); //funcion call to change the color of the bonus
	     }
	  else
	    {
	    food_color(1); //function call to change the color of food
	    }

	if(ntail%5==0)
	   {
	    eat_food(0);
	   }
	 else
	   {
	   eat_food(1);
	   }

	 x=x-10;
	setfillstyle(1,4); //rand()%15+1);
	fillellipse(x,y,5,5);
	delay(speed);
	snaketail();
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	fillellipse(tailx[ntail-1],taily[ntail-1],5,5);


      }

  }

 void goright()
   {
     for(i=0;i<45;i++)
	{


	if(kbhit())
	   {
	   ch=getch();
	    if(ch==80)
	      {
	       godown();
	      }

	    else if(ch==72)
	       {
	       goup();
	       }
	    else if(ch==32)
	      {
	      getch();

	      continue;
	      }
	    else if(ch==27)
	       {
		exit(1);
	       }
	}
      if(x>=456-21)
	  { gameover();

	  }
	snakehit();
       //	food_color();
	 if(ntail%5==0)
	   {
	     food_color(0); //funcion call to change the color of the bonus
	   }
	 else
	   {
	    food_color(1); //function call to change the color of food
	   }

      if(ntail%5==0)
	  {
	   eat_food(0);
	  }
	 else
	    {
	     eat_food(1);
	    }


	 x=x+10;

	 setfillstyle(1,4);//rand()%15+1);
	 fillellipse(x,y,5,5);
	 delay(speed);
	  snaketail();
	  setcolor(BLACK);
	 setfillstyle(1,BLACK);
	 fillellipse(tailx[ntail-1],taily[ntail-1],5,5);


      }
   }

void init()
{

   int gd=DETECT;
   int gm;
   initgraph(&gd,&gm,"..\\bgi");
   }

void logic()
{
   x=228,y=208;

while(1)
      { // setcolor(GREEN);
      //	rectangle(0,0,450,400);
       //	rectangle(4,4,446,396);
       //*********wall*********
	 setfillstyle(7,6);
	 bar(0,0,12,416);
	 bar(0,0,456,12);
	 bar(0,404,456,416);
	 bar(444,0,456,416);

       setcolor(GREEN);
       rectangle(0,0,screenw,screenh);
	ellipse(x,y,0,360,5,5);
	delay(50);
	setcolor(BLACK);
	ellipse(x,y,0,360,5,5);

     if(kbhit())
       {
       z=getch();
    switch(z)
       {
     case(72): // ascii

	 goup();
	 break;
     case(80):

	godown();
	break;
     case(75):

       goleft();
       break;
    case(77):

       goright();
       break;

    case(27):
	exit(1);
	break;

     }

     }
     }
     }
    void ins()   // TO PROVIDE INSTRUCTIONS AND SCORES
{

setcolor(GREEN);
line(456,416,639,416);

  setcolor(BLUE);
 // settextstyle(7,0,1);
  settextstyle(7,0,4);
  outtextxy(480,15,"Snake");
  outtextxy(510,55,"Game");
  setcolor(WHITE);
  settextstyle(11,0,2);
  outtextxy(480,140," CONTROLS ");
  outtextxy(480,160,"PAUSE = Space");
  outtextxy(480,180,"RESUME=any key");
  outtextxy(480,200,"EXIT=Esc");
  outtextxy(480,220,"ARROWS");
  outtextxy(480,240,"    -MOVEMENT");
  outtextxy(500,280,"SCORE-  ");
  outtextxy(500,300,"High Score -");
  setcolor(4);
  sprintf(a1,"%d",hs);
  outtextxy(600,300,a1);
  setcolor(WHITE);
  outtextxy(480, 330,"Press 'Esc'for exit");
  if(q==1)
     {
      setcolor(6);
      settextstyle(1,0,4);
      outtextxy(50,430,"Basic level");
     }
   if(q==2)
     {
      setcolor(6);
      settextstyle(1,0,4);
      outtextxy(50,430,"Normal level");
     }
   if(q==3)
     {
      setcolor(6);
      settextstyle(1,0,4);
      outtextxy(50,430,"Hard level");
     }
   if(q==4)
     {
      setcolor(6);
      settextstyle(1,0,4);
      outtextxy(50,430,"Expert level");
     }


}

void help()
{
   setfillstyle(10,1);
    bar(0,0,639,479);

   setcolor(2);
   settextstyle(4,0,5);
   outtextxy(180,20,"How To Play");
   setcolor(6);
   settextstyle(1,0,2);
   outtextxy(60,100,"The main goal of the game is to maneuver the snake ");
   outtextxy(20,130,"towards the fruit to eat it to increase the score .");
   setcolor(4);
   outtextxy(90,200, "Control");

   rectangle(100,270,160,300);
   rectangle(100,300,160,330);
   rectangle(40,300,100,330);
   rectangle(160,300,220,330);
   rectangle(99,269,159,299);
   rectangle(99,299,159,329);
   rectangle(39,299,99,329);
   rectangle(159,299,219,329);


   line(50,315,80,315);
   line(50,315,60,310);
   line(50,315,60,320);
   line(180,315,210,315);
   line(210,315,200,310);
   line(210,315,200,320);
   line(128,305,128,322);
   line(128,322,123,317);
   line(128,322,132,317);
   line(128,275,128,295);
   line(128,275,123,280);
   line(128,275,132,280);
   outtextxy(280,200,"Food of a snake :");
   setfillstyle(1,6);
   fillellipse(500,215,5,5);
   outtextxy(280,260,"Bonus :");
   setfillstyle(7,6);
   fillellipse(390,275,10,10);
   setcolor(WHITE);
   outtextxy(100,420,"Press any key  for main manu");
   getch();
   mainscr();

}

void start()
{// cleardevice();
  ntail=1;
  sc=0;

   init();
   file();
   ins();
   food_co(1);
   food_color(1);
   logic();

 }


 void mainscr()
{
   // clrscr();
     char ch;

     int x=getmaxx();
     int y=getmaxy();
     setfillstyle(10,1);
     bar(0,0,x,y);
     setcolor(2);
     settextstyle(1,0,5);
     outtextxy(200,100,"SNAKE GAME");



    while(1)
       {

	 char ch;
	 if(kbhit())
	    {

	      ch=getch();
	      if(ch==72)
		{
		   m=m-1;
		   if(m<0)
		      {
		       m=4;
		      }
		 }
	      if(ch==80)
		 {
		  m=m+1;
		  if(m>4)
		    {
		     m=0;
		    }
		  }
	     // if(ch==27)
		 // {
		 // exit(1);
		//  }
	   }

    if(m==0)
	{
	   colorm(m);
	   setcolor(RED);

	   outtextxy(275,170,"START");
	   if(ch==13)
	    {
	      cleardevice();
	      start();
	     // break;
	     }


	   }

       if(m==1)
	  {
	    colorm(m);
	    setcolor(RED);
	    outtextxy(275,200,"LEVEL");
	     if(ch==13)
		{
		 cleardevice();
		 level();
		 }

	   }

	if(m==2)
	   {
	     colorm(m);
	     setcolor(RED);
	     outtextxy(275,230,"HIGH SCORE");
	      if(ch==13)
	       {
		 cleardevice();
		 highsc();
		}
	    }

      if(m==3)
	    {
	      colorm(m);
	      setcolor(RED);
	      outtextxy(275,260,"HELP");
	       if(ch==13)
		{
		 cleardevice();
		 help();
		}

	     }


      if(m==4)
	    {
	      colorm(m);
	      setcolor(RED);
	      outtextxy(275,290,"EXIT");
	      if(ch==13)
		{
		 exit(1);
		 }
	       }

       }

    }

  void colorm(int x)
      {
	settextstyle(1,0,1);
	setcolor(10);
	if(x!=0)
	   {
	    outtextxy(275,170,"START");
	    }
	if(x!=1)
	   {
	     outtextxy(275,200,"LEVEL");
	    }
	 if(x!=2)
	     {
	      outtextxy(275,230,"HIGH SCORE");
	      }
	 if(x!=3)
	     {
	     outtextxy(275,260,"HELP");
	     }
	  if(x!=4)
	     {
	     outtextxy(275,290,"EXIT");
	     }

     }


void level()
{ //clrscr();

    char ch;

    int x=getmaxx();
    int y=getmaxy();
    setfillstyle(10,1);
    bar(0,0,x,y);
    setcolor(2);
    settextstyle(1,0,3);
    outtextxy(240,120," SELECT LEVEL");
    settextstyle(1,0,2);
    setcolor(5);
    outtextxy(90,400," Press 'Esc' for  main menu");
   //  colorm();




  while(1)
   {
      char ch;
      if(kbhit())
	 {
	   ch=getch();
	   if(ch==72)
	    {
	      n=n-1;
		if(n<0)
		 {
		  n=3;
		 }
	     }
	    if(ch==80)
	       {
	       n=n+1;
		if(n>3)
		 {
		  n=0;
		  }
	       }
	    if(ch==27)
	     {
	      cleardevice();
	      mainscr();
	      }
	  }

       if(n==0)
	{
	  colorlevel(n);
	 setcolor(RED);
	// settextstyle(1,0,1);
	 outtextxy(275,170,"BASIC");
	 if(ch==13)
	   {  q=1;
	     rect(q);
	     speed=100;
	     setcolor(4);
	     rectangle(270,170,340,195);
	    }


	 }

       if(n==1)
	{
	   colorlevel(n);
	   setcolor(RED);
	   outtextxy(275,200,"NORMAL");
	   if( ch==13)
	      {
		q=2;
		rect(q);
		speed=80;
		setcolor(4);
		rectangle(270,200,350,225);
	      }

	  }

       if(n==2)
	  {
	    colorlevel(n);
	    setcolor(RED);
	    outtextxy(275,230,"HARD");
	    if(ch==13)
	      {
		q=3;
		rect(q);
		speed=55;
		setcolor(4);
		rectangle(270,230,350,255);
	       }
	  }

      if(n==3)
	{ colorlevel(n);
	  setcolor(RED);
	  outtextxy(275,260,"EXPERT");
	    if(ch==13)
	       {
		q=4;
		rect(q);
		speed=30;
		setcolor(4);
		rectangle(270,260,355,285);
	       }

	 }

    }// end of while loop

}// end bracket of main function

void colorlevel(int x)
      {
	settextstyle(1,0,1);
	setcolor(10);
	if(x!=0)
	   {
	     outtextxy(275,170,"BASIC ");
	    }
	if(x!=1)
	   {
	     outtextxy(275,200,"NORMAL");
	    }
	if(x!=2)
	  {
	    outtextxy(275,230,"HARD");
	   }
	if(x!=3)
	  {
	    outtextxy(275,260,"EXPERT");
	   }


    }

void rect(int p)
     {
	    setcolor(0);
	   if(p!=1)
	       {
		rectangle(270,170,340,195);
	       }
	   if(p!=2)
	       {
		rectangle(270,200,350,225);
	       }

	   if(p!=3)
	       {
	       rectangle(270,230,350,255);
	       }

	   if(p!=4)
	      {
	       rectangle(270,260,355,285);
	      }
      }
 void main()
 {
   init();
   mainscr();

  }