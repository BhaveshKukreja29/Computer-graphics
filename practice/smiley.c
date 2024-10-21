#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

int main()
{
    int gr=DETECT, gm;
    int check = 0;
    int i = 1;
    int count = 0;
    int eye_height = 0;

    initgraph(&gr, &gm, "C:\\TURBOC3\\BGI");

	while(count < 4)
    {
        cleardevice();
        setcolor(YELLOW);
        circle(300, 100, 40);  
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(300, 100, YELLOW);

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);

        ellipse(290, 85, 0, 360, 5, eye_height);  
        ellipse(310, 85, 0, 360, 5, eye_height); 

        ellipse(300, 110, 270-i, 270+i, 20, 10);  

		eye_height = i / 9;
        if (i == 0) check = 0;
        else if (i >= 60)
        {
            check = 1;
            count++;
        }

        if (check == 0) i++;
        else i--;

        delay(40); 
    }

    closegraph();
    return 0;
}
