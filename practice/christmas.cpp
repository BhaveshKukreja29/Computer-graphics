#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawStar(int x, int y, int brightness)
{
    setcolor(brightness);
    line(x-5, y, x+5, y);
    line(x, y-5, x, y+5);
    line(x-3, y-3, x+3, y+3);
    line(x-3, y+3, x+3, y-3);
}

void drawTree(int x, int y)
{
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    
    // Draw three triangles for tree
    int points[] = {x, y-80, x-40, y, x+40, y, x, y-80};
    fillpoly(4, points);
    
    int points2[] = {x, y-40, x-30, y+30, x+30, y+30, x, y-40};
    fillpoly(4, points2);
    
    int points3[] = {x, y, x-20, y+60, x+20, y+60, x, y};
    fillpoly(4, points3);
    
    // Draw trunk
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(x-10, y+60, x+10, y+80);
    floodfill(x, y+70, BROWN);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int starBrightness[] = {15, 15, 15};  // Start all stars bright
    int starPhase[] = {0, 120, 240};      // Different phases for each star
    
    while(!kbhit())
    {
        cleardevice();
        
        // Draw and animate stars
        for(int i = 0; i < 3; i++) {
            starPhase[i] = (starPhase[i] + 10) % 360;
            starBrightness[i] = 8 + abs(sin(starPhase[i] * 3.14159/180) * 7);
            drawStar(200 + i*100, 100, starBrightness[i]);
        }
        
        // Draw static tree
        drawTree(320, 240);
        
        delay(50);
    }
    
    getch();
    closegraph();
    return 0;
}