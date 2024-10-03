#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void main()
{
int a[100][100];

  
  int i, j, k, l = 99;
  int gd=DETECT,gm;
  
  initgraph(&gd,&gm,"c:\\tc\\bgi");


  //letter X
  for (k = 0; k < 100; k++)
  {
      for (l = 0; l < 100; l++)
      {
          if (k == l)
          {
              a[k][l] = 1;
          }
          else
          {
              a[k][l] = 0;
          }
      }
  }
  
  for (k = 0; k < 100; k++)
  {
    a[k][l] = 1;
    l--;
  }
  
  
  for(i=0;i<100;i++)
  {
    for(j=0;j<100;j++)
    {
      putpixel(200+i,200+j,10*a[i][j]);
    }
  }
  getch();
  closegraph();
}
  
