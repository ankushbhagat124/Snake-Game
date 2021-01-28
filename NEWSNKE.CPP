#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
char dir=4;
int  gameover=0;
int h=20,l=75;               //height length
int x=l/2,y=h/2;             //snake head
int fx= rand() % l,fy=rand() % h;    //fruit coordinates
const LEFT=0,RIGHT=1,UP=2,DOWN=3;
int tailx[500],taily[500];           //tail coordinates
int tailn=1;                         //no of tails
class player
{
  public:
  int roll;
  char name[10];
  int score;
    player()
    {
      score=0;
    }
    void addname()
    {
      cout<<"Enter roll no: ";
      cin>>roll;
      cout<<"\t\t\t\tEnter your name: ";
      gets(name);
    }
    void cscore(int s)        //change score
    {
      score=s;
    }
    char* getname()
    {
      return name;
    }
    int getscore()
    {
      return score;
    }
    void mscore()               //modify score
    {
       score=tailn*2;
    }
    int getroll()
    {
      return roll;
    }
    void display()
    {
      cout<<"\n\t\t\t";
      cout<<roll;
      cout<<"\t\t";
      cout<<name;
      cout<<"\t\t";
      cout<<score;
    }
}p,pl;
void base();
void input();
void main()
{
  clrscr();
  base();
  while(!gameover)
  {
    input();
  }
  if(gameover)
  {
    clrscr();
    cout<<"\n\n\n\n\n\t\t\t\tYOUR SCORE: "<<p.getscore();
    cout<<"\n\n\n\n\n\n\t\t\t\t";
    p.addname();
    fstream f;
    f.open("players.dat",ios::app);
 //   int x=0;
/*    while(f.read((char*)&pl,sizeof(pl)))
    {
   if(p.getname()==pl.getname())
   {
   x=p.getscore()+pl.getscore();
   p.cscore(x);
   f.seekp(-sizeof(p),ios::cur);  */
   f.write((char*)&p,sizeof(p));
   f.close();
//  }
//  else
 // {
//  f.write((char*)&p,sizeof(p));
//  }
//  }
 }
  getch();
  clrscr();
  cout<<"\n\n\t\t\tTHANKS FOR PLAYING THE GAME\n\n\n\t\t\tplayer details:\n\n\t\t\tRoll No\t\tName\t\tScore";
 fstream f;
  f.open("players.dat",ios::in);
  f.seekg(0);
  while(f.read((char*)&pl,sizeof(pl)))
  {
    pl.display();
  }
  f.close();
  getch();
}
void base()
{
  clrscr();
/*  if(x==l)
  x=1;
  if(x==0)
  x=l-1;
  if(y==0)
  y=h-1;
  if(y==h)
  y=1; */
  for(int op=0;op<tailn;op++)
  {
    if(x==tailx[op]&&y==taily[op])
    {
      gameover++;
    }
  }
  if(x==fx && y==fy)
   {
     fx=(rand() %(l-3))+2 ;
     fy=(rand() %(h-3))+2;
     p.mscore();
     tailn++;
   }
  for (int i=0;i<=l;i++)
    cout<<"Ü";
    cout<<endl;
  for(int k=0;k<=h;k++)
  {
    for(int j=0;j<=l;j++)
    {
      if(j==0)
	cout<<"Ý";
      else if(j==l)
	cout<<"Þ";
      else if(j==x&&k==y)
	cout<<"O";
      else if(j==fx&&k==fy)
	cout<<"*";
      else
      {
	int po=0;
	for(int w=0;w<tailn;w++)
	{
	  if(j==tailx[w]&&k==taily[w])
	    {cout<<"o";
	    po++;}
	}
	if(!po)
	cout<<" ";
      }

    }
    cout<<endl;
   }

   for(int m=0;m<=l;m++)
   cout<<"ß";
   cout<<"\n\t\t\t\t\t\t\tSCORE: "<<p.getscore();


}
void input()
{
  int prevx=tailx[0];
  int prevy=taily[0];
  int prev2x,prev2y;
  for(int f=0;f<tailn;f++)
  {

    prev2x=tailx[f];
    prev2y=taily[f];
    tailx[f]=prevx;
    taily[f]=prevy;
    prevx=prev2x;
    prevy=prev2y;

  }


  for(long double z=0;z<140000-tailn*32000;z++);
  if(kbhit())
   {
     switch(getch())
     {
       case 'a':
	      if(dir!=RIGHT)
		dir=LEFT;
	      break;
       case 'd':
	      if(dir!=LEFT)
		dir=RIGHT;
	      break;
       case 'w':
	      if(dir!=DOWN)
	      dir=UP;
	      break;
       case 's':
	      if(dir!=UP)
	      dir=DOWN;
	      break;
       case 'x':
	      gameover++;
	      break;
       default:
	       break;
     }
   }
   switch(dir)
   {
     case LEFT:
	       tailx[0]=x;
		taily[0]=y;
	       x--;
	       base();
	       break;
     case RIGHT:
		tailx[0]=x;
		taily[0]=y;
		x++;

		base();

		break;
     case UP:
	     tailx[0]=x;
		taily[0]=y;
	     y--;

	     base();
	     break;
     case DOWN:
	     tailx[0]=x;
		taily[0]=y;
	      y++;
	      base();
	      break;
     default:
	     break;
   }
   if(x>=l+1||x<=0||y>=h+1||y<=0)
   {
     gameover++;
   }

}


