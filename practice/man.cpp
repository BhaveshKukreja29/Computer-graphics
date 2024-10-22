#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawStickFigure(int x, int y, int phase)
{
    // Head
    circle(x, y, 20);
    
    // Body
    line(x, y+20, x, y+60);
    
    // Arms - animated
    int armY = y + 30;
    int armAngle = sin(phase * 3.14159/180) * 30;
    line(x, armY, x-20-armAngle, armY+20);
    line(x, armY, x+20+armAngle, armY+20);
    
    // Legs - animated
    int legX = sin(phase * 3.14159/180) * 20;
    line(x, y+60, x-20+legX, y+100);
    line(x, y+60, x+20-legX, y+100);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int phase = 0;
    int x = 320, y = 200;
    
    while(!kbhit())
    {
        cleardevice();
        drawStickFigure(x, y, phase);
        phase = (phase + 10) % 360;
        delay(50);
    }
    
    getch();
    closegraph();
    return 0;
}