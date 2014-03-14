#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>


#include "Includes.h"
#include "Constants.h"
#include "StatusBar.h"
#include "Alien.h"
#include "GreenAlien.h"
#include "RedAlien.h"
#include "PurpleAlien.h"
#include "EvilAlien.h"
#include "Swarm.h"
#include "Player.h"
#include "PlayerFire.h"
#include "EnemyFire.h"
#include "Boom.h"

const int gameoverPosX = 150;
const int gameoverPosY = 165;
const int swarmStartPosX = 10;
const int swarmStartPosY = 50;
const int horizontalAliensNum = 9;	
const int verticalAliensNum = 4;
const int horizontalGap = 40;		//avoid going beyond a total of W size (horizontal aliens X horiz Gap should be less than W
const int veticalGap = 40; 
const int enemyBulletsMax = 20;
const int attackingAliensMax = 5;




int main(int argc, char * argv[])
{	
	//music and sound
	Music music("sounds/GameLoop.ogg");
	Sound bang("sounds/laser.wav");
	Sound boom("sounds/explosion.wav");

	
	//used for welcome loop
	GreenAlien greenmodel(600, 250);
	RedAlien redmodel(600, 280);
	PurpleAlien purplemodel(600, 310);
	EvilAlien evilmodel(600, 340);


	int lazerticks = getTicks();					//IMAA FIREEN MA LAZZER
	int distX; 						//used to hold for dist x -x 
	int distY;						//used to holdfor dist y -y
	double totdist; 				//to hold distance between two points
	int moveDir;					//to hold move direction for aliens update
	int widthAccum;					//to hold width for swarm
	int randomize;
	srand (time(NULL));


	bool welcome = true;
	bool gameover = true;
	bool startgame = true;

	//making stuff & such..
	Surface surface(W, H);
    Event event;
	Keyboard kbd(event);
	StatusBar statbar;
	widthAccum = (horizontalGap*(horizontalAliensNum));
	Swarm fleet(swarmStartPosX, widthAccum);
	Player player;
	std::vector<Alien*> aliens;
	std::vector<PlayerFire> lazer;
	std::vector<EnemyFire> badlazer;
	std::vector<Boom> explosion;
	


	for (int j = 0; j < verticalAliensNum; j++)
	{
		for (int i = 0; i < horizontalAliensNum; i++)
		{
			randomize = rand() % 4 + 1;
			switch (randomize)
			{
				case 1:
				{
					aliens.push_back(new EvilAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
					break;
				}
				case 2:
				{
					aliens.push_back(new GreenAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
					break;
				}
				case 3:
				{
					aliens.push_back(new RedAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
					break;
				}
				case 4:
				{
					aliens.push_back(new PurpleAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
					break;
				}
				default: break;
			}

			
		}
	}

	//welcome screen
	while(welcome)
	{
		//events
		if (event.poll() && event.type() == QUIT) 
			{
				startgame = false;
				gameover = false;
				break;
			}

		KeyPressed keypressed = get_keypressed();
		if (keypressed[SPACE])
		{
			welcome = false;
		}

		//update
		if (greenmodel.getX() > 320)
		{
			greenmodel.move(-1,0);
			redmodel.move(-1,0);
			purplemodel.move(-1,0);
			evilmodel.move(-1,0);
		}



		surface.lock();
		surface.fill(BLACK);
		//draw starts

		Font font("fonts/FreeSerifBoldItalic.ttf", 60);
		Color r = {255,0,0};
		Image image(font.render("GALAXIAN", r));
		Rect rect = image.getRect();
		rect.x = 140;
		rect.y = 50;
		surface.put_image(image, rect);

		Font font2("fonts/FreeMono.ttf", 30);
		Color b = {0,0,225};
		Image image2(font2.render("A Game By: Ahmad Elhedek", b));
		Rect rect2 = image2.getRect();
		rect2.x = 100;
		rect2.y = 190;
		surface.put_image(image2, rect2);

		Font font3("fonts/FreeSerifBoldItalic.ttf", 20);
		Color y = {0,225,0};
		Image image3(font3.render("Press Spacebar to continue", y));
		Rect rect3 = image3.getRect();
		rect3.x = 175;
		rect3.y = 450;
		surface.put_image(image3, rect3);

		greenmodel.drawOn(surface);
		redmodel.drawOn(surface);
		purplemodel.drawOn(surface);
		evilmodel.drawOn(surface);


		Image image4(font3.render("10", r));
		Rect rect4 = image4.getRect();
		rect4.x = 240;
		rect4.y = 235;
		surface.put_image(image4, rect4);

		Image image5(font3.render("20", r));
		Rect rect5 = image5.getRect();
		rect5.x = 240;
		rect5.y = 265;
		surface.put_image(image5, rect5);

		Image image6(font3.render("30", r));
		Rect rect6 = image6.getRect();
		rect6.x = 240;
		rect6.y = 295;
		surface.put_image(image6, rect6);

		Image image7(font3.render("50", r));
		Rect rect7 = image7.getRect();
		rect7.x = 240;
		rect7.y = 325;
		surface.put_image(image7, rect7);

		//draw ends
		surface.unlock();
		surface.flip();

		delay(10);

	}

	
	music.play();

	while(startgame)
    {
		/*
    	//keyboard events
		*/

		if (statbar.getLives() == 0)
		{
			startgame = false;
		}

		if (event.poll() && event.type() == QUIT) 
			{
				gameover = false;
				break;
			}

		KeyPressed keypressed = get_keypressed();
		if (keypressed[LEFTARROW])
		{
			player.move('l');
		}
		if (keypressed[RIGHTARROW])
		{
			player.move('r');
		}
		if (keypressed[SPACE] && (lazerticks+200)< getTicks())
		{
			if(lazer.size() < 3)
			{
				lazerticks = getTicks();
				lazer.push_back(PlayerFire(player.getX(),player.getY()));
				bang.play();
			}
		}

		/*
		//update events
		*/

		//lazer and alien related
		for (int j = 0; j < aliens.size(); j++)
		{
			for (int i = 0; i < lazer.size(); i++)
			{
				distX = aliens[j]->getX() - lazer[i].getX();
				distY = aliens[j]->getY() - lazer[i].getY();
				totdist = sqrt((distX*distX) + (distY*distY));
				if ((totdist <= 10) && (lazer[i].getLive() != false))  //impact with aliens
				{
					explosion.push_back(Boom(aliens[j]->getX(),aliens[j]->getY()));
					statbar.addScore(aliens[j]->getWorth());
					statbar.plusKills();
					if (aliens[j]->getAttackMode() == true)
					{
						fleet.updateTotalAttacking(-1);
					}
					boom.play();
					delete aliens[j];							//deleting the object the pointer is pointing to
					aliens.erase(aliens.begin()+j);
					lazer[i].setLive(false);
				}
			}
		}


		//aliens and fleet
		moveDir = fleet.getMoveDirection();
		fleet.update();
		
		for (int i = 0; i < aliens.size(); i++)
		{
			if ((aliens[i]->shallShoot() == true) && (fleet.getTotEnemyLazer() < enemyBulletsMax)) //decide and shoot
			{
				fleet.updateEnemyLazer(1);
				aliens[i]->setShootFlag(true);
				badlazer.push_back(EnemyFire(aliens[i]->getX(),aliens[i]->getY()));
			}

			if ((aliens[i]->shallAttack() == true) && (fleet.getTotalAttacking() < attackingAliensMax)) //decide and attack
			{
				fleet.updateTotalAttacking(1);
				aliens[i]->setAttackMode(true);
				
			}

			if ((aliens[i]->getY() == H) && (aliens[i]->getAttackMode() == true))
			{
				fleet.updateTotalAttacking(-1);
				aliens[i]->returnToSwarm();
				aliens[i]->setReturnMode(true);
				aliens[i]->setAttackMode(false);
			}

			if ((aliens[i]->getY() == aliens[i]->getSwaY()) && (aliens[i]->getReturnMode() == true))
			{
				aliens[i]->setReturnMode(false);
			}

			if (badlazer.empty() == true) //reset shoot flag if badlazer is empty
			{
				aliens[i]->setShootFlag(false);
			}


			//movement for aliens 
			if ((aliens[i]->getReturnMode() == true) && (aliens[i]->getY() < aliens[i]->getSwaY()))
			{
				aliens[i]->move(moveDir,1);
			}

			if (aliens[i]->getAttackMode() == true)
			{
				aliens[i]->move(moveDir,1);
			}
			if ((aliens[i]->getAttackMode() == false) && (aliens[i]->getReturnMode() == false))
			{
				aliens[i]->move(moveDir,0);
			}

			aliens[i]->moveInSwarm(moveDir,0);
		}

		//update explosions if not empty and get rid of some
		if (!explosion.empty())
		{
			for (int i = 0; i < explosion.size(); i++)
			{
				explosion[i].update();
			
				if (explosion[i].getTimer()> 1000)
				{
					explosion.erase(explosion.begin()+i);
				}
			}
		}

		//lazer alone
		for (int i = 0; i < lazer.size(); i++)
		{
			lazer[i].setActive();
			lazer[i].update();
			if (lazer[i].getActive() == false) //delete last lazer from vector if not active
			{	
				lazer.erase(lazer.begin());
			}
		}

		//bad lazer  hitting player..

		for (int i = 0; i < badlazer.size(); i++)
		{
			distX = (player.getX()+16) - badlazer[i].getX();
			distY = (player.getY()+16) - badlazer[i].getY();
			totdist = sqrt((distX*distX) + (distY*distY));

			if ((totdist <= 16) && (badlazer[i].getLive() != false))  //impact with player
			{
				explosion.push_back(Boom(player.getX()+20,player.getY()+20));
				statbar.minusLives();
				badlazer[i].setLive(false);
				player.respawn();
				boom.play();
			}

		}

		//aliens hitting player

		for (int i = 0; i < aliens.size(); i++)
		{
			distX = (player.getX()+16) - aliens[i]->getX();
			distY = (player.getY()+16) - aliens[i]->getY();
			totdist = sqrt((distX*distX) + (distY*distY));

			if ((totdist <= 16) && (aliens[i]->getAttackMode() == true))  //alien impact with player 
			{
				explosion.push_back(Boom(player.getX()+20,player.getY()+20));
				statbar.minusLives();
				explosion.push_back(Boom(aliens[i]->getX(),aliens[i]->getY()));
				delete aliens[i];
				aliens.erase(aliens.begin()+i);
				fleet.updateTotalAttacking(-1);
				player.respawn();
				boom.play();
			}

		}

		//bad lazer alone
		for (int i = 0; i < badlazer.size(); i++)
		{
			badlazer[i].setActive();
			badlazer[i].update();

			if (badlazer[i].getActive() == false) //delete last badlazer from vector if not active
			{
				fleet.updateEnemyLazer(-1);
				badlazer.erase(badlazer.begin()+i);
			}
		}

		//repopulate if empty
		if (aliens.empty() == true)
		{
			fleet.reset(swarmStartPosX, widthAccum);
			for (int j = 0; j < verticalAliensNum; j++)
			{
				for (int i = 0; i < horizontalAliensNum; i++)
				{
					randomize = rand() % 4 + 1;
					switch (randomize)
					{
						case 1:
						{
							aliens.push_back(new EvilAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
							break;
						}
						case 2:
						{
							aliens.push_back(new GreenAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
							break;
						}
						case 3:
						{
							aliens.push_back(new RedAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
							break;
						}
						case 4:
						{
							aliens.push_back(new PurpleAlien (swarmStartPosX+(horizontalGap*i), swarmStartPosY+(veticalGap*j)));
							break;
						}
						default: break;
					}

					
				}
			}

		}


	
		surface.lock();
		surface.fill(BLACK);

		/*
		//drawing starts
		*/

		//draw status bar

		statbar.drawOn(surface);


		//draw aliens
		for (int i = 0; i < aliens.size(); i++)
		{
			aliens[i]->drawOn(surface);
		}
		
		//draw player
		player.drawOn(surface);

		//draw lazer
		for (int i = 0; i < lazer.size(); i++)
		{
			if (lazer[i].getLive() == true)
			{
				lazer[i].drawOn(surface);
			}
		}

		//draw bad lazer
		for (int i = 0; i < badlazer.size(); i++)
		{
			if (badlazer[i].getLive() == true)
			{
				badlazer[i].drawOn(surface);
			}
		}

		//draw explosions
		for (int i = 0; i < explosion.size(); i++)
		{
			explosion[i].drawOn(surface);
		}
		
		/*
		//drawing ends 
		*/
			
		surface.unlock();
		surface.flip();
	

		delay(10);
		
    }

    int overticks = getTicks(); //counter
    
    while(gameover)
    {
    	//events
		if (event.poll() && event.type() == QUIT) break;


		if ((overticks+5000)< getTicks())
		{
			gameover = false;
		}

		//update



		surface.lock();
		surface.fill(BLACK);
		//draw starts

		Font font("fonts/FreeMono.ttf", 60);
		Color r = {255,0,0};
		Image image(font.render("GAME OVER", r));
		Rect rect = image.getRect();
		rect.x = gameoverPosX;
		rect.y = gameoverPosY;
		surface.put_image(image, rect);


		//draw ends
		surface.unlock();
		surface.flip();

		delay(10);

    }

}
