#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

void main()
{
	int x[4], y[4], i;
	double putx, puty, t;
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "\\BGI");

	printf("Enter x and y values: \n");

	for (i = 0; i < 4; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		putpixel(x[i], y[i], WHITE);
	}

	for (t = 0.00; t <= 1.0; t += 0.001)
	{
		putx = pow(1 - t, 3)*x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * t * t * (1 - t) * x[2] + pow(t, 3) * x[3];
		puty = pow(1 - t, 3)*y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * t * t * (1 - t) * y[2] + pow(t, 3) * y[3];
		putpixel(putx, puty, WHITE);
	}

	getch();
	closegraph();
}
