// Classe g�rant le jeu. 
// Elle regroupe les fonctions g�n�rales essentielles au bon d�roulement de la partie.

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

namespace TP3
{
  class Game
  {
  public:
    Game();
    ~Game();

  private:
    // Les 4 fonctions de bases � tout jeu
    bool Init();
    void GetInputs();
    void Update();
    void Draw();

    // Fonctions li�es aux contr�les du jeu
    //void KeyboardMovement();

    const enum DIRECTIONS { IMMOBILE = -1, GAUCHE, GAUCHE_HAUT, HAUT, DROITE_HAUT, DROITE, DROITE_BAS, BAS, GAUCHE_BAS };

    const int WIDTH = 1280; // La largeur du jeu
    const int HEIGHT = 720; // La hauteur du jeu

    Event event;

    //Player* player; // Le personnage du joueur

    Vector2f lastOrientationOfPlayer; // La derni�re orientation du joueur avant une transition

    Vector2f interfaceDeplacement; //Vecteur de d�placement du Player
  };
}
