#define _USE_MATH_DEFINES
#include "Game.h"
#include <iostream>
#include <time.h>
#define LARGEUR 1280
#define HAUTEUR 720

using namespace TP3;
using namespace sf;

RenderWindow mainWin(VideoMode(LARGEUR, HAUTEUR, 32), "TP3 - Thunder Force");

Game::Game()
{

  Init();

  while (mainWin.isOpen())
  {
    GetInputs();
    Update();
    Draw();
  }
}


Game::~Game()
{
  //delete player;
}

// Initialise les diff�rents �l�ments principaux
bool Game::Init()
{
  mainWin.setFramerateLimit(60);
  srand(time(NULL));

  //Ici chargement dans notre texture.
  //if (!player->ChargerTextures("Assets\\player.png"))
  //{
  //  return false;
  //}

  ////On cr�e notre Player
  //player = new Player(125, 600, VITESSE, 6, NOMBRE_ANIMATIONS, NOMBRE_FRAMES_IMMOBILE, NOMBRE_FRAMES_MOUVEMENT, &mainWin);

  //player->AjustementsVisuels();

  lastOrientationOfPlayer = Vector2f(0, -1);

  return true;
}

//void Game::KeyboardMovement()
//{
//  //Avec le clavier les directions sont franches
//  //On teste les directions gauche / droite / neutre
//  //Et pour chacune au dessus les direction haut / bas / neutre
//  if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
//  {
//    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
//    {
//      interfaceDeplacement.x = -DIAGONALE;
//      interfaceDeplacement.y = -DIAGONALE;
//      player->AjustementsDuCadrant(GAUCHE_HAUT);
//      lastOrientationOfPlayer = interfaceDeplacement;
//
//    }
//    else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
//    {
//      interfaceDeplacement.x = -DIAGONALE;
//      interfaceDeplacement.y = DIAGONALE;
//      player->AjustementsDuCadrant(GAUCHE_BAS);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//    else
//    {
//      interfaceDeplacement.x = -1;
//      interfaceDeplacement.y = 0;
//      player->AjustementsDuCadrant(GAUCHE);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//  }
//  else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
//  {
//    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
//    {
//      interfaceDeplacement.x = DIAGONALE;
//      interfaceDeplacement.y = -DIAGONALE;
//      player->AjustementsDuCadrant(DROITE_HAUT);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//    else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
//    {
//      interfaceDeplacement.x = DIAGONALE;
//      interfaceDeplacement.y = DIAGONALE;
//      player->AjustementsDuCadrant(DROITE_BAS);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//    else
//    {
//      interfaceDeplacement.x = 1;
//      interfaceDeplacement.y = 0;
//      player->AjustementsDuCadrant(DROITE);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//  }
//  else
//  {
//    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
//    {
//      interfaceDeplacement.x = 0;
//      interfaceDeplacement.y = -1;
//      player->AjustementsDuCadrant(HAUT);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//    else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
//    {
//      interfaceDeplacement.x = 0;
//      interfaceDeplacement.y = 1;
//      player->AjustementsDuCadrant(BAS);
//      lastOrientationOfPlayer = interfaceDeplacement;
//    }
//    else
//    {
//      interfaceDeplacement.x = 0;
//      interfaceDeplacement.y = 0;
//      player->AjustementsDuCadrant(IMMOBILE);
//    }
//  }
//
//  if (Keyboard::isKeyPressed(Keyboard::Space) && player->GetShootingState() && playerBullets.size() < MAXBULLETSFORPLAYER)
//  {
//    playerBullets.push_back(player->Shoot(lastOrientationOfPlayer, player->getPosition(), player->GetBulletRotation()));
//    player->SetShootingState(false);
//  }
//}

void Game::Update()
{

}

void Game::Draw()
{

  mainWin.clear();

  mainWin.display();
}

void Game::GetInputs()
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
    }

    if (event.type == Event::KeyReleased) // COMMANDE DE TEST POUR GENERER LES MURS
    {
      if (event.key.code == Keyboard::Space)
      {
       // player->SetShootingState(true);
      }
    }

    //KeyboardMovement();
  }
}
