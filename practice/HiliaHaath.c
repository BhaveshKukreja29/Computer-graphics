#include<stdio.h>
#include<graphics.h>

void main()
{
	int gd = DETECT, gm;
	int mid_x, mid_y, i = 0, flag, j = 0;

	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	mid_x = getmaxx() / 2;
	mid_y = getmaxy() / 2;

	while(!kbhit())
	{
		cleardevice();
		circle(mid_x, mid_y - 100, 35);
		ellipse(mid_x - 15, mid_y - 110, 0, 360, 3, 3);
		ellipse(mid_x + 15, mid_y - 110, 0, 360, 3, 3);
		ellipse(mid_x, mid_y - 90, 270 - j, 270 + j, 25, 15);
		line(mid_x, mid_y - 65, mid_x, mid_y + 75);
		line(mid_x, mid_y + 75, mid_x - 30, mid_y + 125);
		line(mid_x, mid_y + 75, mid_x + 30, mid_y + 125);
		line(mid_x, mid_y - 30, mid_x - 30, mid_y + 30);
		line(mid_x, mid_y - 30, mid_x + 30, mid_y);
		if(i == 15)
		{
			flag = 1;
		}
		else if(i == 0)
		{
			flag = 0;
		}
		line(mid_x + 30, mid_y, mid_x + 60 - i, mid_y - 30);
		if(flag == 1)
		{
			i--;
			j-=3;
		}
		else
		{
			i++;
			j+=3;
		}
		delay(50);
	}

	getch();
	closegraph();
