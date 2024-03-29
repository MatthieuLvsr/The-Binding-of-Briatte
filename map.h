/** Génération d'une pièce
 * Date 23/10/2022
*/

#ifndef MAP_H
#define MAP_H

#include "floor.h"
#include "map.h"
#include "player.h"
#include "shooter.h"

// #include "floor.h"
// #include "player.h"

typedef struct MAP{
    char** room;
    int height;
    int width;
    char status;
}MAP;

/** Récupération de la disposition de la salle
 * @param id id de la salle
 * @return l'objet MAP de la salle
*/
MAP* getMap(int id);

/** Initialisation du tableau de caractères
 * @param height hauteur de la salle
 * @param width largeur de la salle
 * @return tableau à 2 dimensions de caractères
*/
char** initRoom(int height, int width);

/** Affichage de la salle
 * @param room tableau de caractères à deux dimensions
 * @param height hauteur de la pièce
 * @param width largeur de la pièce
 * @param player joueur
 * @param shoots liste des tirs
*/
void displayRoom(char** room, int height, int width, PLAYER player, SHOOT* shoots);

/** Récupération du nombre de maps
 * @return nombre de pattern disponibles dans le fichier
*/
int nbMaps(void);

#endif