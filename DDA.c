#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int sign(float n);

void main()
{
	int gd=DETECT, gm, i = 0, k;
	float x1,x2,y1,y2,dx,dy,xinc,yinc,x,y,l;

	clrscr();

	initgraph(&gd, &gm, "\\BGI");

	printf("Enter the x1,y1: ");
	scanf("%f %f", &x1, &y1);

	printf("Enter the x2,y2: ");
	scanf("%f %f", &x2, &y2);

	if (x1 == x2 && y1 == y2)
	{
		putpixel((int)x1,(int)y1,RED);
	}

	else
	{
		dx = x2 - x1;
		dy = y2 - y1;

		if (abs(dx) >= abs(dy))
		{
			l = abs(dy);

			xinc = dx / l;
			yinc = dy / l;

			x = x1 + 0.5*sign(xinc);
			y = y1 + 0.5*sign(yinc);

			while ( i < l)
			{
				putpixel((int)x, (int)y, RED);
				x = x + xinc;
				y = y + yinc;

				printf("X: %d Y: %d\n", (int)x, (int)y);

				i++;
			}
		}
		getch();
		closegraph();
	}



	getch();
}

int sign(float n)
{
	if (n < 0)
	{
		return -1;
	}

	else if (n > 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
