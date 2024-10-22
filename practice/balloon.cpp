#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void drawBalloon(int x, int y, int color)
{
    // Draw balloon
    ellipse(x, y, 0, 360, 20, 30);
    //line(x, y+30, x, y+60);  // String
    arc(x + 50, y + 30, 180, 270, 50);
    
    // Fill balloon
    setfillstyle(SOLID_FILL, color);
    floodfill(x, y, getcolor());
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int y = 400;
    while(y > 0)
    {
        cleardevice();
        
        // Draw three balloons with different colors
        drawBalloon(150, y, LIGHTMAGENTA);
        drawBalloon(250, y-20, RED);
        drawBalloon(350, y-40, MAGENTA);
        
        delay(10);
        y -= 2;
    }
    
    getch();
    closegraph();
    return 0;
}