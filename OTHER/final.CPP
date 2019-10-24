#include <iostream.h>
#include <stdio.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <process.h>
union REGS in, o;
int x, y, i,m, n, cl;
int *a, *b, *c;
char check[9]={'p','a','s','s','w','o','r','d'};
 char name [25];
    char address[25], mobile[15], phone [15], email[25];
    void menu();
    void welcome();
    void imp_cont();
void tempdelete()

{
system("cls");
    cleardevice();
    setbkcolor(1);
    fstream stud;
    fstream temp,rec;
    stud.open("contact.bin",ios::in);
    rec.open("recover.bin",ios::app);
    temp.open("temp.bin",ios::out);
    char a[25];
    cout<<"\n\n\n\n\t\t\t\tTEMPORARY DELETE";
    cout<<"\n\t\t***********************************************";
    cin.ignore();
    cout<<" \n\t\t   Enter the name to be deleted:";
    cin.getline(a,25);
   rec.seekg(0, ios::end);
    if (rec.tellg() != 0)
     {
      rec<<"\n";
     }
    while(!stud.eof())
    {
	stud.getline(name,25, ' ');
	stud.getline(address,25, ' ');
	stud.getline(mobile,15, ' ');
	stud.getline(phone,15, ' ');
	stud.getline(email,25,'\n');
	if(strcmp(name,a)==0)
	{
	rec<<name<< ' ';
	rec<<address<< ' ';
	rec<<mobile<< ' ';
	rec<<phone<< ' ';
	rec<<email;
	//	continue;
	}

	else
	{
	temp.seekg(0, ios::end);
	if (temp.tellg() != 0) {
	 temp<<"\n";
	 }
	 temp<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;

	}

    }
    rec.close();
    temp.close();
    stud.close();
   remove("contact.bin");
   rename("temp.bin","contact.bin");
   delay(200);
   cout<<"\n \n\t\t\t\tdone !!! \n";
    cout<<"\n\t\t    Press any key to enter previous menu!!!";
   getch();
   system("cls");
}
void perdelete()

{
system("cls");
    cleardevice();
    setbkcolor(1);
    fstream stud;
    fstream temp,rec;
    stud.open("contact.bin",ios::in);
    temp.open("temp.bin",ios::out);
    cout<<"\n\n\n\n\t\t\t\tPERMANENT DELETE";
    cout<<"\n\t\t***********************************************";
    char a[25];
    cin.ignore();
    cout<<" \n\t\t    Enter the name to be deleted:";
    cin.getline(a,25);

    while(!stud.eof())
    {
	stud.getline(name,25, ' ');
	stud.getline(address,25, ' ');
	stud.getline(mobile,15, ' ');
	stud.getline(phone,15, ' ');
	stud.getline(email,25,'\n');
	if(strcmp(name,a)==0)
	{
	continue;
	}
	else
	{
	 temp.seekg(0, ios::end);
	 if (temp.tellg() != 0)
	 {
	   temp<<"\n";
	 }
	 temp<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;

	}

    }
    temp.close();
    stud.close();
    stud.open("contact.bin",ios::out);
    temp.open("temp.bin",ios::in);

    while(!temp.eof())
    {
	temp.getline(name,25, ' ');
	temp.getline(address,25, ' ');
	temp.getline(phone,15, ' ');
	temp.getline(mobile,15, ' ');
	temp.getline(email,25,'\n');
	stud.seekg(0, ios::end);
	if (stud.tellg() != 0)
	{
	  stud<<"\n";
	}
    stud<< name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;
   }
    temp.close();
  stud.close();
   remove("temp.bin");
   delay(100);
   cout<<"\n\t\t\t\t done !!! \n";
    cout<<"\n\t\t    Press any key to enter previous menu!!!";
   getch();
   system("cls");
}

void delete_student()
{
system("cls");
   cleardevice();
   setbkcolor(1);
   int choice;
	cout<<"\n\n\n\n\t\t\t\tDELETE CONTACTS";
	cout<<"\n\t\t***********************************************";
   cout<<"\n\n\n\t\t\t1.Permanent Delete\n\n\t\t\t2.Temporary Delete\n\n\t\t\t3.Back to Menu Board";
   cout<<"\n\n\t\tMake the Choice::";
   cin>>choice;
   switch(choice)
   {
      case 1: perdelete();
	     break;
      case 2: tempdelete();
	      break;
      case 3: menu();
	      break;
      default:
      cout<<"invalid selection";
   }
   system("cls");
}

void recover_cont()
{
  system("cls");
 cleardevice();
 setbkcolor(1);
 char a[25];
   fstream rec,stud,del;
   rec.open("recover.bin",ios::in);
   cout<<"\n\n\n\n\t\t\t\tRECOVER CONTACTS";
   cout<<"\n\t\t***********************************************";
   cout<<"\n\t\t   ******** list of deleted contacts ********\n";
    while(!rec.eof())
   {

    rec.getline(name,25,' ');
   rec.getline(address,25, ' ');
   rec.getline(mobile,15, ' ');
   rec.getline(phone,15, ' ');
   rec.getline(email,25,'\n');
   cout<<"\t\t\t      "<<name<<' '<<address<<' '<<mobile;
   }
   rec.close();

   rec.open("recover.bin",ios::in);
   stud.open("contact.bin",ios::app);
   del.open("delete.bin",ios::out);
   cin.ignore();
   cout<<"\n\t\t  Enter name of contact to be recovered::";
   cin.getline(a,25);

   while(!rec.eof())
   {
     rec.getline(name,25, ' ');
     rec.getline(address,25, ' ');
     rec.getline(mobile,15, ' ');
     rec.getline(phone,15, ' ');
     rec.getline(email,25,'\n');
     if(strcmp(name,a)==0)
      {
	 stud.seekg(0, ios::end);
    if (stud.tellg() != 0) {
      stud<<"\n";
     }
	stud<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;
      }
     else
      {
      // cout<<"no matching";
     del<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;
      }

   }
  stud.close();
  rec.close();
  del.close();
  rec.open("recover.bin",ios::out);
  del.open("delete.bin",ios::in);
  rec.seekg(0, ios::end);
    if (rec.tellg() != 0) {
      rec<<"\n";
     }
  while(!del.eof())
  {
    del.getline(name,25, ' ');
    del.getline(address,25, ' ');
    del.getline(mobile,15, ' ');
    del.getline(phone,15, ' ');
    del.getline(email,25,'\n');

    rec<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;
  }
   rec.close();
   del.close();
   remove("delete.bin");
   cout<<"\n\t\t\t\tdone!!";
    cout<<"\n\t\t    Press any key to enter previous menu!!!";
   getch();
   delay(100);
   system("cls");

}



void update_student()
{
top:
    system("cls");
    cleardevice();
    setbkcolor(1);
    int len;
    fstream stud;
    fstream temp;
  stud.open("contact.bin",ios::in);
  temp.open("temp.bin",ios::out);
  cout<<"\n\n\n\n\t\t\t\tUPDATE CONTACTS";
  cout<<"\n\t\t***********************************************";
  char a[25];
   cin.ignore();
   cout<<"\n\t\t    enter the  name to be updated : ";
   cin.getline(a,25);

   while(!stud.eof())
   {

      stud.getline(name,25, ' ');
      stud.getline(address,25, ' ');
      stud.getline(phone,15, ' ');
      stud.getline(mobile,15, ' ');
      stud.getline(email,25,'\n');
	if(strcmp(name,a)==0)
	{
	    cout<<"\n\t\t    Enter new value for the record  \n ";
	    cout<<"\n\t\t\t     Name : ";
	    cin.getline(name, ' ');
	    cout<<"\n\t\t\t     Address : ";
	    cin.getline(address, ' ');
	    cout<<"\n\t\t\t     Mobile : ";
	     cin>>mobile;
     len=strlen(mobile);
     if(len==10)
     {
	for(int i=0; i<10; i++)
	{
	   if(!(mobile[0]==57&&mobile[i]>=48&&mobile[i]<=57))
	   {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid mobile number";
	       delay(1000);
	       cleardevice();
	       goto top;
	   }
	   else
	   continue;
	}
     }
	else
	{
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid mobile number";
	       delay(1000);
	       cleardevice();
	       goto top;
	}
	len=0;
     cout<<"\n\t\t\t     Phone : ";
    cin>>phone;
    len=strlen(phone);
    if(len==9)
    {
       for(int i=0; i<9; i++)
       {
	  if(!(phone[i]>=48&&phone[i]<=57))
	  {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid phone number";
	       delay(1000);
	       cleardevice();
	       goto top;
	  }
	  else
	  continue;
       }
    }
    else
    {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid phone number";
	       delay(1000);
	       cleardevice();
	       goto top;
    }
	    cout<<"\n\t\t\t     Email : ";
    len=0;
    gets(email);
    len=strlen(email);
    int a=0;
    if(len>7)
    {
     for(int i=0;i<len;i++)
      {
       if(email[i]=='@'&&email[len-4]=='.'&&email[len-3]=='c'&&email[len-2]=='o'&&email[len-1]=='m')
	{
	  a=a+1;
	}
      }
       if(a!=1)
	 {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid email address!!!";

	       delay(1000);
	      cleardevice();
	       goto top;
	 }
       }
   else
   {    cleardevice();
	cout<<"\n\n\n\t\t\tenter the valid email address!!!";
	cleardevice();
	goto top;
   }
	    temp.seekg(0,ios::end);
	    if (temp.tellg() != 0)
		{
			temp<<"\n";
		}
	    temp<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;
	}
	else
	{
	   temp.seekg(0,ios::end);
	    if (temp.tellg() != 0)
		{
			temp<<"\n";
		}
	   temp<<name<< ' '<<address<< ' '<<mobile<< ' '<<phone<< ' '<<email;
	}
   }
   temp.close();
   stud.close();
    remove("contact.bin");
    rename("temp.bin","contact.bin");
    cout<<"\n\n\t\t\t\t done !!! \n";
     cout<<"\n\t\t    Press any key to enter previous menu!!!";
    getch();
    system("cls");

}

void display_all()
{
    system("cls");
    cleardevice();
    setbkcolor(1);
    fstream stud;
    stud.open("contact.bin",ios::in);
	cout<<"\n\n\n\n\t\t\t\tDISPLAY CONTACTS";
	cout<<"\n\t\t***********************************************";
   // cout<<"\nName:\tAddress:\tMobile:\t\tPhone:\t\tEmail:\n";
  while(!stud.eof())
    {

	stud.getline(name,25, ' ');
	stud.getline(address,25, ' ') ;
	stud.getline(mobile,15, ' ');
	stud.getline(phone,15, ' ');
	stud.getline(email,25,'\n');
	cout<<"\n\t\t\t***************************";
	cout<<"\n\t\t\t    Name     :"<<name;
	cout<<"\n\t\t\t    Address  :"<<address;
	cout<<"\n\t\t\t    Mobile   :"<<mobile;
	cout<<"\n\t\t\t    Phone    :"<<phone;
	cout<<"\n\t\t\t    Email    :"<<email;
	cout<<"\n\t\t\t****************************\n\n";
	 delay(400);
    }
 cout<<"\n\t\t    Press any key to enter previous menu!!!";
 getch();
 system("cls");
}

void search_student(   )
{
    system("cls");
    cleardevice();
    setbkcolor(1);
    fstream stud;
    stud.open("contact.bin",ios::in);
    char a[25];
	cout<<"\n\n\n\n\t\t\t\tSEARCH CONTACTS";
	cout<<"\n\t\t***********************************************";
    cout<<" \n\t\t   enter the name to search contacts : ";
    cin.ignore();
    cin.getline(a,25);
    int x=0;
   while(!stud.eof())
   {
      stud.getline(name,25, ' ');
      stud.getline(address,25, ' ');
      stud.getline(mobile,15, ' ');
      stud.getline(phone,15, ' ');
      stud.getline(email,25,'\n');
      if(strcmp(name, a)==0)
       {
       cout<<"\n\n\n\t\tName    :"<<name;
       cout<<"\n\t\tAddress :"<<address;
       cout<<"\n\t\tMobile  :"<<mobile;
       cout<<"\n\t\tPhone   :"<<phone;
       cout<<"\n\t\tEmail   :"<<email;
       cout<<"\n";

	x=1;
	  //break;
      }
      delay(20);
   }
    if(x==0)
    {
	cout<<" \n\t\t\t\t not found !!!!\n";
    }

  stud.close();
  delay(200);
   cout<<"\n\t\t    Press any key to enter previous menu!!!";
   getch();
  system("cls");
  //menu();
}

void  insert_student()

{
 top:
      system("cls");
      setbkcolor(1);
      int len;
      int gd=DETECT, gm;
      initgraph(&gd, &gm, "..\\bgi");
      x=getmaxx();
      y=getmaxy();
      setbkcolor(1);
      outtextxy(x/2-50,y/2-150,"ADD CONTACTS");
      outtextxy(x/2-150,y/2-75,"Name        :");
      outtextxy(x/2-150,y/2-43,"Address     :");
      outtextxy(x/2-150,y/2-11,"Mobile      :");
      outtextxy(x/2-150,y/2+21,"Phone       :");
      outtextxy(x/2-150,y/2+53,"Email       :");
      rectangle(x/2-40,y/2-81,x/2+200,y/2-62);
      rectangle(x/2-40,y/2-49,x/2+200,y/2-30);
      rectangle(x/2-40,y/2-17,x/2+200,y/2+2);
      rectangle(x/2-40,y/2+15,x/2+200,y/2+34);
      rectangle(x/2-40,y/2+47,x/2+200,y/2+66);
    fstream stud;
    stud.open("contact.bin", ios::app);
    stud.seekg(0, ios::end);
    if (stud.tellg() != 0) {
      stud<<"\n";
     }
    cin.ignore();
    gotoxy(x/3+80,y/2+28);
    cin.getline(name,' ');
    gotoxy(x/3+80,y/2+30);
    cin.getline(address, ' ');
    gotoxy(x/3+80,y/2+32);
    cin>>mobile;
     len=strlen(mobile);
     if(len==10)
     {
	for(int i=0; i<10; i++)
	{
	   if(!(mobile[0]==57&&mobile[i]>=48&&mobile[i]<=57))
	   {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid mobile number";
	       delay(1000);
	       cleardevice();
	       goto top;
	   }
	   else
	   continue;
	}
     }
	else
	{
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid mobile number";
	       delay(1000);
	       cleardevice();
	       goto top;
	}
	len=0;
    gotoxy(x/3+80,y/2+34);
    cin>>phone;
    len=strlen(phone);
    if(len==9)
    {
       for(int i=0; i<9; i++)
       {
	  if(!(phone[i]>=48&&phone[i]<=57))
	  {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid phone number";
	       delay(1000);
	       cleardevice();
	       goto top;
	  }
	  else
	  continue;
       }
    }
    else
    {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid phone number";
	       delay(1000);
	       cleardevice();
	       goto top;
    }
    len=0;
    A:
    gotoxy(x/3+80,y/2+36);
    gets(email);
    len=strlen(email);
    int a=0;
    if(len>7)
    {
     for(int i=0;i<len;i++)
      {
       if(email[i]=='@'&&email[len-4]=='.'&&email[len-3]=='c'&&email[len-2]=='o'&&email[len-1]=='m')
	{
	  a=a+1;
	}
      }
       if(a!=1)
	 {
	       cleardevice();
	       cout<<"\n\n\n\t\t\tenter the valid email address!!!";

	       delay(1000);
	      cleardevice();
	       goto A;
	 }
       }
   else
   {    cleardevice();
	cout<<"\n\n\n\t\t\tenter the valid email address!!!";
	delay(1000);
	cleardevice();
	goto A;
   }
    stud<<name<<" ";
    stud<<address<<" ";
    stud<<mobile<<" ";
    stud<<phone<<" ";
    stud<<email;
    outtextxy(x/2-40,y/2+105,"**Added to file successfully**");
   delay(1000);
    stud.close();
    delay(200);
     cout<<"\n\n\n\t\t\t    Press any key to enter previous menu!!!";
    getch();
    system("cls");
}

void click(int *, int *, int *)
    {
       in.x.ax=3;
       int86(0x33, &in, &o);
       cl=o.x.bx;
       m=o.x.cx;
       n=o.x.dx;
    }

void menu()
{
  while (1)
    {
       system("cls");
       cleardevice();
       setbkcolor(1);
       int flag;
       cout<<"\n\n\n\n\t\t\t\tAdmin Session";
       cout<<"\n\t\t   *****************************************";
       cout<<"\n\t\t\t*******************************";
       cout<<"\n\t\t   *****************************************";
       cout << "\n\t\t\tImportant contact:  1 \n\t\t\t\t Insert  :  2 \n\t\t\t\t Search  :  3 \n\t\t\t\t Display :  4 \n\t\t\t\t Update  :  5 \n\t\t\t\t Delete  :  6 \n\t\t\t\t Recover :  7 \n\t\t\t\t Exit    :  8";
       cout<<"\n\t\t   *****************************************";
       cout<<"\n\t\t\t*******************************";
       cout<<"\n\t\t   *****************************************";
       cout<<"\n\t\t\t   Choose your option::";
       int c;
       cin>>c;
     switch (c)
     {
     case 1: imp_cont();
		break;
     case 2 :
	  insert_student();
	  break;
     case 3:
	   search_student();
	 break;
     case 4:
	 display_all();
	   break;
     case 5 :
	  update_student();
	  menu();
	   break;
     case 6 :
	delete_student();
	   break;
     case 7:
	recover_cont();
	break;
     case 8:
      welcome();
     default :
	    cout << " \n choose right number \n";
    }
  }
}


void login()
{

       char pass[9];
	top1:
       cleardevice();
       setbkcolor(1);
       int gd=DETECT, gm;
       initgraph(&gd, &gm, "..\\bgi");
       in.x.ax=1;
       int86(0x33, &in, &o);
       setbkcolor(1);
       settextstyle(DEFAULT_FONT, 0, 1);
       setlinestyle(SOLID_LINE,7, THICK_WIDTH);
       setfillstyle(SOLID_LINE, 3);
       outtextxy(x/3, y/2-50,"USER NAME:");
       rectangle(x/3+100, y/2-60, x/3+200, y/2-35);
       outtextxy(x/3+120, y/2-50,"ADMIN");
       outtextxy(x/3+3, y/2+5,"PASSWORD:");
       rectangle(x/3+100, y/2-5, x/3+200,y/2+20);
       outtextxy(x/3+140,y/2+55,"OK");
       rectangle(x/3+122,y/2+50,x/3+173,y/2+65);
       int i=0;
       while(i<8)
       {
	  gotoxy(x/3+85+i,y/2+33);
	  pass[i]=getch();
	  if(pass[i]==8)
	  {
	    cout<<"\b \b";
	    i--;
	    if(i<0)
	    {
	      cout<<"";
	      i++;
	    }
	  }
	  else if(pass[i]==13)
	    break;
	  else
	  {
	    cout<<"*";
	    i++;
	  }
	}
	  pass[i]='\0';
	  char hit;
	  while(!kbhit())
	  {
	     click(&m, &n, &cl);
	     if(m>(x/3+122) && m<(x/3+173) && n>(y/2+50) && n<(y/2+65) && cl==1)
	     {
	     entry:
	    if(strcmp(check,pass)==0)
	    {
	      setcolor(WHITE);
	      outtextxy(x/3+100,y/2+80,"Correct Password!!!");
	      delay(1000);
	      cleardevice();
	      menu();
	    }
	    else
	    {
	      setcolor(RED);
	      outtextxy(x/3+100,y/2+80,"Wrong Password!!!");
	      delay(1000);
	      cleardevice();
	      goto top1;
	    }
	 }
     }
}
void imp(char filename[30])
{
	system("cls");
	clrscr();
	cleardevice();
	setbkcolor(1);
	ifstream ifile;
	char s[100],file[30];
	strcpy(file,filename);
	ifile.open(file);
	if(!ifile)
	{
		cout<<"Error in opening file..!!";
		goto i;
	}
	else
	{
	  while(ifile.eof()==0)
	  {
	    ifile.getline(s,100);
	    cout<<s<<endl;
	  }
	ifile.close();
	}
	i:
	system("cls");
}
void imp_cont()
{
system("cls");
cleardevice();
   while(1)
   {
   system("cls");
   setbkcolor(1);
   int choice;
   cout<<"\n\n\n\n\t\t\t\tIMPOTRTANT CONTACTS";
   cout<<"\n\t\t***********************************************";
   cout<<"\n\t\t\t\t1.Fire Brigade \n\t\t\t\t2.Blood Bank \n\t\t\t\t3.Hospitals\n\t\t\t\t4.Ambulance\n\t\t\t\t5.Police Stations\n\t\t\t\t6.Exit";
   cout<<"\n\t\t***********************************************";
   cout<<"\n\t\t\tMake the choice::";
   cin>>choice;
   switch(choice)
   {
      case 1:imp("fire.txt");
		getch();
		break;
      case 2:imp("blood.txt");
		getch();
		break;
      case 3:imp("hospital.txt");
		getch();
		break;
      case 4:imp("amb.txt");
		getch();
		break;
      case 5:imp("police.txt");
		getch();
		break;
      case 6:goto j;
      default:cout<<"  Enter the correct choice!!!";
   }
  }
  j:
}

void guest()
{
    system("cls");
    cleardevice();
    setbkcolor(1);
  while (1)
    {
       cleardevice();
       int flag;
       cout<<"\n\n\n\n\t\t\t\tGuest Session";
       cout<<"\n\t\t   *****************************************";
       cout<<"\n\t\t\t*******************************";
       cout<<"\n\t\t   *****************************************";
       cout << "\n\t\t\t\tSearch  :  1 \n\t\t\t\tDisplay :  2 \n\t\t\t\tImportant Contacts :  3 \n\t\t\t\tExit    :  4";
       cout<<"\n\t\t   *****************************************";
       cout<<"\n\t\t\t*******************************";
       cout<<"\n\t\t   *****************************************";
       cout<<"\n\t\t\t   Choose your option::";
       int c;
       cin>>c;
     switch (c)
     {
	 case 1:
		search_student();
		break;
	 case 2:
		display_all();
		break;
	 case 3:
		imp_cont();
		break;

	 case 4:
		 welcome();
	 default :
	    cout << " \n choose right number \n";
     }
  }
  system("cls");
}


void welcome()
{
   int gd=DETECT, gm;
   initgraph(&gd, &gm, "..\\bgi");
   in.x.ax=1;
   int86(0x33, &in, &o);
    for(int a=2;a<=315;a+=8)
       {
	 setcolor(a-1);
	 outtextxy((x/2)-153+a, (y/3)-134," * ");
	 outtextxy((x/2)-153+a, (y/2)-25," * ");
       }
       for(int i=2;i<=180;i+=8)
       {
	  outtextxy((x/3)-38, (y/3)-(130-i),"* ");
	  outtextxy((x)-150, (y/3)-130+i, "*");
       }
       setcolor(GREEN);
       settextstyle(TRIPLEX_FONT, 0, 3);
       outtextxy(x/2-30, y/4-60,"Welcome");
       outtextxy(x/2+10, y/4-30,"to");
       outtextxy(x/2-105, y/4,"Contact Management");
       outtextxy(x/2-20, y/4+30,"System");
       setlinestyle(SOLID_LINE,7, THICK_WIDTH);
       rectangle(x/3-20,y/2,x/2, y/2+30);
       outtextxy(x/3+10, y/2,"ADMIN");
       rectangle(x/2+30,y/2,x/2+160, y/2+30);
       outtextxy(x/2+58, y/2,"GUEST");
       rectangle(x/2-40,y/2+80,x/2+55,y/2+110);
       outtextxy(x/2-15,y/2+80,"Exit");
       while(!kbhit())
       {
	  click(&m, &n, &cl);
	  if(m>(x/3-20) && m<(x/2) && n>(y/2) && n<(y/2+30) && cl==1)
	  {
	  cleardevice();
	  setbkcolor(1);
	      cout<<"\n\n\n\n\n\n\t\t   *****************************************";
	      cout<<"\n\t\t\t*******************************";
	      cout<<"\n\t\t   *****************************************";
	      cout<<"\n\t\t\t    Welcome to Admin Pannel";
	      cout<<"\n\t\t   *****************************************";
	      cout<<"\n\t\t\t*******************************";
	      cout<<"\n\t\t   *****************************************";
	       delay(2000);
	       cleardevice();

	     login();

	    // menu();
	  }
	  else if(m>(x/2+30) && m<(x/2+160) && n>(y/2) && n<(y/2+30) && cl==1)
	  {
		  cleardevice();
		  setbkcolor(1);
	      cout<<"\n\n\n\n\n\n\t\t   *****************************************";
	      cout<<"\n\t\t\t*******************************";
	      cout<<"\n\t\t   *****************************************";
	      cout<<"\n\t\t\t    Welcome to Guest Pannel";
	      cout<<"\n\t\t   *****************************************";
	      cout<<"\n\t\t\t*******************************";
	      cout<<"\n\t\t   *****************************************";
	       delay(2000);
	       cleardevice();
	     guest();
	    // exit(0);
	  }
	  else if(m>(x/2-40) && m<(x/2+55) && n>(y/2+80) && n<(y/2+110) && cl==1)
	  {
		exit(0);
	  }
	}
}


int main()
{

   int gd=DETECT, gm;
   initgraph(&gd, &gm, "..\\bgi");
   in.x.ax=1;
   int86(0x33, &in, &o);
   x=getmaxx();
   y=getmaxy();
   welcome();

    getch();
    return 0;
}

