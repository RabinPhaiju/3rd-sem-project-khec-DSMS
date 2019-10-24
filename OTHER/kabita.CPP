#include<stdio.h>
#include<iomanip.h>
#include<graphics.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<fstream.h>
#include<iostream.h>
#include<dos.h>
void admin_func();
int check_admin(char name[50],char *id);
int compare(char name[50],char *id);
void voter_func(char *id);
int check(char *filename);
int check_admin(char name[50],char id[])
{
   if(strcmp(name,"admin")!=0)
     return 0;
   char ch;
   ifstream fin;
   fin.open("admin.bin",ios::in | ios::binary);
   fin.seekg(0,ios::beg);
   for(int i=0;i<6;i++)
   {
     fin.get(ch);
     if(ch!=id[i])
     {
       fin.close();
       return 0;
       }
   }
   fin.close();
   return 1;
}
void admin_file()
{
   char pswd[7]={'1','2','3','4','5','6'};
   ofstream fout;
   fout.open("admin.bin",ios::out | ios::binary);
   for(int i=0;i<7;i++)
   fout.put(pswd[i]);
   fout.close();
}
int check(char *filename)
{
  ifstream fin;
  fin.open(filename);
  return(fin.good());
}
class candidate
{
   int nov;
   char name[50];
   char symbol[20];
   int id;
   public:
   candidate()
   {}
   candidate(int x, char a[])
   {
     nov=0;
     strcpy(symbol,a);
     id=x;
   }
   void set()
   {
     printf("\n--------------------------\n");
     cout<<"enter name of candidate ";
     gets(name);
     cout<<"symbol: "<<symbol;
     cout<<"\nid: "<<id;
     printf("\n--------------------------\n");
   }
   void count()
   {
    nov++;
   }
   char* getname()
   {
     return(name);
   }
   void display()
   {
      printf("\n--------------------------\n");
	cout<<"NAME:  "<<name;
	cout<<"\nSYMBOL:   "<<symbol;
	cout<<"\nNO. OF VOTES"<<nov;
      printf("\n--------------------------\n");
   }
};
candidate c1(1,"rectangle"),c2(2,"circle"),c3(3,"triangle");
class voter
{
    char id[7];
    char name[50];
  public:
    void set();
    char* getid()
    {
	return id;
     }
    void delet()
    {
	   strcpy(name,"                     ");
	  strcpy(id,"               ");
    }
    void display()
    {
	  cout<<setiosflags(ios::left);
	  cout<<setw(35)<<name;
	  cout<<id<<"\n";
     }
     int compare();
     friend int compare(char name[50],char id[7]);
};
void voter::set()
    {
       printf("\n--------------------------\n");
       cout<<"enter name of voter ";
       gets(name);
       cout<<"enter id ";
       gets(id);
       if(strlen(id)!=6)
  {
    cout<<"id should be of 6 digits";
    cout<<"\nenter again";
    set();
  }
       for(int i=0;i<6;i++)
       {
       if(id[i]>=48 && id[i]<=57)
	 {}
       else
       {
	     printf("enter numbers only(0 - 9)\n");
	     set();
	     break;
	}
	}
	printf("\n--------------------------\n");
    }
int voter::compare()
{
   voter v;
   ifstream fin;
   fin.open("voters.bin",ios::in | ios::binary);
   while(fin.read((char*)&v,sizeof(v)))
   {
      if(strcmp(name,v.name)==0 && strcmp(id,v.id)==0)
      {
	return 1;
      }
      if(strcmp(id,v.id)==0)
      {
	return 2;
      }
   }
   return 0;
}
void main()
{
  admin_file();
  int gm,gd=DETECT;
  initgraph(&gd,&gm,"..\\bgi");
 //  setcolor(10);
 // setbkcolor(15);
  settextstyle(8,HORIZ_DIR,7);
  outtextxy(10,10,"ELECTRONIC");
  outtextxy(100,100,"VOTING");
  outtextxy(200,200,"SYSTEM");
  settextstyle(3,HORIZ_DIR,6);
  outtextxy(10,300,"of class representative");
  delay(2500);
  closegraph();
  char id[7];
  char name[50];
  initgraph(&gd,&gm,"..\\bgi");
  settextstyle(8,HORIZ_DIR,3);
  outtextxy(30,20,"*******LOG-IN MENU*******");
  settextstyle(8,HORIZ_DIR,1);
  start:
  rectangle(20,60,350,120);
  outtextxy(25,70,"enter name:");
  gotoxy(21,6);
  cout<<"_\b";
  gets(name);
  outtextxy(25,90,"enter id: ");
  gotoxy(21,7);
  cout<<"_\b";
  for(int j=0;j<6;)
  {
      id[j]=getch();
      if(id[j]==8)
      {
	 if(j!=0)
	 {
	    b:
	    printf(" \b\b \b");
	    j--;
	 }
      }
      else
      {
	 printf("*");
	 printf("_\b");
	 j++;
      }
  }
  id[j]='\0';
  char ch;
  ch=getch();
  if(ch==8)
    goto b;
  if(ch!=13)
  {
    outtextxy(20,120,"id should be of 6 digits");
    outtextxy(20,135,"enter again");
    gotoxy(21,6);
    cout<<"                         ";
    gotoxy(21,7);
    cout<<"             ";
    goto start;
  }
  for(int i=0;i<6;i++)
       {
       if(id[i]>=48 && id[i]<=57)
	 {}
       else
       {
	     outtextxy(20,220,"enter numbers only(0 - 9)");
	     outtextxy(20,235,"enter again!!");
	      gotoxy(21,6);
	      cout<<"                             ";
	     gotoxy(21,7);
	     cout<<"             ";
	     goto start;
	}
	}
  if(check_admin(name,id)==1)
  {
    closegraph();
    admin_func();
  }
  else
  {
   if(compare(name,id)==1)
   {
   closegraph();
   voter_func(id);
   }
   else
   {
	     outtextxy(20,180,"invalid id or username");
	     outtextxy(20,195,"enter again!!");
	      gotoxy(21,6);
	      cout<<"                             ";
	     gotoxy(21,7);
	     cout<<"             ";
   goto start;
   }
  }
}

int compare(char name1[50],char id1[])
{
   voter v;
   ifstream fin;
   if(check("voters.bin")==0)
	 {
	    return 0;
	 }
   fin.open("voters.bin",ios::in | ios::binary);
   fin.seekg(0,ios::beg);
   while(fin.read((char*)&v,sizeof(v)))
   {
      if(strcmp(name1,v.name)==0 && strcmp(id1,v.id)==0)
      {
	fin.close();
	return 1;
      }
   }
   fin.close();
   return 0;
}

void admin_func()
{
  clrscr();
  voter v;
  candidate c;
  char choice;
  int loc,obj;
  ofstream outfile;
  ifstream infile;
  while(1)
  {
    cout<<"enter choice:";
    cout<<"\n1.Add voters information";
    cout<<"\n2.Update voter information";
    cout<<"\n3.Display voter information";
    cout<<"\n4.Reset voter's file";
    cout<<"\n5.Add candidates information";
    cout<<"\n6.Display candidates information";
    cout<<"\n7.Exit";
    cin>>choice;
    switch(choice)
    {
       case '1':
	 if(check("voters.bin")==1)
	 {
	  infile.open("voters.bin",ios::in | ios::binary);
	 infile.seekg(0,ios::beg);
	 infile.read((char*)&v,sizeof(v));
	 while(!infile.eof())
	 {
	    infile.read((char*)&v,sizeof(v));
	 }
	 loc=infile.tellg();
	 infile.close();
	 if(48*sizeof(v)==loc)
	 {
	    printf("\nvoter's list has been completed\n");
	    break;
	 }
       }
	 outfile.open("voters.bin",ios::app | ios::binary);
	 v.set();
	 if(v.compare()==1)
	 {
	   cout<<"\n This voter is already present\n";
	   v.display();
	 }
	 else if(v.compare()==2)
	 {
	   cout<<"\n This id is already present";
	   cout<<"\n Entry failed!!\n";
	 }
	 else
	 {
	   outfile.write((char*)&v,sizeof(v));
	 }
	 outfile.close();
	 break;
       case '2':
	 if(check("voters.bin")==0)
	 {
	    printf("\nthere is no file to update");
	    break;
	 }
	 outfile.open("voters.bin",ios::ate | ios::binary);
	 cout<<"\nenter the position of object to be updated";
	 cin>>obj;
	 loc=(obj-1)*sizeof(v);
	 outfile.seekp(loc,ios::beg);
	 v.set();
	  if(v.compare()==1)
	 {
	   cout<<"\n This voter is already present";
	   v.display();
	 }
	  else if(v.compare()==2)
	 {
	   cout<<"\n This id is already present";
	   cout<<"\n Entry failed!!\n";
	 }
	 else
	 outfile.write((char*)&v,sizeof(v));
	 outfile.close();
	 break;
      case '3':
	 clrscr();
	 if(check("voters.bin")==0)
	 {
	    printf("\nthere is no data to display");
	    break;
	 }
	 printf("NAME");
	 printf(" \t\t\t ID\n");
	 infile.open("voters.bin",ios::in | ios::binary);
	 infile.seekg(0,ios::beg);
	 infile.read((char*)&v,sizeof(v));
	 while(!infile.eof())
	 {
	    loc=infile.tellg();
	    if(loc==24*sizeof(v) || loc==47*sizeof(v))
	    {
	      cout<<"\nPress any key to go to next page";
	      getch();
	      clrscr();
	    }
	    v.display();
	    infile.read((char*)&v,sizeof(v));
	 }
	 printf("\n----------------------------------\n");
	 infile.close();
	 cout<<"Press any key to continue\n";
	 getch();
	 break;
      case '4':
	 char ch;
	 cout<<"This will delete all voters information\n";
	 cout<<"Press y to delete\n";
	 cin>>ch;
	  if(ch!='y')
	 {
	    break;
	 }
	 outfile.open("voters.bin",ios::out | ios::binary);
	 outfile.close();
	 cout<<"\n Voters file has been deleted\n";
	 break;
      case '5':
	 outfile.open("candidat.bin",ios::out | ios::binary);
	 outfile.seekp(0,ios::beg);
	 c1.set();
	 outfile.write((char*)&c1,sizeof(c1));
	  c2.set();
	 outfile.write((char*)&c2,sizeof(c2));
	  c3.set();
	 outfile.write((char*)&c3,sizeof(c3));
	 outfile.close();
	 break;

      case '6':
	   if(check("candidat.bin")==0)
	 {
	    printf("\nthere is no file to display");
	    break;
	 }
	  infile.open("candidat.bin",ios::in | ios::binary);
	 infile.seekg(0,ios::beg);
	 infile.read((char*)&c,sizeof(c));
	 while(!infile.eof())
	 {
	    c.display();
	    infile.read((char*)&c,sizeof(c));
	 }
	 infile.close();
	 break;
      case '7':
	exit(1);
      default:
	cout<<"\nwrong choice\n";
    }
  }
}

void voter_func(char *id)
{
   clrscr();
   char choice;
   int gm,gd=DETECT;
   char name[50];
   initgraph(&gd,&gm,"..\\bgi");
   setcolor(9);
   setbkcolor(15);
   rectangle(40,10,300,300);
   line(40,25,300,25);
   line(125,25,125,300);
   line(40,120,300,120);
   line(40,180,300,180);
   outtextxy(140,15,"BALLOT PAPER");
   rectangle(50,40,100,100);
   ifstream infile;
   infile.open("candidat.bin",ios::in | ios::binary);
   if(check("candidat.bin")==0)
	 {
	    printf("\nCANDIDATE FILE IS ABSENT");
	    return;
	 }
   infile.read((char*)&c1,sizeof(c1));
   strcpy(name,c1.getname());
    outtextxy(130,50,name);
    outtextxy(130,70,"enter 1 to vote");
    circle(80,150,25);
   infile.read((char*)&c2,sizeof(c2));
   strcpy(name,c2.getname());
  outtextxy(130,130,name);
  outtextxy(130,150,"enter 2 to vote");
   line(70,210,50,250);
   line(50,250,90,250);
   line(90,250,70,210);
   infile.read((char*)&c3,sizeof(c3));
   strcpy(name,c3.getname());
    outtextxy(130,230,name);
    outtextxy(130,250,"enter 3 to vote");
   a:
   cin>>choice;
   infile.close();
   ofstream outfile;
   int loc;
   outfile.open("candidat.bin",ios::ate | ios::binary);
   if(choice=='1')
   {
     c1.count();
     outfile.seekp(0,ios::beg);
     outfile.write((char*)&c1,sizeof(c1));
   }
   else if(choice=='2')
   {
     c2.count();
     loc=sizeof(c2);
     outfile.seekp(loc,ios::beg);
     outfile.write((char*)&c2,sizeof(c2));
   }
   else if(choice=='3')
   {
      c3.count();
      loc=2*sizeof(c3);
     outfile.seekp(loc,ios::beg);
     outfile.write((char*)&c3,sizeof(c3));
   }
   else
   {
      settextstyle(8,HORIZ_DIR,2);
      outtextxy(120,300,"invalid choice");
      outtextxy(120,330,"enter again");
      goto a;
   }
   outfile.close();
   ifstream fin;
   voter v;
   fin.open("voters.bin",ios::in | ios::binary);
   while(fin.read((char*)&v,sizeof(v)))
   {
    if(strcmp(v.getid(),id)==0)
     loc=fin.tellg()-sizeof(v);
   }
   fin.close();
   ofstream fout;
   fout.open("voters.bin",ios::ate | ios::binary);
   v.delet();
   fout.seekp(loc,ios::beg);
   fout.write((char*)&v,sizeof(v));
   fout.close();
   closegraph();
   initgraph(&gd,&gm,"..\\bgi");
 setcolor(9);
 setbkcolor(14);
  settextstyle(8,HORIZ_DIR,7);
  outtextxy(10,10,"THANK-YOU!");
  settextstyle(3,HORIZ_DIR,5);
  outtextxy(10,200,"You have successfully voted!");
  delay(2500);
  closegraph();
}