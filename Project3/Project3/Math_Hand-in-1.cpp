

#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>
#include <iostream>
#include <Mouse.hpp>

using namespace sf;    //use this so i don't have to write sf every time i want to do a sfml function
using namespace std;


float Eco; //coordinates for the Earth
float Mco; //coordinates for the Moon
float eSwitcher = -0.01; //using this to dictate which direction the EARTH is orbiting
float mSwitcher = 0.02; //using this to dictate which direction the EARTH is orbiting


Clock Orb;
CircleShape sun(100.f);
CircleShape earth(20.f);
CircleShape moon(10.f);
RenderWindow window(VideoMode(1000, 1000), "Sola System");

//various details about the shapes
void draw()
{
	//basic stats for the various planets
	sun.setFillColor(Color::Yellow);
	earth.setFillColor(Color::Blue);
	moon.setFillColor(Color::White);
	sun.setPosition(500, 500);
	earth.setPosition(250 * cos(Eco * 3.14 / 180.0f) + sun.getPosition().x, 250 * sin(Eco * 3.14 / 180.0f) + sun.getPosition().y);
	moon.setPosition(50 * cos(Mco * 3.14 / 180.0f) + earth.getPosition().x, 50 * sin(Mco * 3.14 / 180.0f) + earth.getPosition().y);

	sun.setOrigin(100, 100);        //setting the origins just make it easier to do this stuff
	earth.setOrigin(20, 20);
	moon.setOrigin(10, 10);
}
//rotation using a clock
void rotate()
{
	Eco += eSwitcher;
	Mco += mSwitcher;

	Time elapsed = Orb.getElapsedTime();
	if (elapsed.asMilliseconds())
	{

		earth.setPosition(250 * cos(Eco * 3.14 / 180.0f) + sun.getPosition().x, 250 * sin(Eco * 3.14 / 180.0f) + sun.getPosition().y);
		moon.setPosition(50 * cos(Mco * 3.14 / 180.0f) + earth.getPosition().x, 50 * sin(Mco * 3.14 / 180.0f) + earth.getPosition().y);

		Orb.restart();
	}

}

int main()
{

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:

				window.close();

				break;

			case Event::MouseButtonPressed:

				switch (event.key.code)
				{
				case Mouse::Left:
					//switches moon and earth orbit
					if (Mouse::getPosition(window).x < earth.getPosition().x + 20
						&& Mouse::getPosition(window).x > earth.getPosition().x - 20
						&& Mouse::getPosition(window).y < earth.getPosition().y + 20
						&& Mouse::getPosition(window).y > earth.getPosition().y - 20)
						eSwitcher *= -1;
					if (Mouse::getPosition(window).x < moon.getPosition().x + 10
						&& Mouse::getPosition(window).x > moon.getPosition().x - 10
						&& Mouse::getPosition(window).y < moon.getPosition().y + 10
						&& Mouse::getPosition(window).y > moon.getPosition().y - 10)
						mSwitcher *= -1;

					break;
				}

			}

		}

		draw();                           //draws the stuff
		window.clear();
		window.draw(sun);
		window.draw(earth);
		window.draw(moon);
		window.display();
		rotate();           //rotates both earth and the moon, alter 'switcher' to change rotation speed and direction
	}

	return 0;
}
