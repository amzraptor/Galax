#include "Boom.h"


Boom::Boom(int x_, int y_)
{	
    x = x_+16;
    y = y_+16;
	startTime = getTicks();
}

void Boom::drawOn(Surface & surface)
{
	srand(time(NULL));

	for (int i=0; i < 160; i++)
	{	
		u = rand() % 40 + (-40);
		d = rand() % 40 + (-40);
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		xU = x + u;
		yU = y + d;
		if ((xU >= 0) && (xU <= W) && (yU >= 0) && (yU <= H)) //to avoid crash
		{
			surface.put_pixel(xU, yU, r, g, b);
		}
	}

}

void Boom::update()
{
	now = getTicks();
	timer = now - startTime;
}

int Boom::getTimer()
{	
	return timer;
}


