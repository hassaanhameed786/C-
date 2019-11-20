#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

void setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

 enum SYGLE[3][3] = {‘ ‘ ,’-‘,’-‘,’-‘,’-‘,’-‘,’-‘,’-‘,’-‘ };
 bool BOOLSWITCH[3][3]= { true, true, true ,true , true , true , true , true , true };
 bool SWITCHPLACE [40][15];

 int compteur=0;

 int score_IA=0;
 int score_P =0;

 int count_P=0;
 int ROLL_;
 int ROLL;

 int x;
 int y;
 char tempo;

 int H=30;
 int V=5;

 char drawing[11];

const void draw()
{
  int b = 28;
  int a = 5;

  drawing[0]=205;
  drawing[1]=186;
  drawing[2]=188;
  drawing[3]=187;
  drawing[4]=200;
  drawing[5]=201;
  drawing[6]=206;
  drawing[7]=204;
  drawing[8]=185;
  drawing[9]=202;
  drawing[10]=203;

 for(a=3 ; a < 16 ; a++)
 {
   gotoxy(b,a);
   printf(“%c”,drawing[1]);

   if(b==40 && a==15)
   goto end;

   if(a==15)
   {
    a=3;
    b=b+4;
   }

 }

end: ;

 a=3;
 for(b=28 ; b < 41 ; b++)
 {
   gotoxy(b,a);
   printf(“%c”,drawing[0]);

   if(b==40 && a==15)
   goto end2;

   if(b==40)
   {
    b=27;
    a=a+4;
   }

 }
end2: ;

gotoxy(28,3);
printf(“%c”,drawing[5]);
gotoxy(40,3);
printf(“%c”,drawing[3]);
gotoxy(28,15);
printf(“%c”,drawing[4]);
gotoxy(40,15);
printf(“%c”,drawing[2]);

gotoxy(28,11);
printf(“%c”,drawing[7]);
gotoxy(28,7);
printf(“%c”,drawing[7]);

gotoxy(40,11);
printf(“%c”,drawing[8]);
gotoxy(40,7);
printf(“%c”,drawing[8]);

gotoxy(32,7);
printf(“%c”,drawing[6]);
gotoxy(36,7);
printf(“%c”,drawing[6]);
gotoxy(32,11);
printf(“%c”,drawing[6]);
gotoxy(36,11);
printf(“%c”,drawing[6]);

gotoxy(32,3);
printf(“%c”,drawing[10]);
gotoxy(36,3);
printf(“%c”,drawing[10]);
gotoxy(32,15);
printf(“%c”,drawing[9]);
gotoxy(36,15);
printf(“%c”,drawing[9]);
}

void reboot()
{
    SYGLE[0][0]=’-‘;
    SYGLE[1][0]=’-‘;
    SYGLE[2][0]=’-‘;
    SYGLE[0][1]=’-‘;
    SYGLE[1][1]=’-‘;
    SYGLE[2][1]=’-‘;
    SYGLE[0][2]=’-‘;
    SYGLE[1][2]=’-‘;
    SYGLE[2][2]=’-‘;

    BOOLSWITCH[0][0]=’-‘;
    BOOLSWITCH[1][0]=’-‘;
    BOOLSWITCH[2][0]=’-‘;
    BOOLSWITCH[0][1]=’-‘;
    BOOLSWITCH[1][1]=’-‘;
    BOOLSWITCH[2][1]=’-‘;
    BOOLSWITCH[0][2]=’-‘;
    BOOLSWITCH[1][2]=’-‘;
    BOOLSWITCH[2][2]=’-‘;

    SWITCHPLACE[30][5]=false;
    SWITCHPLACE[34][5]=false;
    SWITCHPLACE[38][5]=false;
    SWITCHPLACE[30][9]=false;
    SWITCHPLACE[34][9]=false;
    SWITCHPLACE[38][9]=false;
    SWITCHPLACE[30][13]=false;
    SWITCHPLACE[34][13]=false;
    SWITCHPLACE[38][13]=false;

    H=30;
    V=5;
    x=0;
    y=0;
}

const void CHECK()
{
            if(H==30 && V == 5)                                                  // Where to Switch
            {
             x=0;
             y=0;
            }

            if( H==34 && V == 5)
            {
             x=1;
             y=0;
            }
            if( H==38 && V == 5)
            {
             x=2;
             y=0;
            }
            if( H==30 && V == 9)
            {
             x=0;
             y=1;
            }
            if( H==34 && V == 9)
            {
             x=1;
             y=1;
            }
            if( H==38 && V == 9)
            {
             x=2;
             y=1;
            }
            if( H==30 && V == 13)
            {
             x=0;
             y=2;
            }
            if( H==34 && V == 13)
            {
             x=1;
             y=2;
            }
            if( H==38 && V == 13)
            {
             x=2;
             y=2;
            }
}

 void gotoxied()
{
    srand (time(NULL));

    for( x ; x<=2 ;x++ )
    {
        setcolor(3);
        gotoxy(H,V);
        printf(“%c”,SYGLE[x][y]);
        H=H+4;
        if(x==2)
        {
            x=-1;
            y=y+1;
            H=30;
            V=V+4;
        }
        if(y==3)
        break;
    }

    gotoxy(30,5);
      H=30;
      V=5;
      x=0;
      y=0;
}

 void IA()
 {

  SWITCHPLACE[H][V];
  ROLL = 1+rand() %100 ;
  //ROLL_ = 1+rand() %100 ;

while(1)
{

setcolor(9);
if(count_P >= 2)
{
 if(ROLL > 1)                                                                                        // DEF IA
 {
      if(SYGLE[0][y] == ‘X’ && SYGLE[1][y] == ‘X’ && BOOLSWITCH[2][y]==true)                    // Case 1 FOR CURSOR
     {
        SYGLE[2][y]=’O’;
        gotoxy(38,V);
        printf(“%c”,SYGLE[2][y]);
        H=38;
        x=2;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[2][y]=false;
        break;
     }

      if(SYGLE[2][y] == ‘X’ && SYGLE[1][y] == ‘X’ && BOOLSWITCH[0][y]==true)                    // Case 2 FOR CURSOR
     {
        SYGLE[0][y]=’O’;
        gotoxy(30,V);
        printf(“%c”,SYGLE[0][y]);
        H=30;
        x=0;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[0][y]=false;
        break;
     }

       if(SYGLE[x][0] == ‘X’ && SYGLE[x][1] == ‘X’ && BOOLSWITCH[x][2]==true)                    // Case 3 FOR CURSOR
     {
        SYGLE[x][2]=’O’;
        gotoxy(H,13);
        printf(“%c”,SYGLE[x][2]);
        V=13;
        y=2;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[x][2]=false;
        break;
     }

       if(SYGLE[x][2] == ‘X’ && SYGLE[x][1] == ‘X’ && BOOLSWITCH[x][0]==true)                    // Case 4 FOR CURSOR
     {
        SYGLE[x][0]=’O’;
        gotoxy(H,5);
        printf(“%c”,SYGLE[x][0]);
        V=5;
        y=0;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[x][0]=false;
        break;
     }

       if(SYGLE[1][1] == ‘X’ && SYGLE[2][0] == ‘X’ && BOOLSWITCH[0][2]==true)                    // Case Diagonale 1 FOR CURSOR
     {
        SYGLE[0][2]=’O’;
        gotoxy(30,13);
        printf(“%c”,SYGLE[0][2]);
        V=13,H=30;
        x=0,y=2;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[0][2]=false;
        break;
     }

        if(SYGLE[0][2] == ‘X’ && SYGLE[1][1] == ‘X’ && BOOLSWITCH[2][0]==true)                    // Case Diagonale 2 FOR CURSOR
     {
        SYGLE[2][0]=’O’;
        gotoxy(38,5);
        printf(“%c”,SYGLE[2][0]);
        V=5,H=38;
        x=2,y=0;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[2][0]=false;
        break;
     }

         if(SYGLE[0][0] == ‘X’ && SYGLE[1][1] == ‘X’ && BOOLSWITCH[2][2]==true)                    // Case Diagonale 3 FOR CURSOR
     {
        SYGLE[2][2]=’O’;
        gotoxy(38,13);
        printf(“%c”,SYGLE[2][2]);
        V=13,H=38;
        x=2,y=2;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[2][2]=false;
        break;
     }

        if(SYGLE[2][2] == ‘X’ && SYGLE[1][1] == ‘X’ && BOOLSWITCH[0][0]==true)                    // Case Diagonale 4 FOR CURSOR
     {
        SYGLE[0][0]=’O’;
        gotoxy(30,5);
        printf(“%c”,SYGLE[0][0]);
        V=5,H=30;
        x=0,y=0;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[0][0]=false;
        break;
     }

       if(SYGLE[0][y] == ‘X’ && SYGLE[2][y] == ‘X’ && BOOLSWITCH[1][y]==true)                    // Case Midle Normal
     {
        SYGLE[1][y]=’O’;
        gotoxy(34,V);
        printf(“%c”,SYGLE[1][y]);
        H=34;
        x=1;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[1][y]=false;
        break;
     }

       if(SYGLE[x][2] == ‘X’ && SYGLE[x][0] == ‘X’ && BOOLSWITCH[x][1]==true)                    // Case Midle Normal
     {
        SYGLE[x][1]=’O’;
        gotoxy(H,9);
        printf(“%c”,SYGLE[x][1]);
        V=9;
        y=1;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[x][1]=false;
        break;
     }

      if(SYGLE[0][2] == ‘X’ && SYGLE[2][0] == ‘X’ && BOOLSWITCH[1][1]==true)                    // Case Midle diago /
     {
        SYGLE[1][1]=’O’;
        gotoxy(34,9);
        printf(“%c”,SYGLE[1][1]);
        V=9,H=34;
        y=1,x=1;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[1][1]=false;
        break;
     }

       if(SYGLE[0][0] == ‘X’ && SYGLE[2][2] == ‘X’ && BOOLSWITCH[1][1]==true)                    // Case Midle diago
     {
        SYGLE[1][1]=’O’;
        gotoxy(34,9);
        printf(“%c”,SYGLE[1][1]);
        V=9,H=34;
        y=1,x=1;

        gotoxy(H,V);
        SWITCHPLACE[H][V]=true;
        BOOLSWITCH[1][1]=false;
        break;
     }

 }
     else
     goto begin;

}

begin: ;                                                                                // Basic first random part
    setcolor(9);
    x = rand() %3;
    y = rand() %3;

    H = rand() %9 + 30;
    V = 5+ rand() %13;

    if( H == 30 && V == 5 || H==34 && V == 5 || H == 38 && V==5 || H == 30 && V==9 || H == 34 && V==9 || H == 38 && V==9 || H == 30 && V==13 || H == 34 && V==13 || H == 38 && V==13)

       if(SWITCHPLACE[H][V] !=true && BOOLSWITCH[x][y]!=false)
       {

            CHECK();

            SYGLE[x][y]=’O’;
            gotoxy(H,V);
            printf(“%c”,SYGLE[x][y]);
            gotoxy(H,V);

            SWITCHPLACE[H][V] = true;
            BOOLSWITCH[x][y] =false;

            goto end;
        }
  }

 end: ;
}                                                                                                 /// End basic part

 void PlayerT()
 {

     if(x==3)
     {
      x=x-1;
      goto inner;
     }

      else
      setcolor(4);
      SYGLE[x][y]=’X’;
      SWITCHPLACE[H][V]=true;
      printf(“%c”,SYGLE[x][y]);
      BOOLSWITCH[x][y]=false;
      gotoxy(H,V);
      count_P++;

 inner: ;
 }

static void todown()
{

if(y==2)
goto inner;

for(y;y<3;y++)
{

             if(BOOLSWITCH[x][y] == false && BOOLSWITCH[x][y+1] == true )
             {

                SYGLE[x][y+1]=’ ‘;
                gotoxy(H,V+4);
                printf(“%c”,SYGLE[x][y+1]);
                gotoxy(H,V+4);
                y=y++;
                V=V+4;

                break;

             }

             if(BOOLSWITCH[x][y] == true && BOOLSWITCH[x][y+1] == false )
             {

                SYGLE[x][y]=’-‘;
                printf(“%c”,SYGLE[x][y]);
                gotoxy(H,V+4);
                y=y++;
                V=V+4;

                break;

             }

             if(BOOLSWITCH[x][y]==false && BOOLSWITCH[x][y+1]== false)
             {

                gotoxy(H,V+4);
                y=y++;
                V=V+4;

                break;

             }

        if(SYGLE[x][2]!=’ ‘)                 /// BEGINING DIRECTION
        {

             swap(&SYGLE[x][y],&SYGLE[x][y+1]);
             gotoxy(H,V);
             printf(“%c”,SYGLE[x][y]);
             gotoxy(H,V+4);
             printf(“%c”,SYGLE[x][y+1]);
             gotoxy(H,V+4);
             V=V+4;
             y=y++;
             break;
        }

}

inner: ;
}

static void toup()
{

if(y==0)
goto inner;

 for(y;y>=0;y–)
{
             if(BOOLSWITCH[x][y] == false && BOOLSWITCH[x][y-1] == true )
             {

                SYGLE[x][y-1]=’ ‘;
                gotoxy(H,V-4);
                printf(“%c”,SYGLE[x][y-1]);
                gotoxy(H,V-4);
                y=y–;
                V=V-4;

                break;

             }

             if(BOOLSWITCH[x][y] == true && BOOLSWITCH[x][y-1] == false )
             {

                SYGLE[x][y]=’-‘;
                printf(“%c”,SYGLE[x][y]);
                gotoxy(H,V-4);
                y=y–;
                V=V-4;

                break;

             }

             if(BOOLSWITCH[x][y]==false && BOOLSWITCH[x][y-1]== false)
             {

                gotoxy(H,V-4);
                y=y–;
                V=V-4;

                break;

             }

            if(SYGLE[x][0]!=’ ‘)
            {

             swap(&SYGLE[x][y],&SYGLE[x][y-1]);
             gotoxy(H,V);
             printf(“%c”,SYGLE[x][y]);
             gotoxy(H,V-4);
             printf(“%c”,SYGLE[x][y-1]);
             gotoxy(H,V-4);
             V=V-4;
             y=y–;
             break;

            }
}

inner: ;
}

static void toleft()
{
if(x==0)
goto inner;

for(x;x>=0;x–)
{

           if(BOOLSWITCH[x][y] == false && BOOLSWITCH[x-1][y] == true )
             {

                SYGLE[x-1][y]=’ ‘;
                gotoxy(H-4,V);
                printf(“%c”,SYGLE[x-1][y]);
                gotoxy(H-4,V);
                x=x–;
                H=H-4;

                break;

             }

             if(BOOLSWITCH[x][y] == true && BOOLSWITCH[x-1][y] == false )
             {

                SYGLE[x][y]=’-‘;
                printf(“%c”,SYGLE[x][y]);
                gotoxy(H-4,V);
                x=x–;
                H=H-4;

                break;

             }

             if(BOOLSWITCH[x][y]==false && BOOLSWITCH[x-1][y]== false)
             {

                gotoxy(H-4,V);
                x=x–;
                H=H-4;

                break;

             }

            if(SYGLE[0][y]!=’ ‘)
            {

             swap(&SYGLE[x][y],&SYGLE[x-1][y]);
             gotoxy(H,V);
             printf(“%c”,SYGLE[x][y]);
             gotoxy(H-4,V);
             printf(“%c”,SYGLE[x-1][y]);
             gotoxy(H-4,V);
             H=H-4;
             x=x–;
             break;

           }
}

inner: ;
}

static void toright()
{

if(x==2)
goto inner;

for(x;x<3;x++)
{

            if(BOOLSWITCH[x][y] == false && BOOLSWITCH[x+1][y] == true )
             {

                SYGLE[x+1][y]=’ ‘;
                gotoxy(H+4,V);
                printf(“%c”,SYGLE[x+1][y]);
                gotoxy(H+4,V);
                x=x++;
                H=H+4;

                break;

             }

             if(BOOLSWITCH[x][y] == true && BOOLSWITCH[x+1][y] == false )
             {

                SYGLE[x][y]=’-‘;
                printf(“%c”,SYGLE[x][y]);
                gotoxy(H+4,V);
                x=x++;
                H=H+4;

                break;

             }

             if(BOOLSWITCH[x][y]==false && BOOLSWITCH[x+1][y]== false)
             {

                gotoxy(H+4,V);
                x=x++;
                H=H+4;

                break;

             }

             if(SYGLE[2][y]!=’ ‘)                                         /// CURSOR FIRST.
             {
                swap(&SYGLE[x][y],&SYGLE[x+1][y]);
                gotoxy(H,V);
                 printf(“%c”,SYGLE[x][y]);
                gotoxy(H+4,V);
                printf(“%c”,SYGLE[x+1][y]);
                gotoxy(H+4,V);
                H=H+4;
                x=x++;
                break;
             }
}

inner: ;
}

main()
{
    draw();

    gotoxy(0,23);
    printf(“USE: NUMPAD 4,6,8,2 ASE ARROWS.nUSE: CAPITAL ‘x’ AS SYMBOL.”);
    gotoxy(31,0);
    printf(“WELCOME!.”);
    gotoxy(60,23);
    printf(“PLAYER SCORE : %d”,score_P);
    gotoxy(60,24);
    printf(“IA SCORE : %d”,score_IA);

startgame: ;

    if(tempo==’r’)
    {
    compteur++;
    reboot();
    gotoxied();
    }

    if(compteur %2!= 0)
    goto IA_TURN;

    gotoxied();

while(1)
{

        tempo=0;
        tempo = _getch();

        if(tempo == 54)                               // Cases.
        toright();

        if(tempo == 52)
        toleft();

        if(tempo == 50)
        todown();

        if(tempo == 56)
        toup();

          if(tempo==’X’)                                  // IA Case.
          {

             if(BOOLSWITCH[x][y]==false)
             goto ClearZone;
             PlayerT();

             if(SYGLE[0][0]==’X’ && SYGLE[1][0]==’X’ && SYGLE[2][0]==’X’ || SYGLE[0][1]==’X’ && SYGLE[1][1]==’X’ && SYGLE[2][1]==’X’ || SYGLE[0][2]==’X’ && SYGLE[1][2]==’X’ && SYGLE[2][2]==’X’ || SYGLE[0][0]==’X’ && SYGLE[0][1]==’X’ && SYGLE[0][2]==’X’ || SYGLE[1][0]==’X’ && SYGLE[1][1]==’X’ && SYGLE[1][2]==’X’ || SYGLE[2][0]==’X’ && SYGLE[2][1]==’X’ && SYGLE[2][2]==’X’ || SYGLE[2][0]==’X’ && SYGLE[1][1]==’X’ && SYGLE[0][2]==’X’ || SYGLE[0][0]==’X’ && SYGLE[1][1]==’X’ && SYGLE[2][2]==’X’ )
             {
               setcolor(4);
               gotoxy(50,9);
               printf(“Player WIN.”);
               score_P++;
               Sleep(2000);
               gotoxy(50,9);
               printf(”                  “);
               goto endgame;
             }

              if( BOOLSWITCH[0][0]==false && BOOLSWITCH[1][0]==false && BOOLSWITCH[2][0]==false && BOOLSWITCH[0][1]==false && BOOLSWITCH[1][1]==false && BOOLSWITCH[2][1]==false && BOOLSWITCH[0][2]==false && BOOLSWITCH[1][2]==false && BOOLSWITCH[2][2]==false )
             {
                setcolor(7);
                gotoxy(50,9);
                printf(“DRAW GAME!”);
                Sleep(1000);
                gotoxy(50,9);
                printf(”             “);
                goto endgame;
             }
             Sleep(1000);
             IA_TURN: ;
             IA();

              if(SYGLE[0][0]==’O’ && SYGLE[1][0]==’O’ && SYGLE[2][0]==’O’ || SYGLE[0][1]==’O’ && SYGLE[1][1]==’O’ && SYGLE[2][1]==’O’ || SYGLE[0][2]==’O’ && SYGLE[1][2]==’O’ && SYGLE[2][2]==’O’ || SYGLE[0][0]==’O’ && SYGLE[0][1]==’O’ && SYGLE[0][2]==’O’ || SYGLE[1][0]==’O’ && SYGLE[1][1]==’O’ && SYGLE[1][2]==’O’ || SYGLE[2][0]==’O’ && SYGLE[2][1]==’O’ && SYGLE[2][2]==’O’ || SYGLE[2][0]==’O’ && SYGLE[1][1]==’O’ && SYGLE[0][2]==’O’ || SYGLE[0][0]==’O’ && SYGLE[1][1]==’O’ && SYGLE[2][2]==’O’ )
             {
               setcolor(1);
               gotoxy(50,9);
               printf(“IA SCORES !”);
               score_IA++;
               Sleep(2000);
               gotoxy(50,9);
               printf(”             “);
               goto endgame;
             }

              if( BOOLSWITCH[0][0]==false && BOOLSWITCH[1][0]==false && BOOLSWITCH[2][0]==false && BOOLSWITCH[0][1]==false && BOOLSWITCH[1][1]==false && BOOLSWITCH[2][1]==false && BOOLSWITCH[0][2]==false && BOOLSWITCH[1][2]==false && BOOLSWITCH[2][2]==false )
             {
                setcolor(7);
                gotoxy(50,9);
                printf(“DRAW GAME!”);
                Sleep(1000);
                gotoxy(50,9);
                printf(”             “);
                goto endgame;
             }

             ClearZone:;
          }

}

endgame:;

gotoxy(60,23);
printf(“PLAYER SCORE : %d”,score_P);
gotoxy(60,24);
printf(“IA SCORE : %d”,score_IA);

setcolor(7);
gotoxy(0,0);
printf(“PRESS: r TO REMATCH.nPRESS: q TO QUIT.”);

while(1)
{
    tempo=_getch();
    if(tempo ==’r’)
    goto startgame;

    if(tempo == ‘q’)
    goto exit;
}
exit:;
}
