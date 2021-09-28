#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

const length=100,height=20;
int gameover;
int dir;
enum dir{STOP=0,UP,DOWN,LEFT,RIGHT};
int x,y,fruitx,fruity,score;
int tailn,tailx[100],taily[100];

void setup()
{
    //randomize();
    x=length/2;
    y=height/2;
    fruitx=rand()%length;
    fruity=rand()%height;
    score=0;
    gameover=0;
    dir=STOP;
    tailn=20;
}


void Draw()
{
    system("cls");
    for(int j = 0 ; j < height ; j++ )
    {
        for(int i = 0 ; i < length ; i++ )
        {
            if( j==0 || j==height-1 || i==0 || i==length-1 )
                printf("#");
            else
                if( i==x && j==y )
                    printf("O");
            else
                if( i==fruitx && j==fruity )
                    printf("*");
            else                                            //
                if(tailn)                                   //
                {
                    int a=0;
                    for(int k=0;k<tailn;k++)                //
                    {
                        if( i==tailx[k] && j==taily[k] )    //
                        {
                            printf("o");
                            a++;
                        }
                    }
                    if(!a)
                        printf(" ");
                }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\nx=%d y=%d",x,y);
    printf(" Fx=%d Fy=%d tailx=%d taily=%d\t\t    SCORE:%d",fruitx,fruity,tailx[1],taily[1],score);
}


void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'a':
                dir=LEFT;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'x':
                gameover=1;
                break;
        }
    }
}


void logic()
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
    switch(dir)
    {
        case UP:
            y--;
            taily[0]=y;
            break;
        case DOWN:
            y++;
            taily[0]=y;
            break;
        case LEFT:
            x--;
            tailx[0]=x;
            break;
        case RIGHT:
            x++;
            tailx[0]=x;
            break;
        default:
            break;
    }
    if( x==fruitx && y==fruity )
    {
        score++;
        tailn++;
        fruitx=rand()%(length-1)+1;
        fruity=rand()%(height-1)+1;
    }
    if( x==length+1 || x==-1 || y==height+1|| y==-1)
    {
        gameover=1;
    }
    for(int i=1;i<tailn;i++)
    {
        if( x==tailx[i]&& y==taily[i] )
            gameover++;
    }
}

int main()
{
    setup();
    while(!gameover)
    {
        Draw();
        input();
        logic();
    }

    return 0;
}
