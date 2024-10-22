#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>

void boat(int x, int y)
{
    //boat
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    line(x, y, x + 120, y);
    line(x, y, x + 30, y + 30);
    line(x + 30, y + 30, x + 90, y + 30);
    line(x + 90, y + 30, x + 120, y);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 10, y + 10, WHITE);

    setcolor(WHITE);

    //triangle at top
    line(x + 40, y, x + 50, y - 30);
    line(x + 50, y - 30, x + 60, y);

    //water below
    setcolor(BLUE);
    setlinestyle(DASHED_LINE, 0, NORM_WIDTH);
    line(0, y + 35, getmaxx() - 10, y + 35);
    line(0, y + 40, getmaxx() - 10, y + 40);
    line(0, y + 45, getmaxx() - 10, y + 45);
    line(0, y + 50, getmaxx() - 10, y + 50);
}

int main()
{
    int x,y;
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x = 100;
    y = 250;
    while (x < getmaxx() - 10)
    {
        cleardevice();
        boat(x, y);
        x++;
        delay(2);
    }
}