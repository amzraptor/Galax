#include "PlayerFire.h"



PlayerFire::PlayerFire(int posX, int posY)
{
	x = posX+16;
	y = posY;
	dy = -4;
	active = true;
	live = true;
}

int PlayerFire::getY()
{
	return y;
}	

int PlayerFire::getX()
{
	return x;
}

void PlayerFire::drawOn(Surface & surface)
{
    Image image("images/galaxian/WhiteFire.gif");
    Rect rect = image.getRect();
    rect.x = x-5;
    rect.y = y-5;

    surface.put_image(image, rect);
}

void PlayerFire::update()
{
	y += dy;
}

void PlayerFire::setActive()
{
	if (y <= 0)
	{
		active = false;
	}
}
bool PlayerFire::getActive()
{
	return active;
}

void PlayerFire::setLive(bool state)
{
	live = state;
}
bool PlayerFire::getLive()
{
	return live;
}



