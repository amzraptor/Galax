#include "Swarm.h"

Swarm::Swarm(int startp, int w)
{
	leftEdge = startp;
	width = w;
	rightEdge = leftEdge + width;
	dx = 1;
	totenemylazer = 0;
	totattacking = 0;
}

int Swarm::getMoveDirection()
{
  return  dx;
}

void Swarm::update()
{
	leftEdge += dx;
	rightEdge += dx;
	setMoveDirection();
}

void Swarm::setMoveDirection()
{
	if (rightEdge >= W)
	{   
		dx = -1;   
	}
    else if (leftEdge <= 30)
	{
		dx = 1;
	}
}

void Swarm::updateEnemyLazer(int count)
{
	totenemylazer += count;
}

int Swarm::getTotEnemyLazer()
{
	return totenemylazer;
}

void Swarm::updateTotalAttacking(int count)
{
	totattacking += count;
}

int Swarm::getTotalAttacking()
{
	return totattacking;
}

void Swarm::reset(int startp, int w)
{
	leftEdge = startp;
	width = w;
	rightEdge = leftEdge + width;
	dx = 1;
	totenemylazer = 0;
	totattacking = 0;
}
