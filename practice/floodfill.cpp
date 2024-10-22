#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void flood(int x, int y, int fill, int interior);

int main()
{
	int gd=DETECT, gm, x = 125, y = 125, fill = 5, interior = 0;

	char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
	rectangle(100,100,150,150);

	flood(x,y,fill,interior);


	getch();
	closegraph();
	getch();

	return 0;
}

void flood(int x, int y, int fill, int interior)
{
	if (getpixel(x,y) == interior)
	{
		putpixel(x, y, fill);
		flood(x + 1, y, fill, interior);
		flood(x - 1, y, fill, interior);
		flood(x, y + 1, fill, interior);
		flood(x, y - 1, fill, interior);
	}
}