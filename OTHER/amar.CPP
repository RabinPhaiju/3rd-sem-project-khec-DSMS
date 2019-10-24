#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
//****************************************************************
//                 CLASS:  DOCTOR INFO DATABASE
//****************************************************************

void bar()                   //creating a table as bar
{
 bar(140,60,141,380);       // bar(int left, int top, int right, int bottom);
 bar(140,60,521,61);
 bar(520,61,521,380);
 bar(141,380,521,380);
 bar(140,110,520,111);
}

class employee
{
  public:
  char pass_e[10],cat;
  char name_employee[50],address[50],email[50];
  char qualification[50],specilization[50],experience[50];
  int id_no;
  char num[10],age[2];

  void get_employee_info();
  void get_e();
  void employee_display();
  void txt();
};

void employee::get_employee_info()          //create unquie id no.
{
   fstream f;                               //file mode both in read write mode
   int i=1;
   employee emp;
   f.open("ef2.txt",ios::in|ios::binary);
   f.seekg(0,ios::beg);
   f.read((char *)&emp,sizeof(emp));
   while(!f.eof())
   {
     i++;
     f.read((char *)&emp,sizeof(emp));
   }
   f.close();
   cout<<"\n\n\n\t\t\t*************************************";
   cout<<"\n\t\t\t\tEmployee Database";
   cout<<"\n\t\t\t*************************************";
   cout<<"\n\t\t\tInput Employee id no.   :"<<i;
   id_no=i;
   get_e();

}

void employee::get_e()                   //input employee info
{
   fstream f;
   e:                                              //password
   cout<<"\n\t\t\tPassword to login       :";
   cin>>pass_e;
   if(strlen(pass_e)>10)
   {
     cout<<"\n\t\t\tEnter password less than 10 digit";
     goto e;
   }
    cout<<"\t\t\tRe-enter Password       :";
    char temp_p[10];
    cin>>temp_p;
    if(strcmp(pass_e,temp_p)!=0)
    {
      cout<<"\t\t\tPassword doesnot match";
     goto e;
     }

   cout<<"\t\t\tInput full name         :";
   gets(name_employee);
   g:                                             //category a or b
   cout<<"\t\t\tCategory                :";
   cin>>cat;
   if(cat==65||cat==66||cat==97||cat==98)
   {
     goto g1;
   }
   else
   {
     cout<<"\t\t\tEnter A or B\n";
     goto g;
   }

   g1:                                           //mobile no.
   cout<<"\t\t\tInput mobile no.        :";
   cin>>num;
   int a=0,l=strlen(num);
   if(l==10)
    {
       for(int i=0;i<10;i++)
	{
	  if(!(num[0]==57&&num[i]>=48&&num[i]<=57))
	  {
	     cout<<"\t\t\tInvalid mobile no.\n";
	     goto g1;
	  }
       }
    }
 else
 {
   cout<<"\t\t\tInvalid mobile no.\n";
   goto g1;
 }


  g2:                                                 //Age
  cout<<"\t\t\tInput Age               :";
  cin>>age;
  if(strlen(age)==2)
  {
    for(int i=0;i<2;i++)
    {
       if(!(age[i]>=48&&age[i]<=57))
	{
	   cout<<"\t\t\tInvalid age.\n";
	   goto g2;
	}
     }
   }
   else
   {
     cout<<"\t\t\tInvalid age.\n";
     goto g2;
    }
   cout<<"\t\t\tInput address           :";
   gets(address);

   g3:                                           //email
   cout<<"\t\t\tInput Email             :";
   gets(email);
   l=strlen(email);
   if(l>7)
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
       cout<<"\t\t\tInvalid email id\n";
       goto g3;
     }
   }
  else
  {
    cout<<"\t\t\tInvalid email id\n";
    goto g3;
  }
   cout<<"\t\t\tInput Specilization     :";
   gets(specilization);
   cout<<"\t\t\tInput Qualification     :";
   gets(qualification);
   cout<<"\t\t\tInput Experience        :";
   gets(experience);
   txt();
   cout<<"\n\n\t\t\tData saved.\n\t\t\t<< Press any key >>";
  }

  void employee::txt()                       //create file txt as 1,2,3.txt
  {
   fstream f;
   char temp[5],*temp1=".txt";
   itoa(id_no,temp,10);                       //convert int into char
   strcat(temp,temp1);                        //combinig as (1+.txt)=1.txt (file)
   f.open(temp,ios::out);                     //opening/creating 1.txt file
   f.close();
}

void employee::employee_display()              //display emp info
{
    cleardevice();
   bar();
   gotoxy(32,6);
   cout<<"Employee Information";
   gotoxy(21,10);
   cout<<"Employee id no.  :"<<id_no;
   gotoxy(21,11);
   cout<<"Name             :"<<name_employee;
   gotoxy(21,12);
   cout<<"Category         :"<<cat;
   gotoxy(21,13);
   cout<<"Age              :"<<age;
   gotoxy(21,14);
   cout<<"Address          :"<<address;
   gotoxy(21,15);
   cout<<"Email            :"<<email;
   gotoxy(21,16);
   cout<<"Contact no.      :";
   for(int i=0;i<10;i++)
   {
     cout<<num[i];
     }
   gotoxy(21,17);
   cout<<"Specilization    :"<<specilization;
   gotoxy(21,18);
   cout<<"Qualification    :"<<qualification;
   gotoxy(21,19);
   cout<<"Experience       :"<<experience;

}

//*******************************************************
//    CLASS NAME : patient
//*******************************************************
class patient
{
public:
char name[50],phn[10], blood_group[5];
char disease[50],address[50];
int pat_id;

void patientdata();
void showdata();

};
//*******************************************************
//    FUNCTIONS TO GET AND SHOW DATA OF PATIENT
//*******************************************************
void patient::patientdata()
{
gotoxy(1,1);
cout<<"";
cout<<"\n\n\t\t\t*************************************";
cout<<"\n\t\t\t    Create New Patient Database\n ";
cout<<"\t\t\t*************************************";
cout<<"\n\t\t\tEnter Patient ID        : ";
cin>>pat_id;
cout<<"\t\t\tEnter Patient Name        : ";
gets(name);

g4:
cout<<"\t\t\tEnter patient mobile no.  :";
cin>>phn;
   int l=strlen(phn);
   if(l==10)
    {
       for(int i=0;i<10;i++)
	{
	  if(!(phn[0]==57&&phn[i]>=48&&phn[i]<=57))
	  {
	     cout<<"\t\t\tInvalid mobile no.\n";
	     goto g4;
	  }
       }
    }
 else
 {
   cout<<"\t\t\tInvalid mobile no.\n";
   goto g4;
 }

cout<<"\t\t\tEnter Patient Blood Group : ";
cin>>blood_group;

cout<<"\t\t\tEnter address             :";
gets(address);
cout<<"\t\t\tEnter disease             :";
cin>>disease;
cout<<"\n\t\t\tData saved.\n\t\t\t<< Press any key >>";
}

void patient::showdata()
{
cleardevice();
bar(140,60,141,380);
bar(140,60,521,61);
bar(520,61,521,380);
bar(141,380,521,380);
bar(140,110,520,111);
gotoxy(32,6);cout<<"Patient Database ";
gotoxy(21,10);cout<<"Patient ID   : "<<pat_id;
gotoxy(21,11);cout<<"Patient Name : "<<name;
gotoxy(21,12);cout<<"Blood Group  : "<<blood_group;
gotoxy(21,13);cout<<"Patient Phone: ";
for(int i=0;i<10;i++)
{
  cout<<phn[i];
}
gotoxy(21,14);cout<<"Address      :"<<address;
gotoxy(21,15);cout<<"Disease      :"<<disease;
gotoxy(21,18);cout<<"<<Press any key>>";

}

//******************************** LOGIN PAGE ADMIN *************************
int login()
 { char t[30]={'a','d','m','i','n'};
   char u[30],pass[30],ch;
   cleardevice();
   rectangle(250,30,387,48);
   rectangle(275,143,398,160);
   rectangle(275,175,398,192);

   gotoxy(34,3);
   cout<<" Admin Login";
   gotoxy(25,10);
   cout<<"Username:";
   gotoxy(25,12);
   cout<<"Password:";
  gotoxy(51,10);
  cout<<"(Press enter after entering)";
  gotoxy(51,12);
  cout<<"(8 characters only)";
  gotoxy(36,10);
  gets(u);
  gotoxy(36,12);

   for(int i=0;;i++)
   {
	ab:
	ch=getch();

	if(int(ch)==13)
	{
	  pass[i]='\0';
	  break;
	 }
	if(int(ch)==8)
	{
	  if(i==0)
	    goto ab;
	  cout<<"\b \b";
	  i--;
	  goto ab;
	}
	pass[i]=ch;
	cout<<"*";
	}

   pass[i]='\0';

   if((strcmp(u,t))==0 &&strcmp(pass,t)==0)
   return(1);
   else
   return(0);
 }


 class duty                                // *** class duty
{
 public:
   char du[10];
   int yy,dd,mm;

   void get();
   void display() ;

 };
 duty dd;


 void duty::get()                           // get duty
 {
    gotoxy(23,12);cout<<"Enter Date:-\n";
    gotoxy(23,13);cout<<"Year      :";
    cin>>yy;
    gotoxy(23,14);cout<<"Month     :";
    cin>>mm;
    gotoxy(23,15);cout<<"Day       :";
    cin>>dd;
    gotoxy(23,16);cout<<"Enter duty:";
    cin>>du;
    gotoxy(23,18);cout<<"Data saved.";
    gotoxy(23,19);cout<<"<< Press any key >>";
 }

 void duty::display()                             //display duty
 {
   cout<<"\nDate :"<<yy<<"/"<<mm<<"/"<<dd;
   cout<<"\nDuty :"<<du;
   }

void see_duty()                                   // see duty function
 {
   fstream f;
   employee e;
   ifstream fin;
   gotoxy(23,10);
   cout<<"Enter Id:";
   int ti;
   cin>>ti;
   int i1=0;
   f.open("ef2.txt",ios::in|ios::binary);
   f.seekg(0,ios::beg);
   f.read((char *)&e,sizeof(e));
   while(!f.eof())
   {
      if(e.id_no==ti)
      {
	i1++;
      }
      f.read((char *)&e,sizeof(e));
    }
   f.close();
  if(i1==1)
  {
   char *temp1=".txt",ch[5];
   itoa(ti,ch,10);
   strcat(ch,temp1);
   struct date d;
   getdate(&d);
   cleardevice();
   cout<<"\n\n\t\tDATE\t\t\t\tDUTY\n";
   /*printf("The current year is: %d\n", d.da_year);
   printf("The current day is: %d\n", d.da_day);
   printf("The current month is: %d\n", d.da_mon);  */
   fin.open(ch,ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   fin.read((char *)&dd,sizeof(dd));
    while(!fin.eof())
      {
	for(int j=0;j<7;j++)
	{
	  if(dd.yy==d.da_year&&d.da_mon==dd.mm&&d.da_day+j==dd.dd)
	   {
	      cout<<"\n\t\t"<<dd.yy<<"/"<<dd.mm<<"/"<<dd.dd;
	      cout<<"\t\t\t"<<dd.du;
	     //getch();
	    // goto aa;
	    }
	   }
	fin.read((char *)&dd,sizeof(dd));
      }
    //cout<<"\nNOT found";
   // aa:
    fin.close();
    getch();
   }
  else
  {
   gotoxy(25,10);
   cout<<"Id not found";
   }

}

void search_patient()
{
  patient obj;
  fstream f;
  cleardevice();
  gotoxy(21,10);cout<<"Enter Patient name:";
  char nm[50];
  int i=0;
  gets(nm);
  f.open("pf1.txt",ios::in|ios::binary);
  f.seekg(0,ios::beg);
  f.read((char *)&obj,sizeof(obj));
  while(!f.eof())
   {
    if(strcmp(nm,obj.name)==0)
    {
     obj.showdata();
     i++;
     getch();
    }
    f.read((char *)&obj,sizeof(obj));
     }
    f.close();
    if(i==0)
    {
      gotoxy(21,13);cout<<"Not Found";
      getch();
    }
  }

void e_duty(employee);
void emp_update();


//  ********************************* cover page ***********************

void cover()
{
   setfillstyle(10,1);                             //background
   bar(0,0,639,479);
   settextstyle(1,0,4);
   setcolor(GREEN);                                //topic
   outtextxy(140,100,"HOSPITAL   EMPLOYEE") ;
   outtextxy(200,180,"MANAGEMENT");
   outtextxy(240,260,"SYSTEM");
   settextstyle(1,0,1);
   outtextxy(180,400,"<< Press any key...... >>");
   setcolor(4);                                         //'+' figure draw
   setfillstyle(1,4);
   bar(40,30,50,80);
   bar(20,50,70,60);
   getch();
}

employee e_login();
void main1();

//**************************  void main function  **********************
void main()
{

  int gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\bgi");
  cleardevice();
  cover();
  main1();
  getch();
}


void main1()                                // void main1 function -starting the program
{                                           // main page (menu)
  while(1)
  { char c;
    gotoxy(1,1);

    fstream f;
    f.open("ef2.txt",ios::app|ios::binary);
    f.close();
    cleardevice();
    textcolor(15);
    bar();
    gotoxy(32,6);
    cout<<"Main Page";
    gotoxy(21,9);
    cout<<"1:Admin login";
    gotoxy(21,11);
    cout<<"2:Employee login";
    gotoxy(21,13);
    cout<<"3:Exit";
    gotoxy(21,16);
    cout<<"Enter choice:";
    cin>>c;
    switch(c)
     {
       case '1':

		char c;
		int i=login();
		if(i==1)
		 {

		 while(1)
		     {
		       cleardevice();
			gotoxy(1,1);
			fstream f;
			patient obj;
			employee emp;
			char ch;
			bar();
			gotoxy(32,6);
			cout<<"Logged in as Admin";
			gotoxy(21,10);
			cout<<"1:Create new employee ID";
			gotoxy(21,11);
			cout<<"2:Search employee";
			gotoxy(21,12);
			cout<<"3:Add employee duty";
			gotoxy(21,13);
			cout<<"4:see employee duty";
			gotoxy(21,14);
			cout<<"5:Update employee data";
			gotoxy(21,15);
			cout<<"6:Add new patient detail";
			gotoxy(21,16);
			cout<<"7:Search patient";
			gotoxy(21,17);
			cout<<"8:Back to Main page";
			gotoxy(21,20);
			cout<<"Enter choice :";
		       cin>>ch;
		       switch(ch)
			{

			  case '1':
				   cleardevice();
				   gotoxy(1,1);
				   f.open("ef2.txt",ios::app|ios::binary);
				   emp.get_employee_info();
				   f.write((char *)&emp,sizeof(emp));
				   f.close();
				   getch();
				   break;
			  case '2':
				   cleardevice();
				   char nm1[50];
				   gotoxy(21,10);
				   cout<<"Enter employee name:";
				   gets(nm1);
				   f.open("ef2.txt",ios::in|ios::binary);
				   f.seekg(0,ios::beg);
				   f.read((char *)&emp,sizeof(emp));
				   while(!f.eof())
				    {
				      if(strcmp(nm1,emp.name_employee)==0)
				       {
					 emp.employee_display();
					 gotoxy(21,21);
					 cout<<"<< Press any key >>";
					 goto es;
				       }

				       f.read((char *)&emp,sizeof(emp));
				     }
				    gotoxy(21,14);cout<<"Not Found";
				    f.close();
				    es:
				    getch();
				    break;

			     case '3':
					cleardevice();
					gotoxy(23,10);
					cout<<"Enter Employee ID:";
					char t[5];
					cin>>t;
					f.open("ef2.txt",ios::in|ios::binary);
					f.seekg(0,ios::beg);
					f.read((char *)&emp,sizeof(emp));
					while(!f.eof())
					{

						 char c1[5];
						 itoa(emp.id_no,c1,10);
						if(strcmp(t,c1)==0)
						{
						  ofstream fout;
						  char *temp1=".txt";
						  strcat(c1,temp1);
						  fout.open(c1,ios::app|ios::binary);
						  dd.get();
						  fout.write((char *)&dd,sizeof(dd));
						  fout.close();
						  goto m;
						   }
					f.read((char *)&emp,sizeof(emp));
					}
					gotoxy(23,13);
					cout<<"Id not found";
					m:
					f.close();
					getch();
					break;
			 case '4':
				   cleardevice();
				   gotoxy(1,1);
				   see_duty();
				   getch();
				   break;

			 case '5':
				  cleardevice();
				  gotoxy(1,1);
				  emp_update();
				  break;

			  case '6':
				   cleardevice();
				   f.open("pf1.txt",ios::app|ios::binary);
				   obj.patientdata();
				   f.write((char *)&obj,sizeof(obj));
				   f.close();
				   getch();
				   break;
			  case '7':
				    cleardevice();
				    search_patient();
				    break;
			  case '8':
				   goto a;

			 }
		      }


		      a:
		     }
		  else
		  {
		    gotoxy(25,14);
		    cout<<"Login fail";
		    getch();
		    cleardevice();
		   }
		break;

      case '2':                                         //employee logged in

		    employee emp;
		    emp=e_login();
		     if(emp.cat==65||emp.cat==97)
		     {
		      while(1)
		      {
		       cleardevice();
		       bar();
		       gotoxy(32,6);cout<<"Login success";
		       gotoxy(21,10);cout<<"Employee ID:"<<emp.id_no;
		       gotoxy(21,11);cout<<"Name:"<<emp.name_employee;
		       gotoxy(21,14);cout<<"1:See duty";
		       gotoxy(21,15);cout<<"2:See patient info:";
		       gotoxy(21,16);cout<<"3:Exit";
		       char c;
		       gotoxy(21,18);cout<<"Enter choice:";
		       cin>>c;
		       switch(c)
			 {
			     case '1':
				      gotoxy(1,1);
				      e_duty(emp);
				      break;
			     case '2':

				      search_patient();
				      break;
			     case '3':
				      goto aa;
			    }
		       }
		   }
		  else
		  {
		    while(1)
		    {
		       cleardevice();
		       bar();
		       gotoxy(32,6);cout<<"Login success";
		       gotoxy(21,10);cout<<"Employee ID:"<<emp.id_no;
		       gotoxy(21,11);cout<<"Name:"<<emp.name_employee;
		       gotoxy(21,14);cout<<"1:See duty";
		       gotoxy(21,15);cout<<"2:Exit";
		       char c1;
		       gotoxy(21,18);cout<<"Enter choice:";
		       cin>>c1;
			switch(c1)
			 {
			     case '1':
				      gotoxy(1,1);
				      e_duty(emp);
				      break;

			     case '2':
				      goto aa;
			    }
		       }
		   }

	       aa:
	       break;

      case '3':
	      exit(1);
	       break;
      }
     }
   }


void emp_update()
{
  employee e;
  fstream f;
  cleardevice();
  gotoxy(21,10);
  cout<<"Enter employee ID to be updated:";
  int ch;
  cin>>ch;
  f.open("ef2.txt",ios::binary|ios::in|ios::out);
  f.seekg(0,ios::beg);
  f.read((char *)&e,sizeof(e));
  while(!f.eof())
  {
   if(e.id_no==ch)
    {

     f.seekp(f.tellp()-sizeof(e));
      e.get_e();
     f.write((char *)&e,sizeof(e));
     }
      f.read((char *)&e,sizeof(e));
  }
 f.close();
 getch();
}

void e_duty(employee emp)
{
  ifstream fin;
  char tem[5],*temp1=".txt";
  itoa(emp.id_no,tem,10);
  strcat(tem,temp1);
  struct date d;
  getdate(&d);
  //printf("The current year is: %d\n", d.da_year);
  //printf("The current day is: %d\n", d.da_day);
  //printf("The current month is: %d\n", d.da_mon);
  cleardevice();
  cout<<"\n\n\t\tDATE\t\t\t\tDUTY\n";
  fin.open(tem,ios::in|ios::binary);
  fin.seekg(0,ios::beg);
  fin.read((char *)&dd,sizeof(dd));
  while(!fin.eof())
  {

   for(int j=0;j<7;j++)
   {
      if(dd.yy==d.da_year&&d.da_mon==dd.mm&&d.da_day+j==dd.dd)
       {
	 if(d.da_day==dd.dd)
	 {
	    printf("\n\t\t");
	    //textcolor(10);
	    setcolor(2);
	    printf("\%d/%d/%d",dd.yy,dd.mm,dd.dd);
	    printf("\t\t\t");
	    printf("%s",dd.du);
	    //setcolor(15);
	    }
	 else
	 {
	  cout<<"\n\t\t"<<dd.yy<<"/"<<dd.mm<<"/"<<dd.dd;
	  cout<<"\t\t\t"<<dd.du;
	  }
	  }
	 }
	 fin.read((char *)&dd,sizeof(dd));
	 }
	 //cout<<"\nNOT found";
	 //aa1:
	 fin.close();
	 getch();
    }



 employee e_login()
 {
		fstream f;
		employee emp;

		char pass1[10],ch,idd[5];
	       cleardevice();
	       rectangle(250,30,387,48);
	      rectangle(275,143,398,160);
	       rectangle(275,175,398,192);

	       gotoxy(34,3);
	       cout<<"Employee Login";
	       gotoxy(20,10);
	       cout<<"Employee ID:";
	       gotoxy(20,12);
	       cout<<"Password:";
	       gotoxy(51,10);
	       cout<<"(Press enter after entering)";
	       gotoxy(51,12);
	       cout<<"(10 characters only)";
	       gotoxy(36,10);
	       gets(idd);

	       gotoxy(36,12);
	       for(int k=0;k<10;k++)
	       {
		  ab1:
		  ch=getch();

		if(int(ch)==13)
		 {
		   pass1[k]='\0';
		   break;
		   }
		   if(int(ch)==8)
		   {
		     if(k==0)
		     goto ab1;
		     cout<<"\b \b";
		     k--;
		     goto ab1;
		   }
		pass1[k]=ch;
		cout<<"*";
	       }
		pass1[k]='\0';
	       f.open("ef2.txt",ios::in|ios::binary);
	       f.seekg(0,ios::beg);
	       f.read((char *)&emp,sizeof(emp));
	       while(!f.eof())
	       {
		   char id[5];
		   itoa(emp.id_no,id,10);
		  if(strcmp(id,idd)==0&&strcmp(emp.pass_e,pass1)==0)
		  {
		    return(emp);
		  }
	       f.read((char *)&emp,sizeof(emp));
	       }
	       f.close();
	       gotoxy(20,15);
	      printf("Login fail");
	      getch();
	      main1();
 }
