#include <vld.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#define LARGEUR 800
#define HAUTEUR 600

//using namespace TP3;
using namespace sf;
using namespace std;

RenderWindow mainWin(VideoMode(LARGEUR, HAUTEUR, 32), "Circle Beat!");
View view(mainWin.getDefaultView());

Event event;

void Init();
void GetInputs();
void Update();
void Draw();

int main()
{
	Init();

	while (mainWin.isOpen())
	{
		GetInputs();
		Update();
		Draw();
	}

	return EXIT_SUCCESS;
}

void Init()
{
	mainWin.setFramerateLimit(60);
}

void GetInputs()
{
	while (mainWin.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}

		if (event.type == Event::Resized)
		{
			mainWin.setTitle(to_string(mainWin.getSize().x) + " * " + to_string(mainWin.getSize().y));
		}
	}
}

void Update()
{

}

void Draw()
{
	mainWin.clear();

	mainWin.display();
}