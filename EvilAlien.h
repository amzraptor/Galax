#ifndef EVILALIEN_H
#define EVILALIEN_H

#include "Includes.h"
#include "Constants.h"
#include "Alien.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>


class EvilAlien : public Alien
{
public:
	EvilAlien(int x_, int y_);
	void drawOn(Surface & surface);
	bool shallShoot();
	void setShootFlag(bool shtflg);

protected:
	int shootchance;
	bool shootflag;
};


#endif
