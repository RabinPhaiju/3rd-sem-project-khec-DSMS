#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

 struct record
 {
   long int sn,price,quantity;
   char goodname[20];
 };

 FILE *p;
 struct record r;

union REGS in, out;    //mouse ko lagi variables..
struct date today; // date ko lagi
char string[25];   // date ko lagi
int end=1,end1=1,end2=1,logincount=0,code1,code2;
int button,x,y,option,x_co,y_co,displaycount;
char name[20],password[20],pstring[20],filestring[30];
void login();
void callprogramend();
void displayforever();
void alwaysdisplay();
void calculatebill();
void additem();
void additem1();
void edititem();
void display();
void display1();
void search();
void deelete();
void exxit();

struct BACKGROUND  /// back ground ma blue color rakhna....
    {
      char Type[2];
      unsigned long Size,Reserved,OffSet,headsize,Width,Height,ColorsUsed;
      unsigned int  Planes,BitsPerPixel;
      unsigned long Compression,SizeImage,XPixelsPreMeter,YPixelsPreMeter,ColorsImportant;
    };

    int ShowBACKGROUND(int x, int y, char* FileName)
    {
	int b,a;
	struct  BACKGROUND Obj;

	unsigned char* Datas;
	int in=0;
	unsigned char c=0;
	FILE * fp;

	fp = fopen(FileName,"rb");
	fread(&Obj, sizeof(Obj), 1, fp);
	fseek(fp,Obj.OffSet,SEEK_SET);
	Datas=(unsigned char*) calloc(Obj.Width/2+1, sizeof(unsigned char));
	for(b=Obj.Height;b>=0;b--)
	{
	 fread(Datas, sizeof(unsigned char), Obj.Width/2, fp);
	 c=0; in=0;
	 for(a=0;a<=Obj.Width;a+=2)
	 {
	     c = (Datas[in] | 0x00) >>4;
	     putpixel(a+x,b+y,c);
	     c = (Datas[in] | 0xF0) & 0x0F;
	     putpixel(a+1+x,b+y,c);
	     in++;
	 }}
	free (Datas);
	fclose(fp);
	return 1;
    }

void date()      //date print garna lai..
{
getdate(&today);
setcolor(WHITE);
settextstyle(3,0,1);
outtextxy(70,432,itoa(today.da_day,string,10));
outtextxy(101,432,itoa(today.da_mon,string,10));
outtextxy(138,432,itoa(today.da_year,string,10));
outtextxy(22,432,"Date:   /  /");
}

void storename()     //store name print garna lai..
{
setcolor(YELLOW);
settextstyle(1,0,2);
outtextxy(50,2,"Departmental Store Management System");
}

int callmouse()    //mouse call garna lai..
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}

void hidemouse()
{
in.x.ax=2;
int86(51,&in,&out);
}

void getmousepos(int *button,int *x, int *y)     //mouse ko position search garna...
{
	in.x.ax = 3;
	int86(51, &in, &out);
	*button = out.x.bx;
	*x = out.x.cx;
	*y = out.x.dx;
}

void restrictmouseptr(int x1,int y1, int x2, int y2)
{                  // mouse bahera na pathauna lai..
in.x.ax=7;
in.x.cx=x1;
in.x.dx=x2;
int86(51,&in,&out);
in.x.ax=8;
in.x.cx=y1;
in.x.dx=y2;
int86(51,&in,&out);
}

void menu()       //menu..
{
   rectangle(120,64,242,84);
   rectangle(122,94,221,113);
   rectangle(119,124,220,145);
   rectangle(120,154,221,176);
   rectangle(121,184,243,205);
   rectangle(120,214,233,235);
   rectangle(120,243,160,264);
   setcolor(WHITE);
   settextstyle(3,0,2);
   outtextxy(95,60,"--Calculate bill");
   outtextxy(95,90,"--Add items");
   outtextxy(95,120,"--Edit items");
   outtextxy(95,150,"--Display All");
   outtextxy(95,180,"--Search item");
   outtextxy(95,210,"--Delete item");
   outtextxy(95,240,"--Exit");
}

void main()
{
int gd=DETECT, gm,status;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
//login();     /// password rakhna lai
alwaysdisplay();
closegraph();
cout<<"Press any Key to continue";
getch();
}

void callprogramend()
{
 end=0;
 alwaysdisplay();
}

void login()
{
  if(logincount==3)
   {
   displayforever();
   outtextxy(40,45,"Incorrect password Attempted"); delay(2000);
   callprogramend();
   }
   else
   {
  clrscr();   /// same place bata input lina lai
  cleardevice();
  displayforever();
  outtextxy(40,40,"Enter yourname and password \t Password Attempt=");
  outtextxy(520,40,itoa(logincount,pstring,10));
  cout<<"\n\n\n\n\n\tLogin Name:- ";
  rectangle(20,30,620,433);
  cin>>name;
  cout<<"\tPassword:- ";
  rectangle(20,30,620,433);
  cin>>password;
  code1= strcmp(password,"password");
  code2= strcmp(name,"rabin");
  if(code1==0 && code2==0)
    {
    cleardevice();
    alwaysdisplay();
    }
  else
   {
    outtextxy(40,55,"Incorrect password Attempted"); delay(1300);
    logincount++;
    cleardevice();
    login();
   }
   }
}

void displayforever()     // store name, date, mouse rectriction and rectangle....print garna..
{
  setbkcolor(BLUE);
  //ShowBACKGROUND(20,30,"back.bmp");
  rectangle(20,30,620,433);
  callmouse();
  restrictmouseptr(20,30,620,433);
  storename();
  date();
}

void alwaysdisplay() // display forecer + menu..
{
  setbkcolor(BLUE);
  //ShowBACKGROUND(20,30,"back.bmp");
  rectangle(20,30,620,433);
  restrictmouseptr(20,30,620,433);
  storename();
  date();
  callmouse();
  getmousepos(&button,&x,&y);
  while(end!=0)//(!kbhit())
  {
   menu();
   getmousepos(&button,&x,&y);
    if(button == 1)
     {
       if(x>=120 && x<=242 && y>=64 && y<=84)
	  {  option=1;  }
       else if(x>=122 && x<=221 && y>=94 && y<=113)
	  {  option=2;  }
       else if(x>=119 && x<=220 && y>=124 && y<=145)
	  {  option=3;  }
	else if(x>=120 && x<=221 && y>=154 && y<=176)
	  {  option=4;  }
	else if(x>=121 && x<=243 && y>=184 && y<=205)
	  {  option=5;  }
	else if(x>=120 && x<=223 && y>=214 && y<=235)
	  {  option=6;  }
	else if(x>=120 && x<=160 && y>=243 && y<=264)
	  {  option=7;  }
      else option=-1;
      hidemouse();
       switch(option)
       {
       case 1: calculatebill(); break;
       case 2: additem(); break;
       case 3: edititem(); break;
       case 4: display(); break;
       case 5: search(); break;
       case 6: deelete(); break;
       case 7: exxit();
       default:  callmouse();  break;
      }

       button= -1;
      //clrscr();
     // cleardevice();
       //cout<<x<<"\t"<<y<<"\n";
     }
   }
   cleardevice();
}

void calculatebill()  //case 1..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is just a test page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }

void additem()     //case 2..
  {
    end1=1;
    cleardevice();
    displayforever();
    getmousepos(&button,&x,&y);
     while(end1!=0)
       {//mouse lag then print menu here./////

	rectangle(48,55,137,71);
	rectangle(47,75,106,93);
	outtextxy(50,50,"Add items");
	outtextxy(50,70,"Cancel");

	getmousepos(&button,&x,&y);
	  if(button == 1)
	    {
	      if(x>=48 && x<=137 && y>=55 && y<=71)
		 {  option=1;  }
	      else if(x>=48 && x<=106 && y>=75 && y<=93)
		 {  option=2;  }
	      else option=-1;
	     hidemouse();
		 switch(option)
		   {
		     case 1: additem1(); end1=0; break; /// end1 vaya paxi, fere additem1 ma jana pauxa....
		     case 2: end1=0; break;
		     default:  callmouse();  break;
		   }
		  button= -1;
	     }
	}
  cleardevice();
  alwaysdisplay();
  }
void additem1()
{
   clrscr(); /////
   cleardevice();
   displayforever();
   rectangle(124,43,330,63);
   rectangle(124,63,330,130);
   outtextxy(128,41,"Enter Item Information.");
   rectangle(124,63,330,130);
   //for notes//
   outtextxy(35,196,"Note:");
   rectangle(35,220,605,420);
   ////////////
   hidemouse();
   cout<<"\n\n\n\n\t\tEnter serial no :";
   rectangle(124,63,330,130);
   displayforever();
   callmouse();
   cin>>r.sn;
   hidemouse();
   cout<<"\t\tEnter price :";
   rectangle(124,63,330,130);
   displayforever();
   callmouse();
   cin>>r.price;
   hidemouse();
   cout<<"\t\tEnter quantity :";
   rectangle(124,63,330,130);
   displayforever();
   callmouse();
   cin>>r.quantity;
   hidemouse();
   cout<<"\t\tEnter name :";
   rectangle(124,63,330,130);
   displayforever();
   callmouse();
   cin>>r.goodname;
   p=fopen("c:\\turboc3\\file\\record","ab");
   fwrite(&r,sizeof(r),1,p);
   fclose(p);
   cleardevice();
   displayforever();
   outtextxy(50,50,"Item Added"); delay(1000);
   cleardevice();
}

void edititem()     //case 3..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is another3333333 test page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }

void display()     //display...
  {
    end2=1;
    clrscr();
    cleardevice();
    displayforever();
    display1();
    getmousepos(&button,&x,&y);
     while(end2!=0)
       {//mouse lag then print menu here./////

	rectangle(47,35,106,53);
	outtextxy(50,30," Back ");
	getmousepos(&button,&x,&y);
	  if(button == 1)
	    {
	    if(x>=48 && x<=106 && y>=35 && y<=53)
		 {  option=1;  }
	      else option=-1;
	     hidemouse();
		 switch(option)
		   {
		     case 1:cleardevice(); alwaysdisplay();  end2=0; break; /// end1 vaya paxi, fere additem1 ma jana pauxa....
		     default:  callmouse();  break;
		   }
		  button= -1;
	     }

	}
  cleardevice();
  alwaysdisplay();
}

void display1()     //case 4..
{
  outtextxy(55,50,"---------------- List of Items ---------------");
  rectangle(35,75,605,420);
  line(320,75,320,420);
  displayforever();
  settextstyle(11,0,1);
  setcolor(RED);
  outtextxy(37,85,"SN.");
  outtextxy(70,85,"Name");
  outtextxy(170,85,"Quantity");
  outtextxy(250,85,"Price");
  settextstyle(3,0,2);
  displayforever();
  rectangle(35,75,605,420);
  line(320,75,320,420);
  p=fopen("c:\\turboc3\\file\\record","rb");
  x_co=40; y_co=100;
  displaycount=0;
  while(1)//(!feof(p))
  {
  fread(&r,sizeof(r),1,p);
  hidemouse();
  if(feof(p)!=0)
    {  break;  }
  settextstyle(11,0,1);
  outtextxy(x_co,y_co,itoa(r.sn,filestring,10));
  outtextxy(x_co+30,y_co,r.goodname);
  outtextxy(x_co+140,y_co,itoa(r.quantity,filestring,10));
  outtextxy(x_co+210,y_co,itoa(r.price,filestring,10));
  y_co=y_co+11;
  displayforever();
  rectangle(35,75,605,420);
  line(320,75,320,420);
  settextstyle(3,0,2);
  displaycount=displaycount+1;
	if(displaycount==29)
	    {   x_co=340;  y_co=100;
			setcolor(RED);
			settextstyle(11,0,1);
			outtextxy(340,85,"SN.");
			outtextxy(373,85,"Name");
			outtextxy(473,85,"Quantity");
			outtextxy(543,85,"Price");
			settextstyle(3,0,2);
		while(1)
		{
		  fread(&r,sizeof(r),1,p);
		 if(feof(p)!=0)
		{  break;  }
		setcolor(WHITE);
		settextstyle(11,0,1);
		outtextxy(x_co,y_co,itoa(r.sn,filestring,10));
		outtextxy(x_co+30,y_co,r.goodname);
		outtextxy(x_co+140,y_co,itoa(r.quantity,filestring,10));
		outtextxy(x_co+210,y_co,itoa(r.price,filestring,10));
		y_co=y_co+11;
		displayforever();
		rectangle(35,75,605,420);
		line(320,75,320,420);
		settextstyle(3,0,2);
		}
	   }
  }
  callmouse();
  settextstyle(3,0,2);
  fclose(p);
}

  void search()     //case 5..
  {
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is search page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
  void deelete()     //case 6..
  {
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is delete page"); delay(2000);
  cleardevice();
  alwaysdisplay();
}

void exxit()      //case 7...
{
   cleardevice();
   displayforever();
   outtextxy(50,50,"Program End"); delay(800);
   end=0;
}