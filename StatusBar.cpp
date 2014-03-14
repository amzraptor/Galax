#include "StatusBar.h"

StatusBar::StatusBar()
{
	lives = 3;
	score = 0;
	kills = 0;
}

int StatusBar::getLives()
{
	return lives;
}

int StatusBar::getScore()
{
	return score;
}

int StatusBar::getKills()
{
	return kills;
}

void StatusBar::addScore(int value)
{
	score += value;
}

void StatusBar::minusLives()
{
	lives--;
}

void StatusBar::plusKills()
{
	kills++;
}

void StatusBar::drawOn(Surface & surface)
{
	
	switch (lives)
	{
		case 3: 
		{
			Image image("images/galaxian/GalaxianGalaxip.gif");
		    Rect rect = image.getRect();
		    rect.x = W-32;
		    rect.y = H-32;

		    surface.put_image(image, rect);

		    Image image2("images/galaxian/GalaxianGalaxip.gif");
		    Rect rect2 = image2.getRect();
		    rect2.x = W-64;
		    rect2.y = H-32;

		    surface.put_image(image2, rect2);

		    Image image3("images/galaxian/GalaxianGalaxip.gif");
		    Rect rect3 = image3.getRect();
		    rect3.x = W-96;
		    rect3.y = H-32;

		    surface.put_image(image3, rect3);
		    break;
		}
		case 2:
		{
			Image image("images/galaxian/GalaxianGalaxip.gif");
		    Rect rect = image.getRect();
		    rect.x = W-32;
		    rect.y = H-32;

		    surface.put_image(image, rect);

		    Image image2("images/galaxian/GalaxianGalaxip.gif");
		    Rect rect2 = image2.getRect();
		    rect2.x = W-64;
		    rect2.y = H-32;

		    surface.put_image(image2, rect2);
		    break;
		}
		case 1:
		{
			Image image("images/galaxian/GalaxianGalaxip.gif");
		    Rect rect = image.getRect();
		    rect.x = W-32;
		    rect.y = H-32;

		    surface.put_image(image, rect);
		    break;
		}
		default:
		break;
	}

	//printing score
	Font font("fonts/FreeSans.ttf", 32);
	Color c = {0,255,0};
	Color b = {225,255, 0};

	Image imagescoretext(font.render("Score:",c));
	Rect rectscoretext = imagescoretext.getRect();
	rectscoretext.x = 5;
	rectscoretext.y = H- 42;

	surface.put_image(imagescoretext, rectscoretext);

	//converting int to string
	std::stringstream strmsc;
	strmsc << score;

	Image imagescore(font.render(strmsc.str().c_str(), b));
	Rect rectscore = imagescore.getRect();
	rectscore.x = 170;
	rectscore.y = H-42;

	surface.put_image(imagescore, rectscore);

	Image imagehittext(font.render("Kills:",c));
	Rect recthittext = imagehittext.getRect();
	recthittext.x = 300;
	recthittext.y = H- 42;

	surface.put_image(imagehittext, recthittext);


	std::stringstream strmki;
	strmki << kills;

	Image imagekills(font.render(strmki.str().c_str(), b));
	Rect rectkills = imagekills.getRect();
	rectkills.x = 430;
	rectkills.y = H-42;

	surface.put_image(imagekills, rectkills);
}