#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int xmin, ymin, xmax, ymax;
    int i;
    float m;
    // Store original coordinates for drawing
    int orig_x1, orig_y1, orig_x2, orig_y2;

    // Arrays to store region codes
    int op1[4] = {0}, op2[4] = {0};

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter Xmin, Ymin, Xmax, Ymax: \n");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    // Store original coordinates
    orig_x1 = x1;
    orig_y1 = y1;
    orig_x2 = x2;
    orig_y2 = y2;

    // Draw the clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line in RED
    setcolor(RED);
    line(orig_x1, orig_y1, orig_x2, orig_y2);

    // Calculate slope
    m = (float)(y2 - y1) / (x2 - x1);

    // Generate region codes for first point
    if (y1 > ymax) op1[0] = 1; else op1[0] = 0;
    if (y1 < ymin) op1[1] = 1; else op1[1] = 0;
    if (x1 > xmax) op1[2] = 1; else op1[2] = 0;
    if (x1 < xmin) op1[3] = 1; else op1[3] = 0;

    // Generate region codes for second point
    if (y2 > ymax) op2[0] = 1; else op2[0] = 0;
    if (y2 < ymin) op2[1] = 1; else op2[1] = 0;
    if (x2 > xmax) op2[2] = 1; else op2[2] = 0;
    if (x2 < xmin) op2[3] = 1; else op2[3] = 0;

    // Check if line is completely inside
    for (i = 0; i < 4; i++)
    {
        if (op1[i] | op2[i] != 0) break;
        if (i == 3)
        {
            setcolor(GREEN);
            line(x1, y1, x2, y2);
            outtextxy(10, 10, "Line completely inside - No clipping needed");
            getch();
            closegraph();
            return 0;
        }
    }

    // Check if line is completely outside
    for (i = 0; i < 4; i++)
    {
        if (op1[i] & op2[i] != 0)
        {
            outtextxy(10, 10, "Line completely outside - Not visible");
            getch();
            closegraph();
            return 0;
        }
    }

    // Line needs clipping
    // Clip against left edge
    if (x1 < xmin)
    {
        y1 = y1 + m * (xmin - x1);
        x1 = xmin;
    }
    if (x2 < xmin)
    {
        y2 = y2 + m * (xmin - x2);
        x2 = xmin;
    }

    // Clip against right edge
    if (x1 > xmax)
    {
        y1 = y1 + m * (xmax - x1);
        x1 = xmax;
    }
    if (x2 > xmax)
    {
        y2 = y2 + m * (xmax - x2);
        x2 = xmax;
    }

    // Recalculate slope after x-clipping
    m = (float)(y2 - y1) / (x2 - x1);

    // Clip against bottom edge
    if (y1 > ymax)
    {
        x1 = x1 + (ymax - y1) / m;
        y1 = ymax;
    }
    if (y2 > ymax)
    {
        x2 = x2 + (ymax - y2) / m;
        y2 = ymax;
    }

    // Clip against top edge
    if (y1 < ymin)
    {
        x1 = x1 + (ymin - y1) / m;
        y1 = ymin;
    }
    if (y2 < ymin)
    {
        x2 = x2 + (ymin - y2) / m;
        y2 = ymin;
    }

    // Draw the clipped line in GREEN
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    
    // Add legend
    setcolor(WHITE);
    outtextxy(10, 10, "RED: Original Line");
    outtextxy(10, 25, "GREEN: Clipped Line");
    outtextxy(10, 40, "WHITE: Clipping Window");

    getch();
    closegraph();
    return 0;
}