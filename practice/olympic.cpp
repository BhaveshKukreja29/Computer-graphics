#include <graphics.h>
#include <conio.h>

void drawOlympicLogo() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    setbkcolor(DARKGRAY);
    // Blue Ring
    setcolor(WHITE);
    circle(100, 100, 30);
    circle(100, 100, 40);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(100+35, 100, WHITE);
    
    // Black Ring
    setcolor(WHITE);
    circle(170, 100, 30);
    circle(170, 100, 40);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(170+35, 100, WHITE);
    
    // Red Ring
    setcolor(WHITE);
    circle(240, 100, 30);
    circle(240, 100, 40);
    setfillstyle(SOLID_FILL, RED);
    floodfill(240+35, 100, WHITE);
    
    // Yellow Ring
    setcolor(WHITE);
    circle(135, 130, 30);
    circle(135, 130, 40);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(135+35, 130, WHITE);

    // Green Ring
    setcolor(WHITE);
    circle(205, 130, 30);
    circle(205, 130, 40);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(205+35, 130, WHITE);

    getch();
    closegraph();
}

int main()
{
    drawOlympicLogo();
    return 0;
}