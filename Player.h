#ifndef PLAYER_H
#define PLAYER_H

#include "Includes.h"
#include "Constants.h"


class Player
{
public:
    Player();
	int getX();
	int getY();
	void respawn();
    void drawOn(Surface & surface);
    void move(char dir);


private:
    // Position
    int x, y;

    // Velocity
    int dx, dy;
};

#endif
