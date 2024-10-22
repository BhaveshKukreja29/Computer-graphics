#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawAnt(int x, int y, int phase)
{
    // Body
    ellipse(x, y, 0, 360, 20, 12);
    
    // Head
    circle(x+25, y, 8);
    
    // Eyes
    putpixel(x+28, y-3, WHITE);
    putpixel(x+28, y+3, WHITE);
    
    // Legs - animated
    int legOffset = sin(phase * 3.14159/180) * 5;
    
    // Left legs
    line(x-10, y, x-20, y-15-legOffset);
    line(x, y, x-10, y-15+legOffset);
    line(x+10, y, x, y-15-legOffset);
    
    // Right legs
    line(x-10, y, x-20, y+15+legOffset);
    line(x, y, x-10, y+15-legOffset);
    line(x+10, y, x, y+15+legOffset);
    
    // Antennae
    line(x+25, y, x+35, y-10);
    line(x+25, y, x+35, y+10);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int x = 0, phase = 0;
    
    while(!kbhit())
    {
        cleardevice();
        drawAnt(x, 240, phase);
        
        x = (x + 2) % 640;
        phase = (phase + 10) % 360;
        
        delay(50);
    }
    
    getch();
    closegraph();
    return 0;
}