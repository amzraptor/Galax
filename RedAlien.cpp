#include "RedAlien.h"

RedAlien::RedAlien(int x_, int y_)
{	
	worth = 20;
	x = x_;
    y = y_;
    swaX = x_;
    swaY = y_;
    dx = 0;
    dy = 0;
    attackmode = false;
}

void RedAlien::drawOn(Surface & surface)
{	
	srand(time(NULL));
	frameChange = rand() % 3 + 1;
	switch (frameChange)
	{
		case 1:
		{	
			Image image("images/galaxian/GalaxianRedAlien.gif");
			Rect rect = image.getRect();
			rect.x = x-16;
			rect.y = y-16;
			surface.put_image(image, rect);
			break;
		}
		case 2:
		{
			Image image("images/galaxian/GalaxianRedAlien2.gif");
			Rect rect = image.getRect();
			rect.x = x-16;
			rect.y = y-16;
			surface.put_image(image, rect);
			break;
		}
		case 3:
		{
			Image image("images/galaxian/GalaxianRedAlien3.gif");
			Rect rect = image.getRect();
			rect.x = x-16;
			rect.y = y-16;
			surface.put_image(image, rect);
			break;
		}
		default:
			break;
	}
}

bool RedAlien::shallShoot()
{
	return 0;
}

void RedAlien::setShootFlag(bool shtflag)
{}
