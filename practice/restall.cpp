// 1. Olympic Rings Logo
#include <graphics.h>
#include <conio.h>

void drawOlympicLogo() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    // Blue Ring
    setcolor(BLUE);
    circle(100, 100, 30);
    
    // Black Ring
    setcolor(BLACK);
    circle(170, 100, 30);
    
    // Red Ring
    setcolor(RED);
    circle(240, 100, 30);
    
    // Yellow Ring
    setcolor(YELLOW);
    circle(135, 130, 30);
    
    // Green Ring
    setcolor(GREEN);
    circle(205, 130, 30);
    
    getch();
    closegraph();
}

// 2. Rainbow using Midpoint Circle
void drawRainbow() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    int colors[] = {RED, LIGHTRED, YELLOW, GREEN, BLUE, MAGENTA};
    int x = getmaxx()/2;
    int y = getmaxy()-50;
    int radius = 200;
    
    for(int i = 0; i < 6; i++) {
        setcolor(colors[i]);
        arc(x, y, 0, 180, radius - (i * 20));
    }
    
    // Ground
    setcolor(GREEN);
    line(0, getmaxy()-50, getmaxx(), getmaxy()-50);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(10, getmaxy()-40, GREEN);
    
    getch();
    closegraph();
}

// 3. Cricket Ground using Midpoint Circle
void drawCricketGround() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    // Main ground
    setcolor(GREEN);
    circle(300, 200, 150);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(300, 200, GREEN);
    
    // Inner circles
    setcolor(WHITE);
    circle(300, 200, 100);
    circle(300, 200, 50);
    
    // Pitch
    setcolor(BROWN);
    rectangle(280, 150, 320, 250);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(300, 200, BROWN);
    
    getch();
    closegraph();
}

// 4. Moving Cycle Animation
void drawMovingCycle() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    for(int i = 0; i <= getmaxx(); i += 5) {
        cleardevice();
        
        // Ground line
        line(0, getmaxy()-50, getmaxx(), getmaxy()-50);
        
        // Wheels
        circle(50+i, getmaxy()-70, 20);
        circle(100+i, getmaxy()-70, 20);
        
        // Frame
        line(50+i, getmaxy()-70, 75+i, getmaxy()-100);
        line(75+i, getmaxy()-100, 100+i, getmaxy()-70);
        line(75+i, getmaxy()-100, 60+i, getmaxy()-90);
        
        // Handle
        line(75+i, getmaxy()-100, 80+i, getmaxy()-110);
        
        delay(50);
    }
    
    getch();
    closegraph();
}

// 5. Rotating 3D Object (45 degrees)
void drawRotatingObject() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    // Draw hexagonal prism
    int points[] = {
        200, 100,  // top-left
        250, 100,  // top-right
        270, 150,  // middle-right
        250, 200,  // bottom-right
        200, 200,  // bottom-left
        180, 150   // middle-left
    };
    
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, RED);
    
    // Draw front face
    drawpoly(6, points);
    floodfill(210, 150, YELLOW);
    
    // Draw depth lines for 3D effect
    for(int i = 0; i < 6; i++) {
        line(points[i*2], points[i*2+1], 
            points[i*2]+20, points[i*2+1]-20);
    }
    
    getch();
    closegraph();
}

// Main function to test all implementations
int main() {
    drawOlympicLogo();  // Test each function individually
    drawRainbow();
    drawCricketGround();
    drawMovingCycle();
    drawRotatingObject();
    return 0;
}