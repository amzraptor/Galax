#include "Player.h"


Player::Player()
{
	x = (W/2)-15;
	y = H-80;
	dx = 0;
	dy = 0;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

void Player::respawn()
{
	x = 570;
	y = H-80;	
}	

void Player::drawOn(Surface & surface)
{
    Image image("images/galaxian/GalaxianGalaxip.gif");
    Rect rect = image.getRect();
    rect.x = x;
    rect.y = y;

    surface.put_image(image, rect);
}

void Player::move(char dir)
{
	if (x <= 0 && dir == 'l')
	{
		return;
	}
	else if (x >= 570 && dir == 'r')
	{
		return;
	}
	else
	{
		if (dir == 'l')
		{
			dx = -3;
		}

		if (dir == 'r')
		{
			dx = 3;
		}
	x += dx;
	}
	
}

