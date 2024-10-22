#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawFish(int x, int y, int tailPhase)
{
    // Body
    ellipse(x, y, 0, 360, 40, 20);
    
    // Tail - animated
    int tailOffset = sin(tailPhase * 3.14159/180) * 10;
    line(x-40, y, x-60+tailOffset, y-20);
    line(x-40, y, x-60+tailOffset, y+20);
    line(x-60+tailOffset, y-20, x-60+tailOffset, y+20);
    
    // Eye
    circle(x+20, y, 3);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x+20, y, WHITE);
    
    // Fins
    line(x-5, y-20, x+5, y-30);
    line(x-5, y-30, x+5, y-20);
    line(x-5, y+20, x+5, y+30);
    line(x-5, y+30, x+5, y+20);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int x = 320, y = 240;
    int phase = 0;
    int direction = 1;
    
    while(!kbhit())
    {
        cleardevice();
        drawFish(x, y, phase);
        
        x += direction * 2;
        if(x >= getmaxx()-100 || x <= 100)
            direction *= -1;
            
        phase = (phase + 10) % 360;
        delay(50);
    }
    
    getch();
    closegraph();
    return 0;
}