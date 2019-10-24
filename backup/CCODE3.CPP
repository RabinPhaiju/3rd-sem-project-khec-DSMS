#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>

union REGS in, out;    //mouse ko lagi variables..
struct date today; // date ko lagi
struct time t;
char string[25];   // date ko lagi
int end=1,end1=1,end2=1,logincount=0,code1,code2,passend=1;
int button,x,y,option,x_co,y_co,displaycount;
char name[20],password[20],pstring[20],filestring[30];
int sn_temp;
void login();
void hidemouse();
int callmouse();
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
void cusdetail();
void vendetail();
void finance();
void history();
void checkexp();
void time();
void passwordMatch();
void getmousepos(int *,int *,int *);

 class Store
 {
 private:

   int sn,quantity;
   int expdatem,expdated,expdatey;
   char goodname[20],brand[20];
   long price;
 public:

 void getGoodData();
 void displayGoodData();
 void searchGoodData();
 void deleteGoodData();
 void editGoodData();
 };

 void Store::getGoodData()
	 {
	   clrscr();
	   cleardevice();
	   displayforever();
	   rectangle(124,43,400,63);
	   rectangle(124,63,400,160);
	   outtextxy(128,41,"Enter Item Information.");
	   rectangle(124,63,400,160);
	   outtextxy(35,196,"Note:");
	   rectangle(35,220,605,420);
	   hidemouse();
	ifstream fin;
	fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
	if(!fin)
	   {
		hidemouse();
		outtextxy(200,230,"File not found -- Created new file");
		sn_temp=0;    //if file nae xena vane sn 1 bata suru hunxa
		callmouse();
	   }
	else
	{
	   while(!fin.eof())
		{
		  fin.read((char *)this,sizeof(*this));
		}
	    sn_temp=sn;   //if file xa vane last+1
	  }
	   fin.close();
	   sn=sn_temp+1;
	   cout<<"\n\n\n\n\t\tEnter item name :";
	   rectangle(124,63,400,160);
	   displayforever();
	   callmouse();
	   gets(goodname);
	   hidemouse();
	   cout<<"\t\tEnter brand :";
	   rectangle(124,63,400,160);
	   displayforever();
	   callmouse();
	   gets(brand);
	   hidemouse();
	   cout<<"\t\tEnter price :";
	   rectangle(124,63,400,160);
	   displayforever();
	   callmouse();
	   cin>>price;
	   hidemouse();
	   cout<<"\t\tEnter quantity :";
	   rectangle(124,63,400,160);
	   displayforever();
	   callmouse();
	   cin>>quantity;
	   hidemouse();
	   getdate(&today);
	   expdatem=today.da_mon;
	   expdated=today.da_day;
	   expdatey=today.da_year;
	   ofstream fout;
	   fout.open("c:\\turboc3\\file\\record3",ios::app|ios::binary);
	   fout.write((char *)this,sizeof(*this));
	   fout.close();
	   outtextxy(50,230,"Item Added"); delay(600);
	   cleardevice();
	 }
 void Store::editGoodData()
	{

	  int flag=0;
	  char ch[20];
	  cout<<"\n\n\t\tEnter a detail to edit goods information\n";
	  cout<<"\t\tGood Name :";
	  displayforever();
	  cin>>ch;
	  displayforever();
	  fstream file;
	  file.open("c:\\turboc3\\file\\record3",ios::in|ios::out|ios::ate|ios::binary);
	  file.seekg(0);
	  file.read((char *)this,sizeof(*this));
	  while(!file.eof())
		{
		  if(!strcmp(goodname,ch))
			{
			   clrscr();
			   cleardevice();
			   displayforever();

		  hidemouse();
		  cout<<"\n\n\n\t\t\t\t\t\t"<<"Previous record";
		  cout<<"\n\t\t\t\t\t\t"<<" Item Name:"<<goodname;
		  cout<<"\n\t\t\t\t\t\t"<<"    Brand :"<<brand;
		  cout<<"\n\t\t\t\t\t\t"<<" Serail no:"<<sn;
		  cout<<"\n\t\t\t\t\t\t"<<"   price--:"<<price;
		  cout<<"\n\t\t\t\t\t\t"<<" Quantity-:"<<quantity;
		  cout<<"\n\t\t\t\t\t\t"<<" Date-:"<<expdated<<"/"<<expdatem<<"/"<<expdatey;
		  line(380,62,550,62);// for before record ko lagi rectangle
		  rectangle(380,45,550,170);
		  outtextxy(60,100,"Item found ");
		  outtextxy(60,120,"Enter good Information to update.");

			   cout<<"\n\tEnter price :";
			 //  rectangle(380,45,550,170);
			   displayforever();
			   callmouse();
			   cin>>price;
			   cout<<"\tEnter quantity :";
			   displayforever();
			   cin>>quantity;
			   callmouse();
			   getdate(&today);
			   expdatem=today.da_mon;
			   expdated=today.da_day;
			   expdatey=today.da_year;
			  file.seekp(file.tellp()-sizeof(*this));
			  file.write((char *)this,sizeof(*this));
			  flag=1;
			outtextxy(35,196,"Note:");
			rectangle(35,220,605,420);
			outtextxy(50,230,"Information Updated");
			outtextxy(50,260,"Enter any key to continue");
			  getch();
			  break;
			}
		  file.read((char *)this,sizeof(*this));
		}
		if(flag==0)
		{
			outtextxy(35,196,"Note:");
			rectangle(35,220,605,420);
			outtextxy(50,300,"No such information found");
			outtextxy(50,330,"Enter any key to continue");
			getch();
		}
	  }
 void Store::deleteGoodData()
	{
	  int match=0;
	  ifstream fin;
	  ofstream fout;
	  clrscr();
	  cleardevice();
	  char ch[20];
	  displayforever();
	  cout<<"\n\n\t\tEnter information to delete item\n";
	  cout<<"\t\tName :";
	  displayforever();
	  cin>>ch;
	  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
	  if(!fin)
		{       hidemouse();
			outtextxy(35,196,"Note:");
			rectangle(35,220,605,420);
			outtextxy(50,230,"File not found");
			outtextxy(50,260,"Enter any key to continue");
			callmouse();
			getch();
		}
	  else
	      { fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
		    if(!strcmp(ch,goodname))
		    {   match=1;  }
		    fin.read((char *)this,sizeof(*this));
		}
		fin.close();
		if(match==1)
		{
		  fout.open("c:\\turboc3\\file\\temprecord3",ios::out|ios::binary);
		  ifstream fin;
		  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
		  fin.read((char *)this,sizeof(*this));
		  while(!fin.eof())
			{
			  if(!strcmp(ch,goodname))
				{
					hidemouse();
					outtextxy(35,196,"Note:");
					rectangle(35,220,605,420);
					outtextxy(50,230,"Item found");
				  cout<<"\n\n\n\n\n\n\n\n\n";
				  cout<<"\n\t\t\t\t\t\t"<<" Item Name:"<<goodname;
				  cout<<"\n\t\t\t\t\t\t"<<"    Brand :"<<brand;
				  cout<<"\n\t\t\t\t\t\t"<<" Serail no:"<<sn;
				  cout<<"\n\t\t\t\t\t\t"<<"   price--:"<<price;
				  cout<<"\n\t\t\t\t\t\t"<<" Quantity-:"<<quantity;
				  cout<<"\n\t\t\t\t\t\t"<<"     Date-:"<<expdated<<" / "<<expdatem<<" / "<<expdatey;
				  rectangle(35,220,605,420);
				  outtextxy(50,230,"Item found     ...Deleting....");
				  displayforever();
				}
			  else
				{
				  fout.write((char *)this,sizeof(*this));
				}
			  fin.read((char *)this,sizeof(*this));
			}
	  delay(1500);
	  setcolor(BLUE);
	  outtextxy(50,230,"Item found     ...Deleting....");
	  setcolor(WHITE);
	  outtextxy(50,230,"Item found     ...Deleted.....");
	  outtextxy(50,260,"Enter any key to continue");
	  callmouse();
	  fin.close();
	  fout.close();
	  remove("c:\\turboc3\\file\\record3");
	  rename("c:\\turboc3\\file\\temprecord3","c:\\turboc3\\file\\record3");
	  getch();
	  }
	  else
	      { outtextxy(35,196,"Note:");
		rectangle(35,220,605,420);
		outtextxy(50,230,"Item not found");
		outtextxy(50,260,"Enter any key to continue");
		getch();
	      }
	  }
	}
 void Store::searchGoodData()
	{

	  int flag=0;
	  char ch[20];
	  clrscr();
	  cleardevice();
	  displayforever();
	  cout<<"\n\n\t\tEnter a Good information to search\n";
	  cout<<"\t\tName:";
	  displayforever();
	  cin>>ch;
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
	  fin.read((char *)this,sizeof(*this));
	  while(!fin.eof())
		{
		  if(!strcmp(ch,goodname))
		  {
		  outtextxy(35,196,"Note:");
		  rectangle(35,220,605,420);
		  hidemouse();
		  cout<<"\n\n\n\n\n\n\n\n\n";
		  cout<<"\n\t\t\t\t\t\t"<<" Item Name:"<<goodname;
		  cout<<"\n\t\t\t\t\t\t"<<"    Brand :"<<brand;
		  cout<<"\n\t\t\t\t\t\t"<<" Serail no:"<<sn;
		  cout<<"\n\t\t\t\t\t\t"<<"   price--:"<<price;
		  cout<<"\n\t\t\t\t\t\t"<<" Quantity-:"<<quantity;
		  cout<<"\n\t\t\t\t\t\t"<<"     Date-:"<<expdated<<" / "<<expdatem<<" / "<<expdatey;
		  outtextxy(50,230,"Record found");
		  rectangle(35,220,605,420);
		  outtextxy(50,260,"Enter any key to continue");
		  callmouse();
		  displayforever();
		  getch();
		  flag=1;
		  break;
		  }
		  fin.read((char *)this,sizeof(*this));
		}
	  if(flag==0)
		{  outtextxy(35,196,"Note:");
		   rectangle(35,220,605,420);
		   outtextxy(50,230,"Record not found");
		   delay(1200);
		}
	  fin.close();
	}
 void Store::displayGoodData()
	{
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
      if(!fin)
	 {
		hidemouse();
		clrscr();
		cleardevice();
		displayforever();
		outtextxy(35,196,"Note:");
		rectangle(35,220,605,420);
		outtextxy(50,230,"File not found");
		callmouse();
	 }
      else
      {
	  fin.read((char *)this,sizeof(*this));
	  display29:
	  x_co=40; y_co=100;
	  displaycount=0;
      while(!fin.eof())
	  {
	  hidemouse();
	  displayforever();
	  outtextxy(55,50,"---------------- List of Items ---------------");
	  rectangle(35,75,605,420);
	  displayforever();
	  settextstyle(11,0,1);
	  setcolor(RED);
	  outtextxy(37,85,"Code");
	  outtextxy(90,85,"Product");
	  outtextxy(220,85,"Quantity");
	  outtextxy(310,85,"Price");
	  outtextxy(390,85,"Brand");
	  outtextxy(495,85,"Exp.date");
	  setcolor(WHITE);
	  settextstyle(3,0,2);
	  rectangle(35,75,605,420);
		  settextstyle(11,0,1);
		  outtextxy(x_co,y_co,itoa(sn,filestring,10));
		  outtextxy(x_co+50,y_co,goodname);
		  outtextxy(x_co+190,y_co,itoa(quantity,filestring,10));
		  outtextxy(x_co+270,y_co,ltoa(price,filestring,10));
		  outtextxy(x_co+350,y_co,brand);
		  outtextxy(x_co+460,y_co,itoa(expdated,filestring,10));
		  outtextxy(x_co+470,y_co,"/");
		  outtextxy(x_co+480,y_co,itoa(expdatem,filestring,10));
		  outtextxy(x_co+490,y_co,"/");
		  outtextxy(x_co+500,y_co,itoa(expdatey,filestring,10));
		  y_co=y_co+11;
		  rectangle(35,75,605,420);
		  settextstyle(3,0,2);
		  displaycount=displaycount+1;
		  callmouse();
	   fin.read((char *)this,sizeof(*this));
		if(displaycount==29)
		{
		 outtextxy(310,30,"  Press Enter for NEXT page");
		 rectangle(485,35,545,55);
		 rectangle(47,35,112,53);
		 outtextxy(50,30," MENU ");
		 while(!kbhit())
		 {
			getmousepos(&button,&x,&y);
			if(button == 1)
			{
			if(x>=485 && x<=545 && y>=35 && y<=55)
			{ ungetch('\n'); }//enter key auto click garna lai
			else if(x>=47 && x<=112 && y>=35 && y<=53)
			{   fin.eof(); goto menu;   }
			} //file complete check na gari nae menu ma jana lai
		 }
		 getch(); clrscr(); cleardevice();  goto display29;
		}
	}
   }
  menu:
  fin.close();
}

Store s; //class ko object

void time()
{
   gettime(&t);
   if(t.ti_hour>12)
   {
   t.ti_hour=t.ti_hour-12;
   outtextxy(348,432,"pm");
   }
   else
   {  outtextxy(348,432,"am");  }
   settextstyle(3,0,2);
   outtextxy(280,432,itoa(t.ti_hour,string,10));
   outtextxy(317,432,itoa(t.ti_min,string,10));
 //  outtextxy(352,432,itoa(t.ti_sec,string,10));
   outtextxy(225,432,"Time:");
   outtextxy(280,432,"   :     ");
   /////////////
   if(t.ti_sec==0)
   {
   gettime(&t);
   settextstyle(3,0,2);
   setcolor(BLUE);
   setfillstyle(SOLID_FILL,1);
   bar(278,438,342,455);
   outtextxy(280,432,itoa(t.ti_hour,string,10));
   outtextxy(317,432,itoa(t.ti_min,string,10));
   settextstyle(11,0,1);
   setcolor(WHITE);
   delay(990);
   }
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
   rectangle(120,64,245,84);
   rectangle(122,94,221,113);
   rectangle(119,124,220,145);
   rectangle(120,154,221,176);
   rectangle(121,184,243,205);
   rectangle(120,214,233,235);
   rectangle(120,243,160,264);
	rectangle(300,64,462,84);
	rectangle(300,94,436,113);
	rectangle(300,124,400,145);
	rectangle(300,154,401,176);
	rectangle(300,184,471,205);
   setcolor(WHITE);
   settextstyle(3,0,2);
   outtextxy(95,60,"   Calculate bill");
   outtextxy(95,90,"   Add item");
   outtextxy(95,120,"   Edit item");
   outtextxy(95,150,"   Display All");
   outtextxy(95,180,"   Search item");
   outtextxy(95,210,"   Delete item");
   outtextxy(95,240,"   Exit");
	outtextxy(302,60,"Customer Detail");
	outtextxy(302,90,"Vendor Detail");
	outtextxy(302,120,"Finance");
	outtextxy(302,150,"History");
	outtextxy(302,180,"Check Expiration");
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

void passwordMatch()
{
  int u=0;
  while(u<8)
  {
      if(password[u]==10)  { u=15;}
      else
     {   password[u]=getch();  }
      if(password[u]==8)
	 {
	   cout<<"\b\b";
	   u--;
	   if(u<0)  { cout<<"";  u++;  }
	 }
	 else if(password[u]==13)  break;
	 else
	 {  cout<<"*"; u++;      }

  }
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
  //////////
  passwordMatch();
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
  rectangle(20,30,620,433);
  callmouse();
  restrictmouseptr(20,30,620,433);
  storename();
  date();
}

void alwaysdisplay() // display forecer + menu..
{
  setbkcolor(BLUE);
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
       if(x>=120 && x<=245 && y>=64 && y<=84)
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
	else if(x>=300 && x<=462 && y>=64 && y<=84)
	  {  option=8;  }
	else if(x>=300 && x<=436 && y>=94 && y<=113)
	  {  option=9;  }
	  else if(x>=300 && x<=400 && y>=124 && y<=145)
	  {  option=10;  }
	  else if(x>=300 && x<=401 && y>=154 && y<=176)
	  {  option=11;  }
	  else if(x>=300 && x<=471 && y>=184 && y<=205)
	  {  option=12;  }

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
       case 8: cusdetail(); break;
       case 9: vendetail(); break;
       case 10: finance(); break;
       case 11: history(); break;
       case 12: checkexp(); break;
       case 7: exxit();
       default:  callmouse();  break;
      }

       button= -1;
     }
	time();
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
  void cusdetail()  //case 8..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is just a customer detail page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
  void vendetail()  //case 9..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is just a vendor detail page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
void finance()  //case 10..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is just a finance page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
void history()  //case 11..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is just a history page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
void checkexp()  //case 12..
{
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is just a exipration detail page"); delay(2000);
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
	outtextxy(50,50,"Add item");    //category
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
   s.getGoodData();
}

void edititem()     //case 3..
{
  clrscr();
  cleardevice();
  displayforever();

  s.editGoodData();

  clrscr();
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

	rectangle(47,35,112,53);
	outtextxy(50,30," MENU ");
	getmousepos(&button,&x,&y);
	  if(button == 1)
	    {
	    if(x>=48 && x<=112 && y>=35 && y<=53)
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
  s.displayGoodData();
}

  void search()     //case 5..
{
  s.searchGoodData();
  cleardevice();
  alwaysdisplay();
}
  void deelete()     //case 6..
{
  s.deleteGoodData();
  cleardevice();
  alwaysdisplay();
}

void exxit()      //case 7...
{
   cleardevice();
   displayforever();
   outtextxy(50,50,"Program End"); delay(800);
   cleardevice();
   closegraph();
   end=0;
}