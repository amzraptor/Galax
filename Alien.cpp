#include "Alien.h"

int Alien::getY()
{
    return y;
}   

int Alien::getX()
{
    return x;
}

int Alien::getSwaY()
{
	return swaY;
}

void Alien::move(int dirX, int dirY)
{
    x += dirX;
    y += dirY;
}

void Alien::moveInSwarm(int dirX, int dirY)
{
    swaX += dirX;
    swaY += dirY;	
}

int Alien::getWorth()
{
	return worth;
}

bool Alien::getAttackMode()
{
	return attackmode;
}

void Alien::setAttackMode(bool atkflag)
{
	attackmode = atkflag;
}

bool Alien::shallAttack()
{
	if (attackmode == false)
	{
		attackchance = rand() % 100+ 1;
		switch (attackchance)
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

void Alien::returnToSwarm()
{
	x= swaX;
	y= 0;
}

void Alien::setReturnMode(bool rtrnflg)
{
	returnmode = rtrnflg;
}

bool Alien::getReturnMode()
{
	return returnmode;
}