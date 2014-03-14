#ifndef EVENT_H
#define EVENT_H

/*****************************************************************************

  An Event object models an event. The useful methods are poll() and type().
  The most useful values returned by type() are
  * QUIT
  * KEYDOWN
  * KEYUP

  USAGE: The following is an example involving the Event and Keyboard classes.

	Event event;
	Keyboard kbd;
	bool quit = false;

	while ( !quit )
	{
		if ( event.poll() )
		{
			if ( event.type() == QUIT )
			{ 
				quit = true;
			}
			else if ( event.type() == KEYDOWN || event.type() == KEYUP )
			{
				kbd.update( event );
			}
		}
		if ( kbd.keypressed(LEFTARROW) )
			std::cout << "left key down\n";
		if ( kbd.keypressed(RIGHTARROW) )
			std::cout << "right key down\n";

	}

*****************************************************************************/
const Uint32 QUIT        = SDL_QUIT;
const Uint32 KEYDOWN     = SDL_KEYDOWN;
const Uint32 KEYUP       = SDL_KEYUP;
const Uint32 LEFTARROW   = SDLK_LEFT;
const Uint32 RIGHTARROW  = SDLK_RIGHT;
const Uint32 UPARROW     = SDLK_UP;
const Uint32 DOWNARROW   = SDLK_DOWN;
const Uint32 SPACE       = SDLK_SPACE;
const Uint32 MOUSEMOTION = SDL_MOUSEMOTION;
const Uint32 TAB		 = SDLK_TAB;

class Event;
class Keyboard;

class Event
{
public:

	int poll() 
	{
		return SDL_PollEvent( &event );
	}

	Uint32 type()
	{
		return event.type;
	}

	Uint8 keypressed( int code )
	{
		kbd = SDL_GetKeyState( NULL );
		return kbd[ code ];
	}

	SDL_KeyboardEvent * get_key()
	{
		return &event.key;
	}

	SDL_MouseMotionEvent * motion()
	{
		return &event.motion;
	}

private:
	SDL_Event event;
	Uint8 * kbd;
};


/*****************************************************************************

  A Keyboard object models a simple keyboard. The Keyboard object considers a 
  key pressed until the key is released. While a key is pressed, if another
  key is pressed, the second key is ignored. (Hence this does not work in the
  case when you need Shift-A. But it's enough for your game).

  USAGE:
    If there is a KEYDOWN or KEYUP event type, then the update() method of the
	Keyboard class should be called. To check if the left arrow key is pressed,
	called keyboard.pressed( LEFTARROW ).
	See above.

*****************************************************************************/
class Keyboard
{
public:
	Keyboard( Event & event ) : keydown(false) {}

	void update( Event & event )
	{
		SDL_KeyboardEvent * key = event.get_key();
		switch ( key->type )
		{
			case KEYDOWN:
			{
				if ( !keydown )
				{
					keydown = true;
					sym = key->keysym.sym;
				}
				break;
			}

			case KEYUP:
			{
				if ( keydown && key->keysym.sym == sym )
				{
					keydown = false;
				}
				break;
			}
		}
	}

	int get_sym()
	{
		return sym;
	}

	bool keypressed( int sym0 )
	{
		return keydown && ( sym == sym0 );
	}

private:
	bool keydown;
	int sym;
};

/*****************************************************************************

  A Mouse object models a mouse. Right now this support only the mouse motion,
  i.e., it returns the x and y value of the relative mouse cursor position. 

  If there is a MOUSEMOTION event type, then the update() method of the Mouse
  class should be called.
	* x() returns the relative x position of the mouse cursor
	* y() returns the relation y position of the mouse cursor

  USAGE:
    Event event;
	Mouse mouse;
	bool quit
	while ( !quit )
	{
	    if ( event.poll() )
		{
			switch ( event.type() )
			{
				case QUIT: 
					quit = true;
					break;

				case MOUSEMOTION:
					mouse.update( event );
					printf( "%d, %d\n", mouse.x(), mouse.y() );
			}
		}
	}

*****************************************************************************/
class Mouse
{
public:
	void update( Event & event )
	{
		x0 = event.motion()->x;
		y0 = event.motion()->y;
	};

	int x()
	{
		return x0;
	}

	int y()
	{
		return y0;
	}

private:
	int x0, y0;
};

#endif
