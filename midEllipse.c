#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	int gm, gd=DETECT;
	int a, b, xc, yc, xo, yo;
	int po;
	clrscr();

	printf("Enter a and b value of the ellipse: ");
	scanf("%d %d", &a, &b);

	printf("Enter the coordinates of the ellipse: \n");
	scanf("%d %d",&xc, &yc);

	initgraph(&gd, &gm, "C://TURBOC3//BGI");

	xo = 0;
	yo = b;

	po = (b * b) - (a * a * b) + ((a * a) * 0.25);

	putpixel(xc + xo, yc + yo, WHITE);
	putpixel(xc + xo, yc - yo, WHITE);
	putpixel(xc - xo, yc + yo, WHITE);
	putpixel(xc - xo, yc - yo, WHITE);


	while((a * a)*(yo - 0.5) > (b * b)*(xo + 1))
	{
		if(po < 0)
		{
			po = po + (b * b) * (2 * xo + 3);
			xo = xo + 1;
		}

		else
		{
			po = po + ((b * b) * (2 * xo + 3)) + ((a * a) * ((- 2) * yo + 2));
			yo = yo - 1;
			xo = xo + 1;
		}

		putpixel(xc + xo, yc + yo, WHITE);
		putpixel(xc + xo, yc - yo, WHITE);
		putpixel(xc - xo, yc + yo, WHITE);
		putpixel(xc - xo, yc - yo, WHITE);
	}

	//Region 2

	po = ((b * b) * (xo + 0.5)) - ((a * a)*(yo - 1)*(yo - 1)) - ((a * a) * b);

	while(yo > 0)
	{
		if(po < 0)
		{

			po = po + ((b * b) * (2 * xo + 2)) + ((a * a) * ((- 2) * yo + 3));
			xo = xo + 1;
			yo = yo - 1;
		}

		else
		{
			po = po + (b * b) * ((-2) * yo + 3);
			yo = yo - 1;
		}

		putpixel(xc + xo, yc + yo, WHITE);
		putpixel(xc + xo, yc - yo, WHITE);
		putpixel(xc - xo, yc + yo, WHITE);
		putpixel(xc - xo, yc - yo, WHITE);
	}


	getch();
	closegraph();

	return 0;
}
