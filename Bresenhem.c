#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
	int gd = DETECT, gm, k;
	int x1, x2, y1, y2, dx, dy;
	int p;

	clrscr();

	initgraph(&gd, &gm, "C://TURBOC3//BGI");

	printf("Enter x1 and y1: ");
	scanf("%d %d", &x1, &y1);

	printf("Enter x2 and y2: ");
	scanf("%d %d", &x2, &y2);

	if (x1 == x2 && y1 == y2)
	{
		putpixel((int)x1, (int)x2, RED);
	}

	else
	{
		dx = (int)x2 - (int)x1;
		dy = (int)y2 - (int)y1;

		p = 2*dy - dx;

		for (k = 0; k < dx; k++)
		{
			if (p >= 0)
			{
				x1 = (int)x1 + 1;
				y1 = (int)y1 + 1;
				putpixel((int)x1, (int)y1, RED);

				p = p + 2 * (dy - dx);
				printf("%d %d", x1, y1);
			}

			else
			{
				x1 = (int)x1 + 1;
				putpixel((int)x1, (int)y1, RED);

				p = p + 2 * dy;
				printf("%d %d", x1, y1);
			}
		}
		getch();
		closegraph();
	}

	getch();
	return 0;
}
