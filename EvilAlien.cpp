#include "EvilAlien.h"

EvilAlien::EvilAlien(int x_, int y_)
{	
	worth = 50;
	x = x_;
    y = y_;
    swaX = x_;
    swaY = y_;
    dx = 0;
    dy = 0;
    shootflag = false;
    attackmode = false;
}

void EvilAlien::drawOn(Surface & surface)
{	
	Image image("images/galaxian/GalaxianFlagship.gif");
	Rect rect = image.getRect();
	rect.x = x-16;
	rect.y = y-16;
	surface.put_image(image, rect);	
}

bool EvilAlien::shallShoot()
{	
	if (shootflag == false)
	{
		shootchance = rand() % 5 + 1;
		switch (shootchance)
		{
			case 1:
			{
				return 1;
				break;
			}
			default:
			{
				return 0;
				break;
			}
		}
	}
	else
	{
		return 0;
	}
		
}

void EvilAlien::setShootFlag(bool shtflag)
{
	shootflag = shtflag;
}