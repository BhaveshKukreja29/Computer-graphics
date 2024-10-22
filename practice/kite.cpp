#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void drawKite(int x, int y, int size)
{
    // Main diamond
    line(x, y-size, x+size / 2, y);
    line(x+size / 2, y, x, y+size);
    line(x, y+size, x-size / 2, y);
    line(x-size / 2, y, x, y-size);
    
    // Cross lines
    line(x-size / 2, y, x+size / 2, y);
    line(x, y-size, x, y+size);
    
    // Tail
    arc(x, y, 0, 180, size / 4); //inner arc
    arc(x, y + size, 90, 180, 40); //first half of string
    arc(x - 80, y + size, 270, 360, 40); //second half of string
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int x = 100, y = 100;
    int dx = 2, dy = 1;
    
    while(!kbhit())
    {
        cleardevice();
        drawKite(x, y, 40);
        
        x += dx;
        y += dy;
        
        // Bounce off screen edges
        if(x <= 50 || x >= getmaxx()-50) dx = -dx;
        if(y <= 50 || y >= getmaxy()-50) dy = -dy;
        
        delay(50);
    }
    
    getch();
    closegraph();
    return 0;
}