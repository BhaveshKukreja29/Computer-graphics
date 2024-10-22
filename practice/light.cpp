#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawLight(int c)
{
    int x, y;

    x = getmaxx() / 2;
    y = getmaxy() / 2;

    rectangle(x - 40, y - 110, x + 40, y + 110);

    circle(x, y - 70, 30);
    circle(x, y, 30);
    circle(x, y + 70, 30);

    switch(c)
    {
        case 0:
            setfillstyle(SOLID_FILL, RED);
            floodfill(x, y - 70, WHITE);
            break;
        case 1:
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(x, y, WHITE);
            break;
        case 2:
            setfillstyle(SOLID_FILL, GREEN);
            floodfill(x, y + 70, WHITE);
            break;
    }
}

int main()
{
    int x, y;
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while(!kbhit())
    {
        cleardevice();
        drawLight(0);
        delay(1000);

        cleardevice();
        drawLight(1);
        delay(1000);

        cleardevice();
        drawLight(2);
        delay(1000);
    }
}