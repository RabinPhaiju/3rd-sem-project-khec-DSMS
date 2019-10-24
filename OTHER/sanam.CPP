#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
int admin_limit=1;
void graphics()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
}

////// classes  ///////

class reviews
{

  char comments[400];
  char user;
  public:
  void set(char u)
  {
     cleardevice();
     system("cls");
     user=u;
     cout<<"\n\n\t\tenter the feedbacks:\n";
     gets(comments);
  }
  void display()
  {
     //clrscr();
     cout<<"\n"<<user<<":-"<<comments<<endl;
  }
};
class vender
{
char name[20];
char email[20];
char no[10];
public:
void set();
void display();
};

class admin
{
	char username[40];
	char password[40];
	char name[40];
	char  number[10];
	char address[60];
	public:
	void reg();
	void display();
	void login();

};
class employee
{
       char username[30];
       char password[30];
       char name[40];
       char address[60];
       char number[15];
       int length;
   public:
       void reg();
       void display();
       friend void login();

};

class mobile
{
     public:
     char model[20],ram[6],brand[20],rcamera[20],fcamera[20],processor[20],rom[10];
     char description[50];
     int id;
     long qty;
     float gross;
     long long price;
     void set();
     friend void search();
     friend void bill();
} ;


class costumer
{
public:
char name[30];
char contact[10];

};

int check_no(char c[10])     ///// phone number check /////
{
  if(strlen(c)==10)
  {
    for(int i=0;i<10;i++)
    {
       if(!(c[i]>=48&&c[i]<=57))
	{
	   return (0);
	}
     }
    if(!(c[0]==57))
     {
       return (0);
     }
    else
       return (1);
   }
   else
   {
     return (0);
    }
  // getch();
 }



int check(int x);
void delete_mobile()

{
    mobile m;
    fstream file;
    int a;
    fstream temp;
    file.open("mobile.txt",ios::in|ios::binary);
    temp.open("temp.txt",ios::out|ios::binary);
    //cin.ignore();
    cout<<" \n\t enter the mobile id (only integers) to delete record : ";
    //cin.getline(a,25);
    cin>>a;
     if(check(a)==0)
     {
       cout<<"\n\t\tdelete unsecessful";
       getch();
     }
     else{
    file.read((char*)&m,sizeof(m));
    while(!file.eof())
    {
   //	file.read((char*)&m,sizeof(m));
	if(m.id==a)
	{
	   file.read((char*)&m,sizeof(m));
	   // continue;
	}
	else

	{
	    temp.write((char*)&m,sizeof(m));
	    file.read((char*)&m,sizeof(m));
	}

	//file.read((char*)&m,sizeof(m));
    }
    file.close();
  temp.close();
    file.open("mobile.txt",ios::out|ios::binary);
    temp.open("temp.txt",ios::in|ios::binary);
    temp.read((char*)&m,sizeof(m));
    while(!temp.eof())
    {
	file.write((char*)&m,sizeof(m));
	temp.read((char*)&m,sizeof(m));
   }
    temp.close();
  file.close();
   remove("temp.txt");
   cout<<"\n done !!! \n";
}
}

void employee::display()
{
  //clrscr();

	 cout<<name<<"\t\t"<<username<<"\t"<<number<<"\t"<<address<<endl;

}

void admin::display()
{
  clrscr();
  system("cls");
	cout<<"\t\t\tadmin\n"<<name<<"\n"<<number<<"\n"<<username<<"\n"<<address<<"\n"<<password<<endl;

}

void admin::reg()
{

	char ch;
	int i=0;
	char pwd[40],temp[40];
	cout<<"\t\tadmin registration\n";
	cout<<"\n enter the name: ";
	gets(name);
	cout<<"\nusername: ";
	gets(username);
	int flag;
  c:
  cout<<"\nEnter mobile no.:";
  gets(number);
  flag=check_no(number);
  if(flag!=1)
  {
	cout<<"\nINVALID NUMBER";
	delay(1000);
	goto c;
  }
	cout<<number;
	cout<<"\naddress :";
	gets(address);
	cout<<"\npassword: ";
	for(i=0;;i++)
	{
		a:
		ch=getch();

		if(int(ch)==13)
		{
		pwd[i]='\0';
		break;
		}
		if(int(ch)==8)
		{
			if(i==0)
			goto a;
			cout<<"\b \b";
			i--;
			goto a;
		}
		pwd[i]=ch;
		cout<<"*";
	}

	strcpy(temp,pwd);
	cout<<"\nre enter the password:";
	x:
	for (i=0;;i++)
	{
		b:
		ch=getch();

		if(int(ch)==13)
		{
		pwd[i]='\0';
		break;
		}
		if(int(ch)==8)
		{
			cout<<"\b \b";
			i--;
			goto b;
		}

		pwd[i]=ch;
		cout<<"*";
	}

	if(strcmp(temp,pwd)==0)
	{

	strcpy(password,pwd);
	admin_limit++;
		clrscr();
		cout<<"\n\tRegestered Sucessfully\n";
		delay(1000);

		//display();
	}
	else
	{
	cout<<"\n\tpassword didnt match please re-enter it";
	goto x;
	}
}


void admin_menu();
void admin::login()
{
	cout<<"\n\n\t\talogin\n";
	clrscr();
	cleardevice();
	system("cls");
	char name[30];
	char pass[30];
	char ch;
	x:
	clrscr();
	cout<<"\n\n\t\t\tADMIN LOGIN";
	cout<<"\n\t\tenter the username :";
	gets(name);
	cout<<"\n\n\t\tpassword : ";
	//ch=getch();
		for(int i=0;;i++)
	{
		a:
		ch=getch();

		if(int(ch)==13)
		{
		pass[i]='\0';
		break;
		}
		if(int(ch)==8)
		{
			cout<<"\b \b";
			i--;
			goto a;
		}
		pass[i]=ch;
		cout<<"*";
	}

	//cout<<"\nthe entered password is : "<<pass<<endl;
       //	cout<<"\t"<<strcmp(pass,password);


       //	cout<<"\n\t adress \tnumber\t name ";
	//cout<<"\n\t "<<address<<" \t"<<number<<"\t"<<name<<endl;
	//cout<<"\nread username: "<<username<<"\tread password "<<password;


	if(strcmp(username,name)==0)
	   {

	      cout<< "\n\t\tusername verified";

	       if(strcmp(password,pass)==0)
		{
		   clrscr();
		   cout<<"\n\n\n\n\t\t\tcorrect password";
		   cout<<"\n\n\t\t\tplease wait";
		   delay(1000);
		   cleardevice();
		   admin_menu();
		}

	      else
		{

		cout<<"\n\t\tpasword didnt match\n\tplease try again !!!!!";
		getch();
		}
	   }


	      else
		{
		cout<<"\n username and pasword didnt match\n\tplease try again !!!!!";
		getch();
		goto x;
		}

    }

//***************************  employ  regestration and login***********************
void first_page();
void employee_menu();
void login()
{
	//cleardevice();
	clrscr();
	system("cls");
	x:
	cout<<"\n\n\n\t\t\tEMPLOYEE LOGIN\n";
	int access=0;
	char name[30];
	char pass[30];
	char ch;

	employee e;
	ifstream fin;
	fin.seekg(0,ios::beg);
	fin.open("employee.txt",ios::in|ios::binary);
  if(fin)
  {
	cout<<"\n\t\tenter the username :";
	gets(name);
	cout<<"\n\t\tpassword : ";
	//ch=getch();
		for(int i=0;;i++)
	{
		a:
		ch=getch();

		if(int(ch)==13)             //in case of back space
		{
		pass[i]='\0';
		break;
		}
		if(int(ch)==8)
		{
			cout<<"\b \b";
			i--;
			goto a;
		}
		pass[i]=ch;
		cout<<"*";
	}

       //	cout<<"\nthe entered password is : "<<pass<<endl;

		while(!fin.eof())
       {

	fin.read((char *)&e,sizeof(e));
       //	cout<<"\t"<<strcmp(pass,e.password);

      /*	cout<<"\n\t adress \tnumber\t name ";
	cout<<"\n\t "<<address<<" \t"<<number<<"\t"<<name<<endl;
	cout<<"\nread username: "<<username<<"\tread password "<<password;
	*/

	if(strcmp(e.username,name)==0)
	   {

	      cout<< "\n\t\tusername verified";

	       if(strcmp(e.password,pass)==0)
		{
		   clrscr();
		   cout<<"\n\n\t\t\tACCESS GRANTED";
		   cout<<"\n\t\tcorrect password";
		   cout<<"\n\n\t\tplease wait";
		   delay(1000);
		   access=1;
		   cleardevice();
		   employee_menu();
		   break;
		}

	      else
		{
		cout<<"\n\t\tpassword didnt match for found username\n\tplease try again !!!!!";
		getch();
		break;
		}
	   }


	      //else{}
      }
      fin.close();
      if(access!=1)
      {
      cout<<"\n username and pasword didnt match(not found)in database\n\tplease try again !!!!!";
      goto x;
      }
   }

   else
   {
     cout<<"\n\n\n\t\tNONE REGISTERED";
     getch();
     first_page();
   }
}

// %%%%%%%%%%%%%%    employ menu ko function haru

mobile search(int x)
{
   //int flag=0;
   //cleardevice();
   //system("cls");
   mobile y;
   ifstream fin;
   fin.open("mobile.txt",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   while(!fin.eof())
   {
      fin.read((char *)&y,sizeof(y));
      if(x==y.id)
      {
    //	flag=1;
	return(y);
	//break;
      }
      else
      {
      continue;
      }
   }
 //  if(flag!=1)
 //  {
     cout<<"\nmobile not found";
	 y.price=0;
	 return (y);
	 //getch();
	 //break;
  // }
}


int check(int x)     /////////////////  checking id for set()  ///////
{
   //int flag=0;
   mobile y;
   ifstream fin;
   fin.open("mobile.txt",ios::in|ios::binary);
   if(fin)
   {
	fin.seekg(0,ios::beg);
   while(!fin.eof())
   {
      fin.read((char *)&y,sizeof(y));
      if(x==y.id)
      {
    //	flag=1;
	return(1);
	//break;
      }
      else
      {
      continue;
      }
   }
 //  if(flag!=1)
 //  {
 //    cout<<"\nmobile not found";
     //	 y.price=0;
	 return (0);
	 //getch();
	 //break;
  // }
   }
   else
   {
     return 0;
   }

}

void analysis()
{
  clrscr();
  mobile x,y;
  float a=0.0,b=0.0;
  float profit,loss;
  ifstream bought("mobile.txt",ios::in|ios::binary);
  ifstream sold("sold.txt",ios::in|ios::binary);
  if(sold)
  {
     cout<<"\n\n\n\n\n\tTotal money spent on inventory is : Rs ";
     bought.read((char*)&x,sizeof(x));
     while(!bought.eof())
     {
       a=a+x.qty*x.price;
       bought.read((char*)&x,sizeof(x));
     }
     cout<<a<<endl;

     cout<<"\n\tTotal money from sold mobiles is : Rs ";
     sold.read((char*)&y,sizeof(y));
     while(!sold.eof())
     {
       b=b+y.gross;
       sold.read((char*)&y,sizeof(y));
     }
     cout<<b<<endl;
     cout<<"\n------------------------------------------------------------\n";
     if(a<=b)
     {cout<<"\tTotal profit is: Rs "<<(b-a)<<endl;
     getch();
     }
     else
     {
     cout<<"\tThere is loss of Rs "<<(a-b);
     getch();
     }


  }
  else
  {
     bought.read((char*)&x,sizeof(x));
     while(!bought.eof())
     {
       a=a+x.qty*x.price;
       bought.read((char*)&x,sizeof(x));
     }
    cout<<"\n\n\n\n\tThere has not been any sales yet\n\tSo,there is loss of Rs "<<(a-b);
     getch();
  }
  bought.close();
  sold.close();
}

void bill()
{

   clrscr();
   cleardevice();
   system("cls");
   mobile m;
   costumer c;
   int id,flag;
   long quantity;
   float tax,net_amount,gross;

   cout<<"\t\tbill function\n\n";
   a:
   cout<<"\nmobile id:";
   cin>>id;
   m=search(id);
   if(m.price==0)
   {
     goto a;

   }
   else
   {
   cout<<"\nname of the customer:";
   gets(c.name);

  c:
  cout<<"\nEnter mobile no.:";
  gets(c.contact);
  flag=check_no(c.contact);
  if(flag!=1)
  {
	cout<<"\nINVALID NUMBER";
	delay(1000);
	goto c;
  }
  // cout<<"\ncontact no(mobile):";
   cout<<c.contact;
   q:
   cout<<"\nquantity:";
   cin>>quantity;
   if(m.qty<quantity)
   {
       cout<<"\n limit exeeded!!!!!!";
       goto q;
   }
   cout<<"\ntax:";
   cin>>tax;
   gross=m.price+(m.price*(tax/100));
   net_amount=(gross*quantity);
 /*  cout<<"net-amount=";
   cout<<net_amount;
   */
   clrscr();
   printf("\n\n\t\t______________________________________________________\n");
   printf("\n\t\t\t\tBILL VOUCHER\n");
   printf("\t\t To: Mr/Mrs %s\n",c.name);
   printf("\t\t______________________________________________________\n");
   printf("\n\t\t SN\tparticulars\trate\tQTY\ttotal\n\n");
//   printf("\n\t\t  1\t%s\t\t%d\t%d\t%d\n",m.brand,m.price,quantity,(m.price*quantity));
   cout<<"\t\t  1\t"<<m.brand<<"\t\t"<<m.price<<"\t"<<quantity<<"\t"<<(m.price*quantity)<<endl;

   printf("\n\n\t\t \t\t\tincluding tax:\tRs %.2f only\n",net_amount);

   scanf("");
   m.gross=net_amount;
   //m.qty=quantity;
   ofstream record("sold.txt",ios::app|ios::binary);
   record.write((char*)&m,sizeof(m));
   record.close();
   getch();
   }
}

void review(char U)
{
   char ch='s';
   fstream box;
   reviews x;
		    while(ch!=27)
		    {
   clrscr();
   cout<<"\n\n\t\treview function\n\nPress 'a' to give your review\n";
   box.open("review.txt",ios::in|ios::binary);
   if(box)
   {
	box.seekg(0,ios::beg);
	box.read((char*)&x,sizeof(x));
	while(!box.eof())
	{
	  x.display();
	  box.read((char*)&x,sizeof(x));
	}
	box.close();
	ch=getch();
   }
   else
   {
	box.close();
	box.open("review.txt",ios::out|ios::binary);
	x.set(U);
	box.write((char*)&x,sizeof(x));
	box.close();
}
   if(ch=='a'||ch=='A')
   {
      box.open("review.txt",ios::app|ios::binary);
	x.set(U);
	box.write((char *)&x,sizeof(x));
	box.close();
   }


   }

}


void searching()
{
 clrscr();
 cleardevice();
 cout<<"\n\n\n \t\t*** searching   ***\n\n";
 while(1)
 {
 clrscr();
 cout<<"\tPress keys to choose your options\n\n";
 cout<<"\t1.By Brand\n";
 cout<<"\t2.By Price range\n";
 cout<<"\t3.Exit\n";
 switch(getch())
{
 case '1':
	   {

	   clrscr();
	   cleardevice();
	    system("cls");
	    mobile y;
	   ifstream fin;
	   fin.open("mobile.txt",ios::in|ios::binary);
	   fin.seekg(0,ios::beg);
	   char brand_name[20];
	   int x;
	   cout<<"\nEnter the brand: ";
	   gets(brand_name);
	   clrscr();
	   cout<<"\n\n\nBRAND\tMODEL\tID\tPRICE\tQTY\tRAM\tPROCESSOR\tCAMERA\n\n";
	   fin.read((char *)&y,sizeof(y));
	   //fin.seekg(0,ios::beg);
		while(!fin.eof())
		{

		x=strcmp(y.brand,brand_name);
		if(x==0)
			{
			       //	fin.read((char*)&y,sizeof(y));

			cout<<y.brand<<"\t"<<y.model<<"\t"<<y.id<<"\t"<<y.price<<"\t"<<y.qty<<"\t"<<y.ram<<"\t"<<y.processor<<"\t"<<y.fcamera<<"\t"<<y.rcamera;
			cout<<endl;
				fin.read((char*)&y,sizeof(y));

					}
		else
			{
			fin.read((char*)&y,sizeof(y));
		  //	pos=fin.tellg();
			//continue;
			}
		}
		fin.close();
		getch();
	   }break;


 case '2':
	  {

	   clrscr();
	    cleardevice();
	    system("cls");
	    mobile y;
	   ifstream fin;
	   fin.open("mobile.txt",ios::in|ios::binary);
	   fin.seekg(0,ios::beg);
	   long long max;
	   //int x;
	   cout<<"\n\n\nEnter max affordable price: ";
	   cin>>max;
	   clrscr();
	   cout<<"\n\n\nBRAND\tMODEL\tID\tPRICE\tQTY\tRAM\tPROCESSOR\tCAMERA\n\n";
	   fin.read((char *)&y,sizeof(y));
	   //fin.seekg(0,ios::beg);
		while(!fin.eof())
		{

		//x=strcmp(y.brand,brand_name);
		if(y.price<=max)
			{
			       //	fin.read((char*)&y,sizeof(y));

			cout<<y.brand<<"\t"<<y.model<<"\t"<<y.id<<"\t"<<y.price<<"\t"<<y.qty<<"\t"<<y.ram<<"\t"<<y.processor<<"\t"<<y.fcamera<<"\t"<<y.rcamera;
			cout<<endl;
				fin.read((char*)&y,sizeof(y));

					}
		else
			{
			fin.read((char*)&y,sizeof(y));
		  //	pos=fin.tellg();
			//continue;
			}
		}
		fin.close();
		getch();
	   }break;


 case '3':
	  cleardevice();
	  system("cls");
	  employee_menu();
	  break;
 }
}
}
void employee_menu()          //shows after employee logs in
{
 while(1)
 {
 clrscr();

 graphics();
 setcolor(GREEN);
 outtextxy(245,100,"Employee Menu");
 outtextxy(200,150,"Enter the option");
 outtextxy(200,170,"1.Search");
 outtextxy(200,190,"2.Create Bill");
 outtextxy(200,210,"3.Update Review");
 outtextxy(200,230,"4.Logout");
 rectangle(180,165,400,250);
 /*
 cout<<"\n\n\n\temployee menu";
 cout<<"\tenter the options\n";
 cout<<"1.search\n2.create bill\n3.update review\n4.logout\n";
 */
 switch(getch())
 {
	  case '1':
		 system("cls");
		 searching();
		 break;
	  case '2':
		system("cls");
		bill();
		break;
	  case '3':
		system("cls");
		review('E');
		break;

	  case '4':
		//exit(1);
		first_page();
		break;
	  default:
	  cout<<"\n*******invalid choice try another*******\n";
	  break;
    }

// getch();
}
  }
void employee::reg()
{

	cleardevice();
	system("cls");
	char ch;
	int i=0;
	char pwd[30],temp[30];
	cout<<"\n\t\temployee regestration\n";
	cout<<"\n enter the name: ";
	gets(name);
	cout<<"\nusername: ";
	cin>>username;;
		int flag;
  c:
  cout<<"\nEnter mobile no.:";
  gets(number);
  flag=check_no(number);
  if(flag!=1)
  {
	cout<<"\nINVALID NUMBER";
	delay(1000);
	goto c;
  }
	cout<<number;
	cout<<"\naddress :";
	gets(address);
	cout<<"\npassword: ";
	for(i=0;;i++)
	{
		a:
		ch=getch();

		if(int(ch)==13)
		{
		pwd[i]='\0';
		break;
		}
		if(int(ch)==8)
		{
			cout<<"\b \b";
			i--;
			goto a;
		}
		pwd[i]=ch;
		cout<<"*";
	}

	strcpy(temp,pwd);
	cout<<"\nre enter the password:";
	x:
	for (i=0;;i++)
	{
		b:
		ch=getch();

		if(int(ch)==13)
		{
		pwd[i]='\0';
		break;
		}
		if(int(ch)==8)
		{
			cout<<"\b \b";
			i--;
			goto b;
		}

		pwd[i]=ch;
		cout<<"*";
	}

	if(strcmp(temp,pwd)==0)
	{

	strcpy(password,pwd);
       //	admin_limit++;
		clrscr();
		cout<<"\n\n\t\tRegestered Sucessfully\n";
		delay(1000);
		display();
	}
	else
	{
	cout<<"\n\tpassword didnt match please re-enter it";
	goto x;
	}
}




  /*
	fout.write((char*)&e1,sizeof(e1));
	e1.length=fout.tellp();
	cout<<"\n"<<e1.length;
	fout.close();


*/



// **********************  mobile part of the program*********************

void mobile::set()
{ //cleardevice();
//system("cls");
   {
      cout<<"\n enter the speceficaion of the mobile: below\n";
      delay(500);
      cout<<"\nbrand		: ";gets(brand);
      cout<<"\nmodel		:";gets(model);
      a:
      cout<<"\nid		:";cin>>id;
      if(check(id)==1)
      {
	cout<<"\n ID ALREADY EXIST, \n TRY AGAIN !!!";
	goto a;
      }
      cout<<"\nprice		:"; cin>>price;
      cout<<"\nfront camera	:"; gets(fcamera);
      cout<<"\nrare camera	:";gets(rcamera);
      cout<<"\nprocessor	:";gets(processor);
      cout<<"\nrom		:";gets(rom);
      cout<<"\nram		:";gets(ram);
      cout<<"\nquantity		:";cin>>qty;
      cout<<"\nExtra description:";gets(description);
     }

}
void add()
{
  clrscr();
  cleardevice();
  system("cls");
  char choice='y';
  ofstream fout;
  mobile m;

  while(choice=='y')
  {

    m.set();
    fout.open("mobile.txt",ios::app|ios::binary);
    fout.write((char*)&m,sizeof(m));
  fout.close();


  cout<<"\n want to continue  y/n ? \n press y to continue ";
  cin>>choice;
  }
}


void display()
{
    cleardevice();
    system("cls");
    char ch='s';
    ifstream fin;
    fin.open("mobile.txt",ios::in|ios::binary);
    if(fin)
    {fin.seekg(0,ios::beg);
    clrscr();
    mobile m;
    cout<<endl;
    cout<<"NOTE:- Press 'd' to delete any content\n";
    cout<<"NOTE:- Press 'a' to analyze profit or loss\n\n\n";
    cout<<"BRAND\tMODEL\tID\tPRICE\tQTY\tRAM\tPROCESSOR\tCAMERA\n";
	fin.read((char*)&m,sizeof(m));
    while(!fin.eof())
    {

	cout<<m.brand<<"\t"<<m.model<<"\t"<<m.id<<"\t"<<m.price<<"\t"<<m.qty<<"\t"<<m.ram<<"\t"<<m.processor<<"\t"<<m.fcamera<<"\t"<<m.rcamera;
	cout<<endl;
		fin.read((char*)&m,sizeof(m));
    }
    ch=getch();
    fin.close();
       if(ch=='d'||ch=='D')
       {
	 delete_mobile();
       }
       else if(ch=='A'||ch=='a')
       {
	 analysis();
       }


     }
     else
     {

       cout<<"\n\n\tINVENTORY EMPTY !!!!";
       getch();
     }
}


////////////////////////vendor///////////////////////////


void vender::display()
{
	cout<<name<<"\t";
	for(int i=0;i<10;i++)
	{cout<<no[i];
	}
	cout<<"\t"<<email<<"\n";
}
//void check_mail(char email[40])


void vender::set()
{
	//cleardevice();
	//system("cls");
	int range,l,a=0,flag;
	cout<<"Enter the name:";
	gets(name);
	g3:
	cout<<"Enter the email address:";

   gets(email);
   l=strlen(email);
   if(l>5)
   {
		for(int i=0;i<l;i++)
		{
		if(email[i]=='@'&&email[l-4]=='.'&&email[l-3]=='c'&&email[l-2]=='o'&&email[l-1]=='m')
		 {
			a=a+1;
		 }
		}
	if(a!=1)
	{
	cout<<"\t\tInvalid email id\n";
	goto g3;
	}
   }
  else
  {
    cout<<"\t\t\tInvalid email id\n";
    goto g3;
  }


  c:
  cout<<"\nEnter mobile no.:";
  gets(no);
  range=strlen(no);
  no[range+1]='\0';
  flag=check_no(no);
  if(flag!=1)
  {
	cout<<"\nINVALID NUMBER";
	delay(1000);
	goto c;
  }

}

void vendor()
{
cleardevice();
system("cls");
  char c='s';
vender vd;
ofstream fout;
ifstream fin;
	while(c!=27)
	{
	clrscr();
	cout<<"\n\n\t\t\t VENDOR INFO \n\n\npress 'a' to add the vendor\t\n\n\n";
	fin.open("Vendor.txt",ios::in|ios::binary);
	if(fin)
	{
	fin.seekg(0,ios::beg);
	fin.read((char*)&vd,sizeof(vd));
	   while(!fin.eof())
	   {
	  vd.display();
	  fin.read((char*)&vd,sizeof(vd));
	   }
	 fin.close();
	 c=getch();
	}
	else
	{
		fin.close();
		fout.open("vendor.txt",ios::out|ios::binary);
		cout<<"\nnew file\n";
		vd.set();
		fout.write((char*)&vd,sizeof(vd));
		fout.close();
	    //	goto a;
	}

if(c=='a'||c=='A')
{
fout.open("Vendor.txt",ios::app);
cout<<"\nappend mode\n";
vd.set();
fout.write((char*)&vd,sizeof(vd));
fout.close();
//goto a;
}

  }
 // getch();
}

void employe_detail()
{
	clrscr();
	cleardevice();
	system("cls");
	employee e1;
	ifstream fin("employee.txt",ios::in|ios::binary);
	if(fin)
	{
	fin.seekg(0,ios::beg);
	cout<<"\n\n\n\nname:\t\t\tusername:  contact no:\taddress\n\n";
		fin.read((char*)&e1,sizeof(e1));
	while(!fin.eof())
	{

	e1.display();
		fin.read((char*)&e1,sizeof(e1));
	}
	fin.close();
	}
	else
	{
	  cout<<"\n\n\t*******  NO ANY EMPLOYEEs YET !   ********";
	}
	getch();

}


void admin_menu() 		//shows after admin logs in

{ //int choice;
 while(1)
  {
    clrscr();
    graphics();
    setcolor(GREEN);
    outtextxy(245,50,"ADMIN PANEL");
    outtextxy(220,80,"Enter the options");
    outtextxy(200,100,"1.Add mobiles to the list");
    outtextxy(200,120,"2.Display the inventory");
    outtextxy(200,140,"3.Employee Registration");
    outtextxy(200,160,"4.Edit vendor info");
    outtextxy(200,180,"5.Display employee details");
    outtextxy(200,200,"6.Reviews from employee");
    outtextxy(200,220,"7.Back to Main Menu");
    rectangle(195,90,410,245);
    rectangle(240,40,340,70);

    /*
    cout<<"\n\t\t\tADMIN PANNEL\n\n";
    cout<<"\nenter the option\n";
    cout<<"\n1.Add mobiles to the list\n";
    cout<<"\n2.Display the inventory\n";
    cout<<"\n3.Employee regestration\n";
    cout<<"\n4.Edit vendor info\n";
    cout<<"\n5.Display employes details\n";
    cout<<"\n6.Reviews from employee\n";
    cout<<"\n7.Back to main menu\n";

    */
    switch(getch())
    {
	  case '1':
		 system("cls");
		 add();
		 break;
	  case '2':
		system("cls");
		display();
		break;
	  case '3':

		employee e1;
		ofstream fout;
		fout.open("employee.txt",ios::app|ios::binary);
		system("cls");
		e1.reg();
		fout.write((char*)&e1,sizeof(e1));
		fout.close();
		break;

	  case '4':
		system("cls");
		vendor();
		break;
	  case '5':
		system("cls");
		employe_detail();
		break;
	  case '6':
		system("cls");

		review('A');
		break;
	  case '7':
		system("cls");
		first_page();
		break;
	  default:
	  cout<<"\n*******invalid choice try another*******\n";
	  break;
    }
  }
}


void first_page()           // shown as main menu
{
	clrscr();
	char choice;
	while(1)
	{

	graphics();
	setbkcolor(BLACK);
	setcolor(GREEN);
		outtextxy(200,100,"Mobile-Store Management System");
		 rectangle(180,120,450,90);
//printf("****************************************************************************************)")
	outtextxy(245,130,"Choose your option");
	outtextxy(245,150,"1.admin login");
	outtextxy(245,170,"2.employee login");
	outtextxy(245,190,"3.info");
	outtextxy(245,210,"4.exit");
	rectangle(225,225,400,140);

       /*	cout<<"\nchoose your option"<<endl;
	cout<<"1.admin login"<<endl;
	cout<<"2.employee login"<<endl;
	cout<<"3.info\n";
	cout<<"4.exit\n";  */


	cin>>choice;
	switch(choice)
	{
	 case '1':
		system("cls");
		admin o;
		ifstream fin1;
		fin1.open("userbook.txt",ios::in|ios::binary);
		fin1.seekg(0,ios::beg);
		fin1.read((char *)&o,sizeof(o));
		o.login();
		fin1.close();
		break;
	 case '2':
		cleardevice();
		system("cls");
		login();
		break;

	 case '3':
		{clrscr();
		cleardevice();
		system("cls");
		cout<<"\t\t\t\t!!!Help!!!\n\n"<<endl;
	cout<<"\t-> Only admin has an authority to assign employee & vendors\n\n";
	cout<<"\t-> Both employee & admin can login separately\n\n";
	cout<<"\t-> Incase ENTER key doesn't respond, use ESC key\n\n";
	cout<<"\t-> Bill vouchers are displayed via employee login\n\n";
	cout<<"\t-> In review option, A denotes review from admin & E from employee\n\n";
	cout<<"\t-> Search can be done by price-range or by brand\n\n";
	cout<<"\t-> Just press the particular keys to choose the options\n\n";

		cout<<"\t\t\t!!!!!!!  WE TEAM MATES  !!!!!";
		getch();
		first_page();
		}
		//break;
	 case '4':
		exit(1);
	 default:
		cout<<"\nchoice invalid\n try again!!!";
		getch();
		break;
	}
	 }

}
void main()                   // where the program starts
{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t*********************\tWELCOME\t*********************\n";
	delay(1000);
	ifstream owner("userbook.txt",ios::in|ios::binary);
	if(owner)
	{
	   first_page();
	   //break;
	}
	else
	{
	   if(admin_limit<=1)
		{
		admin a1;
		ofstream owner;
		owner.open("userbook.txt",ios::out|ios::binary);
	   clrscr();
	   cout<<"\t\tBEGINING ADMIN REGISTRATION\n";
	   delay(500);

		a1.reg();
		owner.write((char*)&a1,sizeof(a1));
		owner.close();

		}
		else
		{clrscr();
		system("cls");
		cout<<"\n\n**********  SORRY !!!!!! there cant be more than one admin ";
		getch();
		}
		//break;
	}
       //	getch();
       first_page();

}


