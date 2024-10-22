#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
void rotation(int arr[8], int midx, int midy, int deg, int color)
{
    int result[8];
    double c = cos(deg * 3.14 / 180);
    double s = sin(deg * 3.14 / 180);

    result[0] = floor(arr[0] * c - arr[1] * s + midx * (1 - c) + midy * s);
    result[1] = floor(arr[0] * s + arr[1] * c + midy * (1 - c) - midx * s);
    result[2] = floor(arr[2] * c - arr[3] * s + midx * (1 - c) + midy * s);
    result[3] = floor(arr[2] * s + arr[3] * c + midy * (1 - c) - midx * s);
    result[4] = floor(arr[4] * c - arr[5] * s + midx * (1 - c) + midy * s);
    result[5] = floor(arr[4] * s + arr[5] * c + midy * (1 - c) - midx * s);
    result[6] = result[0];
    result[7] = result[1];
    setcolor(color);
    drawpoly(4, result);
    // setcolor(14);
}
int main()
{
    int gd = DETECT, gm, i = 10, j, k;
    double dx, dy;
    int arr[] = {290, 370, 350, 370, 320, 440, 290, 370};

    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    setcolor(YELLOW);
    circle(320, 240, 100);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(320, 240, YELLOW);
    for (i = 0; i <= 360; i += 5)
    {
        for (j = 0; j <= 360; j += 45)
        {
            rotation(arr, 320, 240, j + i, 14);
        }

        delay(50);
        for (j = 0; j <= 360; j += 45)
        {
            rotation(arr, 320, 240, j + i, 0);
        }
    }

    closegraph();

    return 0;
}