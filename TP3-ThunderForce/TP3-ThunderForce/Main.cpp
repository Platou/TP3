#include <vld.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#define LARGEUR 800
#define HAUTEUR 600

//namespace SFML
using namespace sf;
using namespace std;

//La fen�tre principale
//http://www.sfml-dev.org/tutorials/2.3/window-window-fr.php
//Deux options suppl�mentaires: Image fixe et plein �cran
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
	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes
	//� faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //�quivalent
}

void GetInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�u!
	while (mainWin.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}

		//Si on a un �v�ment de changement de taille
		if (event.type == Event::Resized)
		{
			//Fixer la taille de la vue (par d�faut, elle reste proportionnelle
			//mainWin.setView(view = View(FloatRect(0.f, 0.f, static_cast<float>(mainWin.getSize().x), static_cast<float>(mainWin.getSize().y))));

			//Afficher la taille de la fen�tre dans la barre de titre
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