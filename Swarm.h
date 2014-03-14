#ifndef SWARM_H
#define SWARM_H

#include "Includes.h"
#include "Constants.h"

class Swarm
{
	public:

	Swarm(int startp, int w);
	int getMoveDirection();
	void update();
	void setMoveDirection();
	void updateEnemyLazer(int count);
	int getTotEnemyLazer();
	void updateTotalAttacking(int count);
	int getTotalAttacking();
	void reset(int startp, int w);
	
	private:
	int dx;
	int leftEdge;
	int rightEdge;
	int width;
	int totenemylazer;
	int totattacking;
};


#endif
