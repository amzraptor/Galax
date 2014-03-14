#include "EnemyFire.h"



EnemyFire::EnemyFire(int posX, int posY)
{
	x = posX;
	y = posY;
	dy = 2;
	active = true;
	live = true;
}

int EnemyFire::getY()
{
	return y;
}	

int EnemyFire::getX()
{
	return x;
}

void EnemyFire::drawOn(Surface & surface)
{
    Image image("images/galaxian/RedFire.gif");
    Rect rect = image.getRect();
    rect.x = x-5;
    rect.y = y-5;

    surface.put_image(image, rect);
}

void EnemyFire::update()
{
	y += dy;
}

void EnemyFire::setActive()
{
	if (y >= H)
	{
		active = false;
	}
}
bool EnemyFire::getActive()
{
	return active;
}

void EnemyFire::setLive(bool state)
{
	live = state;
}
bool EnemyFire::getLive()
{
	return live;
}



