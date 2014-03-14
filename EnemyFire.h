#ifndef ENEMYFIRE_H
#define ENEMYFIRE_H

#include "Includes.h"
#include "Constants.h"

class EnemyFire
{
public:
    EnemyFire(int posX, int posY);
	int getY();
    int getX();
    void drawOn(Surface & surface);
	void update();
    void setActive();
	bool getActive();
    void setLive(bool state);
    bool getLive();

private:
    // Position
    int x, y;
	//active
	bool active;
    //live 
    bool live;

    // Velocity
    int dy;
};


#endif
