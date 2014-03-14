#ifndef REDALIEN_H
#define REDALIEN_H

#include "Includes.h"
#include "Constants.h"
#include "Alien.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>


class RedAlien : public Alien
{
public:
	RedAlien(int x_, int y_);
	void drawOn(Surface & surface);
	bool shallShoot();
	void setShootFlag(bool shtflag);

protected:
	int frameChange;
};

#endif
