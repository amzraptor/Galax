#ifndef ALIEN_H
#define ALIEN_H

#include "Includes.h"
#include "Constants.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>

class Alien
{
public:
    int getX();
    int getY();
    int getWorth();
    int getSwaY();
    bool shallAttack();
	void move(int dirX, int dirY);
    void moveInSwarm(int dirX, int dirY);
    bool getAttackMode();
    bool getReturnMode();
    void setAttackMode(bool atkflg);
    void returnToSwarm();
    void setReturnMode(bool rtrnflg);
    virtual void drawOn(Surface & surface) = 0;
    virtual bool shallShoot() = 0;
    virtual void setShootFlag(bool shtflag) = 0;

protected:
    // Position
    int x, y;

    //Position in swarm
    int swaX, swaY;

    // Velocity
    int dx, dy;

    //worth 
    int worth;

    //attack mode flag
    bool attackmode;

    //attack mode chance
    int attackchance;

    bool returnmode;
};

#endif
