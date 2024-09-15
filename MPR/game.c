#include <graphics.h>
#include <conio.h>
#include <dos.h>

typedef struct
{
	int x, y;
	int active;
}Bullet, Enemy;

Bullet bullets[10];
int baccess = 0;

Enemy enemy[5];

int spaceshipX = 300;
int spaceshipY = 400;
void drawspaceship(int x, int y) ;
void handle();
void game();
void initbullet();
void updateWorld();
void moveenemy();
void movebullet();
void drawenemy();
void drawbullet();
void detect();

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	initbullet();
	game();
	closegraph();
	return 0;
}

void initbullet()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		bullets[i].active = 0;
	}

	for (i = 0; i < 5; i++)
	{
		enemy[i].active = 0;
	}
}

void game()
{
	while (1)
	{
		cleardevice();
		handle();
		updateWorld();
		delay(15);
	}
}

void handle()
{
	if (kbhit())
	{
		char ch = getch();

		if (ch == 0)
		{
			ch = getch();

			switch (ch)
			{
				case 0x4B:  //Left arrow
					spaceshipX -= 10;
					if (spaceshipX < 10) spaceshipX = 10;
					break;
				case 0x4D: //Right arrow
					spaceshipX += 10;
					if (spaceshipX > getmaxx() - 10)
					{
						spaceshipX = getmaxx() - 10;
					} 
					break;
				case 0x48: //top arrow button
					bullets[baccess].x = spaceshipX;
					bullets[baccess].y = spaceshipY - 20;
					bullets[baccess++].active = 1;
					baccess = (baccess + 1) % 10;
					break;
			}
		}
	}
}

void updateWorld()
{
	movebullet();
	moveenemy();
	drawspaceship(spaceshipX, spaceshipY);
	drawenemy();
	drawbullet();
	detect();
}

void movebullet()
{
	int i;
	for (i = 0; i < 10; i++)
	{
        if (bullets[i].y < 0)
        {
			bullets[i].active = 0;
			continue;
        }
		bullets[i].y -= 2;
	}
}

void moveenemy()
{
	int i;
	for (i = 0; i < 5; i++)
	{
        if (enemy[i].y >= getmaxy())
        {
			enemy[i].active = 0;
        }
		else if (enemy[i].active == 1)
		{
			enemy[i].y += 2;
		}
		
	}

	for (i = 0; i < 4; i++)
	{
		if (enemy[i + 1].active == 0 && enemy[i].y != 0)
		{
			i++;
			enemy[i].active = 1;
			enemy[i].y = 0;
			enemy[i].x = rand() % getmaxx();
		}
	}
}

void detect()
{
	int i, j;
	// if bullet, hits remove enemy and bullet
	for (i = 0; i < 10; i++)
	{
		if (bullets[i].active == 1)
		{
			for (j = 0; j < 5; j++)
			{
				if (bullets[i].x <= (enemy[j].x + 30) && bullets[i].x >= (enemy[j].x) && bullets[i].y <= (enemy[j].y + 30))
				{
					enemy[j].active = 0;
					bullets[i].active = 0;
				}
			}
		}
	}
	// if enemy reaches end game, end 
	//TODO
}

void drawspaceship(int x, int y)
{
		line(x, y - 5/2, x - 5/2, y - 5/2);
		line(x - 5/2, y - 5/2, x - 5/2, y - 20/2);
		line(x - 5/2, y - 20/2, x - 10/2, y - 20/2);
		line(x - 10/2, y - 20/2, x - 10/2, y - 15/2);
		line(x - 10/2, y - 15/2, x - 15/2, y - 15/2);
		line(x - 15/2, y - 15/2, x - 15/2, y - 10/2);
		line(x - 15/2, y - 10/2, x - 20/2, y - 10/2);
		line(x - 20/2, y - 10/2, x - 20/2, y - 5/2);
		line(x - 20/2, y - 5/2, x - 25/2, y - 5/2);
		line(x - 25/2, y - 5/2, x - 25/2, y);
		line(x - 25/2, y, x - 30/2, y);
		line(x - 30/2, y, x - 30/2, y - 30/2);
		line(x - 30/2, y - 30/2, x - 25/2, y - 30/2);
		line(x - 25/2, y - 30/2, x - 25/2, y - 10/2);
		line(x - 25/2, y - 10/2, x - 20/2, y - 10/2);
		line(x - 20/2, y - 10/2, x - 20/2, y - 20/2);
		line(x - 20/2, y - 20/2, x - 15/2, y - 20/2);
		line(x - 15/2, y - 20/2, x - 15/2, y - 30/2);
		line(x - 15/2, y - 30/2, x - 5/2, y - 30/2);
		line(x - 5/2, y - 30/2, x - 5/2, y - 55/2);
		line(x - 5/2, y - 55/2, x - 2/2, y - 55/2);
		line(x - 2/2, y - 55/2, x - 2/2, y - 70/2);
		line(x - 2/2, y - 70/2, x, y - 70/2);
		
		line(x, y - 5/2, x + 5/2, y - 5/2);
		line(x + 5/2, y - 5/2, x + 5/2, y - 20/2);
		line(x + 5/2, y - 20/2, x + 10/2, y - 20/2);
		line(x + 10/2, y - 20/2, x + 10/2, y - 15/2);
		line(x + 10/2, y - 15/2, x + 15/2, y - 15/2);
		line(x + 15/2, y - 15/2, x + 15/2, y - 10/2);
		line(x + 15/2, y - 10/2, x + 20/2, y - 10/2);
		line(x + 20/2, y - 10/2, x + 20/2, y - 5/2);
		line(x + 20/2, y - 5/2, x + 25/2, y - 5/2);
		line(x + 25/2, y - 5/2, x + 25/2, y);
		line(x + 25/2, y, x + 30/2, y);
		line(x + 30/2, y, x + 30/2, y - 30/2);
		line(x + 30/2, y - 30/2, x + 25/2, y - 30/2);
		line(x + 25/2, y - 30/2, x + 25/2, y - 10/2);
		line(x + 25/2, y - 10/2, x + 20/2, y - 10/2);
		line(x + 20/2, y - 10/2, x + 20/2, y - 20/2);
		line(x + 20/2, y - 20/2, x + 15/2, y - 20/2);
		line(x + 15/2, y - 20/2, x + 15/2, y - 30/2);
		line(x + 15/2, y - 30/2, x + 5/2, y - 30/2);
		line(x + 5/2, y - 30/2, x + 5/2, y - 55/2);
		line(x + 5/2, y - 55/2, x + 2/2, y - 55/2);
		line(x + 2/2, y - 55/2, x + 2/2, y - 70/2);
		line(x + 2/2, y - 70/2, x, y - 70/2);
}

void drawenemy()
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (enemy[i].active == 1)
		{
			setcolor(WHITE);
			rectangle(enemy[i].x, enemy[i].y, enemy[i].x + 30, enemy[i].y + 30);
		}
	}
}

void drawbullet()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (bullets[i].active == 1)
		{
			setcolor(WHITE);
			line(bullets[i].x, bullets[i].y, bullets[i].x, bullets[i].y - 10);
		}
	}
}
