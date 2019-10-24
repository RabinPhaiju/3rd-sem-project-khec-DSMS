#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>
#include<dos.h>
int mon,d,yr;
int admin_id;
char tmp_name[30];
int delsn;
char inti[10];
int gm,gd;
void graphics(){
 flush;
 fflush(stdin);
 gd=DETECT;
 initgraph(&gd,&gm,"..\\BGI");
}
class menu;
void star();
void main();
void read_menu(ifstream &fin,menu &m);
void write_menu(ofstream &fout,menu &m);
class menu{
  protected:
  unsigned int sn;
  int day,month,year;
  int i;
  char ch;
  int tmp_price;
  public:
  int quanti[100];
  char name[100][30];
  int price[100];
  void set_sn(){
   sn=0;
  }
  int get_sn(){
   return sn;
  }
  void add_menu(menu);
  void view_menu();
  void delete_menu();
  void add_item_quantity();
  void quantity_null();
};
class bill{
  protected:
  char cus_name[30],ch;
  char item_name[15][20],item_price[15];
  unsigned int month,day,year;
  unsigned int n,i,j,sn;
  unsigned long total;
  unsigned long cus_id;
  unsigned int items,quantity[50];
  int x;
  char inti[20];
  ofstream fout;
  ifstream fin;
  public:
  bill(){
   time_t t = time(0);
   struct tm *time = localtime(&t);
   year = time->tm_year + 1900;
   month = time->tm_mon + 1;
   day = time->tm_mday;
  }
  void makebill(menu);
  void display_bill();
};
class cusid{
  unsigned long id;
  public:
  long get_cus_id(){
   return id;
  }
  void set_cus_id(long cus_id){
   id=cus_id;
  }
};

//Inquiry detail class start
//inquiry detail class ends
void valid(int choice){
  system("cls");
  int i,j=0;
  char inti[10];
  graphics();
  setbkcolor(GREEN);
  setcolor(WHITE);
  if(choice==5){
   settextstyle(9,0,2);
   outtextxy(110,40,"Quantities Reset Successfully.");
  }
  else if(choice==22){
   settextstyle(3,0,2);
   outtextxy(110,40,tmp_name);
   outtextxy(198,40,"Has Been Deleted From Menu.");
   strcpy(tmp_name,"");
  }
  else if(choice==21 || choice==34){
   settextstyle(3,0,2);
   sprintf(inti,"%d except ",delsn);
   outtextxy(95,40,"There is no other item in S.N No ");
   outtextxy(getmaxx()-215,40,inti);
   outtextxy(getmaxx()-123,40,tmp_name);
   strcpy(tmp_name,"");
  }
  else if(choice==1){
   settextstyle(3,0,2);
   outtextxy(85,40,"The Entered Items Were Added Successfully.");
  }
  else if(choice==33){
   settextstyle(3,0,2);
   sprintf(inti,"%d",delsn);
   outtextxy(85,40,inti);
   outtextxy(125,40,"Quantity Added Successfully in ");
   outtextxy(450,40,tmp_name);
   strcpy(tmp_name,"");
  }
  circle(getmaxx()/2,getmaxy()/2-40,100);
  circle(getmaxx()/2-50,getmaxy()/2-80,13);
  circle(getmaxx()/2+50,getmaxy()/2-80,13);
  arc(getmaxx()/2,getmaxy()/2-20,200,340,50);
  settextstyle(3,0,2);
  for(i=5;i>=1;i--,j+=15){
   sprintf(inti,"%d",i);
   outtextxy(111+j,getmaxy()-50,inti);
   outtextxy(getmaxx()/2+105+j,getmaxy()-50,"*");
   delay(1000);
  }
}
void invalid(int choice){
  system("cls");
  int i,j=0;
  char inti[10];
  graphics();
 // clrscr();
  setbkcolor(4);
  if(choice==0){
   settextstyle(9,0,2);
   outtextxy(152,40,"Your Choice Is Invalid...!!!");
   circle(getmaxx()/2,getmaxy()/2-40,100);
   circle(getmaxx()/2-50,getmaxy()/2-80,13);
   circle(getmaxx()/2+50,getmaxy()/2-80,13);
   arc(getmaxx()/2,getmaxy()/2+30,20,160,50);
   settextstyle(3,0,2);
   outtextxy(80,getmaxy()-100,"Please Enter Valid Number After Few Seconds.");
   for(i=9;i>=0;i--,j+=15){
    sprintf(inti,"%d",i);
    outtextxy(80,getmaxy()-50,"10");
    outtextxy(getmaxx()/2+90,getmaxy()-50,"*");
    delay(1000);
    outtextxy(111+j,getmaxy()-50,inti);
    outtextxy(getmaxx()/2+105+j,getmaxy()-50,"*");
   }
 }
 else if(choice==23 || choice ==34){
   settextstyle(3,0,2);
   sprintf(inti,"%d",delsn);
   outtextxy(207,40,"There is no S.N No ");
   outtextxy(405,40,inti);
   circle(getmaxx()/2,getmaxy()/2-40,100);
   circle(getmaxx()/2-50,getmaxy()/2-80,13);
   circle(getmaxx()/2+50,getmaxy()/2-80,13);
   arc(getmaxx()/2,getmaxy()/2+30,20,160,50);
   settextstyle(3,0,2);
   outtextxy(80,getmaxy()-100,"Please Enter Valid Number After Few Seconds.");
   for(i=4;i>=1;i--,j+=15){
   sprintf(inti,"%d",i);
   outtextxy(111+j,getmaxy()-50,inti);
   outtextxy(getmaxx()/2+105+j,getmaxy()-50,"*");
   delay(1000);
  }
 }
}
//adding item quantity start
void menu::add_item_quantity(){
 cout<<"\n Enter the S.N no of Item :\t";
 quantity:
 cin>>delsn;
 if(delsn<=0 || delsn>sn){
  cout<<"\n Invalid S.N no. Please Enter Again :\t";
  goto quantity;
 }
 else{
  cout<<"\n Is That "<<name[delsn-1]<<" ? (Y/N) :\t";
  cin>>ch;
  if(ch=='Y' || ch=='y'){
   cout<<"\n Enter the Quantity :\t";
   cin>>i;
   quanti[delsn-1] +=i;
   strcpy(tmp_name,name[delsn-1]);
   delsn=i;
   valid(33);
  }
  else{
   strcpy(tmp_name,name[delsn-1]);
   valid(34);
  }
 }
}
//adding item quantity ends

//Display bill start
void bill::display_bill(){
 system("cls");
 graphics();
 setbkcolor(1);
 x=getmaxx();
 setfillstyle(SOLID_FILL,53);
 bar(0,15,x,40);
 line(35,30,65,30);
 rectangle(38,27,62,33);
 circle(50,30,9);
 outtextxy(243,26,"* Canteen Receipt *");
 sprintf(inti,"%d ",month);
 outtextxy(x-150,26,"Date :");
 outtextxy(x-97,26,inti);
 sprintf(inti,"-%d",day);
 outtextxy(x-88,26,inti);
 sprintf(inti," -%d",year);
 outtextxy(x-69,26,inti);
 setfillstyle(SOLID_FILL,53);
 bar(0,40,x,65);
 outtextxy(30,51," Bill To :");
 outtextxy(120,51,cus_name);
 sprintf(inti,"%d",cus_id);
 outtextxy(x-200,51,"Customer Id :");
 outtextxy(x-95,51,inti);
 rectangle(0,65,x,90);
 outtextxy(10,77,"S.N");
 outtextxy(46,77,"Items");
 outtextxy(320,77,"Rate");
 outtextxy(420,77,"Quantity");
 outtextxy(x-90,77,"Amount(Rs)");
 j=103;
 total=0;
 for(i=0;i<n;i++){
  sprintf(inti,"%d",i+1);
  outtextxy(15,j,inti);
  outtextxy(46,j,item_name[i]);
  sprintf(inti,"%d",item_price[i]);
  outtextxy(325,j,inti);
  sprintf(inti,"%d",quantity[i]);
  outtextxy(446,j,inti);
  sprintf(inti,"%d",quantity[i] * item_price[i]);
  outtextxy(x-85,j,inti);
  outtextxy(x-28,j,"/-");
  j+=25;
  total+=quantity[i] * item_price[i];
 }
 setfillstyle(SOLID_FILL,53);
 rectangle(0,65,x,j-10);
 bar(0,j-10,x,j+16);
 sprintf(inti,"%d /-",total);
 outtextxy(x/2-23,j,"Total");
 outtextxy(x-85,j,inti);
 line(40,65,40,j-10);
 line(310,65,310,j-10);
 line(410,65,410,j-10);
 line(x-100,65,x-100,j+15);
 outtextxy(50,430,"Press Enter To Continue");
 cin.ignore();
 ch=getch();
}
//Display bill ends

//making bill start
void bill::makebill(menu m){
 system("cls");
 char ch;
// graphics();
 setbkcolor(1);
 sn=m.get_sn();
 for(i=1;i<41;i++){
  cout<<"* ";
 }
 m.view_menu();
 star();
 cout<<"\t\t\t\t Creating Bills\n";
 cout<<"\n\t\t\t Customer's Name :\t";
 cin.ignore();
 cin.getline(cus_name,30);
 previous:
 cout<<"\n\t How Many Items You Want To Enter? :\t";
 getn:
 cin>>n;
 if(n>sn){
  cout<<"\n\t Only "<<sn<<" items present. Please enter valid number :\t";
  goto getn;
 }
 else if(n==0){
  cout<<"\n   You Enter The 0 Items. Press P for previous step and any key for continue :";
  cin>>ch;
  if(ch=='p' || ch=='P'){
   goto previous;
  }
 }
 for(i=0;i<n;i++){
  cout<<"\n \tEnter The S.N No Of Item ("<<i+1<<") :\t";
  entersn:
  cin>>items;
  if(items<1 || items>sn){
   cout<<"\n\t Sorry There Is No S.N No "<<items<<". Please Input Again. :"<<endl;
   goto entersn;
  }
  else{
   strcpy(item_name[i],m.name[items-1]);
   item_price[i]=m.price[items-1];
   cout<<"\n \tEnter Quantity Of "<<m.name[items-1]<<" :\t";
   quanti:
   cin>>quantity[i];
   if(quantity[i]>m.quanti[items-1]){
    cout<<"\n Only "<<m.quanti[items-1]<<" quantity remains. Please Enter again :\t";
    goto quanti;
   }
   else{
    m.quanti[items-1]=m.quanti[items-1]-quantity[i];
   }
  }
 }
 cusid id;
 fin.open("bill/cus_id.txt",ios::in);
 fin.read((char*)&id,sizeof(id));
 cus_id = id.get_cus_id();
 id.set_cus_id(cus_id+1);
 fin.close();
 fout.open("bill/cus_id.txt",ios::out);
 fout.write((char*)&id,sizeof(id));
 fout.close();
 write_menu(fout,m);
 fout.close();
 display_bill();
}
//making bill ends

//Contents of class menu starts
void menu::add_menu(menu mm){
 char tmp_name[20];
 int flag=0;
   do{
    addmenu:
    cout<<"\n\t\t\t  Item Name :\t";
    if(flag==0){
     cin.ignore();
    }
    cin.getline(tmp_name,30);
    for(i=0;i<=sn;i++){
     if(strcmp(tmp_name,mm.name[i])==0){
       cout<<"\n\tThe Item already exist..!!!!!!  Please Enter Another Item (*_*) \n";
       flag=1;
       goto addmenu;
     }
     else{
      strcpy(name[sn],tmp_name);
     }
    }
    cout<<"\n\t\t\t  Price     :\t";
    cin>>price[sn];
    quanti[sn] = 100;
    sn++;
    cout<<"\n\t\t      Want To Add Next ? (Y/N) :\t";
    fflush(stdin);
    ch=getchar();
   }
   while(ch=='y' || ch=='Y');
   valid(1);
}
void menu::view_menu(){
 cout<<"\n\t\t\t\t Menu List";
 cout<<"\n\t SN Item\t\t\t\tPrice\t Remaining Quantity";
 for(i=0;i<sn;i++){
  cout<<"\n\t "<<i+1<<". "<<name[i]<<" \t .....................   "<<price[i]<<"\t\t"<<quanti[i];
 }
}
void menu::delete_menu(){
 cout<<"\n\t\tEnter the S.N number of Item you want to delete :\t";
 cin>>delsn;
 strcpy(tmp_name,name[delsn-1]);
 if(delsn>0 && delsn<=sn){
  cout<<"\n\t\t\t   Is That "<<name[delsn-1]<<" ? (Y / N) :\t";
  fflush(stdin);
  ch=getchar();
  if(ch=='Y' || ch=='y'){
   sn--;
   for(i=delsn-1;i<sn;i++){
    strcpy(name[i],name[i+1]);
    price[i]=price[i+1];
    quanti[i]=quanti[i+1];
   }
   valid(22);
  }
  else{
   valid(21);
  }
 }
 else{
  invalid(23);
 }
}
//Contents of class menu ends

void star(){
 cout<<endl;
 for(int i=1;i<41;i++){
  cout<<"* ";
 }
 cout<<endl;
}

//reading and writing menu starts
void read_menu(ifstream &fin,menu &m){
  fin.open("menu.txt",ios::in);
  fin.read((char*)&m,sizeof(m));
}
void write_menu(ofstream &fout,menu &m){
 fout.open("menu.txt",ios::out);
 fout.write((char*)&m,sizeof(m));
}
//reading and writing menu ends

//date function starts
void date(){
 time_t t=time(0);
 struct tm *time = localtime(&t);
 d = time->tm_mday;
 mon = time->tm_mon + 1;
 yr = time->tm_year + 1900 ;
}
//date function ends

//checking day of date start(managing quantitiy)
void menu::quantity_null(){
 for(i=0;i<sn;i++){
  quanti[i]=100;
 }
}
//checking day of date ends

//admin class start
class admin{
 char name[15];
 char pass[15];
 public:
 void set_admin_name(char nam[]){
  strcpy(name," ");
  strcpy(name,nam);
 }
 void set_admin_pass(char pas[]){
  strcpy(pass," ");
  strcpy(pass,pas);
 }
 int validate_admin(char nam[],char pas[]){
  if(strcmp(nam,name)==0 && strcmp(pas,pass)==0){
   return 1;
  }
  else{
   return 0;
  }
 }
 int check_user(char user[]){
  if(strcmp(name,user)==0){
   return 1;
  }
  else{
   return 0;
  }
 }
 int check_pass(char pas[]){
  if(strcmp(pass,pas)==0){
   return 1;
  }
  else{
   return 0;
  }
 }
};
void adminn(){
 char name[15];
 char pass[15];
 char tmp_name[15]="admin";
 char tmp_pass[15]="admin";
 int i;
 char ch;
  cout<<"\n\n\n\t Enter user name and password. Password will be invisible.\n";
  admin:
  cout<<"\n\n\n\n\t\t User     :\t";
  cin>>name;
  cout<<"\n\t\t Password :\t";
  for(i=0;;i++){
   ch=getch();
   if(ch==13){
    pass[i]='\0';
    break;
   }
   else if(ch==8){
    if(i<=0){
     i=0;
    }
    else{
     i--;
     i--;
    }
   }
   else{
    pass[i]=ch;
   }
  }
 cout<<pass;
 ifstream fin;
 ofstream fout;
 admin adm;
 fin.open("bill\\admin.txt",ios::in);
 if(!fin){
  fout.open("bill\\admin.txt",ios::out);
  admin adm;
  adm.set_admin_name(tmp_name);
  adm.set_admin_pass(tmp_pass);
  fout.write((char*)&adm,sizeof(adm));
  fout.close();
  fin.close();
 }
 else{
  fin.read((char*)&adm,sizeof(adm));
   if(adm.validate_admin(name,pass)==1){}
   else{
    fin.close();
    clrscr();
    system("cls");
    setbkcolor(5);
    cout<<"\n Sorry you entered wrong user/pass";
    ch:
    cout<<"\n\n 1.Retry.\n 2.Exit.\n\t";
    fflush(stdin);
    ch=getchar();
    switch(ch){
     case '1':
      goto admin;

     case '2':
      exit(1);
     break;

     default:
      cout<<"\n Invalid choice.. Please Enter valid number :\t";
      goto ch;
    }
   }
  fin.close();
 }
}
void reset_pass(){
 system("cls");
 ifstream fin;
 ofstream fout;
 admin adm;
 char ch;
 int i;
 char user[15];
 char old_pass[15];
 char new_pass[15];
 char re_new_pass[15];
 cout<<"\n Reset User And Password.";
 olduser:
 cout<<"\n\n Enter the Old User Name :\t";
 cin>>user;
 fin.open("bill\\admin.txt",ios::in);
 fin.read((char*)&adm,sizeof(adm));
 if(adm.check_user(user)==0){
  system("cls");
  cout<<"\n User doesn't Matched..!!!!";
  retry:
  cout<<"\n\n 1.Retry.\n 2.Go To Main Page.\n\t";
  fflush(stdin);
  ch=getchar();
  switch(ch){
   case '1':
    goto olduser;

   case '2':
    main();
   break;

   default:
    cout<<"\n Invalid choice..!!!";
    goto retry;
  }
 }
 oldpass:
 cout<<"\n Enter Old Password :\t";
 cin>>old_pass;
 if(adm.check_pass(old_pass)==0){
  system("cls");
  cout<<"\n Password doesn't Matched..!!!!";
  retryy:
  cout<<"\n\n 1.Retry.\n 2.Go To Main Page.\n\t";
  fflush(stdin);
  ch=getchar();
  switch(ch){
   case '1':
    goto oldpass;

   case '2':
    main();
   break;

   default:
    cout<<"\n Invalid choice..!!!";
    goto retryy;
  }
 }
 cout<<"\n Enter the new user :\t";
 cin>>user;
 newpass:
 cout<<"\n Enter the new password :\t";
 cin>>new_pass;
 cout<<"\n Enter again (for confirmation) :\t";
 cin>>re_new_pass;
 if(strcmp(new_pass,re_new_pass)!=0){
  strcpy(new_pass," ");
  strcpy(re_new_pass," ");
  cout<<"\n Password Doesn't Matched. Please Enter Again.";
  goto newpass;
 }
 else{
  adm.set_admin_name(user);
  adm.set_admin_pass(new_pass);
  fout.open("bill\\admin.txt",ios::out);
  fout.write((char*)&adm,sizeof(adm));
  fout.close();
  fin.close();
  system("cls");
  graphics();
  setbkcolor(6);
  settextstyle(3,0,2);
  outtextxy(125,40,"User And Password Reset Successfully.");
  circle(getmaxx()/2,getmaxy()/2-40,100);
  circle(getmaxx()/2-50,getmaxy()/2-80,13);
  circle(getmaxx()/2+50,getmaxy()/2-80,13);
  arc(getmaxx()/2,getmaxy()/2-20,200,340,50);
  for(int m=0;m<=100;m+=10){
   outtextxy(270+m,400,"* ");
   delay(1000);
  }
 }
}
//admin class end

//main function starts
void main(){
 clrscr();
 char choice;
 char ch;
 int i;
 menu m,mm;
 bill b;
 ofstream fout,fileout;
 ifstream fin,filein;
 cusid c_id;
 graphics();
 clrscr();
 system("cls");
 setbkcolor(5);
 filein.open("bill/cus_id.txt",ios::in);
 if(filein){
  filein.seekg(0,ios::end);
  if(filein.tellg()==0){
   c_id.set_cus_id(1);
   fileout.open("bill/cus_id.txt",ios::out);
   fileout.write((char*)&c_id,sizeof(c_id));
   fileout.close();
  }
 }
 else{
  fileout.open("bill/cus_id.txt",ios::out);
  c_id.set_cus_id(1);
  fileout.write((char*)&c_id,sizeof(c_id));
  fileout.close();
 }
 filein.close();
 if(admin_id==0){
  admin_id=1;
  adminn();
 }
 while(1){
 system("cls");
 flush;
 fflush(stdin);
 setbkcolor(1);
 date();
 star();
 read_menu(fin,m);
 cout<<"\t\t\t    CANTEEN BILLING SYSTEM\t       Date : "<<mon<<"-"<<d<<"-"<<yr;
 if(m.get_sn()==0){
  cout<<"\n\n\t\t\t  There is no menu to view"<<endl;
  cout<<"\n\n\t\t      Do You Wana Add Itmes ? (Y or N) : \t";
  fflush(stdin);
  ch=getchar();
  if(ch=='y' || ch=='Y'){
   m.set_sn();
   m.add_menu(mm);
   fin.close();
   write_menu(fout,m);
   fout.close();
  }
  else{
   cout<<"\n\t\t    Program Terminates in 5 sec, Because Of No Menu Items"<<endl;
   star();
   cout<<endl<<"\n\t\t\t\t   ";
   for(i=5;i>=1;i--){
    cout<<"* ";
    delay(1000);
   }
   exit(1);
  }
 }
 else{
  m.view_menu();
  fin.close();
  cout<<endl;
  star();
  cout<<"\t\t\tSELECT THE OPTIONS TO PROCEED";
  cout<<"\n\n\t 1.Add Items";
  cout<<"\t\t\t\t 4.Make Bill";
  cout<<"\n\t 2.Delete Items";
  cout<<"\t\t\t\t 5.Reset Quantities";
  cout<<"\n\t 3.Add Items Quantity";
  cout<<"\t\t\t 6.Reset User & Password.\n\t\t\t\t  7.Exit\n\t\t\t\t";
  cin>>choice;
  switch(choice){
   case '1':
    read_menu(fin,mm);
    m.add_menu(mm);
    write_menu(fout,m);
    fout.close();
    fin.close();
   break;
   case '2':
    read_menu(fin,m);
    m.delete_menu();
    fin.close();
    write_menu(fout,m);
    fout.close();
   break;
    case '3':
     read_menu(fin,m);
     m.add_item_quantity();
     fin.close();
     write_menu(fout,m);
     fout.close();
   break;
    case '4':
     read_menu(fin,m);
     fin.close();
     b.makebill(m);
     clrscr();
     system("cls");
    break;

    case '5':
     cout<<"\n \t Are You Sure To Reset All Quantities ? [Y/N] :\t";
     ch = getchar();
     if(ch=='y' || ch=='Y'){
      read_menu(fin,m);
      m.quantity_null();
      fin.close();
      write_menu(fout,m);
      fout.close();
      valid(5);
     }
     else{
      system("cls");
     }
    break;

    case '6':
     reset_pass();
    break;

    case '7':
     exit(1);
    break;

   default:
   invalid(0);
   system("cls");
  }
 }
 }
}
