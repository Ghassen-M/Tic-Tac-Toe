#include <stdio.h>
#include <math.h>

char C;
char T[3][3];
char P='2';
int B=0;
void empty()  /*Place holders for the boxes*/
{
  for (int l=0 ; l<3;l++)
   {
    for (int c=0; c<3; c++)
    {T[l][c]='.';
  }
    printf("\n");
  }
}

void turn1()
{
  printf("It\'s 1\'st turn! Type either X or O :D \n", P);
  do    /*Get X or O*/
  {
    scanf("%c",&C);
  } while ((C!='O') && (C!='X'));
}

void game()
{
  while (B<9)
 {
   if (P=='2') {P='1';} /*Switching between both players*/
   else  {P='2';}

 int i,j;
 printf("Interesting Roll...Where are you going to put it ? Type line number then column's ;) \n");
 do      /*Get the coordinates*/
 {
   scanf("%d\n",&i);
   i-=1;
   scanf("%d",&j);
   j-=1;
   if ((((i>2) ||	 (i<0)) ||	 ((j>2) ||	 (j<0))) ||	 (T[i][j]=='X') ||	 (T[i][j]=='O'))
   {printf("WHERE DO YOU THINK I WILL PUT THAT!! euh try again..");}
 } while ((((i>2) ||	 (i<0)) ||	 ((j>2) ||	 (j<0))) ||	 (T[i][j]=='X') ||	 (T[i][j]=='O'));
 printf("\n");
 T[i][j]=C; /*Assign X or O in the coordinates*/
 for (int l=0 ; l<3;l++)
  {
   for (int c=0; c<3; c++)
   {printf("%c   ",T[l][c]);
 }
   printf("\n");
 }
 printf("\n");
 B+=1; /*Filled Boxes counter*/

 if (C=='O') {C='X';} /*choosing other dude's place*/
 else {C='O';}
 }
}

void result()
{
  if (((T[1][1]==T[2][2]) && (T[2][2]==T[3][3]) )|| ((T[1][1]==T[1][2]) && (T[1][2]==T[1][3]) ) || ((T[2][1]==T[2][2]) && (T[2][2]==T[2][3]) ) || ((T[3][1]==T[2][2]) && (T[3][2]==T[3][3]) ) || ((T[1][1]==T[2][1]) && (T[2][1]==T[3][1]) ) || ((T[1][2]==T[2][2]) && (T[2][2]==T[3][2]) ) || ((T[1][3]==T[2][3]) && (T[2][3]==T[3][3]) ) || ((T[1][3]==T[2][2]) && (T[2][2]==T[3][1])))
  {printf("Congrats %c ! You are the winner :D", P);}
  else {printf("DRAW");}
