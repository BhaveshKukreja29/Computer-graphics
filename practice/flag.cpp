#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

void drawAshokChakra(int x, int y) {
    setcolor(BLUE);
    circle(x, y, 20);
    for(int i = 0; i < 24; i++) {
        float angle = i * 15 * 3.14159 / 180;
        line(x, y, x + cos(angle)*20, y + sin(angle)*20);
    }
}

void drawFlag(int x, int y, int wavePhase) {
    // Flag pole
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(x-5, y, x+5, y+300);
    floodfill(x, y+150, BROWN);
    
    // Calculate wave effect for each stripe
    for(int i = 0; i < 150; i += 10) {
        int wave = sin((i + wavePhase) * 3.14159/180) * 5;
        
        // Saffron stripe
        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        int saffronPoints[] = {
            x+i, y+wave,
            x+i+10, y+wave,
            x+i+10, y+30+wave,
            x+i, y+30+wave
        };
        fillpoly(4, saffronPoints);
        
        // White stripe
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        int whitePoints[] = {
            x+i, y+30+wave,
            x+i+10, y+30+wave,
            x+i+10, y+60+wave,
            x+i, y+60+wave
        };
        fillpoly(4, whitePoints);
        
        // Green stripe
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        int greenPoints[] = {
            x+i, y+60+wave,
            x+i+10, y+60+wave,
            x+i+10, y+90+wave,
            x+i, y+90+wave
        };
        fillpoly(4, greenPoints);
    }
    
    // Ashok Chakra
    drawAshokChakra(x+75, y+45);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int phase = 0;
    
    while(!kbhit()) {
        cleardevice();
        drawFlag(100, 50, phase);
        phase = (phase + 5) % 360;
        delay(200);
    }
    
    getch();
    closegraph();
    return 0;
}