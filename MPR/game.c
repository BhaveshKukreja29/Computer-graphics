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
int eaccess = 0;

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
		bullets[i].y -= 10;
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
			eaccess = (eaccess + 1) % 5;
			continue;
        }
		enemy[i].y += 2;
	}

	for (i = 0; i < 4; i++)
	{
		if (enemy[eaccess + 1].active == 0 && enemy[eaccess].y != 0)
		{
			eaccess++;
			enemy[eaccess].active = 1;
			enemy[eaccess].y = 0;
			enemy[eaccess].x = rand() % getmaxx();
		}
	}
}

void drawspaceship(int x, int y)
{
	setcolor(WHITE);
	line(x - 10, y, x + 10, y);
	line(x - 10, y, x, y - 20);
	line(x + 10, y, x, y - 20);
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
