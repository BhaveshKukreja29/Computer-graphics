#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float xmin, ymin, xmax, ymax;
    float dx, dy;
    float p[4], q[4], r[4];
    float u1 = 0, u2 = 1;
    float x_new1, y_new1, x_new2, y_new2;
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    // Input window coordinates
    printf("Enter window min point (xmin ymin): ");
    scanf("%f %f", &xmin, &ymin);
    printf("Enter window max point (xmax ymax): ");
    scanf("%f %f", &xmax, &ymax);
    
    // Input line coordinates
    printf("Enter line start point (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter line end point (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    
    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    
    // Draw original line in red
    setcolor(RED);
    line(x1, y1, x2, y2);
    
    // Calculate dx and dy
    dx = x2 - x1;
    dy = y2 - y1;
    
    // Calculate p values
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    
    // Calculate q values
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;
    
    // Calculate r values and update u1, u2
    for(int i = 0; i < 4; i++)
    {
        if(p[i] != 0)
        {
            r[i] = q[i] / p[i];
            
            if(p[i] < 0)
            {
                if(r[i] > u1)
                    u1 = r[i];
            }
            else
            {
                if(r[i] < u2)
                    u2 = r[i];
            }
        }
    }
    
    // Check if line is visible
    if(u1 < u2)
    {
        // Calculate new endpoints
        x_new1 = x1 + u1 * dx;
        y_new1 = y1 + u1 * dy;
        x_new2 = x1 + u2 * dx;
        y_new2 = y1 + u2 * dy;
        
        // Draw clipped line in green
        setcolor(GREEN);
        line(x_new1, y_new1, x_new2, y_new2);
        
        // Display coordinates
        char str[80];
        setcolor(YELLOW);
        sprintf(str, "Clipped: (%.1f,%.1f) to (%.1f,%.1f)", 
                x_new1, y_new1, x_new2, y_new2);
        outtextxy(10, 10, str);
    }
    else
    {
        setcolor(YELLOW);
        outtextxy(10, 10, "Line is outside the window");
    }
    
    // Add legend
    setcolor(WHITE);
    outtextxy(10, 30, "RED: Original Line");
    outtextxy(10, 45, "GREEN: Clipped Line");
    outtextxy(10, 60, "WHITE: Window");
    
    getch();
    closegraph();
    return 0;
}