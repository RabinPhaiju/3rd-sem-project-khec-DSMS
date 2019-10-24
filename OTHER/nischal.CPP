#include<graphics.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void collision_check(int tx[], int bx[], int, float);
int randomizor();
void background();
void storage(int);

int orgnlx=5,orgnly=88;
int ctx,cty,cbx,cby,ty,by,chx[3],rdm[3];
int driver=0,mode;

struct player
{
	float score;
	char name[20];
}p,ps[5];

void identity()
{
	clearviewport();
	setfillstyle(3,4);
	bar(130,160,430,170);
	bar(130,210,430,220);
	bar(130,310,430,320);
	bar(130,170,140,310);
	bar(430,160,440,320);
	line(255,260,400,260);
	settextstyle(6,0,3);
	outtextxy(195,165,"Enter  Your  Name");
	outtextxy(195,230,"Name:");
	gotoxy(35,16);
	gets(p.name);
   }

void gameplay()
{
	clrscr();
	int tx[3],bx[3];
	p.score=0;
	int i,x;
	char cmd;
	initgraph(&driver,&mode,"..\\bgi");
	float delayfactor=15;
	gotoxy(26,9);
	printf("%s",p.name);
	setviewport(190,150,460,260,1);
	while(1)
	{
		randomizor();
		for(x=0;x<3;x++)
			tx[x]=265+rdm[x];
		for(i=570;i>=0;i--)  //i=570 because max random value is 300 i.e. 250+300
		{                    //viewport is of length 270
			gotoxy(49,9);
			printf("SCORE:%0.0f",p.score);
			gotoxy(25,20);
			printf("Press \'SPACE\' to jump");
			gotoxy(25,21);
			printf("Avoid obstacles to survive");
			clearviewport();
			background();
			setfillstyle(2,6);
			bar3d(orgnlx,orgnly,orgnlx+10,orgnly+10,5,1);
			ty=80;
			by=98;
			for(x=0;x<3;x++)
			{
				setfillstyle(5,10);
				bx[x]=tx[x]+5;
				bar(tx[x],ty,bx[x],by);
			}
			delay(delayfactor);
			if(kbhit())
			{
				cmd=getch();
				if(cmd==32)
				{
					sound(450);
					delay(50);
					nosound();
					collision_check(tx,bx,1,delayfactor);
				}
			}
			else
				collision_check(tx,bx,0,0);
			for(x=0;x<3;x++)
				tx[x]--;
			p.score+=0.01;
		}
		delayfactor-=.25;
		if(delayfactor==2)
			delayfactor=15;
	}
}

int randomizor()
{
   int div=10,i,rm;
   int arr[3]={0,50,110};
   time_t t;
   srand(time(&t));
   for(i=0; i<3; i++)
   {    x:
	rm=rand()%div;
	if(rm>=arr[i]&&rm<=300)
		rdm[i]=rm;
	else
		goto x;
	div*=10;
   }
   return 0;
}

void main()
{
	clrscr();
	initgraph(&driver,&mode,"..\\bgi");
	char choice;
	setcolor(6);
	rectangle(30,10,600,450);
	rectangle(35,15,595,445);
	setcolor(7);
	settextstyle(6,0,5);
	outtextxy(200,100,"C U B E-R U N");
	settextstyle(7,0,3);
	outtextxy(210,200,"Start Game [S]");
	outtextxy(210,225,"View Highscore [H]");
	outtextxy(210,250,"Exit [Q]");
	settextstyle(3,0,1);
	outtextxy(180,315,"Press 's' to start the game.");
	outtextxy(180,330,"press 'h' to see highscore.");
	outtextxy(180,345,"press 'q' to quit the game.");
	option:
	choice=getch();
	switch(choice)
	{
	case 's': case 'S':
		identity();
		gameplay();
		break;
	case 'h': case 'H':
		storage(1);
		break;
	case 'q': case 'Q':
		exit(1);
	default:
		goto option;
	}
	getch();
}

void collision_check(int tx[], int bx[], int jump, float delayfactor)
{
	int b,x;
	char ch;
	ctx=5;
	cty=88;
	cbx=15;
	cby=98;
	if(jump==1)
	{
		for(x=0;x<3;x++)
		{
			if(ctx<=tx[x]&&cbx>=tx[x]&&cby>=ty)
			{
				setcolor(4);
				outtextxy(50,59,"G A M E  O V E R!!");
				sound(350);
				delay(250);
				nosound();
				delay(100);
				outtextxy(50,70,"Restart (Y/N)?");
				x:
				ch=getch();
				if(ch=='Y'||ch=='y')
				{
					storage(0);
					gameplay();
				}
				else if(ch=='N'||ch=='n')
				{
					storage(0);
					main();
				}
				else
					goto x;
			}
		}
		cty-=30;
		cby-=30;
		for(b=1;b<=30;b++)
		{
			clearviewport();
			background();
			setfillstyle(2,6);
			bar3d(ctx,cty,cbx,cby,5,1);
			for(x=0;x<3;x++)
			{
				setfillstyle(5,10);
				tx[x]--;
				bx[x]--;
				bar(tx[x],ty,bx[x],by);
			}
			delay(delayfactor);
			p.score+=0.01;
		}
	}
	else
	{
		for(x=0;x<3;x++)
		{
			if(ctx<=tx[x]&&cbx>=tx[x])
			{
				setcolor(4);
				outtextxy(50,59,"G A M E  O V E R!!");
				sound(350);
				delay(250);
				nosound();
				delay(100);
				outtextxy(50,70,"Restart (Y/N)?");
				xy:
				ch=getch();
				if(ch=='Y'||ch=='y')
				{
					storage(0);
					gameplay();
				}
				else if(ch=='N'||ch=='n')
				{
					storage(0);
					main();
				}
				else
					goto xy;
			}
		}
	}
}

void storage(int mode)
{
	FILE *fp;
	if(mode==0)
	{
		fp=fopen("Playerdata.txt","a");
		fwrite(&p,sizeof(struct player),1,fp);
		fclose(fp);
	}
	else if(mode==1)
	{
		int i=0,x,y;
		clearviewport();
		gotoxy(28,12);
		printf("TOP SCORES\n");
		fp=fopen("Playerdata.txt","r");
		while(fread(&p,sizeof(struct player),1,fp))
		{
			ps[i]=p;
			i++;
		}
		fclose(fp);
		for(x=0;x<i;x++)
		{
			for(y=x+1;y<i;y++)
			{
				if(ps[x].score<ps[y].score)
				{
					struct player temp;
					temp=ps[x];
					ps[x]=ps[y];
					ps[y]=temp;
				}
			}
		}
		for(x=0;x<5;x++)
		{
			gotoxy(28,13+x);
			printf("%d. %s",x+1,ps[x].name);
			gotoxy(45,13+x);
			printf("%0.0f\n",ps[x].score);
		}
		getch();
		main();
	}
}

float li=255,li2=0;

void background()
{
	setcolor(15);
	setfillstyle(4,5);
	bar(0,0,270,10);
	bar(0,100,270,110);
	//clouds

	line(li-60,50,li-50,50);
	arc(li-55,50,90,180,5);
	arc(li-55,47,360,90,5);
	line(li-55,45,li-55,42);
	line(li-50,50,li-50,48);

	//second
	line(li-80,30,li-50,30);
	arc(li-70,30,90,180,10);
	arc(li-63.5,20,320,180,5);
	arc(li-60,30,360,85,10);

	//third
	line(li,50,li+10,50);
	arc(li+5,50,90,180,5);
	arc(li+6,47,360,90,5);
	line(li+5,45,li+5,42);
	line(li+11,50,li+11,48);

	//forth
	line(li-20,25,li+10,25);
	arc(li-10,25,90,180,10);
	arc(li-5,15,320,180,5);
	arc(li,25,360,85,10);

	//fifth
	line(li2,35,li2+10,35);
	arc(li2+5,35,90,180,5);
	arc(li2+5,32,360,90,5);
	line(li2+5,30,li2+5,28);
	line(li2+11,35,li2+11,33);

	//sixth
	line(li2-80,25,li2-50,25);
	arc(li2-70,25,90,180,10);
	arc(li2-63.5,15,320,180,5);
	arc(li2-60,25,360,85,10);

	setcolor(2);
	li-=.25;
	li2-=.45;
	if(li<0)
		li=255;
	if(li2<0)
		li2=245;
}