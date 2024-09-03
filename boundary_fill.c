#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void boundary(int x, int y, int fill, int bound);

int main()
{
	int gd=DETECT, gm, x = 110, y = 110, fill = 5, bound = 15;

	clrscr();

	initgraph(&gd, &gm , "C:\\TURBOC3\\BGI");
	rectangle(100,100,120,120);

	boundary(x,y,fill,bound);


	getch();
	closegraph();
	getch();

	return 0;
}

void boundary(int x, int y, int fill, int bound)
{
	if (getpixel(x,y) != fill && getpixel(x,y) != bound)
	{
		putpixel(x, y, fill);
		boundary(x + 1, y, fill, bound);
		boundary(x - 1, y, fill, bound);
		boundary(x, y + 1, fill, bound);
		boundary(x, y - 1, fill, bound);
	}
}
