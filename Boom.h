#ifndef BOOM_H
#define BOOM_H

#include "Includes.h"
#include "Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



class Boom
{
public:

    Boom(int x_, int y_);
    void drawOn(Surface & surface);
    void update();
	int getTimer();

private:
    // Position
    int x, y;

    // Velocity
    int dx, dy;
	
	//to calculate distance travelled
	int travel;

	int u, d;					//for random position for pixels
	int r, g, b; 				//color randoms
	int xU, yU; 				//to hold random factor along with initial pos
	int startTime, timer, now; 	//for time elapsed 

};

#endif
