#include <iostream>
#include <SFML/Window.hpp>
#include "worldbuilder.h"

using namespace std;

static void event_loop()
{
	int mode = 0;
	//mode 1 == peliss‰, t‰h‰n voi lis‰ill‰ modeja menuun mit‰ haluaa
	//mainin piirto
	//keylistenerit / mouse listener mill‰ vaihdetaan tota modea sfml avulla ett‰ p‰‰see peliin
	// jos modeja tulee enemm‰n niin vaihtaa ton if silmukan switchiksi, jne.
	if (mode != 0) {


	}


}

int main()
{
	cout << "STARTING" << endl;
	sf::RenderWindow win(sf::VideoMode(960, 540), "Angry Birds");
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
	float32 timeStep = 1.0f / 1.0f;
	int32 velocityIterations = 8;
	int32 positionIterations = 3;

	RectBody a;
	a.init(&world);
	Worldbuilder wrld("1");

	while (win.isOpen()) {

		world.Step(timeStep, velocityIterations, positionIterations);

		sf::Event evnt;
		while (win.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				win.close();
				break;
			case sf::Event::Resized:
				printf("Uusi leveys: %i Uusi korkeus: %i\n", evnt.size.width, evnt.size.height);
				break;
			}
		}

		wrld.Draw(win);
		win.clear();
		win.display();
	}
	event_loop();
	return 0;
}
