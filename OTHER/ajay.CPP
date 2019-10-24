#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>
#include<graphics.h>
#include<string.h>
#include<process.h>
void design1();
void game_2();
void game_1();
struct node{
	int left,up,right,down;
	struct node *prev,*next;
};
struct node *pnew,*temp,*pthis,*pfirst,*PFIRST,*plast,*PLAST;
class gameplay{
private:
int l,u,r,d,X1,X2,Y1,Y2,c1,c2,a,left,up,right,down,i,ctrl,n;
public:
int signal,sensor1,sensor2,key;
void init1(int mode){ //initialize value for player1
	left=12,up=12,right=17,down=17,c1=1,c2=1,l=6,u=0,r=6,d=0,
	ctrl=100,signal=0,key=NULL,sensor1=0,sensor2=0;
	if(mode==1){
	   c2=2,n=0;
	}

}
void init2(int mode){ //for player 2
	left=516,up=450,right=521,down=455,c1=1,c2=1,l=-6,u=0,r=-6,d=0
	,ctrl=106,signal=0,key=NULL,sensor1=0,sensor2=0;
	if(mode==1){
	       c2=2,n=0;
	}
}
void inline data(int l,int u,int r,int d){ //assign data to temp pointer.
	pnew=(struct node*)malloc(sizeof(struct node));
	pnew->left=l;
	pnew->right=r;
	pnew->up=u;
	pnew->down=d;
	pnew->next=NULL;
	pnew->prev=NULL;
}
int self_destruct(int V1, int V2, int X1, int Y1, int X2, int Y2){//checks crsh
	int a=0;
	//cout<<V1<<"\t"<<V2<<"\t"<<X1<<"\t"<<Y1<<"\t"<<X2<<"\t"<<Y2<<"\n";
	if((V1-1)==V2||V1==(V2-1)){
		if(X1==Y1||X2==Y2){
		//Crash
		a=1;
		}
		else{
		//No Crash
		a=0;
		}
	}
	return a;

}
public:
int body_range(int L1,int T1, int R1, int D1,struct node *head, char mov){
	//organize values to check crash
	int a;
	int L=head->left;
	int T=head->up;
	int R=head->right;
	int D=head->down;
	if(mov=='w'||mov=='W'||mov=='i'||mov=='I')
	a=self_destruct(T,D1,L,L1,R,R1);
	else if(mov=='s'||mov=='S'||mov=='k'||mov=='K')
	a=self_destruct(D,T1,L,L1,R,R1);
	else if(mov=='a'||mov=='A'||mov=='J'||mov=='j')
	a=self_destruct(L,R1,T,T1,D,D1);
	else if(mov=='d'||mov=='D'||mov=='l'||mov=='L')
	a=self_destruct(R,L1,T,T1,D,D1);
	else a=0;
	if(L==L1&&T==T1&&D==D1&&R==R1)a=1;
	return a;
}

void block1();//saves coordinates of the bar box for  player 1
void BLOCK1();
gameplay head_strike(gameplay);
gameplay body_strike1(gameplay);
gameplay body_strike2(gameplay);
gameplay boundry_handler(gameplay);
void remove(int);//for saving mode player 1
void REMOVE(int);//in saving mode for player 2
gameplay error_handler1(gameplay p,int mov,int mode){//handles kbhit() problem
	if(mov=='w'||mov=='s'||mov=='a'||mov=='d'){
		key=mov;
		if(key=='a'&&c2==1&&mode==2||key=='a'&&c2==3&&mode==1){
			signal=0;
		}
		else{
		signal=1;
		if(key=='w'&&ctrl=='s')key='s';
		else if(key=='s'&&ctrl=='w')key='w';
		else if(key=='a'&&ctrl=='d')key='d';
		else if(key=='d'&&ctrl=='a')key='a';
		ctrl=key;
		}
	}
	else if(mov=='j'||mov=='k'||mov=='l'||mov=='i'){
		p.key=mov;
		if(p.key=='l'&&p.c2==1){p.signal=0;}
		else{
		p.signal=2;
		if(p.key=='i'&&p.ctrl=='k')p.key='k';
		else if(p.key=='j'&&p.ctrl=='l')p.key='l';
		else if(p.key=='l'&&p.ctrl=='j')p.key='j';
		else if(p.key=='k'&&p.ctrl=='i')p.key='i';
		p.ctrl=p.key;
		}
	}
	return p;
}
void mover1(){//assign value to which extent the co ordinate to be changed
	if(signal==1){
	if(key=='w'||key=='W'){l=0,u=-6,r=0,d=-6;}
		else if(key=='s'||key=='S'){l=0,u=6,r=0,d=6;}
		else if(key=='a'||key=='A'){l=-6,u=0,r=-6,d=0;}
		else if(key=='d'||key=='D'){l=6,u=0,r=6,d=0;}
	}
}
void mover2(){
	if(signal==2){
	if(key=='i'||key=='I'){l=0,u=-6,r=0,d=-6;}
		else if(key=='k'||key=='K'){l=0,u=6,r=0,d=6;}
		else if(key=='J'||key=='j'){l=-6,u=0,r=-6,d=0;}
		else if(key=='l'||key=='L'){l=6,u=0,r=6,d=0;}
	}
}

void display(int);
void DISPLAY(int);
gameplay yamaraj1(gameplay);
gameplay yamaraj2(gameplay,int score1, int score2);
gameplay ashes(gameplay);
};
void  gameplay::block1(){
	while(c1<=c2){
		left+=l,up+=u,right+=r,down+=d;
		data(left,up,right,down);
		if(pfirst==NULL){
			pfirst=pnew;
			plast=pfirst;
		}
		else{
			pnew->next=pfirst;
			pfirst->prev=pnew;
			pfirst=pnew;
		}
		c1++;
	}

}
void  gameplay::BLOCK1(){
	while(c1<=c2){
		left+=l,up+=u,right+=r,down+=d;
		data(left,up,right,down);
		if(PFIRST==NULL){
			PFIRST=pnew;
			PLAST=PFIRST;
		}
		else{
			pnew->next=PFIRST;
			PFIRST->prev=pnew;
			PFIRST=pnew;
		}
		c1++;
	}
}
void gameplay::display(int signal){
	 pthis=pfirst;
	 i=1;
	 while(pthis!=plast){
	 if(i==1)
		setfillstyle(1,1);
		else if (i==2)
		setfillstyle(1,4);
		bar(pthis->left,pthis->up,pthis->right,pthis->down);
		pthis=pthis->next;
		a=body_range(pthis->left,pthis->up,pthis->right,pthis->down,pfirst,key);
		i++;
		if(a==1){sensor1=4,signal=0;}
	 }
	 if(signal==1)
		c2++;
	 if(i==1)setfillstyle(1,1);
	 bar(pthis->left,pthis->up,pthis->right,pthis->down);
}
void gameplay::DISPLAY(int signal){
	 pthis=PFIRST;
	 i=1;
	 while(pthis!=PLAST){
		if(i==1)
		setfillstyle(1,3);
		else if (i==2)
		setfillstyle(1,6);
		bar(pthis->left,pthis->up,pthis->right,pthis->down);
		pthis=pthis->next;
		a=body_range(pthis->left,pthis->up,pthis->right,pthis->down,PFIRST,key);
		if(a==1){sensor1=3,signal=0;}
		i++;
	 }
	 if(signal==2)
			c2++;
	 if(i==1)setfillstyle(1,3);
	 bar(pthis->left,pthis->up,pthis->right,pthis->down);
}
gameplay gameplay::head_strike(gameplay p){
		p.a=body_range(pfirst->left,pfirst->up,pfirst->right,pfirst->down,
		PFIRST,p.key);
			if(p.a==1){
			sensor1=2;signal=0,p.signal=0;
			}
	return p;
}
gameplay gameplay::body_strike1(gameplay p){
	pthis=pfirst;
	while(pthis!=plast){
		pthis=pthis->next;
	       p.a=body_range(pthis->left,pthis->up,pthis->right,pthis->down,PFIRST,p.key);
		if(p.a==1){p.sensor2=3,p.signal=0;
		}
	}
		return p;

}
gameplay gameplay::body_strike2(gameplay p){
	pthis=PFIRST;
	while(pthis!=PLAST){
		pthis=pthis->next;
		a=body_range(pthis->left,pthis->up,pthis->right,pthis->down,pfirst,key);
		if(a==1){sensor2=4;signal=0;}
	}
		return p;
}
gameplay gameplay::yamaraj1(gameplay p){
	if(sensor1==4||p.sensor1==3||sensor1==2||sensor1==4||p.sensor2==3||sensor2==4){
	char d[4]="DRAW",w1[20]="PLAYER 1 WINNER",w2[20]="PLAYER 2 WINNER";
	char st[20];
	if(sensor1==2||p.sensor2==3&&sensor2==4||sensor1==3&&p.sensor1==4){
		setcolor(4);
		strcpy(st,d);
	}
	else if(p.sensor1==3||p.sensor2==3){
		setcolor(5);
		strcpy(st,w1);
	}
	else if(sensor1==4||sensor2==4||sensor1==4){
		setcolor(3);
		strcpy(st,w2);
	}
			for(i=0;i<=29;i++){
				if(kbhit())key=getch();
				key=NULL;
				settextstyle(1,0,3);
				outtextxy(getmaxx()/2-95,getmaxy()/2,st);
				delay(100);
			}
			sensor1=1;
	}
	else
	sensor1=0;
	sensor2=0,p.sensor1=0,p.sensor2=0;
	return p;
}
gameplay gameplay::yamaraj2(gameplay p,int score1, int score2){
	if(sensor1==4||p.sensor1==3||sensor1==2||sensor1==4||p.sensor2==3||sensor2==4){
	char d[20]="RESPAWNING....",w1[20]="PLAYER 1 WINNER",w2[20]="PLAYER 2 WINNER";
	char st[20];
	if(n<0||p.n<0||sensor1==2||score1==20||score2==20){
		if(p.sensor1==3||p.sensor2==3||score2==20){
			setcolor(5);
			strcpy(st,w2);
		}
		else if(sensor1==2||p.sensor2==3&&sensor2==4||sensor1==3&&p.sensor1==4){
		setcolor(4);
		strcpy(st,d);
		}
		else if(sensor1==4||sensor2==4||sensor1==4||score1==20){
			setcolor(3);
			strcpy(st,w1);
		}
		for(i=0;i<=29;i++){
			if(kbhit())key=getch();
			key=NULL;
			settextstyle(1,0,3);
			outtextxy(getmaxx()/2-160,getmaxy()/2,st);
			delay(100);
		}
		sensor1=1;
	}
	}
	else
	sensor1=0;
	sensor2=0,p.sensor1=0,p.sensor2=0;
	return p;
}

gameplay gameplay::ashes(gameplay p){
	pthis=pfirst;
	while(pthis!=plast){
		temp=pthis;
		pthis=pthis->next;
		free(temp);
	}
	pfirst=plast;
	pthis=PFIRST;
	while(pthis!=PLAST){
		temp=pthis;
		pthis=pthis->next;
	       free(temp);
	}
	pfirst=PLAST;
	pfirst=NULL;
	PFIRST=NULL;
	plast=NULL;
	PLAST=NULL;
	return p;
}
gameplay gameplay::boundry_handler(gameplay p){
	gameplay P;
	setviewport(10,4,543,477,1);
	for(int i=0;i<2;i++){
	if(i==0){
	pthis=pfirst;
	P=*this;
	}
	else if(i==1){
	pthis=PFIRST;
	P=p;
	}
	if(pthis->left==0&&P.key=='a'||pthis->left==0&&P.key=='j'){
		P.left=534,P.right=539;
	}
	else if(pthis->right==533&&P.key=='d'||pthis->right==533&&P.key=='l'){
		P.left=-6,P.right=-1;
	}
	else if(pthis->up==0&&P.key=='w'||pthis->up==0&&P.key=='i'){
		P.up=468,P.down=473;
		}
	else if(pthis->down==467&&P.key=='s'||pthis->down==467&&P.key=='k'){
		P.up=-6,P.down=-1;
	}
	if(i==0)*this=P;
	else if(i==1)p=P;
	}
	return p;
}
void gameplay::remove(int mode){
	if(signal==1){
		pthis=plast;
		if(c2%30!=0){
			pthis=pthis->prev;
			plast=pthis;
		}
		 else
		 n++;
	}
	else if(signal==0&&mode==1){
		 if(sensor1==4||sensor2==4){n++;signal=1;}
	}

}
void gameplay::REMOVE(int mode){
	if(signal==2){
		pthis=PLAST;
		if(c2%30!=0){
			pthis=pthis->prev;
			PLAST=pthis;
		}
		else
		n++;
	}
	else if(signal==0&&mode==1){
		if(sensor1==3||sensor2==3){n++;signal=2;}
	}
}
void main(){
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"..//bgi");
	int a=4,b=15,c=15,n=1,key,game_mode=1;
	char key1;
	setfillstyle(10,6);
	bar(0,0,getmaxx(),getmaxy());
	settextstyle(0,0,5);
	outtextxy(getmaxx()/2-190,getmaxy()/2-30,"WE ARE ABS");
	delay(4000);
	cleardevice();
	menu:
	delay(600);
	key=0;key1=NULL;n=1;
	while(13!=(int)key1){
		setfillstyle(10,9);
		bar(0,0,getmaxx(),getmaxy());
		setcolor(4);
		settextstyle(0,0,9);
		outtextxy(10,getmaxy()/2-100,"LINE");
		outtextxy(35,getmaxy()/2-20,"WAR");
		setcolor(a);
		settextstyle(0,0,2);
		outtextxy(getmaxx()/2+20,80,"Start");
		setcolor(b);
		outtextxy(getmaxx()/2+20,110,"Instruction");
		setcolor(c);
		outtextxy(getmaxx()/2+20,140,"Exit");
	       key1=getche();
			key=(int)key1;
			if(key==80)n++;
			else if(key==72)n--;
			if(n==0)n=3;
			if(n==4)n=1;
			if(n==1)a=4,b=15,c=15;
			else if(n==2)a=15,b=4,c=15;
			else if(n==3)a=15,b=15,c=4;
	}
	cleardevice();
	delay(600);
	if(n==1){
	key=0;key1=NULL;game_mode=1;
	while(13!=(int)key1){
		setfillstyle(10,9);
		bar(0,0,getmaxx(),getmaxy());
		setcolor(4);
		settextstyle(0,0,9);
		outtextxy(10,getmaxy()/2-100,"LINE");
		outtextxy(35,getmaxy()/2-20,"WAR");
		setcolor(a);
		settextstyle(0,0,2);
		outtextxy(getmaxx()/2+20,80,"Save Mode");
		setcolor(b);
		outtextxy(getmaxx()/2+20,110,"Trap Mode");
		setcolor(c);
		outtextxy(getmaxx()/2+20,140,"Back");
	       key1=getche();
			key=(int)key1;
			if(key==80)game_mode++;
			else if(key==72)game_mode--;
			if(game_mode==0)game_mode=3;
			if(game_mode==4)game_mode=1;
			if(game_mode==1)a=4,b=15,c=15;
			else if(game_mode==2)a=15,b=4,c=15;
			else if(game_mode==3)a=15,b=15,c=4;
	}
	cleardevice();
	if(game_mode==1)game_1();
	else if(game_mode==2)game_2();
	else if(game_mode==3)goto menu;
	goto menu;
	}
	else if(n==2){
	cleardevice();
	delay(600);
	while(27!=(int)key1){
		setviewport(0,0,getmaxx(),getmaxy(),1);
		setfillstyle(10,9);
		bar(0,0,getmaxx(),getmaxy());
		setcolor(4);
		outtextxy(10,10,"ESC");
		setcolor(4);
		settextstyle(0,0,9);
		outtextxy(10,getmaxy()/2-100,"LINE");
		outtextxy(35,getmaxy()/2-20,"WAR");
		setcolor(5);
		settextstyle(1,0,3);
		outtextxy(getmaxx()/2,80,"Player 1");
		outtextxy(getmaxx()/2+170,80,"Pllayer 2");
		settextstyle(0,0,1);
		setcolor(15);
		outtextxy(getmaxx()/2+20,110,"w            UP");
		outtextxy(getmaxx()/2+20,130,"s            DOWN");
		outtextxy(getmaxx()/2+20,150,"d            RIGHT");
		outtextxy(getmaxx()/2+20,170,"a            LEFT");
		outtextxy(getmaxx()/2+190,110,"i");
		outtextxy(getmaxx()/2+190,130,"k");
		outtextxy(getmaxx()/2+190,150,"l");
		outtextxy(getmaxx()/2+190,170,"j");
		outtextxy(getmaxx()/2-90,340,"Trap Mode:Avoid hit and trap others");
		outtextxy(getmaxx()/2-90,355,"Save Mode:Save your line. Hit others");
	       key1=getche();
	       key=(int)key1;
	}
	if(key==27)goto menu;
	}
	else if(n==3)exit(1);
}

void game_2(){
	int stopper=0,n=0,c=0,key=0;
	gameplay p1,p2;
	p1.init1(2);
	p2.init2(2);
	p1.block1();
	p2.BLOCK1();
	design1();
	while(key!=27){
		if(kbhit()){
			key=getch();
			c++;
			stopper=n;
			p2=p1.error_handler1(p2,key,2);
			if(key=='w'||key=='s'||key=='a'||key=='d'){
			    p1.mover1();//set value for lurd;
			    sound(300);
			}
			else if(key=='i'||key=='j'||key=='k'||key=='l'){
			    p2.mover2();
			    sound(500);
			}


		}
		p2=p1.boundry_handler(p2);
		p2=p1.head_strike(p2);
		p2=p1.body_strike2(p2);//returns 4 for line 2 hit.
		p2=p1.body_strike1(p2);//returns 3 for line 1 hit.
		p1.display(p1.signal);
		p2.DISPLAY(p2.signal);
		if(key==NULL)
		outtextxy(getmaxx()/2-95,getmaxy()/2,"ESC TO EXIT");
		if(c==1&&stopper==n){cleardevice(); design1();}
		delay(100);
		nosound();
		p2=p1.yamaraj1(p2);
		if(p1.sensor1==1){
			p1.sensor1=0;
			p2=p1.ashes(p2);
			p1.init1(2);
			p2.init2(2);
			cleardevice();
			design1();
		}
		p1.block1();//creates block of 5X5
		p2.BLOCK1();
		n++;
	}
	cleardevice();
	clearviewport();
}
void game_1(){
	int key=0,score1=0,score2=0;
	gameplay p1,p2;
	p1.init1(1);
	p2.init2(1);
	p1.block1();
	p2.BLOCK1();
	while(key!=27){
	setviewport(0,0,getmaxx(),getmaxy(),1);
	setfillstyle(3,5);
	bar(6,0,544,3);//top
	bar(6,0,9,478);//left
	bar(544,3,548,478);//right
	bar(9,478,544,480);//down
	bar(544,0,640,3);
	bar(636,0,640,480);
	bar(544,478,640,480);
	settextstyle(0,0,1);
	outtextxy(556,6,"WHAT'S UP");
	setcolor(15);
	setcolor(8);
	settextstyle(0,0,1);
	outtextxy(550,115,"SCORE BOARD");
	outtextxy(556,150,"20");
	outtextxy(556,165,"19");
	outtextxy(556,180,"18");
	outtextxy(556,195,"17");
	outtextxy(556,210,"16");
	outtextxy(556,225,"15");
	outtextxy(556,240,"14");
	outtextxy(556,255,"13");
	outtextxy(556,270,"12");
	outtextxy(556,285,"11");
	outtextxy(556,300,"10");
	outtextxy(556,315,"09");
	outtextxy(556,330,"08");
	outtextxy(556,345,"07");
	outtextxy(556,360,"06");
	outtextxy(556,375,"05");
	outtextxy(556,390,"04");
	outtextxy(556,405,"03");
	outtextxy(556,420,"02");
	outtextxy(556,435,"01");
	outtextxy(556,450,"00");
	setfillstyle(1,1);
		bar(600,463,615,450-score1*15);
		setfillstyle(1,3);
		bar(617,463,632,450-score2*15);
	setcolor(YELLOW);
		if(kbhit()){
			key=getch();
			p2=p1.error_handler1(p2,key,1);
			if(key=='w'||key=='s'||key=='a'||key=='d'){
			    p1.mover1();//set value for lurd;
			    sound(300);
			}
			else if(key=='i'||key=='j'||key=='k'||key=='l'){
			    p2.mover2();
			    sound(500);
			}
		}
		if(key==NULL)outtextxy(getmaxx()/2-80,getmaxy()/2,"ESC TO EXIT");
		p2=p1.boundry_handler(p2);
		p2=p1.head_strike(p2);
		p2=p1.body_strike2(p2);//returns 4 for line 2 hit.
		p2=p1.body_strike1(p2);
		p2=p1.body_strike2(p2);
		p2=p1.body_strike1(p2);
		p1.display(p1.signal);
		p2.DISPLAY(p2.signal);
		delay(100);
		nosound();
		p1.remove(1);
		p2.REMOVE(1);
		if(p1.sensor1==4||p1.sensor2==4){
			//if(p1.sensor1==4){cout<<"dlfsldflsdkfl";getch();}
			p2.REMOVE(1);
			score1++;
		}

		if(p2.sensor1==3||p2.sensor2==3){
			//if(p1.sensor1==3){cout<<"dlfsldflsdkfl";getch();}
			p1.remove(1);
			score2++;
		}
		p2=p1.yamaraj2(p2,score1,score2);
		if(p1.sensor1==1){
			p1.sensor1=0;
			p2=p1.ashes(p2);
			p1.init1(1);
			p2.init2(1);
			cleardevice();
			design1();
			score1=0;score2=0;
		}
		p1.block1();
		p2.BLOCK1();
		cleardevice();

	}
	p2=p1.ashes(p2);
	cleardevice();
	clearviewport();
}
void design1(){
	setviewport(0,0,getmaxx(),getmaxy(),1);
	setfillstyle(3,5);
	bar(6,0,544,3);//top
	bar(6,0,9,478);//left
	bar(544,3,548,478);//right
	bar(19,478,544,480);//down
	setfillstyle(9,10);
	bar(548,0,640,480);
}
