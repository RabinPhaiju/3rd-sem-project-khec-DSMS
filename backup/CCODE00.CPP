#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

int end=1;
void alwaysdisplay();
void calculatebill();
void additem();
void edititem();
void display();
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

union REGS in, out;    //mouse ko lagi variables..

void date()      //date print garna lai..
{
struct date today;
char string[25];
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
   rectangle(122,216,233,235);
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
int color;
int gd=DETECT, gm,status;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
alwaysdisplay();
closegraph();
cout<<"Press any Key";
getch();
}
void displayforever()     // store name, date, mouse rectriction and rectangle....print garna..
{

  int button,x,y,option;
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
  int button,x,y,option;
  setbkcolor(BLUE);
  //ShowBACKGROUND(20,30,"back.bmp");
  rectangle(20,30,620,433);
  restrictmouseptr(20,30,620,433);
  storename();
  date();
  menu();
  callmouse();
  getmousepos(&button,&x,&y);
  while(end!=0)//(!kbhit())
  {
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
	else if(x>=122 && x<=223 && y>=216 && y<=235)
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
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is another test page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
 void edititem()     //case 3..
  {
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is another3333333 test page"); delay(2000);
  cleardevice();
  alwaysdisplay();
  }
void display()     //case 4..
  {
  cleardevice();
  displayforever();
  outtextxy(50,50,"This is display page"); delay(2000);
  cleardevice();
  alwaysdisplay();
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
   end=0;
}