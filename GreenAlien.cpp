#include "GreenAlien.h"

GreenAlien::GreenAlien(int x_, int y_)
{	
	worth = 10;
	x = x_;
    y = y_;
    swaX = x_;
    swaY = y_;
    dx = 0;
    dy = 0;
    attackmode = false;
}

void GreenAlien::drawOn(Surface & surface)
{	
	srand(time(NULL));
	frameChange = rand() % 3 + 1;
	switch (frameChange)
	{
		case 1:
		{	
			Image image("images/galaxian/GalaxianAquaAlien.gif");
			Rect rect = image.getRect();
			rect.x = x-16;
			rect.y = y-16;
			surface.put_image(image, rect);
			break;
		}
		case 2:
		{
			Image image("images/galaxian/GalaxianAquaAlien2.gif");
			Rect rect = image.getRect();
			rect.x = x-16;
			rect.y = y-16;
			surface.put_image(image, rect);
			break;
		}
		case 3:
		{
			Image image("images/galaxian/GalaxianAquaAlien3.gif");
			Rect rect = image.getRect();
			rect.x = x-16;
			rect.y = y-16;
			surface.put_image(image, rect);
			break;
		}
		default: break;
	}
}

bool GreenAlien::shallShoot()
{
	return 0;
}

void GreenAlien::setShootFlag(bool shtflag)
{}
