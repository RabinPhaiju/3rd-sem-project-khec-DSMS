#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>

union REGS in, out;    //mouse ko lagi variables..
struct date today; // date ko lagi
struct time t;
char string[25];   // date ko lagi
int end=1,end1=1,end2=1,end3=1,end4=1,end5=1,logincount=0,passcode1,passcode2,passend=1;
int button,x,y,option,x_co,y_co,displaycount,displaycount1,x_cor,y_cor;
char name[20],password[20],pstring[20],filestring[30];
int sn_temp,itemcode,itemquantity,flag,fileexist;
int ycod,xcod;
double total,total1;
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
void buytoreceipt();
void displayAddCart();
long input(int,int,char[]);


struct record
{
  char goodname1[20],brand1[20];
  int quantity1;
  long price1,rs1;
};

struct customer
{
  char cusname[25],phoneno[14];
  double money;
  int yr,mo,da;
};

class userpass
{
  private:
  char USER[20],ADDRESS[30],PHONE[14],PASSWORD[8];
  public:
  void checkpass();
  int loginpass(char[20],char[8]);
};

FILE *p,*pp;
struct record r;
struct customer c;

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
 void searchGoodDataByName();
 void searchGoodDataByCode();
 void deleteGoodData();
 void editGoodData();
 void cart();
 void copyfile();
 void checkExpDate();
 };
void Store::copyfile()
{
      ifstream fin;
      ofstream fout;
      fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
      fout.open("c:\\turboc3\\file\\temp",ios::out|ios::binary);
	      fin.read((char *)this,sizeof(*this));
	      while(!fin.eof())
		{
		    fout.write((char *)this,sizeof(*this));
		    fin.read((char *)this,sizeof(*this));
		}
      fin.close();
      fout.close();
}

 void Store::cart() //cart ma item rakhna
 {
    flag=0;
    clrscr();
    cleardevice();
    displayforever();
    gotoxy(12,1);
    itemcode=input(12,3,"Enter item code:"); //function of input for string
    fstream file;
    file.open("c:\\turboc3\\file\\temp",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char *)this,sizeof(*this));
    while(!file.eof())
    {
      if(itemcode==sn)
	{
	  outtextxy(35,196,"Note:");
	  rectangle(35,220,605,420);
	  hidemouse();
	  gotoxy(50,4);  cout<<"Item info";
	  gotoxy(50,5);  cout<<"Item Name:";  cout<<goodname;
	  gotoxy(50,6);  cout<<"    Brand:";  cout<<brand;
	  gotoxy(50,7);  cout<<"Serial no:";  cout<<sn;
	  gotoxy(50,8);  cout<<"    price:"; cout<<price;
	  gotoxy(50,9);  cout<<" Quantity:"; cout<<quantity;
	  gotoxy(50,10); cout<<"     Date:"; cout<<expdated; cout<<"/"<<expdatem; cout<<"/"<<expdatey;
	  line(380,62,550,62);// for before record ko lagi rectangle
	  rectangle(380,45,550,170);
	  outtextxy(50,230,"Record found");
	  rectangle(35,220,605,420);
	 itemquantity=input(12,6,">Enter quantity:");// func for integer
	  flag=1;
	  if(itemquantity>quantity)
	  {
	    outtextxy(50,260,"Item left->");
	    outtextxy(150,260,itoa(quantity,filestring,10));
	    outtextxy(50,290,"Add again");
	    outtextxy(50,320,"Enter any key to continue");
	    getch();
	  }
	  else
	  {
	    outtextxy(300,230,"-> Pay Rs.:");
	    outtextxy(405,230,ltoa(itemquantity*price,filestring,10));
	    /////////////////
	    p=fopen("c:\\turboc3\\file\\cart.txt","ab");
	    strcpy(r.goodname1,goodname);
	    strcpy(r.brand1,brand);
	    r.price1=price;
	    r.quantity1=itemquantity;
	    r.rs1=itemquantity*price;
	    fwrite(&r,sizeof(r),1,p);
	    fclose(p);
	    ///////////////////
	    quantity=quantity-itemquantity;
	    file.seekp(file.tellp()-sizeof(*this));
	    file.write((char *)this,sizeof(*this));
	    ////////////////////
	    outtextxy(50,260,"Enter any key to continue");
	    callmouse();
	    displayforever();
	    getch();
	  }
	  break;
	}
	  file.read((char *)this,sizeof(*this));
      }
	  if(flag==0)
	  {outtextxy(35,196,"Note:");
	   rectangle(35,220,605,420);
	   outtextxy(50,230,"Record not found");
	   delay(1200);
	  }
	  file.close();
	  clrscr();
	  cleardevice();
 }

 void Store::getGoodData()
	 {
	   clrscr();
	   cleardevice();
	   displayforever();
	   hidemouse();
	   rectangle(70,43,400,63);
	   rectangle(70,63,400,160);
	   outtextxy(128,41,"Enter Item Information.");
	   outtextxy(35,196,"Note:");
	   rectangle(35,220,605,420);
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
	   getdataname:
	   gotoxy(18,5); cout<<"Item name:";
	   gets(goodname);
	   if(goodname[0]=='\0')
	   {
	      rectangle(420,45,530,110);
	      gotoxy(55,4); cout<<"Notice";
	      gotoxy(55,5); cout<<"Enter name";
	      goto getdataname;
	   }
	   getdatabrand:
	   gotoxy(18,6); cout<<"    Brand:";
	   gets(brand);
	   if(brand[0]=='\0')
	   {
	     gotoxy(55,4); cout<<"Notice";
	     gotoxy(55,6); cout<<"Enter brand";
	     goto getdatabrand;
	   }
	   price=input(12,7,"          Price:");
	   quantity=input(12,9,"       Quantity:");
	   getdate(&today);
	   expdated=today.da_day;
	   expdatey=today.da_year;
	   expdatem=today.da_mon+6;
	   if(expdatem>=13){ expdatem=expdatem-12; expdatey=expdatey+1; }
	   ofstream fout;
	   fout.open("c:\\turboc3\\file\\record3",ios::app|ios::binary);
	   fout.write((char *)this,sizeof(*this));
	   fout.close();
	   outtextxy(50,230,"Item Added");
	   outtextxy(50,280,"Enter any key to continue");
	   getch();
	   cleardevice();
	 }
 void Store::editGoodData()
	{
	  flag=0;
	  int INTTT;
	  gotoxy(18,3); cout<<"Enter a detail to edit goods information";
	  INTTT=input(13,4,"       Code no.:");
	  fstream file;
	  file.open("c:\\turboc3\\file\\record3",ios::in|ios::out|ios::ate|ios::binary);
	  file.seekg(0);
	  file.read((char *)this,sizeof(*this));
	  while(!file.eof())
	    {
	      if(INTTT==sn)
		 {
		  hidemouse();
		  gotoxy(50,5); cout<<"Previous record";
		  gotoxy(50,6); cout<<" Item Name:"<<goodname;
		  gotoxy(50,7); cout<<"    Brand :"<<brand;
		  gotoxy(50,8); cout<<" Serail no:"<<sn;
		  gotoxy(50,9); cout<<"   price--:"<<price;
		  gotoxy(50,10);cout<<" Quantity-:"<<quantity;
		  gotoxy(50,11);cout<<" Date-:"<<expdated<<"/"<<expdatem<<"/"<<expdatey;
		  line(380,78,550,78);
		  rectangle(380,60,550,180);
		  outtextxy(60,80,"Item found ");
		  outtextxy(60,100,"Enter good Information to update.");
			   price=input(5,9,"   Enter price :");
			   quantity=input(5,11,"Enter quantity :");
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
	  file.close();
	  }
 void Store::deleteGoodData()
	{
	  int match=0;
	  ifstream fin;
	  ofstream fout;
	  clrscr();
	  cleardevice();
	  int INT;
	  displayforever();
	  gotoxy(6,3); cout<<"Enter information to delete item\n";
	  INT=input(4,4,"      Item code:");
	  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
	  if(!fin)
		{
			outtextxy(35,196,"Note:");
			rectangle(35,220,605,420);
			outtextxy(50,230,"File not found");
			outtextxy(50,260,"Enter any key to continue");
			getch();
		}
	  else
	      { fin.read((char *)this,sizeof(*this));
		while(!fin.eof())
		{
		    if(INT==sn)
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
			  if(INT==sn)
				{
					hidemouse();
					outtextxy(35,196,"Note:");
					rectangle(35,220,605,420);
					outtextxy(50,230,"Item found");
				gotoxy(50,5); cout<<"Item Detail";
				gotoxy(50,6); cout<<" Item Name:"<<goodname;
				gotoxy(50,7); cout<<" Brand :"<<brand;
				gotoxy(50,8); cout<<" Serail no:"<<sn;
				gotoxy(50,9); cout<<"   price--:"<<price;
				gotoxy(50,10);cout<<" Quantity-:"<<quantity;
				gotoxy(50,11);cout<<" Date-:"<<expdated<<"/"<<expdatem<<"/"<<expdatey;
				line(380,78,550,78);
				rectangle(380,60,550,180);
				  outtextxy(50,230,"Item found     ...Deleting....");
				  displayforever();
				}
			  else
				{
				  fout.write((char *)this,sizeof(*this));
				}
			  fin.read((char *)this,sizeof(*this));
			}
	  delay(600);
	  setcolor(BLUE);
	  outtextxy(50,230,"Item found     ...Deleting....");
	  setcolor(WHITE);
	  outtextxy(50,230,"Item found     ...Deleted.....");
	  outtextxy(50,260,"Enter any key to continue");
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
	  hidemouse();
	}
 void Store::searchGoodDataByName()
	{

	  int flag=0;
	  char ch[20];
	  clrscr();
	  cleardevice();
	  displayforever();
	  gotoxy(18,3);  cout<<"Enter a Good information to search\n";
	  gotoxy(18,4);  cout<<"Name:";
	  gets(ch);
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
	  fin.read((char *)this,sizeof(*this));
	  while(!fin.eof())
		{
		  if(!strcmp(ch,goodname))
		  {
		  outtextxy(35,196,"Note:");
		  rectangle(35,220,605,420);
		  gotoxy(50,5); cout<<"Previous record";
		  gotoxy(50,6); cout<<" Item Name:"<<goodname;
		  gotoxy(50,7); cout<<" Brand :"<<brand;
		  gotoxy(50,8); cout<<" Serail no:"<<sn;
		  gotoxy(50,9); cout<<"   price--:"<<price;
		  gotoxy(50,10);cout<<" Quantity-:"<<quantity;
		  gotoxy(50,11);cout<<" Date-:"<<expdated<<"/"<<expdatem<<"/"<<expdatey;
		  line(380,78,550,78);
		  rectangle(380,60,550,180);
		  outtextxy(50,230,"Record found");
		  rectangle(35,220,605,420);
		  outtextxy(50,260,"Enter any key to continue");
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
	  cleardevice();
	  displayforever();
	}

void Store::searchGoodDataByCode()
	{

	  int flag4=0;
	  int INTT;
	  clrscr();
	  cleardevice();
	  displayforever();
	  gotoxy(18,3);  cout<<"Enter a Good information to search\n";
	  INTT=input(12,4,"             Code:");
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3",ios::in|ios::binary);
	  fin.read((char *)this,sizeof(*this));
	  while(!fin.eof())
		{
		  if(INTT==sn)
		  {
		  outtextxy(35,196,"Note:");
		  rectangle(35,220,605,420);
		  gotoxy(50,5); cout<<"Previous record";
		  gotoxy(50,6); cout<<" Item Name:"<<goodname;
		  gotoxy(50,7); cout<<" Brand :"<<brand;
		  gotoxy(50,8); cout<<" Serail no:"<<sn;
		  gotoxy(50,9); cout<<"   price--:"<<price;
		  gotoxy(50,10);cout<<" Quantity-:"<<quantity;
		  gotoxy(50,11);cout<<" Date-:"<<expdated<<"/"<<expdatem<<"/"<<expdatey;
		  line(380,78,550,78);
		  rectangle(380,60,550,180);
		  outtextxy(50,230,"Record found");
		  rectangle(35,220,605,420);
		  outtextxy(50,260,"Enter any key to continue");
		  getch();
		  flag4=1;
		  break;
		  }
		  fin.read((char *)this,sizeof(*this));
		}
	  if(flag4==0)
		{  outtextxy(35,196,"Note:");
		   rectangle(35,220,605,420);
		   outtextxy(50,230,"Record not found");
		   delay(1200);
		}
	  fin.close();
	  cleardevice();
	  displayforever();
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
	  if(kbhit())  { getch(); }
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
		 if(!fin.eof())
		 { outtextxy(310,30,"  Press Enter for NEXT page");
		   rectangle(485,35,545,55);
		 }
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
			{   goto menu;   }
			} //file complete check na gari nae menu ma jana lai
		 }
		 getch(); if(fin.eof()) { goto menu;  }
		 clrscr(); cleardevice();  goto display29;
		}
	}
   }
  menu:
  fin.close();
}

void Store::checkExpDate()
	{
	  int click=1;
	  cleardevice();
	  displayforever();
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
	 }
      else
      {
	  getdate(&today);
	  fin.read((char *)this,sizeof(*this));
	  displayexp:
	  x_co=40; y_co=100;
	  displaycount=0;
      while(!fin.eof())
       {
	  if(kbhit())  {  getch(); }
	  hidemouse();
	  displayforever();
	  outtextxy(55,50,"---------------- Expired Items ---------------");
	  rectangle(35,75,605,420);
	  displayforever();
	  hidemouse();
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
	       if(today.da_day>=expdated && today.da_mon>=expdatem && today.da_year>=expdatey )
		  {
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
		  }
		  callmouse();
	   fin.read((char *)this,sizeof(*this));
		if(displaycount==29)
		{
		 if(!fin.eof())
		 { outtextxy(310,30,"  Press Enter for NEXT page");
		   rectangle(485,35,545,55);
		 }
		 rectangle(47,35,112,53);
		 outtextxy(50,30," MENU ");
		 while(!kbhit())
		 {
			getmousepos(&button,&x,&y);
			if(button == 1)
			{
			if(x>=485 && x<=545 && y>=35 && y<=55)
			{ ungetch('\n'); }
			else if(x>=47 && x<=112 && y>=35 && y<=53)
			{   goto returnmenu;   }
			}
		 }
		 getch(); if(fin.eof()) { goto returnmenu;  }
		 clrscr(); cleardevice();  goto displayexp;
		}
	}
   }
  returnmenu:
  rectangle(47,35,112,53);
  settextstyle(3,0,2);
  outtextxy(50,30," MENU ");
  while(click!=0)
  {
    getmousepos(&button,&x,&y);
      if(button==1)
	{  if(x>=47 && x<=112 && y>=35 && y<=53)
	   {click=0;}
	}
  }
  fin.close();
  hidemouse();
}

Store s; //class ko object
userpass u;

void time()
{
   gettime(&t);
   settextstyle(3,0,2);
   if(t.ti_hour>12)
   {
   t.ti_hour=t.ti_hour-12;
   outtextxy(348,432,"pm");
   }
   else
   {  outtextxy(348,432,"am");  }
   outtextxy(280,432,itoa(t.ti_hour,string,10));
   outtextxy(317,432,itoa(t.ti_min,string,10));
 //  outtextxy(352,432,itoa(t.ti_sec,string,10));
   outtextxy(225,432,"Time:");
   outtextxy(280,432,"   :     ");
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

void menu()       //main menu..
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
	rectangle(300,154,465,176);
	rectangle(300,184,400,205);
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
	outtextxy(302,150,"Check Expiration");
	outtextxy(302,180,"Add User ");
}

void main()
{
   int gd=DETECT, gm,status;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   login();     /// password rakhna lai  //////////////////////
   alwaysdisplay();
   closegraph();
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
   closegraph();
}

void login()
{
  int return_pass;
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
  gotoxy(10,7);cout<<"Login Name:- ";
  rectangle(20,30,620,433);
  gets(name);
  gotoxy(4,8); cout<<"8 digit Password:- ";
  rectangle(20,30,620,433);
  //////////
  passwordMatch();
  passcode1= strcmp(password,"password");
  passcode2= strcmp(name,"rabin");
  return_pass=u.loginpass(name,password);
  if((passcode1==0 && passcode2==0) || return_pass==1)
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

void alwaysdisplay() // display forever + menu..
{
  setbkcolor(BLUE);
  rectangle(20,30,620,433);
  restrictmouseptr(20,30,620,433);
  storename();
  date();
  callmouse();
  getmousepos(&button,&x,&y);
  while(end!=0)
  {
   if(kbhit()) { getch(); } // unwanted thau ma keyboard press
   menu();                  // garyo vane ignore
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
	  else if(x>=300 && x<=465 && y>=154 && y<=176)
	  {  option=11;  }
	  else if (x>=300 && x<=400 && y>=184 && y<=205)
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
       case 11: checkexp(); break;
       case 12: u.checkpass(); break;
       case 7: exxit();
       default:  callmouse();  break;
      }

       button= -1;
     }
       //	time();
   }
   cleardevice();
}

void calculatebill()  //case 1..
{
    end3=1;
    fileexist=0;
    cleardevice();
    displayforever();
    getmousepos(&button,&x,&y);
    s.copyfile();//cart ma quantity decrease garna arko file
    delay(200);
	ifstream finn;
     while(end3!=0)
     {
	 if(kbhit())  {  getch();   }
	     rectangle(20,30,620,433);
	     restrictmouseptr(20,30,620,433);
	     storename();
	     date();
       finn.open("c:\\turboc3\\file\\cart.txt",ios::in);
	if(finn)
	{
	  fileexist=1;
	}
	if(fileexist==1)
	{
	  rectangle(310,50,380,75);
	  outtextxy(330,50,"Buy");
	}
	////////////////
	p=fopen("c:\\turboc3\\file\\cart.txt","rb");
	fread(&r,sizeof(r),1,p);
	x_cor=40; y_cor=170;
	total=0;
	settextstyle(11,0,1);
    displayAddCart();  // cart ma vako items print garna
	fclose(p);
	settextstyle(3,0,2);
	rectangle(48,55,165,75);
	rectangle(47,85,110,103);
	outtextxy(50,50,"Add to cart");
	outtextxy(50,80,"Cancel");
	outtextxy(35,126,"Cart:");
	rectangle(33,150,430,420);
	getmousepos(&button,&x,&y);
	  if(button == 1)
	    {
	      if(x>=48 && x<=165 && y>=55 && y<=75)
		 {  option=1;  }
	      else if(x>=48 && x<=110 && y>=85 && y<=103)
		 {  option=2;  }
	      else if(x>=310 && x<=380 && y>=50 && y<=75 && fileexist==1 )
		       {  option=3;  }                //buy button ko lagi
	      else option=-1;
	     hidemouse();
	     switch(option)
	     {
		case 1: s.cart(); break;
		case 2: end3=0; remove("c:\\turboc3\\file\\cart.txt"); remove("c:\\turboc3\\file\\temp");  break;
		case 3: end3=0; buytoreceipt(); break;
		default:  callmouse();  break;
	     }
		  button= -1;
	     }
       }
       clrscr();
       cleardevice();
       alwaysdisplay();
       finn.close();
  }
void displayAddCart()
{
    while(!feof(p))
	{
	   outtextxy(40,155,"Name");
	   outtextxy(155,155,"Brand");
	   outtextxy(245,155,"Price");
	   outtextxy(300,155,"Quantity");
	   outtextxy(370,155,"  Rs. ");
	   outtextxy(x_cor,y_cor,r.goodname1);
	   outtextxy(x_cor+115,y_cor,r.brand1);
	   outtextxy(x_cor+205,y_cor,ltoa(r.price1,filestring,10));
	   outtextxy(x_cor+270,y_cor,itoa(r.quantity1,filestring,10));
	   outtextxy(x_cor+332,y_cor,ltoa(r.rs1,filestring,10));
	   total=total+r.rs1;
	   y_cor=y_cor+12;
	   fread(&r,sizeof(r),1,p);
	}
	gotoxy(55,6); printf("-Total Rs:%.1f",total);
}

void buytoreceipt()
  {
    clrscr();
    cleardevice();
    displayforever();
	p=fopen("c:\\turboc3\\file\\cart.txt","rb");
	fread(&r,sizeof(r),1,p);
	settextstyle(11,0,1);
	total=0;
	displayAddCart();
	gotoxy(55,7); printf("     Tax: %.1f",(total*13/100));
	total1=total*13/100+total;
	gotoxy(55,8); printf("   Total: %.1f",total1);
	line(420,110,600,110);
	rectangle(33,150,430,420);
	settextstyle(3,0,2);
	fclose(p);
   pp=fopen("c:\\turboc3\\file\\cusinfo.txt","ab");
   gotoxy(14,3); cout<<"--> Enter customer info ";
   gotoxy(12,4);  cout<<"Name :";  gets(c.cusname);
   gotoxy(8,5); cout<<"Phone no.:"; gets(c.phoneno);
   c.money=total1;
   /////////
   getdate(&today);
   c.yr=today.da_year;
   c.mo=today.da_mon;
   c.da=today.da_day;
   fwrite(&c,sizeof(c),1,pp);
   fclose(pp);

   outtextxy(70,90,"Enter any key to continue");
   getch();
   remove("c:\\turboc3\\file\\cart.txt");  //print it before delete
   remove("c:\\turboc3\\file\\record3");
   rename("c:\\turboc3\\file\\temp","c:\\turboc3\\file\\record3");
   hidemouse();
  }

void cusdetail()  //case 8..
{
  cleardevice();
  end4=1;
  pp=fopen("c:\\turboc3\\file\\cusinfo.txt","rb");
  fread(&c,sizeof(c),1,pp);
  display10:
  rectangle(25,100,590,410);
  displayforever();
  ycod=9,xcod=5;
  displaycount1=0;
  while(!feof(pp))
     {
	if(kbhit())  { getch();  }
	hidemouse();
	gotoxy(30,6); cout<<"Customer Information";
	gotoxy(5,8); cout<<"Customer";
	gotoxy(25,8); cout<<"Phone no.";
	gotoxy(45,8); cout<<"Paid Ammount";
	gotoxy(65,8); cout<<"Paid Date";
	gotoxy(xcod,ycod); cout<<c.cusname;
	gotoxy(xcod+20,ycod); cout<<c.phoneno;
	gotoxy(xcod+40,ycod); cout<<c.money;
	gotoxy(xcod+60,ycod); cout<<c.da<<"/"<<c.mo<<"/"<<c.yr;
	callmouse();
	fread(&c,sizeof(c),1,pp);
	ycod=ycod+1;
	displaycount1=displaycount1+1;
	if(displaycount1==17)
	  {
	    if(!feof(pp))
	    {  outtextxy(310,30,"    Press Enter for  NEXT page");
	       rectangle(485,35,545,55);
	    }
	    rectangle(47,35,112,53);
	    outtextxy(50,30," MENU ");
	    while(!kbhit())
	     {
	      getmousepos(&button,&x,&y);
	      if(button ==1)
		{
		  if(x>=485 && x<=545 && y>=35 && y<=55)
		    {  ungetch('\n');  }
		  else if(x>=47 && x<=112 && y>=35 && y<=53)
		    {  goto menu1;  }
		}
	     }
	     getch(); clrscr(); cleardevice();  goto display10;
	  }
     }
  fclose(pp);
		rectangle(47,35,112,53);
		outtextxy(50,30," MENU ");
		while(end4==1)
		{
			getmousepos(&button,&x,&y);
			if(button ==1)
			{
			 if(x>=47 && x<=112 && y>=35 && y<=53)
			  { end4=0;   }
			    else button=-1;
		}        }
  menu1:
  hidemouse();
  cleardevice();
  displayforever();
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
  end5=1;
  double totalfinc=0;
  pp=fopen("c:\\turboc3\\file\\cusinfo.txt","rb");
  fread(&c,sizeof(c),1,pp);
  display10:
  rectangle(25,100,590,340);
  displayforever();
  ycod=9,xcod=5;
  displaycount1=0;
  while(!feof(pp))
     {
	if(kbhit())  { getch();  }
	hidemouse();
	gotoxy(30,6); cout<<"Financial Report";
	gotoxy(5,8); cout<<"Customer";
	gotoxy(25,8); cout<<"Paid Ammount";
	gotoxy(45,8); cout<<"Paid Date";
	gotoxy(xcod,ycod); cout<<c.cusname;
	gotoxy(xcod+20,ycod); cout<<c.money;
	gotoxy(xcod+40,ycod); cout<<c.da<<"/"<<c.mo<<"/"<<c.yr;
	callmouse();
	totalfinc=totalfinc+c.money;
	fread(&c,sizeof(c),1,pp);
	ycod=ycod+1;
	displaycount1=displaycount1+1;
	if(displaycount1==12)
	  {
	    if(!feof(pp))
	    {  outtextxy(310,30,"    Press Enter for  NEXT page");
	       rectangle(485,35,545,55);
	    }
	    rectangle(47,35,112,53);
	    outtextxy(50,30," MENU ");
	    while(!kbhit())
	     {
	      getmousepos(&button,&x,&y);
	      if(button ==1)
		{
		  if(x>=485 && x<=545 && y>=35 && y<=55)
		    {  ungetch('\n');  }
		  else if(x>=47 && x<=112 && y>=35 && y<=53)
		    {  goto menu2;  }
		}
	     }
	     getch(); clrscr(); cleardevice();  goto display10;
	  }
     }
  fclose(pp);
	gotoxy(50,23); cout<<"Total : "<<totalfinc;
	gotoxy(50,24); printf("  Vat : %.1f",(totalfinc*13/100));
	gotoxy(50,25); printf("Profit: %.1f",(totalfinc*2/100));
	rectangle(47,35,112,53);
	outtextxy(50,30," MENU ");
	while(end5==1)
	{
		getmousepos(&button,&x,&y);
		if(button ==1)
		{
		 if(x>=47 && x<=112 && y>=35 && y<=53)
		  { end5=0;   }
		    else button=-1;
	}        }
  menu2:
  hidemouse();
  cleardevice();
  displayforever();
}

void checkexp()  //case 11..
{
  s.checkExpDate();
  cleardevice();
  alwaysdisplay();
  hidemouse();
  }

void additem()     //case 2..
  {
    end1=1;
    cleardevice();
    displayforever();
    getmousepos(&button,&x,&y);
     while(end1!=0)
       {//mouse lag then print menu here./////
	if(kbhit())  { getch();  }
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

void display()     //display all list   ...
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

void search()     //case 5...............
{
  clrscr();
  cleardevice();
  displayforever();
  int searchend=1;
  int searchchoice;
  while(searchend!=0)
  {
    if(kbhit()) { getch(); }
    gotoxy(9,4); cout<<"Search By. ";
    rectangle(50,70,130,95);
    outtextxy(50,70,"  Name ");
    rectangle(50,110,130,135);
    outtextxy(50,110,"  Code ");
    rectangle(50,150,130,175);
    outtextxy(50,150,"  Cancel  ");
    getmousepos(&button,&x,&y);
    if(button==1)
       {
	 if(x>=50 && x<=130 && y>=70 && y<=95)
	     {  searchchoice=1;   }
	 else if(x>=50 && x<=130 && y>=110 && y<=135)
	     {  searchchoice =2;   }
	 else if(x>=50 && x<=130 && y>=150 && y<=175)
	     {  searchchoice =3;   }
	 else  searchchoice=-1;
    switch(searchchoice)
	 {
	 case 1: hidemouse(); searchend=0; s.searchGoodDataByName(); break;
	 case 2: hidemouse(); searchend=0; s.searchGoodDataByCode(); break;
	 case 3: searchend=0; delay(200); hidemouse(); break;
	 default: break;
	 }
	 button=-1;
	 }
      }
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
   outtextxy(50,50,"Have a Nice Day"); delay(600);
   cleardevice();
   closegraph();
   end=0;
}

long input(int x_cord,int y_cord,char ch_cord[30])
{
  long aaa;
  int flag3;
  char chhh[13];
  again:
  flag3=1;
  gotoxy(x_cord,y_cord);
  cout<<ch_cord;
  gets(chhh);
  if(chhh[0]==NULL)
  {  flag3=0;  }
  for(int i=0; chhh[i]!='\0';i++)
    {
      if(!isdigit(chhh[i]))
	{ flag3=0; break;  }
    }
  if(flag3==0)
  {
    gotoxy(x_cord+16,y_cord); cout<<"           ";
    gotoxy(x_cord,y_cord+1); cout<<"->Number only";
    goto again;
  }
  aaa=atol(chhh);
  return(aaa);
}

void userpass::checkpass()      //case 12...
{
   cleardevice();
   displayforever();
   ifstream fin;
   ofstream fout;
   char inpassword[8];
   int flagpass=0, flagpass1=0;
   fin.open("c:\\turboc3\\file\\log",ios::in | ios::binary);
       if(!fin)
	   {
		flagpass1=1;
	   }
       else
	   {
		fin.read((char *)this,sizeof(* this));
		gotoxy(10,14); cout<<"User Name";
		gotoxy(25,14); cout<<"Address";
		gotoxy(40,14); cout<<"Phone no";
		gotoxy(55,14); cout<<"Password";
		rectangle(50,200,550,400);
		int yb=16;
		while(!fin.eof())
		{
		  gotoxy(10,yb); cout<<USER;
		  gotoxy(25,yb); cout<<ADDRESS;
		  gotoxy(40,yb); cout<<PHONE;
		  gotoxy(55,yb); cout<<"********";
		  flagpass++;
		  yb++;
		  fin.read((char *)this,sizeof(* this));
		}
		fin.close();
	   }
	if(flagpass>5 && flagpass1==0)
	{
	gotoxy(10,4); cout<<"-> User are more than 5 ";
	}
	else
	{
	   fout.open("c:\\turboc3\\file\\log",ios::app | ios::binary);
	   gotoxy(10,3); cout<<"-> Enter New user information";
	   gotoxy(10,4); cout<<"    Name:"; gets(USER);
	   gotoxy(10,5); cout<<" Address:"; gets(ADDRESS);
	   gotoxy(10,6); cout<<"   Phone:"; gets(PHONE);
	   gotoxy(6,7); cout<<"8 digit Password:"; gets(inpassword);
	   for(int v=0;v<8;v++)
	   {
		PASSWORD[v]=inpassword[v]+5;
	   }
	   fout.write((char *)this,sizeof(*this));
	}
   fout.close();
   rectangle(460,35,545,60);
   outtextxy(310,30,"  Press Enter to continue.");
   while(!kbhit())
   { getmousepos(&button,&x,&y);
      if(button==1)
      {if(x>=460 && x<=545 && y>=35 && y<=60){ungetch('\n'); hidemouse();}}}
   getch();
   cleardevice();
   alwaysdisplay();
}

int userpass::loginpass(char name_a[20],char pass_a[8])
{
  char pass_b[8];
  int v;
  int return_login=0;
  ifstream fin;
  fin.open("c:\\turboc3\\file\\log",ios::in |ios::binary);
  if(!fin) { return_login=0; }
  else {
      fin.read((char *)this,sizeof(* this));
      while(!fin.eof())
	{
	  for(v=0;v<8;v++)
	   {
	      pass_b[v]=PASSWORD[v]-5;
	   }
	  // cout<<name_a<<"\t"<<USER;
	  // getch();
	  if(strcmp(name_a,USER)==0)
	     {
	      if(pass_a[0]==pass_b[0] && pass_a[1]==pass_b[1] && pass_a[2]==pass_b[2] && pass_a[3]==pass_b[3] && pass_a[4]==pass_b[4] && pass_a[5]==pass_b[5] && pass_a[6]==pass_b[6] && pass_a[7]==pass_b[7] )
		{ return_login=1;  }
	     }
	  fin.read((char *)this,sizeof(* this));
	}
      fin.close();
     }
  return(return_login);
}
