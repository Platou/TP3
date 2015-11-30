#include <vld.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#define LARGEUR 800
#define HAUTEUR 600

//namespace SFML
using namespace sf;
using namespace std;

//La fenêtre principale
//http://www.sfml-dev.org/tutorials/2.3/window-window-fr.php
//Deux options supplémentaires: Image fixe et plein écran
RenderWindow mainWin(VideoMode(LARGEUR, HAUTEUR, 32), "Circle Beat!");// , Style::Titlebar); / , Style::FullScreen);
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
	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes
	//À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //Équivalent
}

void GetInputs()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}

		//Si on a un évément de changement de taille
		if (event.type == Event::Resized)
		{
			//Fixer la taille de la vue (par défaut, elle reste proportionnelle
			//mainWin.setView(view = View(FloatRect(0.f, 0.f, static_cast<float>(mainWin.getSize().x), static_cast<float>(mainWin.getSize().y))));

			//Afficher la taille de la fenêtre dans la barre de titre
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