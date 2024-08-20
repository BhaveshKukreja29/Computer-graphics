#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
	int gd=DETECT, gm;
	int r, x, y, d, k;
	clrscr();

	initgraph(&gd, &gm, "C://TURBOC3//BGI");

	printf("Enter the radius: ");
	scanf("%d", &k);

	r = 250; //to align the circle

	x = 0;
	y = k;
	d = 1 - k;

	putpixel(x + r, y + r, RED);
	putpixel(x + r, -y + r, RED);
	putpixel(-x + r, y + r, RED);
	putpixel(-x + r, -y + r, RED);
	putpixel(y + r, x + r, RED);
	putpixel(y + r, -x + r, RED);
	putpixel(-y + r, x + r, RED);
	putpixel(-y + r, -x + r, RED);

	while (x < y)
	{
		if (d < 0)
		{
			d = d + 2*x + 3;
		}
		else
		{
			d = d + 2*x - 2*y + 5;
			y -= 1;
		}
		x += 1;
		putpixel(x + r, y + r, RED);
		putpixel(x + r, -y + r, RED);
		putpixel(-x + r, y + r, RED);
		putpixel(-x + r, -y + r, RED);
		putpixel(y + r, x + r, RED);
		putpixel(y + r, -x + r, RED);
		putpixel(-y + r, x + r, RED);
		putpixel(-y + r, -x + r, RED);

		delay(10);
	}

	getch();
	closegraph();


	getch();
	return 0;
}
