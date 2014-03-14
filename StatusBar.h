#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <sstream> 
#include <string>

#include "Includes.h"
#include "Constants.h"




class StatusBar
{
public:
	StatusBar();
	int getLives();
	int getScore();
	int getKills();
	void addScore(int value);
	void drawOn(Surface & surface);
	void minusLives();
	void plusKills();

private:
	int lives;
	int score;
	int kills;

};

#endif
