#include <vld.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#define LARGEUR 1280
#define HAUTEUR 720

//using namespace TP3;
using namespace sf;
using namespace std;

RenderWindow mainWin(VideoMode(LARGEUR, HAUTEUR, 32), "Thunder Force");
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