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
#include<dir.h>
#define bkclr 1

union REGS in, out;
struct date today;
struct time t;
char string[25];
char charnotice[75],charnotice1[75];
int scrollx,scrollx1;
int ucount,iich;//esc to menu
int cat;//choseCategoty
int adminread;
int end=1,enduser=1,end1=1,end2=1,end3=1,end4=1,end5=1,logincount=0,passcode1,passcode2,passend=1;
int button,x,y,option,ooption,x_co,y_co,displaycount,displaycount1,x_cor,y_cor;
char name[20],password[20],pstring[20],filestring[30];
int sn_temp,itemcode,itemquantity,flag,fileexist;
int ycod,xcod;
double total,total1;
int return_pass;
int return_login=0;
char printname[15];
void login();
void hidemouse();
int callmouse();
void callprogramend();
void displayforever();
void alwaysdisplay();
void useralwaysdisplay();
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
void finance1(int,int,int);
void financeMonthy();
void finance2(int,int,int);
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
  char goodname1[20],vendor1[20];
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
  void deletepass();
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
   char goodname[20],vendor[20],category[15];
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
 void vendorDetail();
 void choseCategory();
 void notice();
 };
void Store::copyfile()
{
      ifstream fin;
      ofstream fout;
      fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
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

void Store::vendorDetail()
{
  cleardevice();
  end4=1;
  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
  fin.read((char *)this,sizeof(*this));
  display100:
  rectangle(25,100,590,410);
  displayforever();
  ycod=9,xcod=5;
  displaycount1=0;
  while(!fin.eof())
     {
	if(kbhit())  { getch();  }
	hidemouse();
	gotoxy(30,6); cout<<" Vendor Information";
	gotoxy(5,8); cout<<"  Vendor";
	gotoxy(25,8); cout<<"Product";
	gotoxy(45,8); cout<<"Quantity";
	gotoxy(65,8); cout<<"Amount";
	gotoxy(xcod,ycod); cout<<vendor;
	gotoxy(xcod+20,ycod); cout<<goodname;
	gotoxy(xcod+40,ycod); cout<<quantity;
	gotoxy(xcod+60,ycod); cout<<price;
	callmouse();
   fin.read((char *)this,sizeof(*this));
	ycod=ycod+1;
	displaycount1=displaycount1+1;
	if(displaycount1==17)
	  {
	    if(!fin.eof())
	    {  outtextxy(310,30,"                     NEXT");
	       rectangle(485,35,545,55);
	    }
	    rectangle(47,35,112,53);
	    outtextxy(50,30," BACK ");
	    while(!kbhit())
	     {
	      getmousepos(&button,&x,&y);
	      if(button ==1)
		{
		  if(x>=485 && x<=545 && y>=35 && y<=55)
		    {  ungetch('\n');  }
		  else if(x>=47 && x<=112 && y>=35 && y<=53)
		    {  goto menu100;  }
		}
	     }
	     getch(); clrscr(); cleardevice();  goto display100;
	  }
     }
  fin.close();
		rectangle(47,35,112,53);
		outtextxy(50,30," BACK ");
		while(end4==1)
		{
			getmousepos(&button,&x,&y);
			if(button ==1)
			{
			 if(x>=47 && x<=112 && y>=35 && y<=53)
			  { end4=0;   }
			    else button=-1;
		}        }
  menu100:
  hidemouse();
  cleardevice();
  displayforever();
}

void Store::cart() //cart ma item rakhna
 {
    flag=0;
    clrscr();
    cleardevice();
    displayforever();
    gotoxy(12,1);
    choseCategory();
    itemcode=input(12,6,"Enter item code:");
    fstream file;
    file.open("c:\\turboc3\\file\\temp",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    for(int IJ=1;IJ<10;IJ++)
    {
      gotoxy(52,5+IJ); cout<<"                          ";
    }
    file.read((char *)this,sizeof(*this));
    while(!file.eof())
    {
      if(itemcode==sn)
	{
	  outtextxy(35,196,"Note:");
	  rectangle(35,220,607,420);
	  gotoxy(52,6);  cout<<"Item info";
	  gotoxy(52,7);  cout<<"Item Name:";  cout<<goodname;
	  gotoxy(52,8);  cout<<"   Vendor:";  cout<<vendor;
	  gotoxy(52,9);  cout<<"Serial no:";  cout<<sn;
	  gotoxy(52,10);  cout<<"    price:"; cout<<price;
	  gotoxy(52,11);  cout<<" Quantity:"; cout<<quantity;
	  gotoxy(52,12); cout<<"     Date:"; cout<<expdated; cout<<"/"<<expdatem; cout<<"/"<<expdatey;
	  line(400,95,607,95);// for before record ko lagi rectangle
	  rectangle(400,80,607,205);
	  outtextxy(50,230,"Record found");
	  rectangle(35,220,607,420);
	 itemquantity=input(12,7,">Enter quantity:");// func for integer
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
	    outtextxy(280,230,"-> Pay Rs.:");
	    outtextxy(405,230,ltoa(itemquantity*price,filestring,10));
	    /////////////////
	    p=fopen("c:\\turboc3\\file\\cart.exe","ab");
	    strcpy(r.goodname1,goodname);
	    strcpy(r.vendor1,vendor);
	    r.price1=price;
	    r.quantity1=itemquantity;
	    r.rs1=itemquantity*price;
	    fwrite(&r,sizeof(r),1,p);
	    fclose(p);
	    quantity=quantity-itemquantity;
	    file.seekp(file.tellp()-sizeof(*this));
	    file.write((char *)this,sizeof(*this));
	    outtextxy(50,260,"Enter any key to continue");
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
	   delay(400);
	  }
	  file.close();
	  hidemouse();
	  clrscr();
	  cleardevice();
 }

void Store::getGoodData()
	 {
	   clrscr();
	   cleardevice();
	   displayforever();
	   hidemouse();
	   rectangle(85,43,400,63);
	   rectangle(85,63,400,160);
	   outtextxy(128,41,"Enter Item Information.");
	   outtextxy(35,196,"Note:");
	   rectangle(35,220,605,420);
	ifstream fin;
	fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
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
	   if(option==1)
	     { strcpy(category,"biscuits"); }
	   if(option==3)
	     { strcpy(category,"chocolate"); }
	   if(option==4)
	     { strcpy(category,"drinks"); }
	   if(option==5)
	     { strcpy(category,"noodles"); }
	   if(option==6)
	     { strcpy(category,"rice"); }
	   if(option==7)
	     { strcpy(category,"spices"); }

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
	   getdatavendor:
	   gotoxy(55,5); cout<<"          ";
	   gotoxy(18,6); cout<<"   Vendor:";
	   gets(vendor);
	   if(vendor[0]=='\0')
	   {
	     gotoxy(55,4); cout<<"Notice";
	     gotoxy(54,6); cout<<"Enter Vendor";
	     goto getdatavendor;
	   }
	   gotoxy(54,6); cout<<"            ";
	   price=input(12,7,"          Price:");
	   quantity=input(12,8,"       Quantity:");
	   getdate(&today);
	   expdated=today.da_day;
	   expdatey=today.da_year;
	   expdatem=today.da_mon+6;
	   if(expdatem>=13){ expdatem=expdatem-12; expdatey=expdatey+1; }
	   ofstream fout;
	   fout.open("c:\\turboc3\\file\\record3.exe",ios::app|ios::binary);
	   fout.write((char *)this,sizeof(*this));
	   fout.close();
	   outtextxy(50,230,"Item Added");
	   outtextxy(50,280,"Enter any key to continue");
	   getch();
	   cleardevice();
	 }

 void Store::choseCategory()
{
   callmouse();
   int iy=6;
   cat=0;
   settextstyle(3,0,1);
   rectangle(200,50,270,72);
   outtextxy(203,47,"Drinks");
   rectangle(270,50,340,72);
   outtextxy(273,47,"Noodles");
   rectangle(340,50,400,72);
   outtextxy(343,47,"Rice");
   rectangle(400,50,480,72);
   outtextxy(403,47,"Spices");
   getmousepos(&button,&x,&y);
     while(cat==0)
     {
       getmousepos(&button,&x,&y);
	rectangle(40,50,110,72);
	outtextxy(43,47,"Biscuits");
	rectangle(110,50,200,72);
	outtextxy(113,47,"Chocolate");
       if(button==1)
	{
	 if(x>=40 && x<=110 && y>=50 && y<=72)
		{ cat=1; }
	 else if(x>=110 && x<=200 && y>=50 && y<=72)
		{ cat =2;}
	 else if(x>=200 && x<=270 && y>=50 && y<=72)
		{ cat =3;}
	 else if(x>=270 && x<=340 && y>=50 && y<=72)
		{ cat=4;}
	 else if(x>=340 && x<=400 && y>=50 && y<=72)
		{ cat=5;}
	 else if(x>=400 && x<=480 && y>=50 && y<=72)
		{ cat=6;}
	 else   { button= -1; }
	 }
	      if(kbhit())
	       {
		 iich=getche();
		   if(iich==27)
		      { hidemouse(); cleardevice();
			if(return_pass==1)
				{ remove("c:\\turboc3\\file\\cart.exe"); remove("c:\\turboc3\\file\\temp");
				  useralwaysdisplay();
				}
			else
				{  remove("c:\\turboc3\\file\\cart.exe"); remove("c:\\turboc3\\file\\temp");
				   alwaysdisplay();
				}
		      }
		   else
		   {  cat=7;
		      rectangle(40,50,110,72);
		      outtextxy(43,47,"Biscuits");
		      rectangle(110,50,200,72);
		      outtextxy(113,47,"Chocolate");
		   }

	       }
   }
	   switch(cat)
	     {
		case 1: callmouse(); cat='b'; break;
		case 2: callmouse(); cat='c'; break;
		case 3: callmouse(); cat='d'; break;
		case 4: callmouse(); cat='n'; break;
		case 5: callmouse(); cat='r'; break;
		case 6: callmouse(); cat='s'; break;
		default: break;
	     }
	    ifstream fin;
	    fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
	    fin.read((char *)this,sizeof(*this));
	    while(!fin.eof())
		{
		  if(cat==category[0])
		  {
		    gotoxy(7,6); cout<<"         ";
		    gotoxy(7,7); cout<<"           ";
		    gotoxy(57,6); cout<<"Code";
		    gotoxy(64,6); cout<<"Name";
		    gotoxy(57,iy+2); cout<<sn;
		    gotoxy(54+10,iy+2); cout<<goodname;
		    iy++;
		  }
		  fin.read((char *)this,sizeof(*this));
		}
		fin.close();
}

void Store::editGoodData()
	{
	  flag=0;
	  int INTTT,qty;
	  gotoxy(5,3); cout<<"Enter a detail to edit goods information";
	  choseCategory();
	  INTTT=input(9,6,"       Code no.:");
	  fstream file;
	  file.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::out|ios::ate|ios::binary);
	  file.seekg(0);
	  file.read((char *)this,sizeof(*this));
	  while(!file.eof())
	    {
	      if(INTTT==sn)
		 {
		  hidemouse();
		  gotoxy(8,9); cout<<"Previous record";
		  gotoxy(8,10); cout<<" Item Name:"<<goodname;
		  gotoxy(8,11); cout<<"   price--:"<<price;
		  gotoxy(8,12);cout<<" Quantity-:"<<quantity;
		  line(48,143,220,143);
		  rectangle(48,125,220,200);
			   price=input(5,14," Enter price:");
			   qty=input(5,15,"Add quantity:");
			   quantity=quantity+qty;
			   getdate(&today);
			   expdated=today.da_day;
			   expdatey=today.da_year;
			   expdatem=today.da_mon+6;
	   if(expdatem>=13){ expdatem=expdatem-12; expdatey=expdatey+1; }
			  file.seekp(file.tellp()-sizeof(*this));
			  file.write((char *)this,sizeof(*this));
			  flag=1;
			outtextxy(50,400,"Updated || Press Enter");
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
	  int INT;
	  cleardevice();
	  displayforever();
	  gotoxy(6,3); cout<<"Enter information to delete item\n";
	  choseCategory();
	  INT=input(4,6,"      Item code:");
	  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
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
		  fout.open("c:\\turboc3\\file\\temprecord3.exe",ios::out|ios::binary);
		  ifstream fin;
		  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
		  fin.read((char *)this,sizeof(*this));
		  while(!fin.eof())
			{
			  if(INT==sn)
				{
					hidemouse();
					outtextxy(35,196,"Note:");
					rectangle(35,220,305,420);
					outtextxy(50,230,"Item found");
				  outtextxy(50,230,"Item found     ...Deleting....");
				  displayforever();
				}
			  else
				{
				  fout.write((char *)this,sizeof(*this));
				}
			  fin.read((char *)this,sizeof(*this));
			}
	  delay(300);
	  setcolor(bkclr);
	  outtextxy(50,230,"Item found     ...Deleting....");
	  setcolor(WHITE);
	  outtextxy(50,230,"Item found     ...Deleted.....");
	  outtextxy(50,260,"Enter any key to continue");
	  fin.close();
	  fout.close();
	  remove("c:\\turboc3\\file\\record3.exe");
	  rename("c:\\turboc3\\file\\temprecord3.exe","c:\\turboc3\\file\\record3.exe");
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
	  gotoxy(18,3);  cout<<"Enter a Good information to search";
	  gotoxy(18,4);  cout<<"Name:";
	  gets(ch);
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
	  fin.read((char *)this,sizeof(*this));
	  while(!fin.eof())
		{
		  if(!strcmp(ch,goodname))
		  {
		  outtextxy(35,196,"Note:");
		  rectangle(35,220,605,420);
		  gotoxy(50,5); cout<<"Previous record";
		  gotoxy(50,6); cout<<" Item Name:"<<goodname;
		  gotoxy(50,7); cout<<"Vendor :"<<vendor;
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
		   delay(800);
		}
	  fin.close();
	  hidemouse();
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
	  choseCategory();
	  INTT=input(4,6,"             Code:");
	  for(int II=1;II<10;II++)
	  { gotoxy(52,5+II); cout<<"                        ";  }
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
	  fin.read((char *)this,sizeof(*this));
	  while(!fin.eof())
		{
		  if(INTT==sn)
		  {
		  outtextxy(35,196,"Note:");
		  rectangle(35,220,605,420);
		  gotoxy(52,6); cout<<"  Item Detail";
		  gotoxy(52,7); cout<<" Item Name:"<<goodname;
		  gotoxy(52,8); cout<<"Vendor :"<<vendor;
		  gotoxy(52,9); cout<<" Serail no:"<<sn;
		  gotoxy(52,10); cout<<"   price--:"<<price;
		  gotoxy(52,11);cout<<" Quantity-:"<<quantity;
		  gotoxy(52,12);cout<<" Date-:"<<expdated<<"/"<<expdatem<<"/"<<expdatey;
		  line(400,95,595,95);
		  rectangle(400,80,595,200);
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
		   delay(800);
		}
	  fin.close();
	  hidemouse();
	  cleardevice();
	  displayforever();
	}

void Store::displayGoodData()
	{
	  ifstream fin;
	  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
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
	  outtextxy(389,85,"Vendor");
	  outtextxy(530,85,"Category");
	  setcolor(WHITE);
	  settextstyle(3,0,1);
	  rectangle(35,75,605,420);
		  settextstyle(11,0,1);
		  outtextxy(x_co,y_co,itoa(sn,filestring,10));
		  outtextxy(x_co+50,y_co,goodname);
		  outtextxy(x_co+190,y_co,itoa(quantity,filestring,10));
		  outtextxy(x_co+270,y_co,ltoa(price,filestring,10));
		  outtextxy(x_co+350,y_co,vendor);
		  outtextxy(x_co+490,y_co,category);
		 // outtextxy(x_co+460,y_co,itoa(expdated,filestring,10));
		 // outtextxy(x_co+470,y_co,"/");
		 // outtextxy(x_co+480,y_co,itoa(expdatem,filestring,10));
		 // outtextxy(x_co+490,y_co,"/");
		 // outtextxy(x_co+500,y_co,itoa(expdatey,filestring,10));
		  y_co=y_co+11;
		  rectangle(35,75,605,420);
		  settextstyle(3,0,1);
		  displaycount=displaycount+1;
		  callmouse();
	   fin.read((char *)this,sizeof(*this));
		if(displaycount==29)
		{
		 if(!fin.eof())
		 { outtextxy(310,30,"                    NEXT");
		   rectangle(485,35,545,55);
		 }
		 rectangle(47,35,112,53);
		 outtextxy(50,30," BACK ");
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
	  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
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
	  outtextxy(389,85,"Vendor");
	  outtextxy(495,85,"Exp.date");
	  setcolor(WHITE);
	  settextstyle(3,0,1);
	  rectangle(35,75,605,420);
		  settextstyle(11,0,1);
		   getdate(&today);
	       if(today.da_day>=expdated && today.da_mon>=expdatem && today.da_year>=expdatey )
		  {
		    outtextxy(x_co,y_co,itoa(sn,filestring,10));
		    outtextxy(x_co+50,y_co,goodname);
		    outtextxy(x_co+190,y_co,itoa(quantity,filestring,10));
		    outtextxy(x_co+270,y_co,ltoa(price,filestring,10));
		    outtextxy(x_co+350,y_co,vendor);
		    outtextxy(x_co+460,y_co,itoa(expdated,filestring,10));
		    outtextxy(x_co+470,y_co,"/");
		    outtextxy(x_co+480,y_co,itoa(expdatem,filestring,10));
		    outtextxy(x_co+490,y_co,"/");
		    outtextxy(x_co+500,y_co,itoa(expdatey,filestring,10));
		    y_co=y_co+11;
		    rectangle(35,75,605,420);
		    settextstyle(3,0,1);
		    displaycount=displaycount+1;
		  }
		  callmouse();
	   fin.read((char *)this,sizeof(*this));
		if(displaycount==29)
		{
		 if(!fin.eof())
		 { outtextxy(310,30,"                  NEXT");
		   rectangle(485,35,545,55);
		 }
		 rectangle(47,35,112,53);
		 outtextxy(50,30," BACK ");
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
  settextstyle(3,0,1);
  outtextxy(50,30," BACK ");
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
   settextstyle(3,0,1);
   if(t.ti_hour>12)
   {
     t.ti_hour=t.ti_hour-12;
     outtextxy(348,432,"pm");
   }
   else
   {  outtextxy(348,432,"am");  }
      outtextxy(280,432,itoa(t.ti_hour,string,10));
      outtextxy(317,432,itoa(t.ti_min,string,10));
 //   outtextxy(352,432,itoa(t.ti_sec,string,10));
      outtextxy(225,432,"Time:");
      outtextxy(280,432,"   :     ");
   if(t.ti_sec==0)
   {
     gettime(&t);
     settextstyle(3,0,1);
     setcolor(WHITE);
     setfillstyle(SOLID_FILL,bkclr);
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
   settextstyle(11,0,1);
   outtextxy(525,20,itoa(today.da_day,string,10));
   outtextxy(556,20,itoa(today.da_mon,string,10));
   outtextxy(583,20,itoa(today.da_year,string,10));
   outtextxy(477,20,"         /  /");
   settextstyle(3,0,1);
}

void storename()     //store name print garna lai..
{
   setcolor(14);
   settextstyle(8,0,2);//2,0,6 //6,0,1 //8,0,1
   //setfillstyle(1,9);
   //bar(0,0,640,29);
  //bar(0,0,19,480);
  // bar(621,30,640,480);
  //bar(0,434,640,480);
   outtextxy(250,2,"Libali Store");

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

void Store::notice()
{
  for(int tin=0;tin<69;tin++)
  {  charnotice[tin]=NULL;  charnotice1[tin]=NULL;  }
  ifstream fin;
  fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
  if(!fin) //record3 file xena vane, create garxa
      { ofstream fincreate;
	fincreate.open("c:\\turboc3\\file\\record3.exe",ios::app| ios::binary);
	fincreate.close();
	fin.close();
	fin.open("c:\\turboc3\\file\\record3.exe",ios::in|ios::binary);
  }
  fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
       {
	       if(quantity<=20)
		  {
		  if(strlen(charnotice)<=68)
		    {
		      strcat(charnotice,goodname);
		      strcat(charnotice,"(");
		      strcat(charnotice,itoa(sn,string,10));
		      strcat(charnotice,") is ");
		      strcat(charnotice,itoa(quantity,string,10));
		      strcat(charnotice,"left. ");
		    }
	     else if(strlen(charnotice1)<=68)
		    {
		      strcat(charnotice1,goodname);
		      strcat(charnotice1,"(");
		      strcat(charnotice1,itoa(sn,string,10));
		      strcat(charnotice1,") is ");
		      strcat(charnotice1,itoa(quantity,string,10));
		      strcat(charnotice1,"left. ");
		    }
		  }
	  fin.read((char *)this,sizeof(*this));
       }
    fin.close();
}
void rectangle1()
{
   setcolor(3);
   rectangle(118,64,230,84);
   rectangle(118,94,230,113);
   rectangle(118,124,230,145);
   rectangle(118,154,230,176);
   rectangle(118,184,230,205);
   rectangle(118,214,230,235);
   rectangle(118,243,230,264);
	rectangle(295,64,450,84);
	rectangle(295,94,450,113);
	rectangle(295,124,450,145);
	rectangle(295,154,450,176);
	rectangle(295,184,450,205);
	rectangle(295,214,450,238);
	setcolor(WHITE);
}

void rectangle2()
{
   setcolor(3);
   rectangle(117,63,231,85);
   rectangle(117,93,231,114);
   rectangle(117,123,231,146);
   rectangle(117,153,231,177);
   rectangle(117,183,231,206);
   rectangle(117,213,231,236);
   rectangle(117,242,231,265);
	rectangle(294,63,451,85);
	rectangle(294,93,451,114);
	rectangle(294,123,451,146);
	rectangle(294,153,451,177);
	rectangle(294,183,451,206);
	rectangle(294,213,451,239);
	setcolor(WHITE);
}

void menu()       //main menu..
{
   if(return_pass==2)
   {
     settextstyle(11,0,1);
     outtextxy(30,35,"Admin:");
     outtextxy(80,35,printname);
     settextstyle(3,0,1);
   }
   rectangle1();
   rectangle2();
   setcolor(WHITE);
   settextstyle(3,0,1);
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
	outtextxy(302,210,"Delete User");
}

void usermenu()       //user menu..
{
   if(return_pass==1)
   {
     settextstyle(11,0,1);
     outtextxy(30,35,"User:");
     outtextxy(70,35,printname);
     settextstyle(3,0,1);
   }
   rectangle(118,64,230,84);
   rectangle(118,94,230,113);
   rectangle(118,124,230,145);
   rectangle(118,154,230,176);
   rectangle(118,184,230,205);
   rectangle(118,214,230,235);
	rectangle(295,64,450,84);
	rectangle(295,94,450,113);
   setcolor(WHITE);
   settextstyle(3,0,1);
   outtextxy(95,60,"   Calculate bill");
   outtextxy(95,90,"   Add item");
   outtextxy(95,120,"   Edit item");
   outtextxy(95,150,"   Display All");
   outtextxy(95,180,"   Search item");
   outtextxy(95,210,"   Exit");
	outtextxy(302,60,"Customer Detail");
	outtextxy(302,90,"Check Expiration");
}

void main()
{
   //importbackup();
   mkdir("c:\\turboc3\\file");
   return_pass=0;
   int gd=DETECT, gm,status;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
      ifstream finlogin;
      finlogin.open("c:\\turboc3\\file\\log.exe",ios::in | ios::binary);
       if(!finlogin)
	   {
		finlogin.close();  u.checkpass();  login();
	   }
       else
	  // {    finlogin.close();  login();   }
   alwaysdisplay();
   getch();
}

void passwordMatch()  //input
{
  ucount=0;
  while(ucount<8)
  {
      if(password[ucount]==10)  { ucount=15;}
      else
	 {   password[ucount]=getch();
	 }
	    if(password[ucount]==8)
	      {
	       if(!ucount<=0)
		 {
		   gotoxy(38+ucount,13); cout<<" \b";
		   ucount--;
		 }
	      }
	    else if(password[ucount]==13)  break;
	    else
	      {  gotoxy(39+ucount,13); cout<<"*"; ucount++;  }
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
  if(logincount==3)
   {
   displayforever();
   outtextxy(200,70,"Incorrect password Attempted"); delay(500);
   callprogramend();
   }
   else
   {
  clrscr();   /// same place bata input lina lai
  cleardevice();
  displayforever();
  outtextxy(400,30,"Password Attempt=");
  outtextxy(40,30,"..LOGIN PAGE..");
  rectangle(200,142,440,222);
  outtextxy(570,30,itoa(logincount,pstring,10));
  gotoxy(28,11);cout<<" Username: ";
  gotoxy(28,8); cout<<"Enter Username";
  rectangle(300,155,430,177);
  loginname:
	   gotoxy(39,11);
	   gets(name);
	   if(name[0]=='\0')
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Name cant be empty.";
	      gotoxy(39,11); cout<<"            ";
	      goto loginname;
	   }
	   else if(isdigit(name[0]))
	   {
	     gotoxy(28,15); cout<<"Notice:";
	     gotoxy(35,15); cout<<"Name cant be number.";
	     gotoxy(39,11); cout<<"             ";
	     goto loginname;
	   }
	   gotoxy(28,15); cout<<"                           ";
	   gotoxy(28,13); cout<<" Password:";
	   rectangle(300,188,430,210);
	   gotoxy(28,8); cout<<"Enter password";
  passwordMatch();
  passcode1= strcmp(password,"password");
  passcode2= strcmp(name,"rabin");
  return_pass=u.loginpass(name,password);
  if((passcode1==0 && passcode2==0) || return_pass==1 || return_login==2)
    {
    cleardevice();
    if(return_pass==1)
      {
	strcpy(printname,name);
	useralwaysdisplay();
      }
   else
   {   if(return_pass==2) { strcpy(printname,name); }  alwaysdisplay();  }
    }
  else
   {
    outtextxy(200,70,"Incorrect password Attempted"); delay(500);
    logincount++;
    cleardevice();
    login();
   }
   }
}

void displayforever()     // store name, date, mouse rectriction and rectangle....print garna..
{
  setbkcolor(bkclr);
  rectangle(20,30,620,433);
  callmouse();
  restrictmouseptr(20,30,620,433);
  storename();
  date();
}

void alwaysdisplay() // display forever + menu..
{
  settextstyle(11,0,1);
  outtextxy(10,440,"  Notice:");
  settextstyle(3,0,1);
  s.notice();//notice update
  scrollx=600,scrollx1=600;
  callmouse();
  setbkcolor(bkclr);
  rectangle(20,30,620,433);
  restrictmouseptr(20,30,620,433);
  storename();
  date();
  callmouse();
  getmousepos(&button,&x,&y);
  hidemouse();
  rectangle1();
  rectangle2();
  callmouse();
  while(end!=0)
  {
    if(scrollx>0 )
    {
      settextstyle(11,0,1);
      setfillstyle(1,bkclr);
      bar(0,457,640,467);
      outtextxy(scrollx,458,charnotice);
      settextstyle(3,0,1);
      scrollx--;
      scrollx1=600;
    }
   else
      {
	if(scrollx==0 && strlen(charnotice1)!=0)
	   {
		settextstyle(11,0,1);
		setfillstyle(1,bkclr);
		bar(0,457,640,480);
		outtextxy(scrollx1,458,charnotice1);
		settextstyle(3,0,1);
		scrollx1--;
		if(scrollx1==0)
		  {
		    scrollx=600;
		  }
	   }
	else scrollx=600;
      }

   if(kbhit())
	   {
	     iich=getche();
	     if(iich==27)
	       {  cleardevice(); callprogramend(); callmouse();  }
	   }
    if(kbhit()) { getch(); } // unwanted thau ma keyboard press
   menu();                  // garyo vane ignore
   getmousepos(&button,&x,&y);
    if(button == 1)
     {
       if(x>=118 && x<=230 && y>=64 && y<=84)
	  {  option=1;  }
       else if(x>=118 && x<=230 && y>=94 && y<=113)
	  {  option=2; }
       else if(x>=118 && x<=230 && y>=124 && y<=145)
	  {  option=3;  }
	else if(x>=118 && x<=230 && y>=154 && y<=176)
	  {  option=4;  }
	else if(x>=118 && x<=230 && y>=184 && y<=205)
	  {  option=5;  }
	else if(x>=118 && x<=230 && y>=214 && y<=235)
	  {  option=6;  }
	else if(x>=118 && x<=230 && y>=243 && y<=264)
	  {  option=7;  }
	else if(x>=295 && x<=450 && y>=64 && y<=84)
	  {  option=8;  }
	else if(x>=295 && x<=450 && y>=94 && y<=113)
	  {  option=9;  }
	  else if(x>=295 && x<=450 && y>=124 && y<=145)
	  {  option=10;  }
	  else if(x>=295 && x<=450 && y>=154 && y<=176)
	  {  option=11;  }
	  else if(x>=295 && x<=450 && y>=184 && y<=205)
	  {  option=12;  }
	  else if (x>=295 && x<=450 && y>=214 && y<=238)
	  {  option=13;  }

      else option=-1;
      hidemouse();
       switch(option)
       {
       case 1: calculatebill(); break;
       case 2: delay(150); additem(); break;
       case 3: edititem(); break;
       case 4: display(); break;
       case 5: search(); break;
       case 6: deelete(); break;
       case 8: cusdetail(); break;
       case 9: vendetail(); break;
       case 10: hidemouse(); finance(); break;
       case 11: checkexp(); break;
       case 12: u.checkpass(); break;
       case 13: u.deletepass(); break;
       case 7: exxit();
       default:  callmouse();  break;
      }

       button= -1;
     }
       //	time();
   }
   cleardevice();
}

void useralwaysdisplay() // display user forever + menu..
{
  settextstyle(11,0,1);
  outtextxy(10,440,"  Notice:");
  settextstyle(3,0,1);
  s.notice();
  scrollx=600,scrollx1=600;
  setbkcolor(bkclr);
  rectangle(20,30,620,433);
  restrictmouseptr(20,30,620,433);
  storename();
  date();
  callmouse();
  getmousepos(&button,&x,&y);
  while(enduser!=0)
  {
   if(scrollx>0)
    {
      settextstyle(11,0,1);
      setfillstyle(1,bkclr);
      bar(0,457,640,480);
      outtextxy(scrollx,458,charnotice);
      settextstyle(3,0,1);
      scrollx--;
      scrollx1=600;
    }
   else
      {
	if(scrollx==0 && strlen(charnotice1)!=0)
	   {
		settextstyle(11,0,1);
		setfillstyle(1,bkclr);
		bar(0,457,640,480);
		outtextxy(scrollx1,458,charnotice1);
		settextstyle(3,0,1);
		scrollx1--;
		if(scrollx1==0)
		  {
		    scrollx=600;
		  }
	   }
	else scrollx=600;
      }
   if(kbhit())
	   {
	     iich=getche();
	     if(iich==27)
	       {  cleardevice(); callprogramend(); callmouse();  }
	   }
   if(kbhit()) { getch(); }
   usermenu();
   getmousepos(&button,&x,&y);
    if(button == 1)
     {
       if(x>=118 && x<=230 && y>=64 && y<=84)
	  {  ooption=1;  }
       else if(x>=118 && x<=230 && y>=94 && y<=113)
	  {  ooption=2; }
       else if(x>=118 && x<=230 && y>=124 && y<=145)
	  {  ooption=3;  }
	else if(x>=118 && x<=230 && y>=154 && y<=176)
	  {  ooption=4;  }
	else if(x>=118 && x<=230 && y>=184 && y<=205)
	  {  ooption=5;  }
	else if(x>=118 && x<=230 && y>=214 && y<=235)
	  {  ooption=6;  }
	else if(x>=295 && x<=450 && y>=64 && y<=84)
	  {  ooption=7;  }
	  else if(x>=295 && x<=450 && y>=94 && y<=113)
	  {  ooption=8;  }

      else ooption=-1;
      hidemouse();
       switch(ooption)
       {
       case 1: calculatebill(); break;
       case 2: delay(150); additem(); break;
       case 3: edititem(); break;
       case 4: display(); break;
       case 5: search(); break;
       case 7: cusdetail(); break;
       case 8: checkexp(); break;
       case 6: exxit();
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
    delay(150);
	ifstream finn;
     while(end3!=0)
     {
	 if(kbhit())  {  getch();   }
	     rectangle(20,30,620,433);
	     restrictmouseptr(20,30,620,433);
	     storename();
	     date();
       finn.open("c:\\turboc3\\file\\cart.exe",ios::in);
	if(finn)
	  {
	    fileexist=1;
	  }
	if(fileexist==1)
	  {
	    rectangle(310,50,380,75);
	    outtextxy(330,50,"BUY");
	  }
	p=fopen("c:\\turboc3\\file\\cart.exe","rb");
	fread(&r,sizeof(r),1,p);
	x_cor=40; y_cor=170;
	total=0;
	settextstyle(11,0,1);
    displayAddCart();  // cart ma vako items print garna
	fclose(p);
	settextstyle(3,0,1);
	rectangle(48,55,165,75);
	rectangle(47,85,110,103);
	callmouse();
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
		case 1: delay(150); s.cart(); break;
		case 2: end3=0; remove("c:\\turboc3\\file\\cart.exe"); remove("c:\\turboc3\\file\\temp");  break;
		case 3: end3=0; buytoreceipt(); break;
		default:  callmouse();  break;
	     }
		  button= -1;
	     }
       }
       clrscr();
       cleardevice();
       if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
       finn.close();
  }

void displayAddCart()
{
    while(!feof(p))
	{
	   outtextxy(40,155,"Name");
	   outtextxy(154,155,"Vendor");
	   outtextxy(245,155,"Price");
	   outtextxy(300,155,"Quantity");
	   outtextxy(370,155,"  Rs. ");
	   outtextxy(x_cor,y_cor,r.goodname1);
	   outtextxy(x_cor+115,y_cor,r.vendor1);
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
    char printname[25];
    char printphone[14];
    int printday,printmon,printyear;
    char printfile[30];
    clrscr();
    cleardevice();
    displayforever();
	p=fopen("c:\\turboc3\\file\\cart.exe","rb");
	fread(&r,sizeof(r),1,p);
	settextstyle(11,0,1);
	total=0;
	displayAddCart();
	gotoxy(55,7); printf("     Tax: %.1f",(total*13/100));
	total1=total*13/100+total;
	gotoxy(55,8); printf("   Total: %.1f",total1);
	line(420,110,600,110);
	rectangle(33,150,430,420);
	settextstyle(3,0,1);
	fclose(p);
   pp=fopen("c:\\turboc3\\file\\cusinfo.exe","ab");
   gotoxy(14,3); cout<<"--> Enter customer info ";
    cusNAMEE:
   gotoxy(12,4);  cout<<"Name :";  gets(printname);
	   if(printname[0]=='\0')
	   {
	      gotoxy(8,6); cout<<"Notice:";
	      gotoxy(8,7); cout<<"Name cant be empty.        ";
	      gotoxy(17,5); cout<<"            ";
	      goto cusNAMEE;
	   }
    gotoxy(8,6); cout<<"       ";
    gotoxy(8,7); cout<<"                              ";
    cusPHONEE:
    gotoxy(8,5); cout<<"Phone no.:";gets(printphone);
	   if(printphone[0]=='\0')
	   {
	      gotoxy(8,6); cout<<"Notice:";
	      gotoxy(8,7); cout<<"Phone cant be empty.       ";
	      gotoxy(17,5); cout<<"            ";
	      goto cusPHONEE;
	   }
	   else if(printphone[0]!='9')
	   {
	      gotoxy(8,6); cout<<"Notice:";
	      gotoxy(8,7); cout<<"Phone no must start with 9.";
	      gotoxy(17,5); cout<<"            ";
	      goto cusPHONEE;
	   }
	   else if(!isdigit(printphone[0]))
	   {
	     gotoxy(8,6); cout<<"Notice:";
	     gotoxy(8,7); cout<<"Phone cant be character.     ";
	     gotoxy(17,5); cout<<"             ";
	     goto cusPHONEE;
	   }

	   if(!isdigit(printphone[9]))
	   {
	      gotoxy(8,6); cout<<"Notice:";
	      gotoxy(8,7); cout<<"Phone no must be 10 digits.  ";
	      gotoxy(17,5); cout<<"            ";
	      goto cusPHONEE;
	   }
    gotoxy(8,6); cout<<"       ";
    gotoxy(8,7); cout<<"                              ";
   strcpy(c.cusname,printname);
   strcpy(c.phoneno,printphone);
   c.money=total1;
   getdate(&today);
   printyear=c.yr=today.da_year;
   printmon=c.mo=today.da_mon;
   printday=c.da=today.da_day;
   fwrite(&c,sizeof(c),1,pp);
   fclose(pp);
   strcpy(printfile,"c:\\turboc3\\file\\print.txt");
   /////
	p=fopen("c:\\turboc3\\file\\cart.exe","rb");
	ofstream files;
	files.open(printfile);
	fread(&r,sizeof(r),1,p);
	files<<"Bill no.\n";
	files<<"Name:"<<printname<<"\n";
	files<<"Phone:"<<printphone<<"\n";
	files<<"Date of purchase :"<<printday<<"-"<<printmon<<"-"<<printyear<<"\n";
	files<<"Rs. price Qty   Item\n";
	while(!feof(p))
	{
	  files<<r.rs1<<"   "<<r.price1<<"    "<<r.quantity1<<"    "<<r.goodname1<<"\n";
	  fread(&r,sizeof(r),1,p);
	}
	files.close();
	fclose(p);
   outtextxy(70,107,"Enter any key to continue");
   getch();
   remove("c:\\turboc3\\file\\cart.exe");  //print it before delete
   remove("c:\\turboc3\\file\\record3.exe");
   rename("c:\\turboc3\\file\\temp","c:\\turboc3\\file\\record3.exe");
   hidemouse();
  }

void cusdetail()  //case 8..
{
  cleardevice();
  end4=1;
  pp=fopen("c:\\turboc3\\file\\cusinfo.exe","rb");
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
	    {  outtextxy(310,30,"                     NEXT");
	       rectangle(485,35,545,55);
	    }
	    rectangle(47,35,112,53);
	    outtextxy(50,30," BACK ");
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
		outtextxy(50,30," BACK ");
		while(end4==1)
		{
			getmousepos(&button,&x,&y);
			if(button ==1)
			{
			 if(x>=47 && x<=112 && y>=35 && y<=53)
			  { end4=0;   }
			    else button= -1;
		}        }
  menu1:
  hidemouse();
  cleardevice();
  displayforever();
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
}

void vendetail()  //case 9..
{
  s.vendorDetail();
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }

}
void finance()  //case 10..
{
  getdate(&today);
  finance1(today.da_day,today.da_mon,today.da_year);
}
void financeMonthy()
{
 getdate(&today);
 finance2(today.da_day,today.da_mon,today.da_year);
}

void finance2(int finday,int finmon,int finyear)
{
  cleardevice();
  int end55=1;
  double totalfinc2=0;
    outtextxy(55,55,"Daily");
    rectangle(47,60,110,80);
    callmouse();
  FILE *ppp;
  ppp=fopen("c:\\turboc3\\file\\cusinfo.exe","rb");
  fread(&c,sizeof(c),1,ppp);
  display101:
  rectangle(25,100,590,340);
  displayforever();
  ycod=9,xcod=5;
  int displaycount101=0;
  while(!feof(ppp))
     {
	if(kbhit())  { getch();  }
	hidemouse();
	gotoxy(28,6); cout<<"Financial Report Monthly "<<finmon<<"-"<<finyear;
	gotoxy(5,8); cout<<"Customer";
	gotoxy(25,8); cout<<"Paid Ammount";
	gotoxy(45,8); cout<<"Phone";
	if(finmon==c.mo && finyear==c.yr)
	 {
	  gotoxy(xcod,ycod); cout<<c.cusname;
	  gotoxy(xcod+20,ycod); cout<<c.money;
	  gotoxy(xcod+40,ycod); cout<<c.phoneno;
	  totalfinc2=totalfinc2+c.money;
	  ycod=ycod+1;
	  displaycount101=displaycount101+1;
	 }
	callmouse();
	fread(&c,sizeof(c),1,ppp);

	if(displaycount101==12)
	  {
	    if(!feof(ppp))
	    {  outtextxy(210,32,"                     NEXT");
	       rectangle(385,35,445,55);
	    }
	    rectangle(47,35,112,53);
	    outtextxy(50,30," BACK ");
	    while(!kbhit())
	     {
	      getmousepos(&button,&x,&y);
	      if(button ==1)
		{
		  if(x>=385 && x<=445 && y>=35 && y<=55)
		    {  ungetch('\n');  }
		  else if(x>=47 && x<=112 && y>=35 && y<=53)
		    {  goto menu201;  }
		}
	     }
	     getch(); clrscr(); cleardevice();  goto display101;
	  }
     }
  fclose(ppp);
	gotoxy(50,23); cout<<"Total : "<<totalfinc2;
	gotoxy(50,24); printf("  Vat : %.1f",(totalfinc2*13/100));
	gotoxy(50,25); printf("Profit: %.1f",(totalfinc2*2/100));
	rectangle(47,35,112,53);
	outtextxy(50,30," BACK ");
	rectangle(500,52,530,77);
	rectangle(530,52,560,77);
	outtextxy(502,52,"<-");
	outtextxy(533,52,"->");
	gotoxy(62,3); cout<<"Change Month";
	hidemouse();
	outtextxy(55,55,"Daily");
	rectangle(47,60,110,80);
	callmouse();
	while(end55==1)
	{
	   outtextxy(55,55,"Daily");
	   rectangle(47,60,110,80);
		getmousepos(&button,&x,&y);
		if(button ==1)
		{
		 if(x>=47 && x<=112 && y>=35 && y<=53)
		  { if(return_pass==1)
		      { hidemouse(); clrscr(); cleardevice(); useralwaysdisplay(); }
		    else
		      { hidemouse(); clrscr(); cleardevice(); alwaysdisplay();  }
		  }
	    else if(x>=47 && x<=110 && y>=60 && y<=80)
		  {
		    hidemouse();delay(150); finance();
		  }
	    else if(x>=500 && x<=530 && y>=52 && y<=77)
		  {
		    if(finmon==1)
		       {  finmon=13; finyear--; }
		    delay(150); finance2(finday,finmon-1,finyear);
		  }
	    else if(x>=530 && x<=560 && y>=52 && y<=77)
		  {
		    getdate(&today);
		    if(finday>=today.da_day && finmon>=today.da_mon && finyear>=today.da_year)
		    { gotoxy(60,6); cout<<" Not Available";}
		    else
		    {
		       if(finmon==12)
			 {  finmon=0; finyear++; }
		       delay(150); finance2(finday,finmon+1,finyear);
		    }
		  }
		    else button= -1;
	}        }
  menu201:
  hidemouse();
  cleardevice();
  displayforever();
}

void finance1(int finday,int finmon,int finyear)
{
  cleardevice();
  end5=1;
  double totalfinc=0;
  outtextxy(50,55,"Monthly");
  rectangle(47,60,120,80);
  callmouse();
  pp=fopen("c:\\turboc3\\file\\cusinfo.exe","rb");
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
	gotoxy(28,6); cout<<"Financial Report Daily "<<finday<<"-"<<finmon<<"-"<<finyear;
	gotoxy(5,8); cout<<"Customer";
	gotoxy(25,8); cout<<"Paid Ammount";
	gotoxy(45,8); cout<<"Phone";
	if(finday==c.da && finmon==c.mo && finyear==c.yr)
	 {
	  gotoxy(xcod,ycod); cout<<c.cusname;
	  gotoxy(xcod+20,ycod); cout<<c.money;
	  gotoxy(xcod+40,ycod); cout<<c.phoneno;
	  totalfinc=totalfinc+c.money;
	  ycod=ycod+1;
	  displaycount1=displaycount1+1;
	 }
	callmouse();
	fread(&c,sizeof(c),1,pp);

	if(displaycount1==12)
	  {
	    if(!feof(pp))
	    {  outtextxy(210,32,"                     NEXT");
	       rectangle(385,35,445,55);
	    }
	    rectangle(47,35,112,53);
	    outtextxy(50,30," BACK ");
	    while(!kbhit())
	     {
	      getmousepos(&button,&x,&y);
	      if(button ==1)
		{
		  if(x>=385 && x<=445 && y>=35 && y<=55)
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
	outtextxy(50,30," BACK ");
	rectangle(500,52,530,77);
	rectangle(530,52,560,77);
	outtextxy(502,52,"<-");
	outtextxy(533,52,"->");
	hidemouse();
	outtextxy(50,55,"Monthly");
	rectangle(47,60,120,80);
	callmouse();
	gotoxy(62,3); cout<<"Change Date";
	while(end5==1)
	{
	    outtextxy(50,55,"Monthly");
	    rectangle(47,60,120,80);
		getmousepos(&button,&x,&y);
		if(button ==1)
		{
		 if(x>=47 && x<=112 && y>=35 && y<=53)
		  { if(return_pass==1)
		      { hidemouse(); clrscr(); cleardevice(); useralwaysdisplay(); }
		    else
		      { hidemouse(); clrscr(); cleardevice(); alwaysdisplay();  }
		  }
	    else if(x>=47 && x<=120 && y>=60 && y<=80)
		  {
		     hidemouse(); delay(150); financeMonthy();
		  }
	    else if(x>=500 && x<=530 && y>=52 && y<=77)
		  {
		    if(finday==1)
		       {  finday=32; finmon--; }
		    if(finmon==0)
		       {  finmon=12; finyear--; }
		    delay(150); finance1(finday-1,finmon,finyear);
		  }
	    else if(x>=530 && x<=560 && y>=52 && y<=77)
		  {
		    getdate(&today);
		    if(finday>=today.da_day && finmon>=today.da_mon && finyear>=today.da_year)
		    { gotoxy(60,6); cout<<" Not Available";}
		    else
		    {
		       if(finday==31)
			 {  finday=0; finmon++; }
		       if(finmon==13)
			 {  finmon=1; finyear++; }
		       delay(150); finance1(finday+1,finmon,finyear);
		    }
		  }
		    else button= -1;
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
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
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
	rectangle(53,63,145,84);
	rectangle(53,93,145,114);
	rectangle(53,123,145,144);
	rectangle(53,153,145,174);
	rectangle(53,183,145,204);
	rectangle(53,213,145,234);   //
	rectangle(27,35,76,53);
	outtextxy(60,60,"Biscuit");    //category
	outtextxy(60,90,"Chocolate");
	outtextxy(60,120,"Drinks");
	outtextxy(60,150,"Noodles");
	outtextxy(60,180,"Rice");
	outtextxy(60,210,"Spices");
	outtextxy(30,30,"BACK");

	getmousepos(&button,&x,&y);
	  if(button == 1)
	    {
	      if(x>=48 && x<=137 && y>=65 && y<=81)
		 {  option=1;  }
	      else if(x>=48 && x<=137 && y>=95 && y<=111)
		 {  option=3;  }
	      else if(x>=48 && x<=137 && y>=125 && y<=141)
		 {  option=4;  }
	      else if(x>=48 && x<=137 && y>=155 && y<=171)
		 {  option=5;  }
	      else if(x>=48 && x<=137 && y>=185 && y<=201)
		 {  option=6;  }
	      else if(x>=48 && x<=137 && y>=215 && y<=231)
		 {  option=7;  }
	      else if(x>=28 && x<=76 && y>=35 && y<=53)
		 {  option=2;  }
	      else option=-1;
	     hidemouse();
		 switch(option)
		   {
		     case 1: additem1(); end1=0; break; /// end1 vaya paxi, fere additem ma jana pauxa....
		     case 2: end1=0; break;
		     case 3: additem1(); end1=0; break;
		     case 4: additem1(); end1=0; break;
		     case 5: additem1(); end1=0; break;
		     case 6: additem1(); end1=0; break;
		     case 7: additem1(); end1=0; break;
		     default:  callmouse();  break;
		   }
		  button= -1;
	     }
	}
  cleardevice();
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
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
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
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
	outtextxy(50,30," BACK ");
	getmousepos(&button,&x,&y);
	  if(button == 1)
	    {
	    if(x>=48 && x<=112 && y>=35 && y<=53)
		 {  option=1;  }
	      else option=-1;
	     hidemouse();
		 switch(option)
		   {
		     case 1:cleardevice();
		     if(return_pass==1)
		     { useralwaysdisplay();  }
			else
			{   alwaysdisplay();  }  end2=0; break; /// end1 vaya paxi, fere additem ma jana pauxa....
		     default:  callmouse();  break;
		   }
		  button= -1;
	     }
	}
  cleardevice();
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
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
	 case 3: searchend=0; delay(150); hidemouse(); break;
	 default: break;
	 }
	 button= -1;
	 }
      }
  cleardevice();
  if(return_pass==1)
      { useralwaysdisplay();  }
   else
   {   alwaysdisplay();  }
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
   outtextxy(50,50,"Have a Nice Day"); delay(150);

   cleardevice();
   closegraph();
   //exportbackup();
   end=0;
}

long input(int x_cord,int y_cord,char ch_cord[30])
{
  long aaa;
  int flag3;
  char chhh[13];
  again:
  flag3=1;
  gotoxy(x_cord,y_cord);  cout<<ch_cord;   gets(chhh);
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
   char pass_bb[9];
   pass_bb[8]='#';
   int vv,get;
   cleardevice();
   displayforever();
   ifstream fin;
   ofstream fout;
   int flagpass=0, flagpass1=0;
   fin.open("c:\\turboc3\\file\\log.exe",ios::in | ios::binary);
       if(!fin)
	   {
		flagpass1=1;
		gotoxy(25,3); cout<<"Admin Registration";
	   }
       else
	   {
		gotoxy(25,3); cout<<"New User Registration";
		fin.read((char *)this,sizeof(* this));
		gotoxy(15,17); cout<<"User Name";
		gotoxy(30,17); cout<<"Address";
		gotoxy(45,17); cout<<"Phone no";
		gotoxy(60,17); cout<<"Password";
		rectangle(50,250,580,400);
		int yb=19;
		while(!fin.eof())
		{
		  gotoxy(10,yb); cout<<"User:";
		  gotoxy(9,19); cout<<"Admin:";
		  gotoxy(17,yb); cout<<USER;
		  gotoxy(32,yb); cout<<ADDRESS;
		  gotoxy(47,yb); cout<<PHONE;
		  for(vv=0;vv<8;vv++)
		   {
			pass_bb[vv]=PASSWORD[vv];
		   }
		  gotoxy(62,yb); cout<<pass_bb;
		  flagpass++;
		  yb++;
		  fin.read((char *)this,sizeof(* this));
		}
		fin.close();
	   }
	if(flagpass>5 && flagpass1==0)
	{
	gotoxy(22,9); cout<<"-- User are more than 5 --";
	}
	else
	{
	   fout.open("c:\\turboc3\\file\\log.exe",ios::app | ios::binary);
	   hidemouse();

	ifstream check;
	check.open("c:\\turboc3\\file\\log1",ios::in | ios::binary);
	   if(check)
	   {
	       gotoxy(25,3); cout<<"Admin Registration";
	   }
	   check.close();
	   gotoxy(29,7); cout<<"Username:";
	   rectangle(200,80,440,218);
	   gotoxy(25,5); cout<<"-> Enter Username";
	   rectangle(300,89,430,113);
	loginUSER:
	   gotoxy(39,7); gets(USER);
	   if(USER[0]=='\0')
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Name cant be empty.";
	      gotoxy(39,7); cout<<"            ";
	      goto loginUSER;
	   }
	   else if(isdigit(USER[0]))
	   {
	     gotoxy(28,15); cout<<"Notice:";
	     gotoxy(35,15); cout<<"Name cant be number.";
	     gotoxy(39,7); cout<<"             ";
	     goto loginUSER;
	   }
	   gotoxy(28,15); cout<<"                               ";
	   gotoxy(29,9); cout<<" Address:";
	   rectangle(300,122,430,144);
	   gotoxy(25,5); cout<<"->  Enter Address";
	   loginADDRESS:
	   gotoxy(39,9); gets(ADDRESS);
	   if(ADDRESS[0]=='\0')
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Address cant be empty.";
	      gotoxy(39,9); cout<<"            ";
	      goto loginADDRESS;
	   }
	   else if(isdigit(ADDRESS[0]))
	   {
	     gotoxy(28,15); cout<<"Notice:";
	     gotoxy(35,15); cout<<"Address cant be number.";
	     gotoxy(39,9); cout<<"             ";
	     goto loginADDRESS;
	   }
	   gotoxy(28,15); cout<<"                                       ";
	   gotoxy(29,11); cout<<"   Phone:";
	   rectangle(300,155,430,177);
	   gotoxy(25,5); cout<<"-> Enter phone no.";
	   loginPHONE:
	   gotoxy(39,11); gets(PHONE);
	   int zz=0;
	   zz=strlen(PHONE);
	   if(PHONE[0]=='\0')
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Phone cant be empty.              ";
	      gotoxy(39,11); cout<<"              ";
	      goto loginPHONE;
	   }

	   else if(!isdigit(PHONE[0]))
	   {
	     gotoxy(28,15); cout<<"Notice:";
	     gotoxy(35,15); cout<<"Phone cant be character.            ";
	     gotoxy(39,11); cout<<"               ";
	     goto loginPHONE;
	   }
	   else if(zz!=10)
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Phone number must be 10 digit.";
	      gotoxy(39,11); cout<<"              ";
	      goto loginPHONE;
	   }
	   else if(PHONE[0]!=57)
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Phone number must start with 9.  ";
	      gotoxy(39,11); cout<<"              ";
	      goto loginPHONE;
	   }
	   gotoxy(28,15); cout<<"                                     ";
	   gotoxy(29,13); cout<<"Password:";
	   rectangle(300,188,430,210);
	   gotoxy(25,5); cout<<"-> Enter New password";
	   ucount=0;
	   while(ucount<8)
	   {
	       gotoxy(39,13); cout<<"        ";
	       passwordMatch();
	       if(password[0]==13)
		  { gotoxy(28,15); cout<<"       Password can't be empty"; }
	       else if(ucount<7)
		  { gotoxy(28,15); cout<<"  Password must be 8 character"; }
	       else if(ucount==8)
		  { gotoxy(28,15); cout<<"     Account Added            "; }
	   }
	   for(int v=0;v<8;v++)
	   {
		PASSWORD[v]=password[v]+5;
	   }
	   fout.write((char *)this,sizeof(*this));
	}
   fout.close();
   ifstream finadmin;
   ofstream foutadmin;
      finadmin.open("c:\\turboc3\\file\\log1",ios::in|ios::binary);
      foutadmin.open("c:\\turboc3\\file\\log.exe",ios::app|ios::binary);
	      finadmin.read((char *)this,sizeof(*this));
	if(finadmin)  //if log1 xa vane copy hunxa///
	{     finadmin.read((char *)this,sizeof(*this));
	      while(!finadmin.eof())
		{
		    foutadmin.write((char *)this,sizeof(*this));
		    finadmin.read((char *)this,sizeof(*this));
		}
	}
      finadmin.close();
      foutadmin.close();
      remove("c:\\turboc3\\file\\log1");
   callmouse();
   rectangle(460,35,545,60);
   outtextxy(310,30,"                 Continue.");
   while(get!=13)
   {
      while(!kbhit())
      {
      getmousepos(&button,&x,&y);
      if(button==1)
       {if(x>=460 && x<=545 && y>=35 && y<=60){ungetch(13);}}}
    get=getch();
      }
      clrscr();
   cleardevice();
   displayforever();
}

void userpass::deletepass()      //case 13...
{
   char pass_bbb[9];
   pass_bbb[8]='#';
   char us[15],ps[8];
   int vvb,same=0,gett,admincount;
   cleardevice();
   displayforever();
   ifstream fin;
   ofstream fout;
   ofstream foout;
   int flagpassb=0, flagpassb1=0;
   fin.open("c:\\turboc3\\file\\log.exe",ios::in | ios::binary);
   foout.open("c:\\turboc3\\file\\log1",ios::out | ios::binary);
       if(!fin)
	   {
		flagpassb1=1;
	   }
       else
	   {
		fin.read((char *)this,sizeof(* this));
		gotoxy(15,17); cout<<"User Name";
		gotoxy(30,17); cout<<"Address";
		gotoxy(45,17); cout<<"Phone no";
		gotoxy(60,17); cout<<"Password";
		rectangle(50,250,580,400);
		int ybb=19;
		while(!fin.eof())
		{
		  gotoxy(9,19);  cout<<"Admin:";
		  gotoxy(10,ybb);  cout<<"User:";
		  gotoxy(17,ybb); cout<<USER;
		  gotoxy(32,ybb); cout<<ADDRESS;
		  gotoxy(47,ybb); cout<<PHONE;
		  for(vvb=0;vvb<8;vvb++)
		   {
			pass_bbb[vvb]=PASSWORD[vvb];
		   }
		  gotoxy(62,ybb); cout<<pass_bbb;
		  flagpassb++;
		  ybb++;
		  foout.write((char *)this,sizeof(*this));
		  fin.read((char *)this,sizeof(* this));
		}
		fin.close();
		foout.close();
	   }
	if(flagpassb==0 || flagpassb1==1)
	{
	gotoxy(20,7); cout<<"-> Empty list";
	}
	else
	{
	 fin.open("c:\\turboc3\\file\\log.exe",ios::in | ios::binary);
	 fout.open("c:\\turboc3\\file\\log",ios::app | ios::binary);
	 hidemouse();
	   gotoxy(25,8); cout<<"-> Enter username to delete";
	   gotoxy(29,11); cout<<"Username:";
	   rectangle(200,142,440,218);
	   rectangle(300,155,430,177);
	   callmouse();
	 loginus:
	   gotoxy(39,11);
	   gets(us);
	   if(us[0]=='\0')
	   {
	      gotoxy(28,15); cout<<"Notice:";
	      gotoxy(35,15); cout<<"Name cant be empty.  ";
	      gotoxy(39,11); cout<<"            ";
	      goto loginus;
	   }
	   else if(isdigit(us[0]))
	   {
	     gotoxy(28,15); cout<<"Notice:";
	     gotoxy(35,15); cout<<"Name cant be number.  ";
	     gotoxy(39,11); cout<<"             ";
	     goto loginus;
	   }
	   gotoxy(25,8); cout<<"-> Enter password to delete";
	   gotoxy(29,13); cout<<"Password:";
	   gotoxy(35,15); cout<<"                        ";
	   rectangle(300,188,430,210);
	   ucount=0;
	   while(ucount<8)
	   {
	       gotoxy(39,13); cout<<"        ";
	       passwordMatch();
	       if(password[0]==13)
		  { gotoxy(28,15); cout<<"       Password can't be empty"; }
	       else if(ucount<7)
		  { gotoxy(28,15); cout<<"  Password must be 8 character"; }
	   }
	   for(int vb=0;vb<8;vb++)
	   {
		ps[vb]=password[vb]+5;
	   }
	   adminread=0; admincount=0;
	   fin.read((char *)this,sizeof(*this));
	   while(!fin.eof())
	      {  if(strcmp(us,USER)==0 && (ps[0]==PASSWORD[0] && ps[1]==PASSWORD[1] && ps[2]==PASSWORD[2] && ps[3]==PASSWORD[3] && ps[4]==PASSWORD[4] && ps[5]==PASSWORD[5] && ps[6]==PASSWORD[6] && ps[7]==PASSWORD[7] ))
		    { same=1;  }
		 else {
			 fout.write((char *)this,sizeof(*this));
		      }
	       if(same==1 && admincount==0) { adminread=1;  break;  }
	       admincount++;
	       fin.read((char *)this,sizeof(*this));
	      }
	}
   fin.close();
   fout.close();
   remove("c:\\turboc3\\file\\log.exe");
   rename("c:\\turboc3\\file\\log","c:\\turboc3\\file\\log.exe");
	hidemouse();
   if(same==1)
     {
       if(adminread==1)
	 {
	     gotoxy(20,15); cout<<"...Admin Account Deleted... Add another Admin...";
	 }
	 else
	 {   gotoxy(28,15); cout<<"     Account Deleted           ";}
     }
   else
     {
     if(!flagpassb==0 || !flagpassb1==1)
	{
	  gotoxy(25,15); cout<<"Username or password donot match.           ";
	}
     }
   rectangle(460,35,545,60);
   callmouse();
   outtextxy(310,30,"                 Continue.");
   while(gett!=13)
   {
     while(!kbhit())
     {
      getmousepos(&button,&x,&y);
      if(button==1)
      {if(x>=460 && x<=545 && y>=35 && y<=60){ungetch(13);}
      }
     }
       gett=getch();
   }
     hidemouse();
   cleardevice();
   if(adminread==1)
      { adminread=0; u.checkpass();  }
   else
      {
	remove("c:\\turboc3\\file\\log1");
	alwaysdisplay();
}     }


int userpass::loginpass(char name_a[20],char pass_a[8])
{
  char pass_b[8];
  int v,logincheck=0;
  return_login=0;
  ifstream fiin;
  fiin.open("c:\\turboc3\\file\\log.exe",ios::in |ios::binary);
  if(!fiin) { return_login=0; }
  else {
      fiin.read((char *)this,sizeof(* this));
      while(!fiin.eof())
	{
	  for(v=0;v<8;v++)
	   {
	      pass_b[v]=PASSWORD[v]-5;
	   }
	  if(strcmp(name_a,USER)==0)
	     {
	      if(pass_a[0]==pass_b[0] && pass_a[1]==pass_b[1] && pass_a[2]==pass_b[2] && pass_a[3]==pass_b[3] && pass_a[4]==pass_b[4] && pass_a[5]==pass_b[5] && pass_a[6]==pass_b[6] && pass_a[7]==pass_b[7] )
		{ return_login=1;  }
	     }
	  if(return_login==1 && logincheck==0)
	     {
	       return_login=2;
	     }
      logincheck++;
      fiin.read((char *)this,sizeof(* this));
	  }
       }
     fiin.close();
  return(return_login);
}
