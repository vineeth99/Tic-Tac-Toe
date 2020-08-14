#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
union REGS in,out;
class mouse
{
  public:
      int callmouse()
      {
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
      }
      void mouseposi(int &xpos,int &ypos,int &click)
      {
	 in.x.ax=3;
	 int86(51,&in,&out);
	 click=out.x.bx;
	 xpos=out.x.cx;
	 ypos=out.x.dx;
      }
      int mousehide()
      {
	 in.x.ax=2;
	 int86(51,&in,&out);
	 return 1;
      }
};
class graphic
{
  int x1,x2,y1,y2;
  public:
      graphic()
      {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\bgi");
      }
      ~graphic()
      {
	closegraph();
      }
      void start()
      {
	char s[20]="TIC-TAC-TOE";
	char s1[40]="Press ENTER To Start The Game";
	x1=10;
	y1=10;
	x2=getmaxx();
	y2=getmaxy();
	setbkcolor(GREEN);
	setcolor(BLUE);
	rectangle(x1,y1,x2-10,y2-10);
	settextstyle(3,HORIZ_DIR,6);
	outtextxy((x2/2-x2/4),(y2/2-y2/5),s);
	settextstyle(0,HORIZ_DIR,1);
	setcolor(RED);
	outtextxy((x2/2-x2/6),(y2/2-y2/13),s1);
      }

      void bg(char *p1="Player 1: X",char *p2="Player 2: O")
      {
	char s[20]="TIC-TAC-TOE";
	setbkcolor(BLUE);
	x1=10;
	y1=10;
	x2=getmaxx()-10;
	y2=getmaxy()-10;
	rectangle(x1,y1,x2,y2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(185,26,s);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(130,100,p1);
	outtextxy(380,100,p2);
	rectangle(180,350,390,140);
	line(250,140,250,350);
	line(320,140,320,350);
	line(180,210,390,210);
	line(180,280,390,280);
      }
};
class logic
{
  int a[3][3],k;
  static int matches,p1wins,p2wins,draw;
  public:
      logic()
      {
	 int i,j;
	 for(i=0;i<3;i++)
	 {
	   for(j=0;j<3;j++)
	   {
	      a[i][j]=-1;
	   }
	 }
	 k=matches%2;
      }
      void display()
      {
	 char msg[50],m[30]="Press ENTER To Contiue";
	 sprintf(msg,"Games played: %d",matches);
	 outtextxy(200,405,msg);
	 sprintf(msg,"Player 1 Score: %d",p1wins);
	 outtextxy(200,415,msg);
	 sprintf(msg,"Player 2 Score: %d",p2wins);
	 outtextxy(200,425,msg);
	 sprintf(msg,"Draw Matches: %d",draw);
	 outtextxy(200,435,msg);
	 outtextxy(200,445,m);
      }
      static void drawg()
      {
	draw=draw+1;
      }
      static void p1winsg()
      {
	p1wins=p1wins+1;
      }
      static void p2winsg()
      {
	p2wins=p2wins+1;
      }
      static void matchesg()
      {
	matches=matches+1;
      }
      int click(int x,int y)
      {
	if(k==0)
	   setcolor(CYAN);
	else
	   setcolor(RED);
	if(x>=180 && x<250)
	{
	  if(y>=140 && y<210 && a[0][0]==-1)
	  {
	    if(k==0)
	    {
	      line(190,150,240,200);
	      line(190,200,240,150);
	      a[0][0]=5;
	      k=1;
	    }
	    else
	    {
	      circle((180+250)/2,(140+210)/2,30);
	      a[0][0]=1;
	      k=0;
	    }
	    return 1;
	  }
	  if(y>=210 && y<280 && a[0][1]==-1)
	  {
	    if(k==0)
	    {
	      line(190,220,240,270);
	      line(190,270,240,220);
	      a[0][1]=5;
	      k=1;
	    }
	    else
	    {
	      circle((180+250)/2,(210+280)/2,30);
	      a[0][1]=1;
	      k=0;
	    }
	    return 1;
	  }
	  if(y>=280 && y<=350 && a[0][2]==-1)
	  {
	    if(k==0)
	    {
	      line(190,290,240,340);
	      line(190,340,240,290);
	      a[0][2]=5;
	      k=1;
	    }
	    else
	    {
	      circle((180+250)/2,(280+350)/2,30);
	      a[0][2]=1;
	      k=0;
	    }
	    return 1;
	  }
	}

	if(x>=250 && x<320)
	{
	  if(y>=140 && y<210 && a[1][0]==-1)
	  {
	    if(k==0)
	    {
	      line(260,150,310,200);
	      line(260,200,310,150);
	      a[1][0]=5;
	      k=1;
	    }
	    else
	    {
	      circle((250+320)/2,(140+210)/2,30);
	      a[1][0]=1;
	      k=0;
	    }
	    return 1;
	  }
	  if(y>=210 && y<280 && a[1][1]==-1)
	  {
	    if(k==0)
	    {
	      line(260,220,310,270);
	      line(260,270,310,220);
	      a[1][1]=5;
	      k=1;
	    }
	    else
	    {
	      circle((320+250)/2,(210+280)/2,30);
	      a[1][1]=1;
	      k=0;
	    }
	    return 1;
	  }
	  if(y>=280 && y<=350 && a[1][2]==-1)
	  {
	    if(k==0)
	    {
	      line(260,290,310,340);
	      line(260,340,310,290);
	      a[1][2]=5;
	      k=1;
	    }
	    else
	    {
	      circle((250+320)/2,(280+350)/2,30);
	      a[1][2]=1;
	      k=0;
	    }
	    return 1;
	  }
	}

	if(x>=320 && x<=390)
	{
	  if(y>=140 && y<210 && a[2][0]==-1)
	  {
	    if(k==0)
	    {
	      line(330,150,380,200);
	      line(330,200,380,150);
	      a[2][0]=5;
	      k=1;
	    }
	    else
	    {
	      circle((390+320)/2,(140+210)/2,30);
	      a[2][0]=1;
	      k=0;
	    }
	    return 1;
	  }
	  if(y>=210 && y<280 && a[2][1]==-1)
	  {
	    if(k==0)
	    {
	      line(330,220,380,270);
	      line(330,270,380,220);
	      a[2][1]=5;
	      k=1;
	    }
	    else
	    {
	      circle((320+390)/2,(210+280)/2,30);
	      a[2][1]=1;
	      k=0;
	    }
	    return 1;
	  }
	  if(y>=280 && y<=350 && a[2][2]==-1)
	  {
	    if(k==0)
	    {
	      line(330,290,380,340);
	      line(330,340,380,290);
	      a[2][2]=5;
	      k=1;
	    }
	    else
	    {
	      circle((390+320)/2,(280+350)/2,30);
	      a[2][2]=1;
	      k=0;
	    }
	    return 1;
	  }
	}
	return 0;
      }
      int check()
      {
	int s1=0,s2=0,s3=0,r1=0,r2=0,r3=0,sd1=0,sd2=0,i,j;
	for(i=0;i<3;i++)
	{
	  for(j=0;j<3;j++)
	  {
	    if(i==0 && a[i][j]!=-1)
	       s1=s1+a[i][j];
	    if(j==0 && a[i][j]!=-1)
	       r1=r1+a[i][j];
	    if(i==1 && a[i][j]!=-1)
	       s2=s2+a[i][j];
	    if(j==1 && a[i][j]!=-1)
	       r2=r2+a[i][j];
	    if(i==2 && a[i][j]!=-1)
	       s3=s3+a[i][j];
	    if(j==2 && a[i][j]!=-1)
	       r3=r3+a[i][j];
	    if(i==j && a[i][j]!=-1)
	       sd1=sd1+a[i][j];
	    if(i+j==2 && a[i][j]!=-1)
	       sd2=sd2+a[i][j];
	  }
	}
	  if(s1==15 || s2==15 || s3==15 || r1==15 || r2==15 || r3==15 || sd1==15 || sd2==15)
	       return 1;
	  else if(s1==3 || s2==3 || s3==3 || r1==3 || r2==3 || r3==3 || sd1==3 || sd2==3)
	       return 2;
	  else
	       return 0;
      }

};
int logic::draw;
int logic::p1wins;
int logic::matches;
int logic::p2wins;
void main()
{
   int x,y,cl,a,b,k,c;
   char ch,p1[20],p2[20];
   clrscr();
   mouse m;
   graphic s;
   s.start();
   getch();
   closegraph();
   cout<<"Enter name of player 1: ";
   cin>>p1;
   cout<<"Enter name of player 2: ";
   cin>>p2;
   clrscr();
   strcat(p1,": X");
   strcat(p2,": O");
   do
   {
    logic l;
    c=0;
    k=0;
    graphic g;
    g.bg(p1,p2);
    m.callmouse();
    do
    {
      m.mouseposi(x,y,cl);
      if(cl==1)
      {
	 c=c+l.click(x,y);
	 if(c>4)
	  k=l.check();
	 if(c==9 && k==0)
	 {
	     logic::drawg();
	     logic::matchesg();
	     outtextxy(260,370,"DRAW");
	     l.display();
	     break;
	 }
	 if(k==1)
	 {
	     logic::p1winsg();
	     logic::matchesg();
	     outtextxy(260,370,"Player 1: X- won");
	     l.display();
	     break;
	 }
	 if(k==2)
	 {
	     logic::p2winsg();
	     logic::matchesg();
	     outtextxy(260,370,"Player 2: O-won");
	     l.display();
	     break;
	 }
      }
    }while(!kbhit());
    getch();
    closegraph();
    cout<<"Do you want to continue press Y/N: ";
    cin>>ch;
   }while(ch!='n' && ch!='N');
    m.mousehide();
}
